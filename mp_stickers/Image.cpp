#include <string>
#include "Image.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <cmath>

using cs225::HSLAPixel;
using cs225::PNG;
using std::cout;
using std::endl;


/**
 * Darken an Image by decreasing the luminance of every pixel by 0.1.
*  This function ensures that the luminance remains in the range [0, 1].
 */
void Image::darken() {
    for(unsigned int x = 0; x < this->width(); x++) {
        for(unsigned int y = 0; y < this->height(); y++) {
            HSLAPixel &p = this->getPixel(x, y);
            if(p.l < 0.1) {
                p.l = 0;
            }
            else {
                p.l = p.l - 0.1;
            }
        }
    }
}
/**
 * Darkens an Image by decreasing the luminance of every pixel by amount.
 * This function ensures that the luminance remains in the range [0, 1].
 * @param amount The amount to decrease the luminance by
 */
void Image::darken(double amount) {
    for(unsigned int x = 0; x < this->width(); x++) {
        for(unsigned int y = 0; y < this->height(); y++) {
            HSLAPixel &p = this->getPixel(x, y);
            if(p.l < amount) {
                p.l = 0;
            }
            else {
                p.l = p.l - amount;
            }
        }
    }
}
/**
 * Desaturates an Image by decreasing the saturation of every pixel by 0.1.
 * This function ensures that the saturation remains in the range [0, 1].
 */
void Image::desaturate() {
    for(unsigned int x = 0; x < this->width(); x++) {
        for(unsigned int y = 0; y < this->height(); y++) {
            HSLAPixel &p = this->getPixel(x, y);
            if(p.s < 0.1) {
                p.s = 0;
            }
            else {
                p.s = p.s - 0.1;
            }
        }
    }
}

/**
 * Desaturates an Image by decreasing the saturation of every pixel by 0.1.
 * This function ensures that the saturation remains in the range [0, 1].
 * @param amount The desired decrease in saturation. 
 */

void Image::desaturate(double amount) {
    for(unsigned int x = 0; x < this->width(); x++) {
        for(unsigned int y = 0; y < this->height(); y++) {
            HSLAPixel &p = this->getPixel(x, y);
            if(p.s < amount) {
                p.s = 0;
            }
            else {
                p.s = p.s - amount;
            }
        }
    }
}
/**
 * Turns the image grayscale.
 */
void Image::grayscale() {
    for(unsigned int x = 0; x < this->width(); x++) {
        for (unsigned int y = 0; y < this->height(); y++) {
        HSLAPixel &p = this->getPixel(x, y);
        p.s = 0;
        }
    }
}

/**
 * Illinify the image.
 *
 * The hue of every pixel is set to the a hue value of either orange or
 * blue, based on if the pixel's hue value is closer to orange than blue.
 *
**/
void Image::illinify() {
  int illini_orange = 11;
  int illini_blue = 216;

  for(unsigned int i = 0; i < this->width(); i++) {
    for(unsigned int j = 0; j < this->height(); j++) {
      HSLAPixel &p = this->getPixel(i, j);
      if(p.h > illini_orange && p.h < illini_blue) {
            if(abs(illini_orange - p.h) > abs(illini_blue - p.h)) {
              p.h = illini_blue;
            }
            else {
              p.h = illini_orange;
            }
      }
      else if(p.h > illini_blue && p.h < 360) {
        if(p.h - illini_blue < 360 - p.h + illini_orange) {
          p.h = illini_blue;
        }
        else {
          p.h = illini_orange;
        }
      }
      else {
        p.h = illini_orange;
      }
    }
  }
}

/**
 * Lighten an Image by increasing the luminance of every pixel by 0.1.
 * This function ensures that the luminance remains in the range [0, 1].
 */
