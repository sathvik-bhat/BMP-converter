#include"structures.h"
#include<stdio.h>
struct Bitmap_Header header;
struct Image_24_bit i1;
struct Info_Header h;
void Copy_pixels_to_destination(FILE *fpf)
{
    fseek(fpf,header.data_offset,0);
    for(int i=0; i<h.height; i++)
    {
            fwrite(i1.rgb[i],((24*h.width+31)/32)*4,1,fpf);
    }
}
