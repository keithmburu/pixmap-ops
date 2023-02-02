/**
 * @file pixmap_test.cpp
 * @author Keith Mburu
 * @author Aline Normoyle
 * @version 2023-02-02
 */

#include <iostream>
#include "image.h"
using namespace std;
using namespace agl;

int main(int argc, char** argv)
{
   Image image;
   if (!image.load("../images/feep.png")) {
      std::cout << "ERROR: Cannot load image! Exiting...\n";
      exit(0);
   }

   std::cout << "feep toString: \n" << image << std::endl;

   for (int i = 0; i < image.height(); i++) {
      for (int j = 0; j < image.width(); j++) {
         Pixel c = image.get(i, j);
         std::cout << "(" << (int)c.r << "," << (int)c.g << "," << (int)c.b << ") ";
      }
      std::cout << std::endl;
   }
   image.save("feep-test-save.png"); // should match original

   // test: copy constructor
   Image copy = image; 
   copy.save("feep-test-copy.png"); // should match original and load into gimp

   // test: assignment operator
   copy = image; 
   copy.save("feep-test-assignment.png"); // should match original and load into gimp

   // should print r,g,b
   Pixel pixel = image.get(1, 1);
   cout << (int) pixel.r << " " << (int) pixel.g << " " << (int) pixel.b << endl;

   // test: setting a color
   pixel.r = 255;
   image.set(1, 1, pixel);
   image.save("feep-test-newcolor.png");

   // test a non-trivial image
   if (!image.load("../images/earth.png")) {
      std::cout << "ERROR: Cannot load image! Exiting...\n";
      exit(0);
   }

   std::cout << "earth toString: \n" << image << std::endl;

   // resize
   Image resize = image.resize(200,300);
   resize.save("earth-200-300.png");

   // grayscale
   Image grayscale = image.grayscale(); 
   grayscale.save("earth-grayscale.png");

   // flip horizontal
   Image flip = image.flipHorizontal(); 
   flip.save("earth-flip.png"); 
   
   // flip vertical
   Image vflip = image.flipVertical(); 
   vflip.save("earth-vflip.png");

   // sub image
   Image sub = image.subimage(200, 200, 100, 100); 
   sub.save("earth-subimage.png"); 

   // gamma correction
   Image gamma1 = image.gammaCorrect(0.6f); 
   gamma1.save("earth-gamma-0.6.png"); 

   Image gamma2 = image.gammaCorrect(2.2f);
   gamma2.save("earth-gamma-2.2.png"); 

   // rotate90
   Image rotate = image.rotate90();
   rotate.save("earth-rotate90.png");

   // swirl
   Image swirl = image.swirl();
   swirl.save("earth-swirl.png");

   // color jitter
   Image colorJitter = image.colorJitter(50);
   colorJitter.save("earth-color-jitter.png"); 

   // blur
   Image blur = image.blur();
   blur.save("earth-blur.png"); 

   // glow
   Image glow = image.glow();
   glow.save("earth-glow.png"); 

   // border
   Image border = image.border({255, 255, 255});
   border.save("earth-border.png"); 


   Image soup;
   soup.load("../images/soup.png");

   Image rose;
   rose.load("../images/rose.jpg");

   std::cout << "rose toString: \n" << image << std::endl;

   // add
   Image add = image.add(rose);
   add.save("earth-add-rose.png");

   // subtract
   Image subtract = image.subtract(rose);
   subtract.save("earth-subtract-rose.png");
   
   // multiply
   Image multiply = image.multiply(rose);
   multiply.save("earth-multiply-rose.png");

   // difference
   Image difference = image.difference(rose);
   difference.save("earth-difference-rose.png");

   // lightest
   Image lightest = image.lightest(rose);
   lightest.save("earth-rose-lightest.png");

   // darkest
   Image darkest = image.darkest(rose);
   darkest.save("earth-rose-darkest.png");

   // invert
   Image invert = image.invert();
   invert.save("earth-invert.png"); 

   // alpha blend
   int y = (int) (0.5f * (image.height() - soup.height()));
   int x = (int) (0.5f * (image.width() - soup.width()));
   Image background = image.subimage(x, y, soup.width(), soup.height());
   background.save("background-test.png");
   Image blend = background.alphaBlend(soup, 0.5f);
   blend.save("blend-test.png");
   image.replace(blend, x, y);
   image.save("earth-blend-0.5.png");
}

