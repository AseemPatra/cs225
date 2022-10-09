#include <cmath>
#include <iterator>
#include <iostream>

#include "cs225/HSLAPixel.h"
#include "cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

using namespace cs225;
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
  ender = true;
  //im_->curr_ = Point(-11, -11);
}

ImageTraversal::Iterator::Iterator(ImageTraversal* im, Point star, PNG & png, double tolerance) {
  /** @todo [Part 1] */
  //std::cout << "CONSTRUCT: " << png.width() << std::endl;
  im_ = im;
  curr_ = star;
  pn = png;
  tolerance_ = tolerance;
  start_ = star;
  ender = false;
}
/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
  if (ender) {return *this;}
  Point cor = im_->pop();
  im_->vis_.push_back(cor);

  //RIGHT
  Point right(cor.x + 1, cor.y);
  if (cor.x + 1 < pn.width()) {
    bool check = true;
    for (int index = 0; index < (int) im_->vis_.size(); index++) {
      if (im_->vis_[index].x == right.x && im_->vis_[index].y == right.y) {
        //std::cout << "-VISITED RIGHT: " << right << std::endl;
        check = false;
        break;
      }
    }
    if (check) {
      double tol = calculateDelta(pn.getPixel(start_.x, start_.y), pn.getPixel(right.x, right.y));
      if (tol <= tolerance_) {
        //std::cout << "      ADD RIGHT: " << right << std::endl;
        im_->add(right);
      }
    }
  }

  //BELOW
  Point below(cor.x, cor.y + 1);
  if (below.y < pn.height()) {
    bool check = true;
    for (int index = 0; index < (int) im_->vis_.size(); index++) {
      if (im_->vis_[index].x == below.x && im_->vis_[index].y == below.y) {
        //std::cout << "-VISITED BELOW" << below << std::endl;
        check = false;
        break;
      }
    }
    if (check) {
      double tol = calculateDelta(pn.getPixel(start_.x, start_.y), pn.getPixel(below.x, below.y));
      if (tol <= tolerance_) {
        //std::cout << "      ADD BELOW: " << below << std::endl;
        im_->add(below);
      }
    }
  }

  //LEFT
if (cor.x != 0) {
    Point left(cor.x - 1, cor.y);
  if (left.x >= 0) {
    bool check = true;
    for (int index = 0; index < (int) im_->vis_.size(); index++) {
      if (im_->vis_[index].x == left.x && im_->vis_[index].y == left.y) {
        //std::cout << "-VISITED LEFT" << left << std::endl;
        check = false;
        break;
      }
    }
    if (check) {
      double tol = calculateDelta(pn.getPixel(start_.x, start_.y), pn.getPixel(left.x, left.y));
      if (tol <= tolerance_) {
        //std::cout << "      ADD LEFT: " << left << std::endl;
        im_->add(left);
      }
    }
  }
}
  

  //UP
if (cor.y != 0) {
  Point up(cor.x, cor.y - 1);
  if (up.y >= 0) {
    bool check = true;
    for (int index = 0; index < (int) im_->vis_.size(); index++) {
      if (im_->vis_[index].x == up.x && im_->vis_[index].y == up.y) {
        //std::cout << "-VISITED UP" << up << std::endl;
        check = false;
        break;
      }
    }
    if (check) {
      double tol = calculateDelta(pn.getPixel(start_.x, start_.y), pn.getPixel(up.x, up.y));
      if (tol <= tolerance_) {
        //std::cout << "      ADD UP: " << up << std::endl;
        im_->add(up);
      }
    }
  }
}
  
  curr_ = im_->peek();
  while (im_->empty() == false) {
    bool chalk = false;
    for (int index = 0; index < (int) im_->vis_.size(); index++) {
      if (im_->vis_[index].x == curr_.x && im_->vis_[index].y == curr_.y) {
        chalk = true;
        break;
      }
    }
    if (chalk == true) {
      Point tmp = im_->pop();
      curr_ = im_->peek();
      continue;
    } else {
      break;
    }
  }
  if (im_->empty()) {ender = true;}
  //std::cout << "peek: " << curr_ << std::endl;
  return *this;
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return im_->peek();
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */
  if (ender != other.ender) {return true;}
  return false;
}

