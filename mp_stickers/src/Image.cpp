#include <Image.h>
#include <iostream>
#include <cstdlib>
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

void Image::lighten() {
    for (unsigned int index1 = 0; index1 < height(); index1++) {
        for (unsigned int index2 = 0; index2 < width(); index2++) {
            cs225::HSLAPixel pixel = getPixel(index2, index1);
            if (pixel.l + 0.1 > 1) {
                getPixel(index2, index1).l = 1;
                continue;
            } else if (pixel.l + 0.1 < 0) {
                getPixel(index2, index1).l = 0;
                continue;
            }
            getPixel(index2, index1).l = pixel.l + 0.1;
        }
    }
}
void Image::lighten(double amount) {
    for (unsigned int index1 = 0; index1 < height(); index1++) {
        for (unsigned int index2 = 0; index2 < width(); index2++) {
            cs225::HSLAPixel pixel = getPixel(index2, index1);
            if (pixel.l + amount > 1) {
                getPixel(index2, index1).l = 1;
                continue;
            } else if (pixel.l + amount < 0) {
                getPixel(index2, index1).l = 0;
                continue;
            }
            getPixel(index2, index1).l = pixel.l + amount;
        }
    }
}
void Image::darken() {
    for (unsigned int index1 = 0; index1 < height(); index1++) {
        for (unsigned int index2 = 0; index2 < width(); index2++) {
            cs225::HSLAPixel pixel = getPixel(index2, index1);
            if (pixel.l - 0.1 < 0) {
                getPixel(index2, index1).l = 0;
                continue;
            } else if (pixel.l - 0.1 > 1) {
                getPixel(index2, index1).l = 1;
                continue;
            }
            getPixel(index2, index1).l = pixel.l - 0.1;
        }
    }
}
void Image::darken(double amount) {
    for (unsigned int index1 = 0; index1 < height(); index1++) {
        for (unsigned int index2 = 0; index2 < width(); index2++) {
            cs225::HSLAPixel pixel = getPixel(index2, index1);
            if (pixel.l - amount < 0) {
                getPixel(index2, index1).l = 0;
                continue;
            } else if (pixel.l - amount > 1) {
                getPixel(index2, index1).l = 1;
                continue;
            }
            getPixel(index2, index1).l = pixel.l - amount;
        }
    }
}
void Image::saturate() {
    for (unsigned int index1 = 0; index1 < height(); index1++) {
        for (unsigned int index2 = 0; index2 < width(); index2++) {
            cs225::HSLAPixel pixel = getPixel(index2, index1);
            if (pixel.s + 0.1 > 1) {
                getPixel(index2, index1).s = 1;
                continue;
            } else if (pixel.s + 0.1 < 0) {
                getPixel(index2, index1).s = 0;
                continue;
            }
            getPixel(index2, index1).s = pixel.s + 0.1;
        }
    }
}
void Image::saturate(double amount) {
    for (unsigned int index1 = 0; index1 < height(); index1++) {
        for (unsigned int index2 = 0; index2 < width(); index2++) {
            cs225::HSLAPixel pixel = getPixel(index2, index1);
            if (pixel.s + amount > 1) {
                getPixel(index2, index1).s = 1;
                continue;
            } else if (pixel.s + amount < 0) {
                getPixel(index2, index1).s = 0;
                continue;
            }
            getPixel(index2, index1).s = pixel.s + amount;
        }
    }
}
void Image::desaturate() {
    for (unsigned int index1 = 0; index1 < height(); index1++) {
        for (unsigned int index2 = 0; index2 < width(); index2++) {
            cs225::HSLAPixel pixel = getPixel(index2, index1);
            if (pixel.s - 0.1 > 1) {
                getPixel(index2, index1).s = 1;
                continue;
            } else if (pixel.s - 0.1 < 0) {
                getPixel(index2, index1).s = 0;
                continue;
            }
            getPixel(index2, index1).s = pixel.s - 0.1;
        }
    }
}
void Image::desaturate(double amount) {
    for (unsigned int index1 = 0; index1 < height(); index1++) {
        for (unsigned int index2 = 0; index2 < width(); index2++) {
            cs225::HSLAPixel pixel = getPixel(index2, index1);
            if (pixel.s - amount > 1) {
                getPixel(index2, index1).s = 1;
                continue;
            } else if (pixel.s - amount < 0) {
                getPixel(index2, index1).s = 0;
                continue;
            }
            getPixel(index2, index1).s = pixel.s - amount;
        }
    }
}
void Image::grayscale() {
    for (unsigned int index1 = 0; index1 < height(); index1++) {
        for (unsigned int index2 = 0; index2 < width(); index2++) {
            //cs225::HSLAPixel pixel = getPixel(index2, index1);
            //pixel.s = 0;
            getPixel(index2, index1).s = 0;
        }
    }
}
void Image::rotateColor(double debrees) {
    for (unsigned int index1 = 0; index1 < height(); index1++) {
        for (unsigned int index2 = 0; index2 < width(); index2++) {
            getPixel(index2, index1).h += debrees;
            if (getPixel(index2, index1).h > 360) {
                getPixel(index2, index1).h = getPixel(index2, index1).h - 360;
            }
            if (getPixel(index2, index1).h < 0) {
                getPixel(index2, index1).h = 360 - std::abs(getPixel(index2, index1).h);
            }
        }
    }
}
void Image::illinify() {
    for (unsigned int index1 = 0; index1 < height(); index1++) {
        for (unsigned int index2 = 0; index2 < width(); index2++) {
            cs225::HSLAPixel pixel = getPixel(index2, index1);
            unsigned int color = pixel.h;
            int diff1 = color - 11; //Orange
            int diff2 = 216 - color; //Blue
            diff1 = std::abs(diff1);
            diff2 = std::abs(diff2);
            if (diff1 < diff2) {
                getPixel(index2, index1).h = 11;
                continue;
            }
            if (diff1 > diff2) {
                getPixel(index2, index1).h= 216;
            }
        }
    }
}
void Image::scale(double factor) {
    if (factor == 1) {
        return;
    }
    // Store original height and width
    unsigned int originalHeight = height();
    unsigned int originalWidth = width();
    // Create a temporary image to hold original pixels of image
    Image* tmp = new Image();
    *tmp = *this;
    // Resize image via the given factor
    resize(factor*width(), factor*height());
    //Set pixels of current image to pixels of the original based on what pixels are found based on the scale factor
    //factor = 2, widthIndex = 0, 0, 1, 1, 2, 2, 3, 3 for the first 8 widths, same with height (ints round down)
    //factor = 0.5, widthIndex = 0, 2, 4, 6, 8, 10, 12, 14, 16 for the first 8 widths
    for (unsigned int index1 = 0; index1 < factor*originalHeight; index1++) {
        for (unsigned int index2 = 0; index2 < factor*originalWidth; index2++) {
            getPixel(index2, index1) = tmp->getPixel(index2/factor, index1/factor);
        }
    }
    delete tmp;
}
void Image::scale(unsigned w, unsigned h) {
    double factor;
    double check1 = w / width();
    double check2 = h / height();
    if (check1 >= check2) {
        factor = check2;
    } else {
        factor = check1;
    }
    if (factor == 1) {
        return;
    }
    unsigned int originalHeight = height();
    unsigned int originalWidth = width();
    std::cout << "OG W: " << originalWidth << std::endl;
    std::cout << "OG H: " << originalHeight << std::endl;
    Image* tmp = new Image();
    *tmp = *this;
    resize(factor*width(), factor*height());
    for (unsigned int index1 = 0; index1 < factor*originalHeight; index1++) {
        for (unsigned int index2 = 0; index2 < factor*originalWidth; index2++) {
            getPixel(index2, index1) = tmp->getPixel(index2/factor, index1/factor);
        }
    }
    delete tmp;
}