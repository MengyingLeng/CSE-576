#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>

#include "image.h"

using namespace std;

// HW0 #3
// const Image& im: input image
// return the corresponding grayscale image
Image rgb_to_grayscale(const Image& im)
  {
  assert(im.c == 3); // only accept RGB images
  Image gray(im.w,im.h,1); // create a new grayscale image (note: 1 channel)
  
  // TODO: calculate the pixels of 'gray'
      for(int j=0;j<im.h;j++)
          for(int i=0;i<im.w;i++)
          {
              gray(i,j) = 0.299*im(i,j,0)+0.587*im(i,j,1)+0.114*im(i,j,2);
          }
  
  //NOT_IMPLEMENTED();
  
  return gray;
  }



// Example function that changes the color of a grayscale image
Image grayscale_to_rgb(const Image& im, float r, float g, float b)
  {
  assert(im.c == 1);
  Image rgb(im.w,im.h,3);
  
  for(int q2=0;q2<im.h;q2++)for(int q1=0;q1<im.w;q1++)
    {
    rgb(q1,q2,0)=r*im(q1,q2);
    rgb(q1,q2,1)=g*im(q1,q2);
    rgb(q1,q2,2)=b*im(q1,q2);
    }
  
  return rgb;
  }




// HW0 #4
// Image& im: input image to be modified in-place
// int c: which channel to shift
// float v: how much to shift
void shift_image(Image& im, int c, float v)
  {
  assert(c>=0 && c<im.c); // needs to be a valid channel
  
  // TODO: shift all the pixels at the specified channel
      for(int j=0;j<im.h;j++)
          for(int i=0;i<im.w;i++)
          {
              im(i,j,c)=im(i,j,c)+v;
          }
  //NOT_IMPLEMENTED();
  
  }

// HW0 #8
// Image& im: input image to be modified in-place
// int c: which channel to scale
// float v: how much to scale
void scale_image(Image& im, int c, float v)
  {
  assert(c>=0 && c<im.c); // needs to be a valid channel
  
  // TODO: scale all the pixels at the specified channel
      for(int j=0;j<im.h;j++)
          for(int i=0;i<im.w;i++)
          {
              im(i,j,c) =(1+v)*im(i,j,c);

          }
  //NOT_IMPLEMENTED();
  
  }


// HW0 #5
// Image& im: input image to be modified in-place
void clamp_image(Image& im)
  {
  // TODO: clamp all the pixels in all channel to be between 0 and 1
      for(int k =0; k<im.c; k++) {
          for (int j = 0; j < im.h; j++)
              for (int i = 0; i < im.w; i++) {
                  int cl = im(i, j, k);
                  if (cl<=0)
                  {
                      cl=0;
                      im(i, j, k) = cl;
                  }
                  if(cl>=1)
                  {
                      cl=1;
                      im(i, j, k) = cl;
                  }

              }
      }
 // NOT_IMPLEMENTED();
  
  }

// These might be handy
float max(float a, float b, float c)
  {
  return max({a,b,c});
  }

float min(float a, float b, float c)
  {
  return min({a,b,c});
  }


