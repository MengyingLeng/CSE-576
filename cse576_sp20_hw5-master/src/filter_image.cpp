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
    for(int c=0;c<im.c;c++){
        float sum=0;
        for(int w=0;w<im.w;w++){
            for(int h=0;h<im.h;h++){
                sum+=im(w,h,c);
            }
        }
        for(int c=0;c<im.c;c++){
            for(int w=0;w<im.w;w++){
                for(int h=0;h<im.h;h++){
                    im(w,h,c)=im(w,h,c)/sum;
                }
            }
        }
    }
}

// HW1 #2.1
// int w: size of filter
// returns the filter Image of size WxW
Image make_box_filter(int w)
{
    assert(w%2); // w needs to be even

    // TODO: Implement the filter
    Image ret(w,w,1);
    for(int i=0;i<w;i++){
        for(int j=0;j<w;j++){
            ret(i,j,0)=1;
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
    Image ret(im.w,im.h,im.c);
    Image ret2(im.w,im.h,1);
    float sum=0.0;
    float q;
    int kw=filter.w/2;
    int kh=filter.h/2;
    for(int i=-kw;i<im.w-kw;i++){
        for(int j=-kh;j<im.h-kh;j++){
            for(int z=0;z<im.c;z++){
                q=0;
                for(int i_f=0;i_f<filter.w;i_f++){
                    for(int j_f=0;j_f<filter.h;j_f++){
                        float im_pix=im.clamped_pixel(i+i_f,j+j_f,z);
                        float fi_pix=filter.clamped_pixel(i_f,j_f,0);
                        q+=im_pix*fi_pix;
                    }
                }
                ret(i+kw,j+kh,z)=q;
            }
        }
    }
    if(preserve==false){
        for(int i=0;i<ret.w;i++){
            for(int j=0;j<ret.h;j++){
                sum=0;
                for(int z=0;z<ret.c;z++){
                    sum+=ret.clamped_pixel(i,j,z);
                }
                ret2(i,j,0)=sum;
            }
        }
        return ret2;
    }else{
        return ret;
    }
}

// HW1 #2.3
// returns basic 3x3 high-pass filter
Image make_highpass_filter()
{
    // TODO: Implement the filter
    Image ret=make_box_filter(3);
    ret(0,0,0)=0;
    ret(1,0,0)=-1;
    ret(2,0,0)=0;
    ret(0,1,0)=-1;
    ret(1,1,0)=4;
    ret(2,1,0)=-1;
    ret(0,2,0)=0;
    ret(1,2,0)=-1;
    ret(2,2,0)=0;

    return ret;
}

// HW1 #2.3
// returns basic 3x3 sharpen filter
Image make_sharpen_filter()
{
    // TODO: Implement the filter
    Image ret=make_box_filter(3);
    ret(0,0,0)=0;
    ret(1,0,0)=-1;
    ret(2,0,0)=0;
    ret(0,1,0)=-1;
    ret(1,1,0)=5;
    ret(2,1,0)=-1;
    ret(0,2,0)=0;
    ret(1,2,0)=-1;
    ret(2,2,0)=0;

    return ret;

}

// HW1 #2.3
// returns basic 3x3 emboss filter
Image make_emboss_filter()
{
    // TODO: Implement the filter
    Image ret=make_box_filter(3);
    ret(0,0,0)=-2;
    ret(1,0,0)=-1;
    ret(2,0,0)=0;
    ret(0,1,0)=-1;
    ret(1,1,0)=1;
    ret(2,1,0)=1;
    ret(0,2,0)=0;
    ret(1,2,0)=1;
    ret(2,2,0)=2;

    return ret;


}

// HW1 #2.4
// float sigma: sigma for the gaussian filter
// returns basic gaussian filter
Image make_gaussian_filter(float sigma)
{
    int size=6*sigma;
    if(size%2==0){
        size+=1;
    }
    Image ret=make_box_filter(size);
    int k=size/2;
    for(int x=-k;x<size-k;x++){
        for(int y=-k;y<size-k;y++){
            ret(x+k,y+k,0)=1/(2*M_PI*sigma*sigma)*exp(-(x*x+y*y)/(2*sigma*sigma));
        }
    }
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
    Image ret(a.w,a.h,a.c);
    for(int w=0;w<a.w;w++){
        for(int h=0;h<a.h;h++){
            for(int c=0;c<a.c;c++){
                ret(w,h,c)=a(w,h,c)+b(w,h,c);
            }
        }
    }

    return ret;

}

// HW1 #3
// const Image& a: input image
// const Image& b: input image
// returns their difference res=a-b
Image sub_image(const Image& a, const Image& b)
{
    assert(a.w==b.w && a.h==b.h && a.c==b.c); // assure images are the same size

    // TODO: Implement subtraction
    Image ret(a.w,a.h,a.c);
    for(int w=0;w<a.w;w++){
        for(int h=0;h<a.h;h++){
            for(int c=0;c<a.c;c++){
                ret(w,h,c)=a(w,h,c)-b(w,h,c);
            }
        }
    }

    return ret;

}

// HW1 #4.1
// returns basic GX filter
Image make_gx_filter()
{
    // TODO: Implement the filter
    Image ret=make_box_filter(3);
    ret(0,0,0)=-1;
    ret(1,0,0)=0;
    ret(2,0,0)=1;
    ret(0,1,0)=-2;
    ret(1,1,0)=0;
    ret(2,1,0)=2;
    ret(0,2,0)=-1;
    ret(1,2,0)=0;
    ret(2,2,0)=1;

    return ret;
}

// HW1 #4.1
// returns basic GY filter
Image make_gy_filter()
{
    // TODO: Implement the filter
    Image ret=make_box_filter(3);
    ret(0,0,0)=-1;
    ret(1,0,0)=-2;
    ret(2,0,0)=-1;
    ret(0,1,0)=0;
    ret(1,1,0)=0;
    ret(2,1,0)=0;
    ret(0,2,0)=1;
    ret(1,2,0)=2;
    ret(2,2,0)=1;

    return ret;
}
// HW1 #4.2
// Image& im: input image
void feature_normalize(Image& im)
{
    assert(im.w*im.h); // assure we have non-empty image

    // TODO: Normalize the features for each channel

    for(int c=0;c<im.c;c++){
        float min=99999.0;
        float max=-9999.0;
        for(int h=0;h<im.h;h++){
            for(int w=0;w<im.w;w++){
                if(im(w,h,c)>max){
                    max=im(w,h,c);
                }
                if(im(w,h,c)<min){
                    min=im(w,h,c);
                }
            }
        }
        for(int i=0;i<im.w;i++){
            for(int j=0;j<im.h;j++){
                if(max-min!=0){
                    im(i,j,c)=(im(i,j,c)-min)/(max-min);
                }else{
                    im(i,j,c)=0;
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
    // TODO: Your code here
    // TODO: Your code here
    Image gx=convolve_image(im,make_gx_filter(),false);
    Image gy=convolve_image(im,make_gy_filter(),false);
    Image ret1(im.w,im.h,1);
    Image ret2(im.w,im.h,1);
    for(int w=0;w<im.w;w++){
        for(int h=0;h<im.h;h++){

            ret1(w,h,0)=sqrt((gx(w,h,0)*gx(w,h,0))+(gy(w,h,0)*gy(w,h,0)));
            ret2(w,h,0)=atan2(gy(w,h,0),gx(w,h,0));

        }
    }

    return {ret1,ret2};
}


// HW1 #4.4
// const Image& im: input image
// returns the colorized Sobel image of the same size
Image colorize_sobel(const Image& im)
{
    // TODO: Your code here
    Image smo=convolve_image(im, make_gaussian_filter(4), 1);
    pair<Image,Image> p= sobel_image(smo);
    feature_normalize(p.first);
    Image ret(im.w,im.h,3);
    for(int w=0;w<im.w;w++){
        for(int h=0;h<im.h;h++){
            ret(w,h,0)=p.second(w,h,0)/(2*M_PI)+0.5;
            ret(w,h,1)=p.first(w,h,0);
            ret(w,h,2)=p.first(w,h,0);
        }
    }
    hsv_to_rgb(ret);
    return ret;
}



// HW1 #4.5
// const Image& im: input image
// float sigma1,sigma2: the two sigmas for bilateral filter
// returns the result of applying bilateral filtering to im
Image bilateral_filter(const Image& im, float sigma1, float sigma2)
{
    Image bf=im;

    // TODO: Your bilateral code
    NOT_IMPLEMENTED();

    return bf;
}



// HELPER MEMBER FXNS

void Image::feature_normalize(void) { ::feature_normalize(*this); }
void Image::feature_normalize_total(void) { ::feature_normalize_total(*this); }
void Image::l1_normalize(void) { ::l1_normalize(*this); }

Image operator-(const Image& a, const Image& b) { return sub_image(a,b); }
Image operator+(const Image& a, const Image& b) { return add_image(a,b); }
