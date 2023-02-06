# pixmap-ops

Image manipulation demos based on the PPM image format.

![](art/art-7.png)

## How to build

*Windows*

Open git bash to the directory containing this repository.

```
pixmap-ops $ mkdir build
pixmap-ops $ cd build
pixmap-ops/build $ cmake -G "Visual Studio 17 2022" ..
pixmap-ops/build $ start pixmap-ops.sln
```

Your solution file should contain two projects: `pixmap_art` and `pixmap_test`.
To run from the git bash command shell, 

```
pixmap-ops/build $ ../bin/Debug/pixmap_test
pixmap-ops/build $ ../bin/Debug/pixmap_art
```

*macOS*

Open terminal to the directory containing this repository.

```
pixmap-ops $ mkdir build
pixmap-ops $ cd build
pixmap-ops/build $ cmake ..
pixmap-ops/build $ make
```

To run each program from build, you would type

```
pixmap-ops/build $ ../bin/pixmap_test
pixmap-ops/build $ ../bin/pixmap_art
```

## Image operators

- Resize an image\
<img src="demo/earth-200-300.png" width="200">
- Flip an image horizontally or vertically\
<img src="demo/earth-flip.png" width="200">
<img src="demo/earth-vflip.png" width="200">
- Rotate an image 90 degrees\
<img src="demo/earth-rotate90.png" width="200">
- Get a sub-image from a given image\
<img src="demo/earth-subimage.png" width="200">
- Replace a portion of an image with another image\
<img src="demo/ebricks-replace-earth.png" width="200">
- Swirl the colors of an image\
<img src="demo/earth-swirl.png" width="200">
- Convert an image to grayscale\
<img src="demo/earth-grayscale.png" width="200">
- Add a border around an image\
<img src="demo/earth-border.png" width="200">
- Invert colors of an image\
<img src="demo/earth-invert.png" width="200">
- Gamma correct an image\
<img src="demo/earth-gamma-0.6.png" width="200">
<img src="demo/earth-gamma-2.2.png" width="200">
- Blend two images together\
<img src="demo/blend-test.png" width="200">
- Apply glow effect to an image\
<img src="demo/earth-glow.png" width="200">
- Apply sobel operator to an image\
<img src="demo/earth-sobel.png" width="200">
- Apply painterly effect to an image\
<img src="demo/earth-painterly.png" width="200">
- Create a pixelated version of a image\
<img src="demo/earth-bitmap.png" width="200">
- Fill one color in an image with another color\
<img src="demo/earth-fill.png" width="200">
- Jitter the colors in an image\
<img src="demo/earth-colorJitter.png" width="200">
- Add two images together\
<img src="demo/earth-rose-add.png" width="200">
- Subtract two images\
<img src="demo/earth-rose-subtract.png" width="200">
- Find the difference between two images (absolute value)\
<img src="demo/earth-rose-difference.png" width="200">
- Multiply two images\
<img src="demo/earth-rose-multiply.png" width="200">
- Brighten an image\
<img src="demo/earth-brighten.png" width="200">
- Dim an image\
<img src="demo/earth-dim.png" width="200">
- Sharpen an image\
<img src="demo/earth-sharpen.png" width="200">
- Apply a vertical or horizontal gradient to an image\
<img src="demo/earth-vgradient.png" width="200">
<img src="demo/earth-hgradient.png" width="200">
- Blur an image using box blur or Gaussian blur\
<img src="demo/earth-blurGaussian.png" width="200">
- Glitch an image\
<img src="demo/earth-glitch.png" width="200">
- Distort an image\
<img src="demo/earth-distort.png" width="200">
- "Deep fry" an image\
<img src="demo/meme-deepFried.png" width="200">

## Results

![](art/art-3.png)\
![](art/art-1.png)
![](art/art-2.png)\
![](art/art-4.png)\
![](art/art-5.png)\
![](art/art-6.png)\
![](art/art-8.png)
![](art/art-9.png)\