// HW0 #6
// Image& im: input image to be modified in-place
void rgb_to_hsv(Image& im) {
    assert(im.c == 3 && "only works for 3-channels images");

    // TODO: Convert all pixels from RGB format to HSV format
    for (int j = 0; j < im.h; j++)
        for (int i = 0; i < im.w; i++) {
            float R = im(i, j, 0);
            float G = im(i, j, 1);
            float B = im(i, j, 2);
            float V = max(R, G, B);
            float m = min(R, G, B);
            float C = V - m;
            float S = V == 0 ? 0 : C / V;
            float h, H;
            if (C == 0) H = 0;
            else {
                if (V == R) {
                    h = (G - B) / C;
                } else if (V == G) {
                    h = (B - R) / C + 2;
                } else if (V == B) {
                    h = (R - G) / C + 4;
                }
                if (h < 0) H = h / 6 + 1;
                else H = h / 6;
            }

            im(i, j, 0) = H;
            im(i, j, 1) = S;
            im(i, j, 2) = V;
            //NOT_IMPLEMENTED();

        }
}
// HW0 #7
// Image& im: input image to be modified in-place
void hsv_to_rgb(Image& im)
{
        assert(im.c==3 && "only works for 3-channels images");
        // TODO: Convert all pixels from HSV format to RGB format
        for (int j = 0; j < im.h; j++)
            for (int i = 0; i < im.w; i++) {
                float H = im(i,j,0);
                float S = im(i,j,1);
                float V = im(i,j,2);
                float C = V * S;
                float X = C * C*(1-abs(fmod(6*H,2)-1)) ;
                float m = V - C;
                float r,g,b;
                if(H<1.0/6.0){
                    r = C,g = X,b = 0;
                }
                else if(H<2.0/6.0){
                    r = X,g = C,b = 0;
                }
                else if (H<3.0/6.0){
                    r = 0,g = C,b = X;
                }
                else if (H< 4.0/6.0){
                    r = 0,g = X,b = C;
                }
                else if(H< 5.0/6.0){
                    r = X,g = 0,b = C;
                }
                else{
                    r = C,g = 0,b = X;
                }
                im(i,j,0)=r+m;
                im(i,j,1)=g+m;
                im(i,j,2)=b+m;
            }
        //NOT_IMPLEMENTED();
}
// HW0 #9
// Image& im: input image to be modified in-place
void rgb_to_lch(Image& im)
 {
  assert(im.c==3 && "only works for 3-channels images");
  
  // TODO: Convert all pixels from RGB format to LCH format
     assert(im.c==3 && "only works for 3-channels images");
     float rr, gg, bb, X, Y, Z, L, U, V, uu, vv, C, H;
     float Xn = 0.9505;
     float Yn = 1.0;
     float Zn = 1.0890;
     float un = 4*Xn / (Xn+15*Yn+3*Zn);
     float vn = 9*Yn / (Xn+15*Yn+3*Zn);
     float epsilon = pow(6 / 29.0, 3.0);
     float kappa = pow(29 / 3.0, 3.0);
     for (int q1 = 0; q1 < im.w; q1++)
         for (int q2 = 0; q2 < im.h; q2++)
         {
             float R = im(q1, q2, 0);
             float G = im(q1, q2, 1);
             float B = im(q1, q2, 2);
             //from rgb to srgb
             //gamma correction , https://en.wikipedia.org/wiki/SRGB
             rr = (R<=0.04045) ? R/12.92 : pow((R + 0.055)/1.055,2.4);
             gg = (G<=0.04045) ? G/12.92 : pow((G + 0.055)/1.055,2.4);
             bb = (B<=0.04045) ? B/12.92 : pow((B + 0.055)/1.055,2.4);

             X = 0.412453*rr + 0.357580*gg + 0.180423*bb;
             Y = 0.212671*rr + 0.715160*gg + 0.072169*bb;
             Z = 0.019334*rr + 0.119193*gg + 0.950227*bb;
             //XYZ to LUV, D65 illumination
             if (X+15*Y+3*Z == 0)
                 L = 0,U = 0, V = 0;
             else
             {
                 if (Y / Yn <= epsilon)
                     L = kappa * Y / Yn;
                 else
                     L = 116 * pow(Y / Yn, 1 / 3.0) - 16;
                 uu = 4*X / (X+15*Y+3*Z);
                 vv = 9*Y / (X+15*Y+3*Z);
                 U = 13*L*(uu-un);
                 V = 13*L*(vv-vn);
             }

             C = sqrt(U*U+V*V);
             H = atan2(V,U);
             im(q1, q2, 0) = H;
             im(q1, q2, 1) = C;
             im(q1, q2, 2) = L;
         }

     // NOT_IMPLEMENTED();


     //NOT_IMPLEMENTED();
  
  }

// HW0 #9
// Image& im: input image to be modified in-place
void lch_to_rgb(Image& im)
  {
  assert(im.c==3 && "only works for 3-channels images");
  
  // TODO: Convert all pixels from LCH format to RGB format
  NOT_IMPLEMENTED();
      float R, G, B, rr, gg, bb, X, Y, Z, uu, vv;
      float Xn = 0.9505;
      float Yn = 1.0;
      float Zn = 1.0890;
      float un = 4*Xn / (Xn+15*Yn+3*Zn);
      float vn = 9*Yn / (Xn+15*Yn+3*Zn);
      float epsilon = pow(3 / 29.0, 3.0);
      for (int q1 = 0; q1 < im.w; q1++)
          for (int q2 = 0; q2 < im.h; q2++)
          {
              float H = im(q1, q2, 0);
              float C = im(q1, q2, 1);
              float L = im(q1, q2, 2);
              float U = C * cos(H);
              float V = C * sin(H);
              if (L == 0)
                  X = 0,Y = 0,Z = 0;
              else
              {
                  if (L <= 8)
                      Y = Yn * L * epsilon;
                  else
                      Y = Yn * pow((L + 16.0) / 116.0, 3.0);
                  uu = U / (13*L) + un;
                  vv = V / (13*L) + vn;
                  X = Y * 9 * uu / (4*vv);
                  Z = Y * (12- 3*uu -20*vv) / (4*vv);
              }

              rr = 3.240479 * X -1.537150 * Y -0.498535 * Z;
              gg = -0.969256 * X + 1.875992 * Y + 0.041556 * Z;
              bb = 0.055648 * X -0.204043 * Y +1.057311  * Z;
              // srgb to rgb
              // reverse gamma transformation

              R = (rr<= 0.0031308) ? 12.92*rr : 1.055*pow(rr, 1.0/2.4)-0.055;
              G = (gg <= 0.0031308) ? 12.92*gg : 1.055*pow(gg, 1.0/2.4)-0.055;
              B = (bb <= 0.0031308) ? 12.92*bb : 1.055*pow(bb, 1.0/2.4)-0.055;
              im(q1, q2, 0) = R;
              im(q1, q2, 1) = G;
              im(q1, q2, 2) = B;

          }
      //NOT_IMPLEMENTED();

  }



// Implementation of member functions
void Image::clamp(void) { clamp_image(*this); }
void Image::shift(int c, float v) { shift_image(*this,c,v); }
void Image::scale(int c, float v) { scale_image(*this,c,v); }

void Image::HSVtoRGB(void) { hsv_to_rgb(*this); }
void Image::RGBtoHSV(void) { rgb_to_hsv(*this); }
void Image::LCHtoRGB(void) { lch_to_rgb(*this); }
void Image::RGBtoLCH(void) { rgb_to_lch(*this); }
