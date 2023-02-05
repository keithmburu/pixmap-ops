# pixmap-ops

Image manipulation demos based on the PPM image format.

TODO: Add a representative image for your project here

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

TODO: Document the features of your PPM image class here. Include example images.
- Resize an image\
![](demo/earth-200-300.png)
- Flip an image horizontally or vertically\
![](demo/earth-flip.png | width=100)
![](demo/earth-vflip.png)
- Rotate an image 90 degrees\
![](demo/earth-rotate90.png)
- Get a sub-image from a given image\
![](demo/earth-subimage.png)
- Replace a portion of an image with another image\
![](demo/bricks-replace-earth.png)
- Swirl the colors of an image\
![](demo/earth-swirl.png)
- Convert an image to grayscale\
![](demo/earth-grayscale.png)
- Add border around an image\
![](demo/earth-border.png)
- Invert colors of an image\
![](demo/earth-invert.png)
- Gamma correct an image\
![](demo/earth-gamma-0.6.png)
![](demo/earth-gamma-2.2.png)
- Blend two images together\
![](demo/blend-test.png)
- Apply glow effect to an image\
![](demo/earth-glow.png)
- Apply sobel operator to an image\
![](demo/earth-sobel.png)
- Apply painterly effect to an image\
![](demo/earth-painterly.png)
- Create a pixelated version of a image\
![](demo/earth-bitmap.png)
- Fill the white in an image with another color\
![](demo/earth-fill.png)
- Jitter the colors in an image\
![](demo/earth-colorJitter.png)
- Add two images together\
![](demo/earth-rose-add.png)
- Subtract two images\
![](demo/earth-rose-subtract.png)
- Find the difference between two images (absolute value)\
![](demo/earth-rose-difference.png)
- Multiply two images\
![](demo/earth-rose-multiply.png)
- Brighten an image\
![](demo/earth-brighten.png)
- Dim an image\
![](demo/earth-dim.png)
- Sharpen an image\
![](demo/earth-sharpen.png)
- Apply a vertical or horizontal gradient to an image\
![](demo/earth-vgradient.png)
![](demo/earth-hgradient.png)
- Blur an image using box blur or Gaussian blur\
![](demo/earth-blurGaussian.png)
- Glitch an image\
![](demo/earth-glitch.png)
- Distort an image\
![](demo/earth-distort.png)
- "Deep fry" an image\
![](demo/meme-deepfried.png)

## Results

TODO: Show artworks using your class

