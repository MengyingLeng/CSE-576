//
// Created by 冷萌颖 on 4/3/20.
//

#include "../image.h"
#include "../utils.h"

#include <string>

using namespace std;
int main(int argc, char **argv)
{
// 1-2. Getting and setting pixels
    Image im2 = load_image("data/dog.jpg");
    for (int i=0; i<im2.w; i++)
        for (int j=0; j<im2.h; j++)
            im2(i, j, 0) = 0;
    im2.save_image("output/set_pixel_result");
// 1-6
    return 0;
}
