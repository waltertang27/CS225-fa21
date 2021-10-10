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
 * Tests the bounds of the point and the PNG. 
 * 
 * @param p Point p to check x and y values of
 * @return true if within bounds of PNG
 * @return false if outside bounds of PNG
 */
bool ImageTraversal::Iterator::inBound(Point p) {
  if(p.x < png.width() && p.y < png.height()) {
    return true;
  }
  return false;
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
  std::cout<<"74";
  Point cur = position->pop();
  position->setVisited(cur);
  Point w(cur.x, cur.y - 1);
  Point a(cur.x - 1, cur.y);
  Point s(cur.x, cur.y + 1);
  Point d(cur.x + 1, cur.y);
  HSLAPixel &pixel = png.getPixel(start.x, start.y);
  if(inBound(d)) {
    HSLAPixel &p = png.getPixel(d.x, d.y);
    if(calculateDelta(pixel, p) < tolerance) {
      position->add(d);
      std::cout<<"test d";
    }
  }
  if(inBound(s)) {
    HSLAPixel &p = png.getPixel(s.x, s.y);
    if(calculateDelta(pixel, p) < tolerance) {
      position->add(s);
      std::cout<<"test s";
    }
  }
  if(inBound(a)) {
    HSLAPixel &p = png.getPixel(a.x, a.y);
    if(calculateDelta(pixel, p) < tolerance) {
      position->add(a);
      std::cout<<"test a";
    }
  }
  if(inBound(w)) {
    HSLAPixel &p = png.getPixel(w.x, w.y);
    if(calculateDelta(pixel, p) < tolerance) {
      position->add(w);
      std::cout << "test w";
    }
  }

  if(position->empty()) {
    done = true;
    return *this;
  }
  
  std::cout<<"116";
  while(position->empty() == false && position->getVisited(position->peek())) {
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

