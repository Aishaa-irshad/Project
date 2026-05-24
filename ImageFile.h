#ifndef IMAGEFILE_H
#define IMAGEFILE_H
#include "Image.h"
#include <iostream>
#include <string>
using namespace std;

class ImageFile {
public:
  static bool loadImage(const string &path, Image &image);
  static bool saveImage(const string &path, const Image &image);
};
#endif