#include "Image.h"
#include "StickerSheet.h"
#include <iostream>
#include <vector>

#include <cstdlib>
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

StickerSheet::StickerSheet(const Image &picture, unsigned max) {
    max_ = max;
    base = picture;
}

StickerSheet::~StickerSheet() {
    im.clear();
    coords.clear();
    max_ = 0;
}

StickerSheet::StickerSheet(const StickerSheet &other) {
    std::vector<Image*> newsy;
    std::vector<std::pair<int, int>> cords;
    max_ = other.max_;
    for (unsigned int index = 0; index < other.im.size(); index++) {
        newsy.push_back(other.im[index]);
        cords.push_back(other.coords[index]);
    }
    im.clear();
    coords.clear();
    im = newsy;
    coords = cords;
    base = other.base;
}

const StickerSheet& StickerSheet::operator=(const StickerSheet &other) {
    if (this == &other) {
        return *this;
    }
    std::vector<Image*> newsy;
    std::vector<std::pair<int, int>> cords;
    max_ = other.max_;
    for (unsigned int index = 0; index < other.im.size(); index++) {
        newsy.push_back(other.im[index]);
        cords.push_back(other.coords[index]);
    }
    im = newsy;
    coords = cords;
    base = other.base;
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
    if (index >= im.size() || index < 0 || im[index] == NULL) {
        return false;
    }
    if (x < 0 || x > base.width() || y < 0 || y > base.height()) {
        return false;
    }
    coords[index] = std::pair<int, int>(x, y);
    return true;
}

void StickerSheet::removeSticker(unsigned index) {
    if (index >= im.size()) {
        return;
    }
    im.erase(im.begin() + index);
    coords.erase(coords.begin() + index);
}

Image* StickerSheet::getSticker(unsigned index) {
    if (index < 0 || index >= im.size()) {
        return NULL;
    }
    return im[index];
}

Image StickerSheet::render() const {
    Image tot;
    tot.resize(base.width(), base.height());
    for (unsigned int index1 = 0; index1 < base.width(); index1++) {
        for (unsigned int index2 = 0; index2 < base.height(); index2++) {
            tot.getPixel(index1, index2) = base.getPixel(index1, index2);
        }
    }
    // Scale the base image to fit all the stickers
    for (unsigned int index = 0; index < im.size(); index++) {
        unsigned int imWidth = im[index]->width();
        if (imWidth + coords[index].first > tot.width()) {
            tot.resize(imWidth + coords[index].first, tot.height());
        }
        unsigned int imHeight = im[index]->height();
        if (imHeight + coords[index].second > tot.height()) {
            tot.resize(tot.width(), imHeight + coords[index].second);
        }
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