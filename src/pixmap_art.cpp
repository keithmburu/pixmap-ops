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
   Image earth;
   earth.load("../images/earth.png");
   Image rose;
   rose.load("../images/rose.jpg");
   Image roseSmall = rose.resize(200, 200);

   Image art = earth.sharpen().colorJitter(10).distort().painterly();
   art.replace(roseSmall.sobel().bitmap(5), (earth.width() - roseSmall.width()) / 2, (earth.height() - roseSmall.height()) / 2);
   art.save("earth-art.png");

   return 0;
}

