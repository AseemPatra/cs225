#include "Image.h"
#include "StickerSheet.h"
#include <iostream>
#include <vector>

#include <cstdlib>
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

StickerSheet::StickerSheet(const Image &picture, unsigned max) {
    //Create image ptr array
    //std::vector<Image*> newsy;
    //std::vector<std::pair<int, int>> cords;
    //Make deep copy of picture
    max_ = max;
    //Image tmp;
    //tmp.resize(picture.width(), picture.height());
    //for (unsigned int index1 = 0; index1 < picture.width(); index1++) {
        //for (unsigned int index2 = 0; index2 < picture.height(); index2++) {
            //tmp.getPixel(index1, index2) = picture.getPixel(index1, index2);
        //}
    //}
    base = new Image(picture);
    //Image* ptr = &tmp;
    //Store picture as first image in array
    //newsy.push_back(ptr);
    //cords.push_back(std::pair<int, int>(0, 0));
    //Set array to private variable, also set initial coordinates
    //coords = cords;
}
StickerSheet::~StickerSheet() {
    //if (im.size() != 0) {
      //  for (unsigned int index = 0; index < im.size(); index++) {
        //    delete im[index];
        //}
    //}
    im.clear();
    coords.clear();
    delete base;
    max_ = 0;
}
StickerSheet::StickerSheet(const StickerSheet &other) {
    std::vector<Image*> newsy;
    std::vector<std::pair<int, int>> cords;
    max_ = other.max_;
    for (unsigned int index = 0; index < other.im.size(); index++) {
        Image* tmp = new Image(*other.im[index]);
        newsy.push_back(tmp);
        cords.push_back(other.coords[index]);
    }
    im = newsy;
    coords = cords;
    Image* tmpBase = new Image(*other.base);
    base = tmpBase;
}


const StickerSheet& StickerSheet::operator=(const StickerSheet &other) {
    if (this == &other) {
        return *this;
    }
    std::vector<Image*> newsy;
    std::vector<std::pair<int, int>> cords;
    max_ = other.max_;
    for (unsigned int index = 0; index < other.im.size(); index++) {
        Image* tmp = new Image(*other.im[index]);
        newsy.push_back(tmp);
        cords.push_back(other.coords[index]);
    }
    im = newsy;
    coords = cords;
    Image* tmpBase = new Image(*other.base);
    base = tmpBase;
    return *this;
}
void StickerSheet::changeMaxStickers(unsigned max) {
    if (max > max_) {
        max_ = max;
        return;
    }
    
    if (im.size() > max ) {
        std::vector<Image*> tmp;
        for (unsigned int index = 0; index < max; index++) {
            tmp.push_back(im[index]);
        }
        //for (unsigned int index = max; index < im.size(); index++) {
          //  delete im[index];
        //}
        im.clear();
        im = tmp;
    }
    max_ = max;
}
int StickerSheet::addSticker(Image &sticker, unsigned x, unsigned y) {
    if (max_ < im.size() + 1) {
        return -1;
    }
    Image* ptr = &sticker;
    im.push_back(ptr);
    coords.push_back(std::pair<int, int>(x, y));
    return im.size();
}
bool StickerSheet::translate(unsigned index, unsigned x, unsigned y) {
    if (index > max_ - 1) {
        return false;
    }
    coords[index].first = x;
    coords[index].second = y;
    return true;
}
void StickerSheet::removeSticker(unsigned index) {
    std::vector<Image*> tmp;
    for (unsigned int num = 0; num < im.size(); num++) {
        if (num == index) {
            continue;
        }
        tmp.push_back(im[index]);
    }
    im = tmp;
}
Image* StickerSheet::getSticker(unsigned index) {
    if (index > max_ - 1) {
        return NULL;
    }
    return im[index];
}
Image StickerSheet::render() const {
    Image tot;
    tot.resize(base->width(), base->height());
    for (unsigned int index1 = 0; index1 < base->width(); index1++) {
        for (unsigned int index2 = 0; index2 < base->height(); index2++) {
            tot.getPixel(index1, index2) = base->getPixel(index1, index2);
        }
    }
    // Scale the base image to fit all the stickers
    for (unsigned int index = 0; index < im.size(); index++) {
        std::cout << "Made it to index " << index << std::endl;
        std::cout << "MAX: " << max_ << std::endl;
        unsigned int imWidth = im[index]->width();
        if (imWidth + coords[index].first > tot.width()) {
            tot.scale(imWidth + coords[index].first, tot.height());
        }
        unsigned int imHeight = im[index]->height();
        if (imHeight + coords[index].second > tot.height()) {
            tot.scale(tot.width(), imHeight + coords[index].second);
        }
        std::cout << "Reached line " << __LINE__ << std::endl;
        //Stick the stickers on the image after scaling for it
        for (unsigned int index1 = 0; index1 < imWidth; index1++) {
            for (unsigned int index2 = 0; index2 < imHeight; index2++) {
                if (im[index]->getPixel(index1, index2).a != 0) {
                    cs225::HSLAPixel& add = tot.getPixel(index1 + coords[index].first, index2 + coords[index].second);
                    add = im[index]->getPixel(index1, index2);
                }
            }
        }
    }
    return tot;
}