
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "image.h"

#define M_PI 3.14159265358979323846

// HW1 #2.1
// Image& im: image to L1-normalize

void l1_normalize(Image& im)
{

    // TODO: Normalize each channel
    //NOT_IMPLEMENTED();

    int x = im.w;
    int y = im.h;

    for (int ch = 0; ch < im.c; ch++){
        float sum = 0;
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                sum += im(i,j,ch) ;
            }
        }
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                im(i,j,ch) /= sum ;
            }
        }
    }
}

// HW1 #2.1
// int w: size of filter
// returns the filter Image of size WxW
Image make_box_filter(int w)
{
    assert(w%2); // w needs to be odd

    // TODO: Implement the filter
    //NOT_IMPLEMENTED();

    Image ret(w,w,1);
    for(int i = 0; i < w; i++){
        for(int j = 0; j < w; j++){
            ret(i,j,0) = 1 ;
        }
    }
    l1_normalize(ret);
    return ret;


}

// HW1 #2.2
// const Image&im: input image
// const Image& filter: filter to convolve with
// bool preserve: whether to preserve number of channels
// returns the convolved image
Image convolve_image(const Image& im, const Image& filter, bool preserve)
{
    assert(filter.c==1);
    //Image ret = Image(im.w, im.h, im.c);
    // This is the case when we need to use the function clamped_pixel(x,y,c).
    // Otherwise you'll have to manually check whether the filter goes out of bounds
    // TODO: Make sure you set the sizes of ret properly. Use ret=Image(w,h,c) to reset ret
    // TODO: Do the convolution operator
    //NOT_IMPLEMENTED();

    if(preserve == true) {
        Image ret = Image(im.w, im.h, im.c);
        for (int i = 0; i < im.w; i++) {
            for (int j = 0; j < im.h; j++) {
                for (int ch = 0; ch < im.c; ch++) {
                    float pixel = 0;
                    for (int f_x = 0; f_x < filter.w; f_x++) {
                        for (int f_y = 0; f_y < filter.h; f_y++) {
                            pixel += filter(f_x, f_y,0) *
                                     im.clamped_pixel(i - filter.w / 2 + f_x, j - filter.w / 2 + f_y, ch);
                        }
                    }
                    ret(i, j, ch) = pixel;
                }
            }
        }
        return  ret;
    }
    else{
        Image ret = Image(im.w, im.h, 1);
        for (int i = 0; i < im.w; i++) {
            for (int j = 0; j < im.h; j++) {
                float pixel = 0;
                for (int ch = 0; ch < im.c; ch++) {
                    for (int f_x = 0; f_x < filter.w; f_x++) {
                        for (int f_y = 0; f_y < filter.h; f_y++) {
                            pixel += filter(f_x, f_y,0) *
                                     im.clamped_pixel(i - filter.w / 2 + f_x, j - filter.w / 2 + f_y, ch);
                        }
                    }
                    ret(i, j, 0) = pixel;
                }
            }
        }
        return  ret;

    }


    // Make sure to return ret and not im. This is just a placeholder
    //return ret;
}

// HW1 #2.3
// returns basic 3x3 high-pass filter
Image make_highpass_filter()
{
    // TODO: Implement the filter
    //NOT_IMPLEMENTED();
    Image ret = Image(3, 3, 1);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ret(i,j,0) = 0;
        }
    }

    ret(0,1,0) = -1;
    ret(1,0,0) = -1;
    ret(1,2,0) = -1;
    ret(2,1,0) = -1;
    ret(1,1,0) = 4;
    return  ret;


}

// HW1 #2.3
// returns basic 3x3 sharpen filter
Image make_sharpen_filter()
{
    // TODO: Implement the filter
    //NOT_IMPLEMENTED();

    Image ret = Image(3, 3, 1);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ret(i,j,0) = 0;
        }
    }
    ret(0,1,0) = -1;
    ret(1,0,0) = -1;
    ret(1,2,0) = -1;
    ret(2,1,0) = -1;
    ret(1,1,0) = 5;
    return ret;
}

// HW1 #2.3
// returns basic 3x3 emboss filter
Image make_emboss_filter()
{
    // TODO: Implement the filter
    //NOT_IMPLEMENTED();
    Image ret = Image(3, 3, 1);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ret(i,j,0) = 0;
        }
    }
    ret(0,0,0) = -2;
    ret(0,1,0) = -1;
    ret(1,0,0) = -1;
    ret(1,2,0) = 1;
    ret(2,1,0) = 1;
    ret(2,2,0) = 2;
    ret(1,1,0) = 1;
    return  ret;


}

