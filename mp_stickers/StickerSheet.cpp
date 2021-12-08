 
#include "StickerSheet.h"
 
/**
* Initializes this StickerSheet with a deep copy of the base picture and the ability to hold a max number of stickers (Images) with indices 0 through max - 1.
* @param picture The base picture to use in the StickerSheet
* @param max The maximum number of stickers (Images) on this StickerSheet
*/
StickerSheet::StickerSheet(const Image &picture, unsigned max) {
  pic = picture;
  list = new Image*[max];
  num = max;
  //Image *img = new Image();
  //*img = picture;
  x_coord = new unsigned[max];
  y_coord = new unsigned[max];
  //index = new int[max];
  layer = 0;
  for(unsigned i = 0; i < max; i++) {
       list[i] = NULL;
       //index[i] = i;
 
  }
 
}
 
/**
* Frees all space that was dynamically allocated by this StickerSheet.
*/
StickerSheet::~StickerSheet() {
  deleteSticker();
}
 
/**
* The copy constructor makes this StickerSheet an independent copy of the source.
* @param other The other StickerSheet object to copy data from
*/
StickerSheet::StickerSheet(const StickerSheet &other) {
   copy(other);
 
 
}
/**
* Adds a sticker to the StickerSheet, so that the top-left of the sticker's Image is at (x, y) on the StickerSheet.
* The sticker must be added to the lowest possible layer available.
* @param sticker The Image of the sticker
* @param x the x location of the sticker on the StickerSheet
* @param y the y location of the sticker on the StickerSheet
* @return The zero-based layer index the sticker was added to, or -1 if the sticker cannot be added
*/
int StickerSheet::addSticker(Image &sticker, unsigned x, unsigned y) {
    
   if(layer < num) {
     if(list[layer] == NULL) {
       list[layer] = new Image();
     }
     *(list[layer]) = sticker;
     y_coord[layer] = y;
     x_coord[layer]= x;
     layer++;
     return (layer - 1);
   }
   return -1;
   
}
 
/**
* Modifies the maximum number of stickers that can be stored on this StickerSheet without changing existing stickers' indices.
* If the new maximum number of stickers is smaller than the current number number of stickers, the stickers with indices above max - 1 will be lost.
* @param max The new value for the maximum number of Images in the StickerSheet
*/
void StickerSheet::changeMaxStickers(unsigned max) {
  if(max == num) {
    return;
  }
  Image **list2 = new Image*[max];
  
  unsigned *x_coord2 = new unsigned[max];
  unsigned *y_coord2 = new unsigned[max];

  for(unsigned i = 0; i < max; i++) {
    list2[i] = NULL;

  }
  if(layer < max) {
    for(unsigned i = 0; i < layer; i++) {
      list2[i] = new Image();
      *list2[i] = *list[i];
      x_coord2[i] = x_coord[i];
      y_coord2[i] = y_coord[i];
    }
  }
  else {
    for(unsigned i = 0; i < max; i++) {
      list2[i] = new Image();
      *list2[i] = *list[i];
      x_coord2[i] = x_coord[i];
      y_coord2[i] = y_coord[i];
    }
    layer = max;
  }
  deleteSticker();
  list = list2;
  list2 = NULL;
  y_coord = y_coord2;
  y_coord2 = NULL;
  x_coord = x_coord2;
  x_coord2 = NULL;
  num = max;



 /*
  //for(unsigned int i = 0; )
  
  for(unsigned i = 0; i < max; i++) {
    list2[i] = NULL;
  }
  if(max > layer) {
   
    for(unsigned i = 0; i < layer; i++) {
      
      list2[i] = new Image();
   
      *list2[i] = *list[i];
      x_coord2[i] = x_coord[i];
      y_coord2[i] = y_coord[i];
    }
  }
  else {
     for(unsigned i = 0; i < max; i++) {
    
       list2[i] = new Image();
       *list2[i] = *list[i];
   
       x_coord2[i] = x_coord[i];
       y_coord2[i] = y_coord[i];
     }
     layer = max;
  }

  deleteSticker();
 
  num = max;
  list = list2;
  //delete[] list2;
  list2 = NULL;

  x_coord = x_coord2;
  //delete[] x_coord2;
  x_coord2 = NULL;
  y_coord = y_coord2;
  //delete[] y_coord2;
  y_coord2 = NULL;
  */
}
 
