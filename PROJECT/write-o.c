#include"structures.h"
#include<stdio.h>
struct Bitmap_Header header;
struct Image_24_bit i1;
struct Info_Header h;
void Copy_pixels_to_destination(FILE *fpf)
{
    fseek(fpf,header.data_offset,0);
    for(int i=h.height-1; i>=0; i--)
    {
            fwrite(i1.rgb[i],h.width,3,fpf);
    }
}
