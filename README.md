# Error Level Analysis

Steps:

 * Implement ELA algorithm on a jpeg image using C/C++.
 * For above C/C++ code, Implement a python wrapper using cython.
 * compare the results of ELA for an image captured from your mobile phone versus the same image after photoshop (or any kind of image editing). This part of  scripting should be done in python using cython wrapper that you wrote earlier.
 

**Filename** - **Function**:
> - *ela.cpp*- Implements the Error Level Analysis algorithm to produce the error in form of an image, to detect image manipulation.

> - *original.jpg* - Original(not edited) image taken by mobile camera.

> - *photoshopped_img.jpg* - Photoshopped version of original image with a logo added to it saved at 100% quality in photoshop.

> - *diff.jpg* - Resultant image obtained after subtracting the original image from compressed image, we need to scale the difference values obtained as they are very close to zero, so not visible properly.

> - *result_original_img.jpg* - Resultant image after applying ELA algorithm on original image and scaling the difference values by a multiplier, so that they can be clearly visible as the difference values were very smaller.

> - *result_edited_img.jpg* - Resultant image after applying ELA algorithm on photoshopped image and scaling the difference values by a multiplier, so that they can be clearly visible as the difference values were very smaller.