/**
* Returns a pointer to the sticker at the specified index, not a copy of it.
* That way, the user can modify the Image.
* If the index is invalid, return NULL.
* @param index The layer in which to get the sticker
* @return A pointer to a specific Image in the StickerSheet
*/
Image *StickerSheet::getSticker(unsigned index) {
   if(index >= layer) {
       return NULL;
   }
   else {
     return list[index];
   }
}
/**
* The assignment operator for the StickerSheet class.
* @param other The other StickerSheet object to copy data from
* @return a constant StickerSheet reference
*/
const StickerSheet &StickerSheet::operator= (const StickerSheet &other) {
  deleteSticker();
  copy(other);
  return *this;
}
/**
* Removes the sticker at the given zero-based layer index.
* @param index The layer in which to delete the png
*/
void StickerSheet::removeSticker(unsigned index) {
  //delete list[index];
  if(layer > index) {
    for(unsigned i = index; i < layer - 1; i++) {
      *list[i] = *list[i + 1];
      x_coord[i] = x_coord[i + 1];
      y_coord[i] = y_coord[i + 1];
    }
    delete list[layer - 1];
    list[layer - 1] = NULL;
    layer--;

  }
}
 
/**
* Renders the whole StickerSheet on one Image and returns that Image.
* The base picture is drawn first and then each sticker is drawn in order starting with layer zero (0), then layer one (1), and so on.
* If a pixel's alpha channel in a sticker is zero (0), no pixel is drawn for that sticker at that pixel. If the alpha channel is non-zero, a pixel is drawn. (Alpha blending is awesome, but not required.)
* The returned Image always includes the full contents of the picture and all stickers. This means that the size of the result image may be larger than the base picture if some stickers go beyond the edge of the picture.
* @return an Image object representing the drawn scene
*/
Image StickerSheet::render() const {
  /*
  Image base;
  int width, height;
  for(unsigned i = 0; i < layer; i++) {
    width = max(pic.width(), x_coord[i] + list[i]->width());
    height = max(pic.height(), y_coord[i] + list[i]->height());
    
  }
  base = pic;
  base.resize(width, height);
  for(unsigned i = 0; i < layer; i++) {
    for(unsigned x = x_coord[i]; x < x_coord[i] + list[i]->width(); x++) {
      for(unsigned y = y_coord[i]; y < y_coord[i] + list[i]->height(); y++) {
        HSLAPixel &p1 = base.getPixel(x, y);
        HSLAPixel &p2 = list[i]->getPixel(x - x_coord[i], y - y_coord[i]);
        if(p2.a != 0.0) {
          p1 = p2;
        }
      }
    }
  }
  return base;
  */
 
 unsigned width2 = pic.width();
 unsigned height2 = pic.height();
 for(unsigned i = 0; i < layer; i++) {
   if(list[i] != NULL) {
     if(list[i]->width() + x_coord[i] > width2) {
       width2 = list[i]->width() + x_coord[i];
     }
     if(list[i]->height() + y_coord[i] > height2) {
       height2 = list[i]->height() + y_coord[i];
     }
   }
 }
 Image im;
 im = pic;
 im.resize(width2, height2);
 for(unsigned i = 0; i < layer; i++) {
   if(list[i] != NULL) {
      for(unsigned a = x_coord[i]; a < list[i]->width() + x_coord[i]; a++) {
        for(unsigned b = y_coord[i]; b < list[i]->height() + y_coord[i]; b++) {
          if(list[i]->getPixel((a - x_coord[i]), (b - y_coord[i])).a != 0) {
            im.getPixel(a, b) = list[i]->getPixel((a - x_coord[i]), (b - y_coord[i]));

          }
        }
      }
   }
 }
  return im;
}
 
/**
* Changes the x and y coordinates of the Image in the specified layer.
* If the layer is invalid or does not contain a sticker, this function must return false. Otherwise, this function returns true.
* @param index Zero-based layer index of the sticker
* @param x The new x location of the sticker on the StickerSheet
* @param y The new y location of the sticker on the StickerSheet
* @return true if the translate was successful; otherwise false
*/
bool StickerSheet::translate(unsigned index, unsigned x, unsigned y) {
   if(index >= layer) {
       return false;
   }
   else {
       x_coord[index] = x;
       y_coord[index] = y;
       return true;
   }
}
 
void StickerSheet::deleteSticker() {
 
   for(unsigned i = 0; i < num; i++) {
         delete list[i];
         list[i] = NULL;
   }
   delete[] list;
   list = NULL;
   delete[] x_coord;
   x_coord = NULL;
   delete[] y_coord;
   y_coord = NULL;

}
 
//copy
void StickerSheet::copy(const StickerSheet &other) {
  num = other.num;
  pic = other.pic;
  x_coord = new unsigned[num];
  y_coord = new unsigned[num];
  layer = other.layer;
  list = new Image*[num];
  for(unsigned i = 0; i < num; i++) {
    list[i] = NULL;
  }
  for(unsigned i = 0; i < layer; i++) {
    list[i] = new Image();
    *list[i] = *other.list[i];
    x_coord[i] = other.x_coord[i];
    y_coord[i] = other.y_coord[i];
  }
  
}
 

