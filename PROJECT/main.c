#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"structures.h"
#include"dec.h"
struct Info_Header h;
int main()
{
    FILE *fp = fopen("sample2.bmp", "rb");
    FILE *fpf = fopen("output.bmp", "wb");
    read_source(fp);
    create_imageheader(fpf);
    Image_pixel(fp,h.height,h.width);
    Gray_to_rgb(h.height,h.width);
    Copy_pixels_to_destination(fpf);
}
