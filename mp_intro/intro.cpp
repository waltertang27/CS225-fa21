#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include <string>

using namespace cs225;


void rotate(std::string inputFile, std::string outputFile) {
  // TODO: Part 2

  //reading in inputFile
  PNG *image = new PNG();
  image->readFromFile(inputFile);
  unsigned int height = image->height();
  unsigned int width = image->width();

  PNG *outImage = new PNG(width, height);

  //flip the pixels around by 180 degrees
  for(unsigned int i = 0; i < width; i++) {
    for(unsigned int j = 0; j < height; j++) {
      HSLAPixel &p1 = image->getPixel(i, j);
      HSLAPixel &p2 = outImage->getPixel(width- i - 1, height - j - 1);
      p2 = p1;


    }
  }

  //write rotated image out
  outImage->writeToFile(outputFile);

  //clear up allocated memory
  delete image;
  delete outImage;
  
}

cs225::PNG myArt(unsigned int width, unsigned int height) {
  cs225::PNG png(width, height);
  // TODO: Part 3
  for(unsigned int i = 0; i < width; i++) {
    for(unsigned int j = 0; j < height; j++) {
      HSLAPixel &p = png.getPixel(i, j);
      p.a = 1;
      p.l = 0.5;
      p.s = 1;
      if(i < height / 3) {
        p.h = 225;
      }
      else if(i > 2 * height / 3) {
        p.h = 0;
      }
      else {
        p.l = 1;
      }
      
    }
  }  return png;
}
