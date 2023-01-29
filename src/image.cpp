// Copyright 2021, Aline Normoyle, alinen

#include "image.h"

#include <cassert>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../external/include/stb/stb_image_write.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../external/include/stb/stb_image.h"

#include <cmath>

namespace agl {


Image::Image() {
   this->_data = NULL;
   this->_width = 0;
   this->_height = 0;
}

Image::Image(int width, int height)  {
   this->_data = new unsigned char[width * height * 3];
   this->_width = width;
   this->_height = height;
}

Image::Image(const Image& orig) {
   this->_data = new unsigned char[orig.width() * orig.height() * 3];
   this->_width = orig.width();
   this->_height = orig.height();
   for (int i = 0; i < orig.height(); i++) {
      for (int j = 0; j < orig.width(); j++) {
         int idx = ((i * orig.width()) + j) * 3;
         this->set(idx, orig.get(idx));
      }
   }
}

Image& Image::operator=(const Image& orig) {
   if (&orig != this) {
      this->_data = orig.data();
      this->_width = orig.width();
      this->_height = orig.height();
   }
   return *this;
}

Image::~Image() {
   std::cout << "Freeing memory" << std::endl;
   if (this->_data) {
      delete[] this->_data;
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
   try {
      int n;
      this->_data = stbi_load(filename.c_str(), &this->_width, &this->_height, &n, 3);
   } catch(...) {
      return false;
   }
   return true;
}


bool Image::save(const std::string& filename, bool flip) const {
   try {
      if (!stbi_write_png(filename.c_str(), this->width(), this->height(), 3, (void*) this->data(), this->width() * 3)) {
         std::cout << "Write error" << std::endl;
      }
   } catch(...) {
      return false;
   }
   return true;
}

Pixel Image::get(int row, int col) const {
   int index = (row * this->width()) + col;
   return Pixel{ this->_data[index], this->_data[index + 1], this->_data[index + 2] };
}

void Image::set(int row, int col, const Pixel& color) {
   int index = (row * this->width()) + col;
   this->_data[index] = color.r;
   this->_data[index + 1] = color.g;
   this->_data[index + 2] = color.b;
}

Pixel Image::get(int i) const {
   return Pixel{ this->_data[i], this->_data[i+1], this->_data[i+2] };
}

void Image::set(int i, const Pixel& c) {
   this->_data[i] = c.r;
   this->_data[i+1] = c.g;
   this->_data[i+2] = c.b;
}

Image Image::resize(int w, int h) const {
   Image result(*this);
   // float xfactor = w/this->width();
   // float yfactor = h/this->height();
   // for (int i = 0; i < result.height(); i++) {
   //    for (int j = 0; j < result.width(); j++) {
   //       int idx = ((i * result.width()) + j) * 3;
   //       result.set(idx, this->get(idx));
   //    }
   // }
   return result;
}

Image Image::flipHorizontal() const {
   Image result(*this);
   for (int i = 0; i < result.height() / 2; i++) {
      for (int j = 0; j < result.width(); j++) {
         int idx = ((i * result.width()) + j) * 3;
         int newI = result.height() - i;
         int flippedIdx = ((newI * result.width()) + j) * 3;
         Pixel temp = this->get(flippedIdx);
         // std::cout << i << " " << j << "  " << idx << " " << flippedIdx << std::endl;
         result.set(flippedIdx, this->get(idx));
         result.set(idx, temp);
      }
   }
   return result;
}

Image Image::flipVertical() const {
   Image result(*this);
   for (int i = 0; i < result.height(); i++) {
      for (int j = 0; j < result.width() / 2; j++) {
         int idx = ((i * result.width()) + j) * 3;
         int newJ = result.width() - j;
         int flippedIdx = ((i * result.width()) + newJ) * 3;
         Pixel temp = this->get(flippedIdx);
         // std::cout << i << " " << j << "  " << idx << " " << flippedIdx << std::endl;
         result.set(flippedIdx, this->get(idx));
         result.set(idx, temp);
      }
   }
   return result;
}

Image Image::rotate90() const {
   Image result(0, 0);
  
   return result;
}

Image Image::subimage(int startx, int starty, int w, int h) const {
   Image sub(w, h);
   for (int i = startx; i < startx + h; i++) {
      for (int j = starty; j < starty + w; j++) { 
         int subIdx = (((i - startx) * sub.width()) + (j - starty)) * 3;
         sub.set(subIdx, this->get(i, j));
      }
   }
   return sub;
}

void Image::replace(const Image& image, int startx, int starty) {
  
}

Image Image::swirl() const {
   Image result(0, 0);
   return result;
}

Image Image::add(const Image& other) const {
   Image result(0, 0);
  
   return result;
}

Image Image::subtract(const Image& other) const {
   Image result(0, 0);
   
   return result;
}

Image Image::multiply(const Image& other) const {
   Image result(0, 0);
   
   return result;
}

Image Image::difference(const Image& other) const {
   Image result(0, 0);
  
   return result;
}

Image Image::lightest(const Image& other) const {
   Image result(0, 0);
  
   return result;
}

Image Image::darkest(const Image& other) const {
   Image result(0, 0);
  
   return result;
}

Image Image::gammaCorrect(float gamma) const {
   Image result(*this);
   for (int i = 0; i < result.height(); i++) {
      for (int j = 0; j < result.width(); j++) {
         int idx = ((i * result.width()) + j) * 3;
         Pixel px = result.get(idx);
         px.r = pow(px.r / 255.0, 1 / gamma) * 255;
         px.g = pow(px.g / 255.0, 1 / gamma) * 255;
         px.b = pow(px.b / 255.0, 1 / gamma) * 255;
         result.set(idx, px);
      }
   }
   return result;
}

Image Image::alphaBlend(const Image& other, float alpha) const {
   Image result(0, 0);

   return result;
}

Image Image::invert() const {
   Image image(0, 0);
   
   return image;
}

Image Image::grayscale() const {
   Image result(*this);
   for (int i = 0; i < result.height(); i++) {
      for (int j = 0; j < result.width(); j++) {
         int idx = ((i * result.width()) + j) * 3;
         Pixel px = this->get(idx);
         float avg = ((0.3 * px.r) + (0.59 * px.g) + (0.11 * px.b)) / 3;
         px.r = px.g = px.b = avg;
         result.set(idx, px);
      }
   }
   return result;
}

Image Image::colorJitter(int size) const {
   Image image(0, 0);
  
   return image;
}

Image Image::bitmap(int size) const {
   Image image(0, 0);
   
   return image;
}

void Image::fill(const Pixel& c) {
  }

}  // namespace agl
