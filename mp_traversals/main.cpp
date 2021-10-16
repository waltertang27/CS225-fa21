
#include "cs225/PNG.h"
#include "FloodFilledImage.h"
#include "Animation.h"

#include "imageTraversal/DFS.h"
#include "imageTraversal/BFS.h"

#include "colorPicker/RainbowColorPicker.h"
#include "colorPicker/GradientColorPicker.h"
#include "colorPicker/GridColorPicker.h"
#include "colorPicker/SolidColorPicker.h"
#include "colorPicker/MyColorPicker.h"

using namespace cs225;

int main() {

  // @todo [Part 3]
  // - The code below assumes you have an Animation called `animation`
  // - The code provided below produces the `myFloodFill.png` file you must
  //   submit Part 3 of this assignment -- uncomment it when you're ready.
  //std::cout<<"first";
  PNG png;
  //std::cout<<"24";
  png.readFromFile("tests/lantern.png");
  //std::cout<<"bye";
  FloodFilledImage dog(png);
  //std::cout<<"hello";
  BFS bfs(png, Point(100, 100), 0.5);
  DFS dfs(png, Point(50, 50), 0.5);
  MyColorPicker color;




  dog.addFloodFill(bfs, color);
  dog.addFloodFill(dfs, color);
  
  Animation animation = dog.animate(2000000);

  PNG lastFrame = animation.getFrame(animation.frameCount() - 1 );
  lastFrame.writeToFile("myFloodFill.png");
  animation.write("myFloodFill.gif");
  




  return 0;
}