void Image::lighten() {
    for(unsigned int x = 0; x < this->width(); x++) {
        for(unsigned int y = 0; y < this->height(); y++) {
            HSLAPixel &p = this->getPixel(x, y);
            if(p.l > 0.9) {
                p.l = 1;
            }
            else {
                p.l = p.l + 0.1;
            }
        }
    }
}

/**
 * Lighten an Image by increasing the luminance of every pixel by amount.
 * This function ensures that the luminance remains in the range [0, 1].
 * @param amount The desired increase in luminance. 
 */

void Image::lighten(double amount) {
    for(unsigned int x = 0; x < this->width(); x++) {
        for(unsigned int y = 0; y < this->height(); y++) {
            HSLAPixel &p = this->getPixel(x, y);
            if(p.l + amount > 1) {
                p.l = 1;
            }
            else {
                p.l = p.l + amount;
            }
        }
    }
}

/**
 * Rotates the color wheel by degrees.
 * Rotating in a positive direction increases the degree of the hue. 
 * This function ensures that the hue remains in the range [0, 360].
 * @param degrees The desired amount of rotation
 */
void Image::rotateColor(double degrees) {
    for(unsigned int x = 0; x < this->width(); x++) {
        for(unsigned int y = 0; y < this->height(); y++) {
            HSLAPixel &p = this->getPixel(x, y);
            p.h += degrees;
            if(p.h > 360) {
                p.h -= 360;
            }
        }
    }
}

/**
 * Saturates an Image by increasing the saturation of every pixel by 0.1.
 * This function ensures that the saturation remains in the range [0, 1].
 */
void Image::saturate() {
    for(unsigned int x = 0; x < this->width(); x++) {
        for(unsigned int y = 0; y < this->height(); y++) {
            HSLAPixel &p = this->getPixel(x, y);
            if(p.s > 0.9) {
                p.s = 1;
            }
            else {
                p.s = p.s + 0.1;
            }
        }
    }
}

/**
 * Saturates an Image by increasing the saturation of every pixel by amount.
 * This function ensures that the saturation remains in the range [0, 1].
 */
void Image::saturate(double amount) {
    for(unsigned int x = 0; x < this->width(); x++) {
        for(unsigned int y = 0; y < this->height(); y++) {
            HSLAPixel &p = this->getPixel(x, y);
            if(p.s + amount > 1) {
                p.s = 1;
            }
            else {
                p.s = p.s + amount;
            }
        }
    }
}

/**
 * Scale the Image by a given factor.
 * @param factor Scale factor
 */
void Image::scale(double factor) {
    int newHeight = factor * this->height();
    int newWidth = factor * this->width();
    PNG *png = new PNG(*this);
    resize(newWidth, newHeight);
    for(unsigned int x = 0; x < this->width(); x++) {
        unsigned int x2 = x / factor;
        for(unsigned int y = 0; y < this->height(); y++) {
            unsigned int y2 = y / factor;
            HSLAPixel &p = this->getPixel(x, y);
            HSLAPixel &p2 = png->getPixel(x2, y2);
            p = p2;
        }
    }

}

/**
 * Scales the image to fit within the size (w x h).
 * @param w desired with of the scaled Image
 * @param h desired height of the scaled Image
 */
void Image::scale(unsigned w, unsigned h) {
    unsigned int height = this->height();
    unsigned int width = this->width();
    int size2 = h / height;
    int size1 = w / width;
    int factor;
    if(size2 > size1) {
        factor = size1;
    }
    else {
        factor = size2;
    }
    int newHeight = this->height() * factor;
    int newWidth = this->width() * factor;
    PNG *png = new PNG(*this);
    resize(newWidth, newHeight);
    for(unsigned int x = 0; x < this->width(); x++) {
        unsigned int x2 = x / factor;
        for(unsigned int y = 0; y < this->height(); y++) {
            unsigned int y2 = y / factor;
            HSLAPixel &p = this->getPixel(x, y);
            HSLAPixel &p2 = png->getPixel(x2, y2);
            p = p2;
        }
    }
}