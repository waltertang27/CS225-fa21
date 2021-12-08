#include "Image.h"
#include "StickerSheet.h"

int main() {

  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //
  Image alma;
  Image p1, p2, p3, out;
  alma.readFromFile("alma.png");
  p1.readFromFile("1.png");
  p2.readFromFile("2.png");
  p3.readFromFile("3.png");
  StickerSheet background(alma, 5);
  background.addSticker(p1, 100, 100);
  background.addSticker(p1, 300, 300);
  background.addSticker(p2, 150, 200);
  background.addSticker(p3, 200, 257);
  out = background.render();
  out.writeToFile("output.png");


  return 0;
}