// HW1 #2.4
// float sigma: sigma for the gaussian filter
// returns basic gaussian filter
Image make_gaussian_filter(float sigma)
{
    // TODO: Implement the filter
    //NOT_IMPLEMENTED();
    int size = ceil(6*sigma);
    if(size %2 == 0) size++;
    int mi = size / 2;
    Image ret = Image(size, size, 1);
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            ret(i,j,0) = 1.0/(2 * M_PI * pow(sigma,2)) * exp(-((pow(i-mi,2))+pow(j-mi, 2))/(2 * pow(sigma,2)));
        }
    }
    l1_normalize(ret);
    return ret;
}


// HW1 #3
// const Image& a: input image
// const Image& b: input image
// returns their sum
Image add_image(const Image& a, const Image& b)
{
    assert(a.w==b.w && a.h==b.h && a.c==b.c); // assure images are the same size

    // TODO: Implement addition
    //NOT_IMPLEMENTED();
    Image add(a.w, a.h, a.c);
    for (int i = 0; i < a.w; i++) {
        for (int j = 0; j < a.h; j++) {
            for (int ch = 0; ch < a.c; ch++) {
                add(i,j,ch) = a(i,j,ch) + b(i,j,ch);
                //add.clamped_pixel(i,j,ch);
            }
        }
    }
    return add;

}

// HW1 #3
// const Image& a: input image
// const Image& b: input image
// returns their difference res=a-b
Image sub_image(const Image& a, const Image& b)
{
    assert(a.w==b.w && a.h==b.h && a.c==b.c); // assure images are the same size

    // TODO: Implement subtraction
    //NOT_IMPLEMENTED();
    Image sub(a.w, a.h, a.c);
    for (int i = 0; i < a.w; i++) {
        for (int j = 0; j < a.h; j++) {
            for (int ch = 0; ch < a.c; ch++) {
                sub(i,j,ch) = a(i,j,ch) - b(i,j,ch);
                //sub.clamped_pixel(i,j,ch);
            }
        }
    }
    return sub;

}

// HW1 #4.1
// returns basic GX filter
Image make_gx_filter()
{
    // TODO: Implement the filter
    // NOT_IMPLEMENTED();
    Image ret(3,3,1);
    ret(0,0,0) = -1;
    ret(0,1,0) = 0;
    ret(0,2,0) = 1;
    ret(1,0,0) = -2;
    ret(1,1,0) = 0;
    ret(1,2,0) = 2;
    ret(2,0,0) = -1;
    ret(2,1,0) = 0;
    ret(2,2,0) = 1;
    return ret;
}

// HW1 #4.1
// returns basic GY filter
Image make_gy_filter()
{
    // TODO: Implement the filter
    //NOT_IMPLEMENTED();
    Image ret(3,3,1);
    ret(0,0,0) = -1;
    ret(0,1,0) = -2;
    ret(0,2,0) = -1;
    ret(1,0,0) = 0;
    ret(1,1,0) = 0;
    ret(1,2,0) = 0;
    ret(2,0,0) = 1;
    ret(2,1,0) = 2;
    ret(2,2,0) = 1;
    return ret;
}

// HW1 #4.2
// Image& im: input image
void feature_normalize(Image& im)
{
    assert(im.w*im.h); // assure we have non-empty image

    // TODO: Normalize the features for each channel
    //NOT_IMPLEMENTED();
    for (int ch = 0; ch < im.c; ch++) {
        float min_x = im(0,0,ch);
        float max_x = 0;
        for (int i = 0; i < im.w; i++) {
            for (int j = 0; j < im.h; j++) {
                if(im(i,j,ch) > max_x) max_x = im(i,j,ch);
                if(im(i,j,ch) < min_x) min_x = im(i,j,ch);
            }
        }
        float range = max_x - min_x;
        if(range == 0){
            for (int i = 0; i < im.w; i++) {
                for (int j = 0; j < im.h; j++) {
                    im(i,j,ch) = 0;
                }
            }
        }
        else{
            for (int i = 0; i < im.w; i++) {
                for (int j = 0; j < im.h; j++) {
                    im(i,j,ch) = (im(i,j,ch) - min_x)/range;
                }
            }
        }

    }

}


