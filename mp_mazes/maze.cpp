/* Your code here! */
#include "maze.h"
#include "dsets.h"
#include <vector>
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <cstdlib>
using namespace cs225;

//empty
SquareMaze::SquareMaze() {
    width = height = 0;
}

/*
This uses your representation of the maze to determine whether it is possible to travel in the given direction from the square at coordinates (x,y).

For example, after makeMaze(2,2), the possible input coordinates will be (0,0), (0,1), (1,0), and (1,1).

dir = 0 represents a rightward step (+1 to the x coordinate)
dir = 1 represents a downward step (+1 to the y coordinate)
dir = 2 represents a leftward step (-1 to the x coordinate)
dir = 3 represents an upward step (-1 to the y coordinate)
You can not step off of the maze or through a wall.

This function will be very helpful in solving the maze. It will also be used by the grading program to verify that your maze is a tree that occupies the whole grid, and to verify your maze solution. So make sure that this function works!
*/
bool SquareMaze::canTravel(int x, int y, int dir) const{
    if(dir < 0 || dir > 3) {
        return false;
    }
    if(dir == 0) {
        if(x > width) {
            return false;
        }
        return walls[x + width * y].first == 0;
    }
    if(dir == 1) {
        if(y > height) {
            return false;
        }
        return walls[x + width * y].second == 0;
    }
    if(dir == 2) {
        if(x < 1) {
            return false;
        }
        return walls[x - 1 + width * y].first == 0;
    }
    if(dir == 3) {
        if(y < 1) {
            return false;
        }
        return walls[x + width * (y - 1)].second == 0;
    }
    return false;
}

