//
//  main.cpp
//  toyRenderer
//
//  Created by Bill Ma on 2021/4/20.
//

#include <iostream>
#include "tgaimage.h"

const TGAColor red = TGAColor(255, 0, 0, 255);
void line(int x1, int y1,
          int x2, int y2,
          TGAImage &image, TGAColor color);

int main(int argc, const char * argv[]) {
    TGAImage image(300, 300, TGAImage::RGB);
//    image.set(52, 41, red);
    line(24, 30,
         300, 150,
         image, red);
    image.flip_vertically();
    image.write_tga_file("./output/lesson00.tga");
    return 0;
}

void line(int x1, int y1,
          int x2, int y2,
          TGAImage &image, TGAColor color) {
    float x = x1;
    float y = y1;
    float step = std::abs(x2 - x1);
    float dx = (x2 - x1) / step;
    float dy = (y2 - y1) / step;
    
    for (int i = 1; i < step; ++i) {
        image.set(x, y, color);
        x += dx;
        y += dy;
    }
}
