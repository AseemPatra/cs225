#include "Image.h"

#include <iostream>

int main() {
  Image alma;

  std::cout << "Using Image::lighten to create `lighten.png`..." << std::endl;
  alma.readFromFile("../alma.png");
  alma.lighten(0.2);
  alma.writeToFile("../lighten.png");

  std::cout << "Using Image::saturate to create `saturate.png`..." << std::endl;
  alma.readFromFile("../alma.png");
  alma.saturate(0.2);
  alma.writeToFile("../saturate.png");

  std::cout << "Using Image::scale to create `scale.png`..." << std::endl;
  alma.readFromFile("../alma.png");
  alma.scale(2);
  alma.writeToFile("../scale2x.png");

  //std::cout << "Using Image::illinify to create `illinify.png`..." << std::endl;
  //alma.readFromFile("../alma.png");
  //alma.illinify();
  //alma.writeToFile("../illinify.png");

  //std::cout << "Using Image::grayscale to create `grayscale.png`..." << std::endl;
  //alma.readFromFile("../alma.png");
  //alma.grayscale();
  //alma.writeToFile("../grayscale.png");

  std::cout << "Using Image::scale to create `scale200x.png`..." << std::endl;
  alma.readFromFile("../alma.png");
  alma.scale(180, 80);
  alma.writeToFile("../scale200x.png");

  return 0;
}
