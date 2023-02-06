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
      cout << "ERROR: Cannot load image! Exiting...\n";
      exit(0);
   }
   cout << "feep toString: \n" << image << endl;

   for (int i = 0; i < image.height(); i++) {
      for (int j = 0; j < image.width(); j++) {
         Pixel c = image.get(i, j);
         cout << "(" << (int)c.r << "," << (int)c.g << "," << (int)c.b << ") ";
      }
      cout << endl;
   }
   image.save("../demo/feep-test-save.png"); // should match original

   // test: copy constructor
   Image copy = image; 
   copy.save("../demo/feep-test-copy.png"); // should match original and load into gimp

   // test: assignment operator
   copy = image; 
   copy.save("../demo/feep-test-assignment.png"); // should match original and load into gimp

   // should print r,g,b
   Pixel pixel = image.get(1, 1);
   cout << (int) pixel.r << " " << (int) pixel.g << " " << (int) pixel.b << endl;

   // test: setting a color
   pixel.r = 255;
   image.set(1, 1, pixel);
   image.save("../demo/feep-test-newcolor.png");

   // test a non-trivial image
   if (!image.load("../images/earth.png")) {
      cout << "ERROR: Cannot load image! Exiting...\n";
      exit(0);
   }
   cout << "\nearth toString: \n" << image << endl;

   Image rose;
   rose.load("../images/rose.jpg");
   cout << "\nrose toString: \n" << rose << endl;

   // resize
   Image resize = image.resize(200,300);
   resize.save("../demo/earth-200-300.png");
   Image resize2 = rose.resize(300,200);
   resize2.save("../demo/rose-300-200.png");

   // grayscale
   Image grayscale = image.grayscale(); 
   grayscale.save("../demo/earth-grayscale.png");

   // flip horizontal
   Image flip = image.flipHorizontal(); 
   flip.save("../demo/earth-flip.png"); 
   
   // flip vertical
   Image vflip = image.flipVertical(); 
   vflip.save("../demo/earth-vflip.png");

   // sub image
   Image sub = image.subimage(200, 200, 100, 100); 
   sub.save("../demo/earth-subimage.png"); 
   Image sub2 = rose.subimage(150, 150, 150, 150); 
   sub2.save("../demo/rose-subimage.png"); 

   // gamma correction
   Image gamma1 = image.gammaCorrect(0.6f); 
   gamma1.save("../demo/earth-gamma-0.6.png"); 

   Image gamma2 = image.gammaCorrect(2.2f);
   gamma2.save("../demo/earth-gamma-2.2.png"); 

   // rotate90
   Image rotate = image.rotate90();
   rotate.save("../demo/earth-rotate90.png");

   // swirl
   Image swirl = image.swirl();
   swirl.save("../demo/earth-swirl.png");
   Image swirl2 = rose.swirl();
   swirl2.save("../demo/rose-swirl.png");

   // color jitter
   Image colorJitter = image.colorJitter(50);
   colorJitter.save("../demo/earth-colorJitter.png"); 
   Image colorJitter2 = rose.colorJitter(100);
   colorJitter2.save("../demo/rose-colorJitter.png"); 

   // blur
   Image blur = image.blur();
   blur.save("../demo/earth-blur.png"); 
   Image blur2 = rose.blur();
   blur2.save("../demo/rose-blur.png"); 

   // gaussian blur
   Image blurGaussian = image.blurGaussian();
   blurGaussian.save("../demo/earth-blurGaussian.png"); 

   // glow
   Image glow = image.glow();
   glow.save("../demo/earth-glow.png"); 
   Image glow2 = rose.glow();
   glow2.save("../demo/rose-glow.png"); 

   // border
   Image border = image.border({255, 255, 255});
   border.save("../demo/earth-border.png"); 

   // sobel
   Image sobel = image.sobel();
   sobel.save("../demo/earth-sobel.png"); 
   Image sobel2 = rose.sobel();
   sobel2.save("../demo/rose-sobel.png"); 

   // bitmap
   Image bitmap = image.bitmap(10);
   bitmap.save("../demo/earth-bitmap.png"); 

   // fill
   Image fill = image.fill({255, 255, 255}, {255, 0, 0});
   fill.save("../demo/earth-fill.png"); 
   Image fill2 = rose.fill({255, 255, 255}, {0, 0, 255});
   fill2.save("../demo/rose-fill.png"); 

   // glitch
   Image glitch = image.glitch();
   glitch.save("../demo/earth-glitch.png"); 
   Image glitch2 = rose.glitch();
   glitch2.save("../demo/rose-glitch.png"); 

   // painterly
   Image painterly = image.painterly();
   painterly.save("../demo/earth-painterly.png"); 
   Image painterly2 = rose.painterly();
   painterly2.save("../demo/rose-painterly.png"); 

   // distort
   Image distort = image.distort("vertical");
   distort.save("../demo/earth-distort.png"); 
   Image distort2 = rose.distort("horizontal");
   distort2.save("../demo/rose-distort.png"); 

   // gradient
   Image vgradient = image.gradient("vertical", {255, 255, 255});
   vgradient.save("../demo/earth-vgradient.png"); 
   Image hgradient = image.gradient("horizontal", {0, 0, 255});
   hgradient.save("../demo/earth-hgradient.png"); 

   // sharpen
   Image sharpen = image.sharpen();
   sharpen.save("../demo/earth-sharpen.png");
   Image sharpen2 = rose.sharpen();
   sharpen2.save("../demo/rose-sharpen.png"); 

   // brighten
   Image brighten = image.brighten(30);
   brighten.save("../demo/earth-brighten.png");
   Image brighten2 = rose.brighten(20);
   brighten2.save("../demo/rose-brighten.png"); 

   // dim
   Image dim = image.dim(20);
   dim.save("../demo/earth-dim.png");
   Image dim2 = rose.dim(30);
   dim2.save("../demo/rose-dim.png"); 

   Image soup;
   soup.load("../images/soup.png");
   cout << "\nsoup toString: \n" << soup << endl;

   // add
   Image add = image.add(rose);
   add.save("../demo/earth-rose-add.png");

   // subtract
   Image subtract = image.subtract(rose);
   subtract.save("../demo/earth-rose-subtract.png");
   
   // multiply
   Image multiply = image.multiply(rose);
   multiply.save("../demo/earth-rose-multiply.png");

   // difference
   Image difference = image.difference(rose);
   difference.save("../demo/earth-rose-difference.png");

   // lightest
   Image lightest = image.lightest(rose);
   lightest.save("../demo/earth-rose-lightest.png");

   // darkest
   Image darkest = image.darkest(rose);
   darkest.save("../demo/earth-rose-darkest.png");

   // invert
   Image invert = image.invert();
   invert.save("../demo/earth-invert.png"); 

   // alpha blend
   int y = (int) (0.5f * (image.height() - soup.height()));
   int x = (int) (0.5f * (image.width() - soup.width()));
   Image background = image.subimage(x, y, soup.width(), soup.height());
   background.save("../demo/background-test.png");
   Image blend = background.alphaBlend(soup, 0.5f);
   blend.save("../demo/blend-test.png");
   image.replace(blend, x, y); 
   image.save("../demo/earth-blend-0.5.png");
   
   Image bricks;
   bricks.load("../images/bricks.png");
   bricks.replace(image, 100, 100);
   bricks.save("../demo/bricks-replace-earth.png");

   Image meme;
   meme.load("../images/meme.jpg");
   Image memeDeepFried = meme.deepFried();
   memeDeepFried.save("../demo/meme-deepfried.png");
}

