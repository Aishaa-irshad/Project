#include "ImageFile.h"
#include <iostream>
#include <fstream>
using namespace std;

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

// Helper: try loading with the given path, then with common extensions appended
static unsigned char* tryLoad(const string& path, int& w, int& h, int& ch) {
    // 1. Try exact path first
    unsigned char* data = stbi_load(path.c_str(), &w, &h, &ch, 3);
    if (data) return data;

    // 2. Try appending .png, .jpg, .jpeg in case Windows hid a double extension
    const char* exts[] = { ".png", ".jpg", ".jpeg" };
    for (int i = 0; i < 3; i++) {
        string candidate = path + exts[i];
        data = stbi_load(candidate.c_str(), &w, &h, &ch, 3);
        if (data) {
            cout << "(Found file as: " << candidate << ")" << endl;
            return data;
        }
    }
    return nullptr;
}

bool ImageFile::loadImage(const string& path, Image& image) {
    cout << "Attempting to load image from: " << path << endl;

    int width = 0, height = 0, channels = 0;
    unsigned char* data = tryLoad(path, width, height, channels);

    if (data == nullptr) {
        cout << "ERROR: Cannot load image '" << path << "'" << endl;
        cout << "Reason: " << stbi_failure_reason() << endl;
        cout << "Tip: Make sure the file exists and the path is correct." << endl;
        cout << "     (Check if Windows is hiding the real extension, e.g. 'pic.jpg' may actually be 'pic.jpg.png' on disk)" << endl;
        return false;
    }

    cout << "Image read: " << width << "x" << height
         << "  (channels: " << channels << ")" << endl;

    if (!image.setFromRGBBuffer(data, width, height)) {
        cout << "ERROR: Could not copy pixel data into Image object." << endl;
        stbi_image_free(data);
        return false;
    }

    stbi_image_free(data);
    cout << "Image loaded successfully!" << endl;
    return true;
}

// Helper: check if a string ends with a given suffix (case-insensitive)
static bool endsWith(const string& str, const string& suffix) {
    if (str.size() < suffix.size()) return false;
    string tail = str.substr(str.size() - suffix.size());
    for (char& c : tail) c = (char)tolower(c);
    string suf = suffix;
    for (char& c : suf) c = (char)tolower(c);
    return tail == suf;
}

bool ImageFile::saveImage(const string& path, const Image& image) {
    cout << "\nAttempting to save image to: " << path << endl;

    int width  = image.getWidth();
    int height = image.getHeight();

    if (width == 0 || height == 0) {
        cout << "ERROR: Image is empty" << endl;
        return false;
    }

    unsigned char* buffer = image.toRGBBuffer();
    if (buffer == nullptr) {
        cout << "ERROR: Could not convert image to RGB buffer" << endl;
        return false;
    }

    int ok = 0;

    // Save as JPG if path ends in .jpg or .jpeg, otherwise save as PNG
    if (endsWith(path, ".jpg") || endsWith(path, ".jpeg")) {
        ok = stbi_write_jpg(path.c_str(), width, height, 3, buffer, 90); // quality=90
        cout << "Format: JPEG (quality 90)" << endl;
    } else {
        ok = stbi_write_png(path.c_str(), width, height, 3, buffer, width * 3);
        cout << "Format: PNG" << endl;
    }

    delete[] buffer;

    if (!ok) {
        cout << "ERROR: Failed to save image to '" << path << "'" << endl;
        return false;
    }

    cout << "Image saved successfully to: " << path << endl;
    return true;
}
