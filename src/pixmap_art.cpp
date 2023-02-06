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
   Image cat;
   cat.load("../images/cat.jpg");
   Image springPink;
   springPink.load("../images/spring-pink.jpg");
   Image lake;
   lake.load("../images/lake.jpg");
   Image forest;
   forest.load("../images/forest.png");
   Image space;
   space.load("../images/space.png");
   Image droplets;
   droplets.load("../images/droplets.png");
   Image pebbles;
   pebbles.load("../images/pebbles.png");
   
   // Image roseSmall = rose.resize(200, 200);
   // Image art1 = earth.sharpen().colorJitter(30).distort().painterly();
   // art1.replace(roseSmall.sobel().bitmap(3), (earth.width() - roseSmall.width()) / 2, (earth.height() - roseSmall.height()) / 2);
   // art1.save("../art/art-1.png");

   // Image art2 = rose.blur().colorJitter(10).distort().sobel();
   // art2.save("../art/art-2.png");

   // Image art3 = bricks.glitch().gradient("vertical", {255, 255, 255}).gradient("horizontal", {255, 0, 0}).bitmap(10).sobel().distort();
   // art3.save("../art/art-3.png");

   // Image art4 = abstract.swirl().sobel().invert();
   // art4.save("../art/art-4.png");

   // Image art5 = cat.sharpen().sobel().glow();
   // art5.save("../art/art-5.png");

   // Image art6 = springPink.gammaCorrect(0.8).swirl().gradient("vertical", {255, 255, 255});
   // art6.save("../art/art-6.png");

   // Image art7 = lake.painterly().sharpen().brighten(100);
   // art7.save("../art/art-7.png");

   Image art8 = forest.add(droplets).alphaBlend(space, 0.5).gammaCorrect(0.5);
   art8.save("../art/art-8.png");

   // Image art9 = pebbles.add(space).sobel().glow();
   // art9.save("../art/art-9.png");

   return 0;
}