/*
Draws the maze without the solution.

First, create a new PNG. Set the dimensions of the PNG to (width*10+1,height*10+1). where height and width were the arguments to makeMaze. Blacken the entire topmost row and leftmost column of pixels, except the entrance (1,0) through (9,0). For each square in the maze, call its maze coordinates (x,y). If the right wall exists, then blacken the pixels with coordinates ((x+1)*10,y*10+k) for k from 0 to 10. If the bottom wall exists, then blacken the pixels with coordinates (x*10+k, (y+1)*10) for k from 0 to 10.

The resulting PNG will look like the sample image, except there will be no exit from the maze and the red line will be missing.
*/
PNG* SquareMaze::drawMaze() const {
    PNG *png = new PNG(width * 10 + 1, height * 10 + 1);
    for(int i = 0; i < width; i++) {
    
        for(int j = 0; j < height; j++) {
            //blacken left column
            if(j == 0) {
                for(int k = 0; k < 10; k++) {
                    if(i * 10 + k < 1 || i * 10 + k > 9) {
                        HSLAPixel &p2 = png->getPixel(i * 10 + k, 0);
                        p2.l = 0;
                    }
                }
            }
        //blacken top row
            if(i == 0) {
                for(int k = 0; k < 10; k++) {
                    HSLAPixel &p1 = png->getPixel(0, j * 10 + k);
                    p1.l = 0;
                }
            }
            if(!canTravel(i, j, 0)) {
                for(int k2 = 0; k2 <= 10; k2++) {
                    HSLAPixel &p3 = png->getPixel((i + 1) * 10, j * 10 + k2);
                }
            }
            if(!canTravel(i, j, 1)) {
                for(int k3 = 0; k3 <= 10; k3++) {
                    HSLAPixel &p4 = png->getPixel(i * 10 + k3, (j + 1) * 10);
                    p4.l = 0;
               }
            }

        }
    }
    return png;
}
/*
This function calls drawMaze, then solveMaze; it modifies the PNG from drawMaze to show the solution vector and the exit.

Start at pixel (5,5). Each direction in the solution vector corresponds to a trail of 11 red pixels in the given direction. If the first step is downward, color pixels (5,5) through (5,15) red. (Red is 0,1,0.5,1 in HSLA). Then if the second step is right, color pixels (5,15) through (15,15) red. Then if the third step is up, color pixels (15,15) through (15,5) red. Continue in this manner until you get to the end of the solution vector, so that your output looks analogous the above picture.

Make the exit by undoing the bottom wall of the destination square: call the destination maze coordinates (x,y), and whiten the pixels with coordinates (x*10+k, (y+1)*10) for k from 1 to 9.
*/
PNG* SquareMaze::drawMazeWithSolution() {
    PNG *png = drawMaze();
    std::vector<int> solvedPath = solveMaze();
    int px, py;
    px = py = 5;
    for(unsigned i = 0; i < solvedPath.size(); i++) {
        if(solvedPath[i] == 0) {
            //whiten
            for(unsigned j = 0; j < 10; j++) {
                HSLAPixel &p1 = png->getPixel(px, py);
                p1.h = 0;
                p1.s = 1;
                p1.l = 0.5;
                p1.a = 1;
                px++;
            }
        }
        if(solvedPath[i] == 1) {
            //whiten
            for(unsigned j = 0; j < 10; j++) {
                HSLAPixel &p2 = png->getPixel(px, py);
                p2.h = 0;
                p2.s = 1;
                p2.l = 0.5;
                p2.a = 1;
                py++;
            }
        }
        if(solvedPath[i] == 2) {
            //whiten
            for(unsigned j = 0; j < 10; j++) {
                HSLAPixel &p3 = png->getPixel(px, py);
                p3.h = 0;
                p3.s = 1;
                p3.l = 0.5;
                p3.a = 1;
                px--;
            }
        }
        if(solvedPath[i] == 3) {
            //whiten
            for(unsigned j = 0; j < 10; j++) {
                HSLAPixel &p4 = png->getPixel(px, py);
                p4.h = 0;
                p4.s = 1;
                p4.l = 0.5;
                p4.a = 1;
                py--;
            }
        }
    }
    
    HSLAPixel &p5 = png->getPixel(px, py);
                p5.h = 0;
                p5.s = 1;
                p5.l = 0.5;
                p5.a = 1;
                px = px - 4;
                py = py + 5;
    
    for(int i = 1; i <= 9; i++) {
        HSLAPixel &p = png->getPixel(px, py);
        p.l = 1;
        p.a = 1;
        px++;
    }
    return png;
}
/*
Makes a new SquareMaze of the given height and width.

If this object already represents a maze it will clear all the existing data before doing so. You will start with a square grid (like graph paper) with the specified height and width. You will select random walls to delete without creating a cycle, until there are no more walls that could be deleted without creating a cycle. Do not delete walls on the perimeter of the grid.

Hints: You only need to store 2 bits per square: the "down" and "right" walls. The finished maze is always a tree of corridors.)
*/
void SquareMaze::makeMaze(int width, int height) {
    this->width = width;
    this->height = height;
    int area = width * height;
    maze.addelements(area);
    for(int i = 0; i < area; i++) {
        walls.push_back(std::pair<bool, bool> (true, true));
    }
    int randX, randY;
    for(int j = 0; j < area - 1; j++) {
        randX = rand() % this->width;
        randY = rand() % this->height;

        if(rand() % 2 == 1) {
            if((randX < this->width - 1) && (walls[randX + this->width * randY].first == 1) && (maze.find(randX + this->width * randY) != maze.find(randX + this->width * randY + 1))) {
                walls[randX + this->width * randY].first = 0;
                maze.setunion(maze.find(randX + this->width * randY), maze.find(randX + this->width * randY + 1));
            }
        }
        else {
            if((randY < this->height - 1) && (walls[randX + this->width * randY].second == 1) && (maze.find(randX + this->width * randY) != maze.find(randX + this->width * (randY + 1)))) {
                walls[randX + this->width * randY].second = 0;
                maze.setunion(maze.find(randX + this->width * randY), maze.find(randX + this->width * (randY + 1)));
            }
        }
    }
    std::cout<<width<<std::endl;
    std::cout<<height<<std::endl;
    std::cout<<this->width<<std::endl;
    std::cout<<this->height<<std::endl;

}
/*Sets whether or not the specified wall exists.

This function should be fast (constant time). You can assume that in grading we will not make your maze a non-tree and then call one of the other member functions. setWall should not prevent cycles from occurring, but should simply set a wall to be present or not present. Our tests will call setWall to copy a specific maze into your implementation.
*/
void SquareMaze::setWall(int x, int y, int dir, bool exists) {
    if(dir != 0 || dir != 1) {
        return;
    }
    if(dir == 0) {
        walls[x + width * y].first = exists;
    }
    if(dir == 1) {
        walls[x + width * y].second = exists;
    }
}

std::vector<int> SquareMaze::solveMaze() {
    std::vector<int> solve;
    return solve;
}



