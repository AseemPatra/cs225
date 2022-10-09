#include "Image.h"
#include "StickerSheet.h"
#include <iostream>

int main() {
  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //
  Image nintendo;  
  std::cout << "SIZE OF NINTENDO: " << sizeof(nintendo) << std::endl;
  nintendo.readFromFile("../nintendo_logo.png");
  std::cout << "Reached line " << __LINE__ << std::endl;   
  Image i;   
  std::cout << "SIZE OF I: " << sizeof(i) << std::endl;     
  i.readFromFile("../super_mario_logo.png");
  std::cout << "Reached line " << __LINE__ << std::endl;   
  Image j;        
  j.readFromFile("../legend_of_zelda_logo.png");
  std::cout << "Reached line " << __LINE__ << std::endl;   
  Image k;        
  k.readFromFile("../kid_icarus_logo.png");
  std::cout << "Reached line " << __LINE__ << std::endl;   

  StickerSheet sheet(nintendo, 5);
  sheet.addSticker(i, 50, 200);
  sheet.addSticker(j, 95, 400);
  sheet.addSticker(k, 725, 125);
  std::cout << "Reached line " << __LINE__ << std::endl;   
  Image render = sheet.render();
  render.writeToFile("../myImage.png");
  std::cout << "Reached line " << __LINE__ << std::endl;   
  return 0;
}
