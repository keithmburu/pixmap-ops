/**
 * @file image.cpp
 * @author Keith Mburu
 * @author Aline Normoyle
 * @version 2023-02-02
 */

#include "image.h"

#include <cassert>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../external/include/stb/stb_image_write.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../external/include/stb/stb_image.h"

#include <cmath>
#include <algorithm>

namespace agl {


Image::Image() {
   this->_data = NULL;
   this->_width = 0;
   this->_height = 0;
}

Image::Image(int width, int height)  {
   this->_data = (unsigned char*) malloc(sizeof(unsigned char*) * width * height * 3);
   this->_width = width;
   this->_height = height;
}

Image::Image(const Image& orig) {
   this->_data = (unsigned char*) malloc(sizeof(unsigned char*) * orig.width() * orig.height() * 3);
   for (int idx = 0; idx < orig.width() * orig.height(); idx++) {
      this->set(idx, orig.get(idx));
   }
   this->_width = orig.width();
   this->_height = orig.height();
}

Image& Image::operator=(const Image& orig) {
   if (&orig == this) {
      return *this;
   }
   free(this->_data);
   this->_data = orig.data();
   this->_width = orig.width();
   this->_height = orig.height();
   return *this;
}

std::ostream& operator<<(std::ostream& os, const Image& image) {
   os << "Width: " << image.width() << "\nHeight: " << image.height();
   int sumRed = 0.0f; int sumGreen = 0.0f; int sumBlue = 0.0f;
   for (int idx = 0; idx < image.width() * image.height(); idx++) {
      Pixel px = image.get(idx);
      sumRed += (int) px.r;
      sumGreen += (int) px.g;
      sumBlue += (int) px.b;
      // std::cout << sumRed << " " << sumGreen << " " << sumBlue << std::endl;
   }
   int avgRed = sumRed / (image.width() * image.height());
   int avgGreen = sumGreen / (image.width() * image.height());
   int avgBlue = sumBlue / (image.width() * image.height());

   os << "\nAverage pixel color: " << avgRed << " " << avgGreen << " " << avgBlue << std::endl;
   return os;
}

Image::~Image() {
   std::cout << "Freeing memory" << std::endl;
   if (this->_data) {
      free(this->_data);
   }
}

int Image::width() const { 
   return this->_width;
}

int Image::height() const {
   return this->_height;
}

unsigned char* Image::data() const {
   return this->_data;
}

void Image::set(int width, int height, unsigned char* data) {
   if (this->width() == width && this->height() == height) {
      this->_data = data;
   } else {
      std::cerr << "set(): Dimensions must match!" << std::endl;
   }
}

bool Image::load(const std::string& filename, bool flip) {
   int n;
   this->_data = stbi_load(filename.c_str(), &this->_width, &this->_height, &n, 3);
   if (flip) {
      this->set(this->_width, this->_height, (this->flipHorizontal()).data());
   }
   if (!this->_data) {
      return false;
   } else {
      return true;
   }
}

bool Image::save(const std::string& filename, bool flip) const {
   unsigned char* data = this->_data;
   if (flip) {
      data = (this->flipHorizontal()).data();
   }
   int saved = stbi_write_png(filename.c_str(), this->width(), this->height(), 3, (void*) data, this->width() * 3);
   if (!saved) {
      std::cout << "Write error" << std::endl;
      return false;
   } else {
      return true;
   }
}

Pixel Image::get(int row, int col) const {
   int idx = ((row * this->width()) + col) * 3;
   return Pixel{ this->_data[idx], this->_data[idx + 1], this->_data[idx + 2] };
}

Pixel Image::get(int i) const {
   int idx = i * 3;
   return Pixel{ this->_data[idx], this->_data[idx + 1], this->_data[idx + 2] };
}

void Image::set(int row, int col, const Pixel& color) {
   int idx = ((row * this->width()) + col) * 3;
   this->_data[idx] = color.r;
   this->_data[idx + 1] = color.g;
   this->_data[idx + 2] = color.b;
}

void Image::set(int i, const Pixel& c) {
   int idx = i * 3;
   this->_data[idx] = c.r;
   this->_data[idx + 1] = c.g;
   this->_data[idx + 2] = c.b;
}

Image Image::resize(int w, int h) const {
   std::cout << "Resizing to " << w << " by " << h << std::endl;
   Image result(w, h);
   for (int i2 = 0; i2 < result.height(); i2++) {
      for (int j2 = 0; j2 < result.width(); j2++) {
         int i1 = (int)((float) i2 / (result.height() - 1) * (this->height() - 1));
         int j1 = (int)((float) j2 / (result.width() - 1) * (this->width() - 1));
         // std::cout << i1 << " " << j1 << std::endl;
         Pixel px1 = this->get(i1, j1);
         // std::cout << (int) px1.r << " " << (int) px1.g << std::endl;
         result.set(i2, j2, px1);
      }
   }
   return result;
}

Image Image::flipHorizontal() const {
   std::cout << "Flipping horizontally" << std::endl;
   Image result(*this);
   for (int i = 0; i < result.height() / 2; i++) {
      for (int j = 0; j < result.width(); j++) {
         int newI = result.height() - i - 1;
         Pixel temp = this->get(newI, j);
         // std::cout << i << " " << j << "  " << idx << " " << flippedIdx << std::endl;
         result.set(newI, j, this->get(i, j));
         result.set(i, j, temp);
      }
   }
   return result;
}

Image Image::flipVertical() const {
   std::cout << "Flipping vertically" << std::endl;
   Image result(*this);
   for (int i = 0; i < result.height(); i++) {
      for (int j = 0; j < result.width() / 2; j++) {
         int newJ = result.width() - j - 1;
         Pixel temp = this->get(i, newJ);
         // std::cout << i << " " << j << "  " << idx << " " << flippedIdx << std::endl;
         result.set(i, newJ, this->get(i, j));
         result.set(i, j, temp);
      }
   }
   return result;
}

Image Image::rotate90() const {
   std::cout << "Rotating 90 degrees" << std::endl;
   Image result(*this);
   for (int i = 0; i < result.height(); i++) {
      for (int j = 0; j < result.width(); j++) {
         Pixel px1 = this->get(i, j);
         int newI = j;
         int newJ = result.height() - i;
         result.set(newI, newJ, px1);
      }
   }
   return result;
}

Image Image::subimage(int startx, int starty, int w, int h) const {
   std::cout << "Creating " << w << " by " << h << " subimage from (" << startx << ", " << starty << ")" << std::endl;
   Image sub(w, h);
   for (int i = starty; i < starty + h; i++) {
      for (int j = startx; j < startx + w; j++) { 
         int subIdx = ((i - starty) * sub.width()) + (j - startx);
         sub.set(subIdx, this->get(i, j));
      }
   }
   return sub;
}

void Image::replace(const Image& image, int startx, int starty) {
   std::cout << "Replacing from (" << startx << ", " << starty << ")" << std::endl;
   if (this->width() - startx >= image.width() && this->height() - starty >= image.height()) {
      for (int i = starty; i < starty + image.height(); i++) {
         for (int j = startx; j < startx + image.width(); j++) {
            int idx1 = (i * this->width()) + j;
            int idx2 = ((i - starty) * image.width()) + (j - startx);
            Pixel px2 = image.get(idx2);
            this->set(idx1, px2);
         }
      }
   } else {
      std::cout << "Image does not fit on this image!" << std::endl;
   }
}

Image Image::swirl() const {
   std::cout << "Swirling colors" << std::endl;
   Image result(*this);
   for (int idx = 0; idx < result.width() * result.height(); idx++) {
      Pixel px = this->get(idx);
      unsigned char red = px.r;
      px.r = px.g;
      px.g = px.b;
      px.b = red;
      result.set(idx, px);
   }
   return result;
}

Image Image::add(const Image& other) const {
   std::cout << "Adding" << std::endl;
   Image result(*this);
   for (int idx = 0; idx < result.width() * result.height(); idx++) {
      Pixel px1 = this->get(idx);
      Pixel px2 = other.get(idx);
      px1.r = std::min(px1.r + px2.r, 255);
      px1.g = std::min(px1.g + px2.g, 255);
      px1.b = std::min(px1.b + px2.b, 255);
      result.set(idx, px1);
   }
   return result;
}

Image Image::subtract(const Image& other) const {
   std::cout << "Subtracting" << std::endl;
   Image result(*this);
   for (int idx = 0; idx < result.width() * result.height(); idx++) {
      Pixel px1 = this->get(idx);
      Pixel px2 = other.get(idx);
      px1.r = std::max(px1.r - px2.r, 0);
      px1.g = std::max(px1.g - px2.g, 0);
      px1.b = std::max(px1.b - px2.b, 0);
      result.set(idx, px1);
   }
   return result;
}

Image Image::multiply(const Image& other) const {
   std::cout << "Multiplying" << std::endl;
   Image result(*this);
   for (int idx = 0; idx < result.width() * result.height(); idx++) {
      Pixel px1 = this->get(idx);
      Pixel px2 = other.get(idx);
      px1.r = std::min(px1.r * px2.r, 255);
      px1.g = std::min(px1.g * px2.g, 255);
      px1.b = std::min(px1.b * px2.b, 255);
      result.set(idx, px1);
   }
   return result;
}

Image Image::difference(const Image& other) const {
   std::cout << "Finding difference" << std::endl;
   Image result(*this);
   for (int idx = 0; idx < result.width() * result.height(); idx++) {
      Pixel px1 = this->get(idx);
      Pixel px2 = other.get(idx);
      px1.r = std::abs(px1.r - px2.r);
      px1.g = std::abs(px1.g - px2.g);
      px1.b = std::abs(px1.b - px2.b);
      result.set(idx, px1);
   }
   return result;
}

Image Image::lightest(const Image& other) const {
   std::cout << "Finding lightest" << std::endl;
   Image result(*this);
   for (int idx = 0; idx < result.width() * result.height(); idx++) {
      Pixel px1 = this->get(idx);
      Pixel px2 = other.get(idx);
      px1.r = std::max(px1.r, px2.r);
      px1.g = std::max(px1.g, px2.g);
      px1.b = std::max(px1.b, px2.b);
      result.set(idx, px1);
   }
   return result;
}

Image Image::darkest(const Image& other) const {
   std::cout << "Finding darkest" << std::endl;
   Image result(*this);
   for (int idx = 0; idx < result.width() * result.height(); idx++) {
      Pixel px1 = this->get(idx);
      Pixel px2 = other.get(idx);
      px1.r = std::min(px1.r, px2.r);
      px1.g = std::min(px1.g, px2.g);
      px1.b = std::min(px1.b, px2.b);
      result.set(idx, px1);
   }
   return result;
}

Image Image::gammaCorrect(float gamma) const {
   std::cout << "Gamma correcting with gamma = " << gamma << std::endl;
   Image result(*this);
   for (int idx = 0; idx < result.width() * result.height(); idx++) {
      Pixel px = result.get(idx);
      px.r = pow(px.r / 255.0, 1 / gamma) * 255;
      px.g = pow(px.g / 255.0, 1 / gamma) * 255;
      px.b = pow(px.b / 255.0, 1 / gamma) * 255;
      result.set(idx, px);
   }
   return result;
}

Image Image::alphaBlend(const Image& other, float alpha) const {
   std::cout << "Blending with alpha = " << alpha << std::endl;
   Image result(*this);
   for (int idx = 0; idx < result.width() * result.height(); idx++) {
      Pixel px1 = this->get(idx);
      Pixel px2 = other.get(idx);
      px1.r = px1.r * (1 - alpha) + px2.r * alpha;
      px1.g = px1.g * (1 - alpha) + px2.g * alpha;
      px1.b = px1.b * (1 - alpha) + px2.b * alpha;
      result.set(idx, px1);
   }
   return result;
}

Image Image::invert() const {
   std::cout << "Inverting" << std::endl;
   Image result(*this);
   for (int idx = 0; idx < result.width() * result.height(); idx++) {
      Pixel px = this->get(idx);
      px.r = 255 - px.r;
      px.g = 255 - px.g;
      px.b = 255 - px.b;
      result.set(idx, px);
   }
   return result;
}

Image Image::grayscale() const {
   std::cout << "Making grayscale" << std::endl;
   Image result(*this);
   for (int idx = 0; idx < result.width() * result.height(); idx++) {
      Pixel px = this->get(idx);
      float avg = ((0.3 * px.r) + (0.59 * px.g) + (0.11 * px.b)) / 3;
      px.r = px.g = px.b = avg;
      result.set(idx, px);
   }
   return result;
}

Image Image::colorJitter(int size) const {
   std::cout << "Jittering colors with size = " << size << std::endl;
   Image result(*this);
   for (int idx = 0; idx < result.width() * result.height(); idx++) {
      Pixel px = this->get(idx);
      int jitter = rand() % size;
      if (jitter % 2 == 0) {
         jitter = -jitter;
      }
      px.r = std::min(px.r + jitter, 255);
      px.g = std::min(px.g + jitter, 255);
      px.b = std::min(px.b + jitter, 255);
      result.set(idx, px);
   }
   return result;
}

Image Image::bitmap(int size) const {
   std::cout << "Creating bitmap with size = " << size << std::endl;
   Image image(0, 0);
   
   return image;
}

void Image::fill(const Pixel& c) {
   std::cout << "Filling" << std::endl;
}

Image Image::blur(int iters) const {
   std::cout << "Blurring with iters = " << iters << std::endl;
   Image result(*this);
   for (int iter = 0; iter < iters; iter++) {
      for (int i = 0; i < result.height(); i++) {
         for (int j = 0; j < result.width(); j++) {
            int sumNeighborsRed; int sumNeighborsGreen; int sumNeighborsBlue;
            sumNeighborsRed = sumNeighborsGreen = sumNeighborsBlue = 0;
            for (int k = i - 1; k <= i + 1; k++) {
               for (int l = j - 1; l <= j + 1; l++) {
                  Pixel px;
                  if (0 <= k && k < result.height() && 0 <= l && l < result.width()) {
                     px = result.get(k, l);
                  } else {
                     px = result.get(i, j);
                  }
                  sumNeighborsRed += px.r;
                  sumNeighborsGreen += px.g;
                  sumNeighborsBlue += px.b;
               }
            }
            unsigned char avgNeighborsRed = sumNeighborsRed / 9; 
            unsigned char avgNeighborsGreen = sumNeighborsGreen / 9; 
            unsigned char avgNeighborsBlue = sumNeighborsBlue / 9;
            result.set(i, j, {avgNeighborsRed, avgNeighborsGreen, avgNeighborsBlue});
         }
      }
   }
   return result;
}

Image Image::glow() const {
   std::cout << "Glowifying" << std::endl;
   Image white(*this);
   for (int idx = 0; idx < this->width() * this->height(); idx++) {
      Pixel px = this->get(idx);
      if (px.r < 200 || px.g < 200 || px.b < 200) {
         white.set(idx, {0, 0, 0});
      }
   }
   white.save("earth-white.png");
   white.blur().save("earth-white-blur.png");
   // std::cout << result << std::endl;
   return this->alphaBlend(white.blur(), 0.25);
}

Image Image::border(const Pixel& c) const {
   std::cout << "Drawing borders with color " << (int) c.r << " " << (int) c.g << " " << (int) c.b << std::endl;
   Image result(*this);
   // top and bottom
   for (int j = 0; j < result.width(); j++) {
      result.set(0, j, c);
      result.set(result.height() - 1, j, c);
   }
   // left and right
   for (int i = 1; i < result.height() - 1; i++) {
      result.set(i, 0, {255, 255, 255});
      result.set(i, result.width() - 1, {255, 255, 255});
   }
   return result;
}

}  // namespace agl
