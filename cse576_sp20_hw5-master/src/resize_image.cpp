#include <cmath>
#include "image.h"
#include <iostream>
using namespace std;

// HW1 #1
// float x,y: inexact coordinates
// int c: channel
// returns the nearest neibor to pixel (x,y,c)
float Image::pixel_nearest(float x, float y, int c) const
  {
  // Since you are inside class Image you can
  // use the member function pixel(a,b,c)

  // TODO: Your code here
  int x_int = round(x);
  int y_int = round(y);
  return clamped_pixel(x_int, y_int, c);
  //NOT_IMPLEMENTED();
  
  
  return 0;
  }

// HW1 #1
// float x,y: inexact coordinates
// int c: channel
// returns the bilinearly interpolated pixel (x,y,c)
float Image::pixel_bilinear(float x, float y, int c) const
  {
  // Since you are inside class Image you can
  // use the member function pixel(a,b,c)
  // TODO: Your code here
  //NOT_IMPLEMENTED();

  int x_left = floor(x);
  int x_right = ceil(x);
  int y_up = floor(y);
  int y_down = ceil(y);
  float v1a1 = clamped_pixel(x_left,y_up,c) * (x_right - x) *(y_down - y);
  float v2a2 = clamped_pixel(x_right,y_up,c) * (x - x_left) *(y_down - y);
  float v3a3 = clamped_pixel(x_left,y_down,c) * (x_right - x) *(y - y_up);
  float v4a4 = clamped_pixel(x_right,y_down,c) * (x - x_left) *(y - y_up);
  float a = v1a1+v2a2+v3a3+v4a4;
//  printf("a %f",a);
  return v1a1+v2a2+v3a3+v4a4;
  }

// HW1 #1
// int w,h: size of new image
// const Image& im: input image
// return new Image of size (w,h,im.c)
Image nearest_resize(const Image& im, int w, int h)
  {
  Image ret(w,h,im.c);
  
  // TODO: Your code here
  //NOT_IMPLEMENTED();
  float w_scale = float(im.w)/float (w);
  float h_scale =float(im.h)/float(h);
  for(int i = 0; i < w; i++){
      for(int j = 0; j < h; j++){
          for( int k = 0; k < im.c; k++){
              ret(i,j,k) = im.pixel_nearest(-0.5+(i+0.5)*w_scale, -0.5+(j+0.5)*h_scale, k);
          }
      }
  }
  return ret;
  }


// HW1 #1
// int w,h: size of new image
// const Image& im: input image
// return new Image of size (w,h,im.c)
Image bilinear_resize(const Image& im, int w, int h)
  {
  
  // TODO: Your code here
  
  //NOT_IMPLEMENTED();
      Image ret(w,h,im.c);

      // TODO: Your code here
      //NOT_IMPLEMENTED();
      float w_scale = float(im.w)/float (w);
      float h_scale =float(im.h)/float(h);
      //cout<<w_scale<<" "<<h_scale<<endl;
      for(int i = 0; i < w; i++){
          for(int j = 0; j < h; j++){
              for( int k = 0; k < im.c; k++){
                  ret(i,j,k) = im.pixel_bilinear(-0.5+(i+0.5)*w_scale, -0.5+(j+0.5)*h_scale, k);
              }
          }
      }
      return ret;
  
  //return Image();
  }



