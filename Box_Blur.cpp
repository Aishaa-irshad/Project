#include "Box_Blur.h"
#include "Image.h"
#include "Pixel.h"
using namespace std;
Box_Blur::Box_Blur(): Filter("08", "Box Blur (3x3)", "Spatial Filter"){
}
Box_Blur::~Box_Blur(){
}

void Box_Blur::apply(Image& image) const{
    cout << "Applying Box Blur Filter." << endl;
// first to create copy image
    if(image.isEmpty()){
        return;
    }
    Image source(image);
//now applying blur to each pixel
    for (int i = 0; i < image.getHeight(); ++i){
        for (int j = 0; j < image.getWidth(); ++j){
            int sumRed = 0, sumGreen = 0, sumBlue = 0;
            int count = 0;
//check all 9 positions in 3x3 grid
            for (int di = -1; di <= 1; ++di){
                for (int dj = -1; dj <= 1; ++dj){
                    int ni = i + di;
                    int nj = j + dj;
//cheking if the neighboring pixel is within bounds
                    if (ni >= 0 && ni < image.getHeight() && nj >= 0 && nj < image.getWidth()){
                        
                    Pixel& neighborPixel = image.at(ni, nj);
                    sumRed += neighborPixel.getRed();
                    sumGreen += neighborPixel.getGreen();
                    sumBlue += neighborPixel.getBlue();
                    count++;
                    }
                }
            }
//calculating the average color values
            int avgR = sumRed/count;
            int avgG = sumGreen/count;
            int avgB = sumBlue/count;
//set the blurred pixel value in the original image
            image.at(i, j).setRed(avgR);
            image.at(i, j).setGreen(avgG);
            image.at(i, j).setBlue(avgB);
        }
    }
//now replacing the org image with copy 
    cout << "Box Blur Filter applied." << endl;

}
Filter* Box_Blur::clone() const{
    return new Box_Blur(*this);
}
            