/**
 * @file pixmap_art.cpp
 * @author Keith Mburu
 * @version 2023-02-09
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

   Image art1 = earth.deepFry().distort("horizontal").painterly();
   art1.replace(roseSmall.sobel().sharpen().glow(), (earth.width() - roseSmall.width()) / 2, (earth.height() - roseSmall.height()) / 2);
   art1.save("../art/art-1.png");

   Image art2 = rose.gammaCorrect(0.8).colorJitter(100).distort("vertical").sobel();
   art2.save("../art/art-2.png");

   Image bricks;
   bricks.load("../images/bricks.png");

   Image art3 = bricks.glitch().bitmap(10).distort("horizontal").distort("vertical").resize(400, 400);
   art3.save("../art/art-3.png");

   Image abstract;
   abstract.load("../images/abstract.jpg");

   Image art4 = abstract.swirl().sobel().invert();
   art4.save("../art/art-4.png");

   Image cat;
   cat.load("../images/cat.jpg");

   Image art5 = cat.resize(756, 1008).sharpen().sobel().glow();
   art5.save("../art/art-5.png");

   Image springPink;
   springPink.load("../images/spring-pink.jpg");

   Image art6 = springPink.resize(756, 1008).swirl().painterly();
   art6.save("../art/art-6.png");

   Image lake;
   lake.load("../images/lake.jpg");

   Image art7 = lake.painterly().sharpen().brighten(30);
   art7.save("../art/art-7.png");

   Image forest;
   forest.load("../images/forest.png");
   Image droplets;
   droplets.load("../images/droplets.png");
   Image sunset;
   sunset.load("../images/sunset.jpg");

   Image art8 = forest.add(droplets).deepFry().alphaBlend(sunset.resize(360, 678), 0.25);
   art8.save("../art/art-8.png");

   Image pebbles;
   pebbles.load("../images/pebbles.png");
   Image space;
   space.load("../images/space.png");

   Image art9 = pebbles.add(space).sobel().glow();
   art9.save("../art/art-9.png");

   Image art10 = earth.glitch().fill({255, 255, 255}, {255, 128, 64}).invert().sobel();
   art10.save("../art/art-10.png");

   return 0;
}

