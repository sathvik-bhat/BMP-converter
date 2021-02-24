#include"structures.h"
#include<stdio.h>

struct Bitmap_Header header;
struct Image_24_bit i1;
struct Info_Header h;

void Copy_pixels_to_destination(FILE *fpf)
{
    int bytes_to_write;
    bytes_to_write=(h.width%4==0)?(h.width):(h.width+4-h.width%4);  // assigning bytes of width which must be multiple of 4
    fseek(fpf,header.data_offset,0);
    for(int i=0; i<h.height; i++)   // writing from i=0 as we have to find the reflection of the image
    {
            fwrite(i1.rgb[i],bytes_to_write,3,fpf);
    }
}