// Normalizes features across all channels
void feature_normalize_total(Image& im)
{
    assert(im.w*im.h*im.c); // assure we have non-empty image

    int nc=im.c;
    im.c=1;im.w*=nc;

    feature_normalize(im);

    im.w/=nc;im.c=nc;

}


// HW1 #4.3
// Image& im: input image
// return a pair of images of the same size
pair<Image,Image> sobel_image(const Image& im)
{
    // TODO: Your code here
    //NOT_IMPLEMENTED();

    Image gx_filter = make_gx_filter();
    Image gx = convolve_image(im, gx_filter, false);
    Image gy_filter = make_gy_filter();
    Image gy = convolve_image(im, gy_filter, false);

    Image g(im.w, im.h, 1);
    Image theta(im.w, im.h, 1);
    for(int i = 0; i < im.w;i++){
        for(int j = 0; j < im.h; j++){
            g(i,j,0) = sqrt(pow(gx(i,j,0),2) + pow(gy(i,j,0),2));
            theta(i,j,0) = atan2(gx(i,j,0),gy(i,j,0));

        }
    }

    return {g,theta};
}


// HW1 #4.4
// const Image& im: input image
// returns the colorized Sobel image of the same size
Image colorize_sobel(const Image& im)
{

    // TODO: Your code here
    //NOT_IMPLEMENTED();
    Image f = make_gaussian_filter(4);
    Image blur = convolve_image(im, f, true);
    pair<Image,Image> res =  sobel_image(blur);
    Image magnitude = res.first;
    feature_normalize(magnitude);
    Image theta = res.second;
    Image hsv(im.w, im.h, im.c);
    for(int i = 0; i < im.w; i++){
        for(int j = 0; j < im.h; j++){
            theta(i,j,0) = theta(i,j,0)/(2 * M_PI) + 0.5;
            hsv(i, j, 0) = theta(i,j,0);
            hsv(i,j,1) = magnitude(i,j,0);
            hsv(i,j,2) =magnitude(i,j,0);
        }
    }
    hsv_to_rgb(hsv);
    return  hsv;

}


// HW1 #4.5
// const Image& im: input image
// float sigma1,sigma2: the two sigmas for bilateral filter
// returns the result of applying bilateral filtering to im
Image bilateral_filter(const Image& im, float sigma1, float sigma2)
{

    Image bf(im.w, im.h, im.c);

    // TODO: Your bilateral code
    //NOT_IMPLEMENTED(); before: 4.40814e+07 after: 2.88301e+07
    int k = ceil(6 * sigma1);
    float g_s[2*k+1][2*k+1];

    for(int i = -k; i < k; i++) {
        for (int j = -k; j < k; j++) {
            g_s[i+k][j+k] =  1.0/(2 * M_PI * pow(sigma1,2)) * exp(-((pow(i,2))+pow(j, 2))/(2 * pow(sigma1,2)));
        }
    }

    for(int x = 0; x < im.w; x++){
        for(int y = 0; y < im.h; y++){
            for(int ch = 0; ch < im.c; ch++){
                float pixel = 0;
                float sum = 0;
                for(int i = -k; i < k; i++){
                    for(int j = -k; j < k; j++){
                        float color_distance = im(x,y,ch) - im.clamped_pixel(x + i, y + j, ch);
                        float g_distance =1.0/(2 * M_PI * pow(sigma2,2)) * exp((-pow(color_distance,2))/(2 * pow(sigma2,2)));
                        //convolve
                        float w = g_s[i+k][j+k] * g_distance;
                        pixel += w * im.clamped_pixel(x + i, y + j, ch);
                        //get normalization number
                        sum += w;
                    }
                }
                bf(x,y,ch) = pixel/sum;
            }
        }
    }
    return bf;
}



// HELPER MEMBER FXNS

void Image::feature_normalize(void) { ::feature_normalize(*this); }
void Image::feature_normalize_total(void) { ::feature_normalize_total(*this); }
void Image::l1_normalize(void) { ::l1_normalize(*this); }

Image operator-(const Image& a, const Image& b) { return sub_image(a,b); }
Image operator+(const Image& a, const Image& b) { return add_image(a,b); }
