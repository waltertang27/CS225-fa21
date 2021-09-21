/**
 * @file StickerSheet.h
 * Contains your declaration of the interface for the StickerSheet class.
 */
#pragma once

#include "Image.h"
using std::cout; 
using std::endl;

class StickerSheet {
    public: 
        StickerSheet(const Image &picture, unsigned max); 
        StickerSheet(const StickerSheet &other);
        ~StickerSheet();

        int addSticker(Image &sticker, unsigned x, unsigned y);
        void changeMaxStickers(unsigned max);
        Image *getSticker(unsigned index);
        void removeSticker(unsigned index);
        Image render() const;
        bool translate(unsigned index, unsigned x, unsigned y);
        void deleteSticker();
        void copy(const StickerSheet &other);

        const StickerSheet &operator= (const StickerSheet &other);
        
    private:
        Image **list;
        Image picture;
        unsigned layer, num;
        unsigned *x_coord;
        unsigned *y_coord;
        
};

 

