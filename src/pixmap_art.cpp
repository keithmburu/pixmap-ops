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
   Image soup;
   soup.load("../images/soup.png");
   Image bricks;
   bricks.load("../images/bricks.png");
   Image abstract;
   abstract.load("../images/abstract.jpg");
   
   // Image roseSmall = rose.resize(200, 200);
   // Image art1 = earth.sharpen().colorJitter(30).distort().painterly();
   // art1.replace(roseSmall.sobel().bitmap(3), (earth.width() - roseSmall.width()) / 2, (earth.height() - roseSmall.height()) / 2);
   // art1.save("../art/art-1.png");

   // Image art2 = rose.blur().colorJitter(10).distort().sobel();
   // art2.save("../art/art-2.png");

   // Image art3 = bricks.glitch().gradient("vertical", {255, 255, 255}).gradient("horizontal", {255, 0, 0}).bitmap(10).sobel().distort();
   // art3.save("../art/art-3.png");

   Image art4 = abstract.swirl().sobel().invert();
   art4.save("../art/art-4.png");

   return 0;
}

