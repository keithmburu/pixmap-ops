/**
 * @file pixmap_art.cpp
 * @author Keith Mburu
 * @version 2023-02-02
 */

#include <iostream>
#include "image.h"
using namespace std;
using namespace agl;

int main(int argc, char** argv)
{ 
   Image art;
   if (!art.load("../images/earth.png")) {
      std::cout << "ERROR: Cannot load image! Exiting...\n";
      exit(0);
   }
   art = art.bitmap().distort().painterly();
   art.save("earth-art.png");

   return 0;
}

