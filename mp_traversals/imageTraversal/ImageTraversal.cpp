#include <cmath>
#include <iterator>
#include <iostream>

#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 *
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );
}

/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator() {
  /** @todo [Part 1] */
  done = true;
}

ImageTraversal::Iterator::Iterator(PNG png, Point start, double tolerance, ImageTraversal *position) {
  this->png = png;
  this->start = start;
  this->tolerance = tolerance;
  this->position = position;
  done = false;
  iterate = position->peek();
   visited.resize(png.width());
  for(unsigned i = 0; i < png.width(); i++) {
    visited[i].resize(png.height());
    for(unsigned j = 0; j < png.height(); j++) {
      visited[i][j] = false;
    }
  }
  visited[start.x][start.y] = true;
  
}

/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
  //if(position->peek() == NULL) {
  //  return NULL;
  //}
  //Point temp = position->pop();
  //position->setVisited(temp);
  

  //std::cout<<"74";
  Point cur = position->pop();
  //position->setVisited(cur);
  visited[cur.x][cur.y] = true;
  
  Point w(cur.x, cur.y - 1);
  Point a(cur.x - 1, cur.y);
  Point s(cur.x, cur.y + 1);
  Point d(cur.x + 1, cur.y);
  HSLAPixel &pixel = png.getPixel(start.x, start.y);
  if(d.x < png.width() && d.y < png.height()) {
    HSLAPixel &p = png.getPixel(d.x, d.y);
    if(calculateDelta(pixel, p) < tolerance) {
      position->add(d);
      //std::cout<<"test d";
    }
  }
  if(s.x < png.width() && s.y < png.height()) {
    HSLAPixel &p = png.getPixel(s.x, s.y);
    if(calculateDelta(pixel, p) < tolerance) {
      position->add(s);
      //std::cout<<"test s";
    }
  }
  if(a.x < png.width() && a.y < png.height()) {
    HSLAPixel &p = png.getPixel(a.x, a.y);
    if(calculateDelta(pixel, p) < tolerance) {
      position->add(a);
      //std::cout<<"test a";
    }
  }
  if(w.x < png.width() && w.y < png.height()) {
    HSLAPixel &p = png.getPixel(w.x, w.y);
    if(calculateDelta(pixel, p) < tolerance) {
      position->add(w);
      //std::cout << "test w";
    }
  }

  if(position->empty()) {
    done = true;
    return *this;
  }
  
  //std::cout<<"116";
  while(position->empty() == false && visited[position->peek().x][position->peek().y]){
  //position->getVisited(position->peek())) {
    position->pop();
  }
  if(position->empty()) {
    done = true;
    return *this;
  }
  else {
    iterate = position->peek();
  }
  return *this;
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return iterate;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */
  if(done == other.done) {
    return false;
  }
  else {
    return true;
  }
}

