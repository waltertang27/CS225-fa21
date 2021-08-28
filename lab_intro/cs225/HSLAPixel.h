#include <iostream>

/**
 * @file HSLAPixel.h
 *
 * @author CS 225: Data Structures
 * @version 2018r1-lab1
 */

#pragma once

#include <iostream>
#include <sstream>

namespace cs225 {
    class HSLAPixel {
    public:
        double a;   //Alpha of the pixel, [0, 1].
        double h;   //Hue of the pixel, in degrees [0, 360)
        double l;   //Luminance of the pixel, [0, 1].
        double s;   //Saturation of the pixel, [0, 1].


        /**
         * Default constructor, completely opaque (alpha component of pixel is 1.0) and white
         */
        HSLAPixel() {
            a = 1;
            h = 0;
            l = 1;
            s = 0;
        }; 

        /*
         * Constructs an opaque HSLAPixel with the given hue, saturation, and luminance values
         *
         * @param hue Hue value for the new pixel, in degrees [0, 360)
         * @param saturation Saturation value for the new pixel, [0, 1]
         * @param luminance Luminance value for the new pixel,
        */
        HSLAPixel(double hue, double saturation, double luminance) {
            h = hue;
            s = saturation;
            l = luminance;
            a = 1;
        };

        /**
         * Constructs an HSLAPixel with the given hue, saturation, luminance, and alpha values
         *
         * @param hue Hue value for the new pixel, in degrees [0, 360)
         * @param saturation Saturation value for the new pixel, [0, 1]
         * @param luminance Luminance value for the new pixel, [0, 1]
         * @param alpha Alpha value for the new pixel, [0, 1]
         */
         HSLAPixel(double hue, double saturation, double luminance, double alpha) {
             h = hue;
             s = saturation;
             l = luminance;
             a = alpha;
         };


    };
}
