#include "CustomerManager.h"
#include <fstream>
#include <sstream>
#include <cctype>

using namespace std;

bool CustomerManager::isDigitsOnly(const string& text) {
    if (text.empty()) return false;

    for (int i = 0; i < text.length(); i++) {
        if (!isdigit(text[i])) {
            return false;
        }
    }
    return true;
}

bool CustomerManager::isValidCnic(const string& text) {
    return (text.length() == 13 && isDigitsOnly(text));
}

bool CustomerManager::isValidPassword(const string& text) {
    if (text.length() != 9) return false;

    bool hasUpper = false;
    bool hasDigit = false;

    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i])) hasUpper = true;
        if (isdigit(text[i])) hasDigit = true;
    }

    return (hasUpper && hasDigit);
}

bool CustomerManager::isValidGender(const string& text) {
    return (text == "M" || text == "F" || text == "Other");
}