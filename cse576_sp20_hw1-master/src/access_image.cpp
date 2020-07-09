#include "image.h"

// HW0 #1
// const Image& im: input image
// int x,y: pixel coordinates
// int ch: channel of interest
// returns the 0-based location of the pixel value in the data array
int pixel_address(const Image& im, int x, int y, int ch)
  {
  // TODO: calculate and return the index
  int entry= x+y*im.w+ch*im.h*im.w;
  return entry;
  }

// HW0 #1
// const Image& im: input image
// int x,y,ch: pixel coordinates and channel of interest
// returns the value of the clamped pixel at channel ch
float get_clamped_pixel(const Image& im, int x, int y, int ch)
  {
  // TODO: clamp the coordinates and return the correct pixel value

      if(x<0) x =0;
      if(x >= im.w){
          x = im.w-1;
      }
      if(y<0) y=0;
      if(y >= im.h){
          y = im.h-1;
      }
      int address = pixel_address(im,x,y,ch);
      float pixel = im.data[address];
      //NOT_IMPLEMENTED();
      return pixel;
  }


// HW0 #1
// Image& im: input image
// int x,y,ch: pixel coordinates and channel of interest
void set_pixel(Image& im, int x, int y, int c, float value)
  {
  // TODO: Only set the pixel to the value if it's inside the image
      int address = pixel_address(im,x,y,c);
      im.data[address] = value;
  }



// HW0 #2
// Copies an image
// Image& to: destination image
// const Image& from: source image
void copy_image(Image& to, const Image& from)
  {
  // allocating data for the new image
      to.data=(float*)calloc(from.w*from.h*from.c,sizeof(float));
      to.c=from.c;
      to.w = from.w;
      to.h = from.h;

      for(int i=0; i<from.c; i++){
          for(int j=0; j<from.h; j++){
              for(int k=0; k<from.w; k++){

                  //int address = pixel_address(from, k, j, i);
                  int address = pixel_address(from, k,j, i);
                  to.data[address] = from.data[address];
              }
          }
      }

  }
