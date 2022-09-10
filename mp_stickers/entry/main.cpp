#include "Image.h"
#include "StickerSheet.h"
#include <iostream>

int main() {
  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //
  Image alma;     
  alma.readFromFile("../tests/alma.png");
  Image i;        
  i.readFromFile("../tests/i.png");

  StickerSheet sheet(alma, 5);
  sheet.addSticker(i, 20, 200);
  sheet.addSticker(i, 40, 200);
  sheet.addSticker(i, 60, 200);
  sheet.changeMaxStickers(1);
  Image rend = sheet.render();
  rend.writeToFile("../rage.png");

  return 0;
}
