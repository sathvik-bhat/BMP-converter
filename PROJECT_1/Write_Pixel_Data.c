#include"structures.h"
#include<stdio.h>
struct Bitmap_Header header;
struct Image_24_bit i1;
struct Info_Header h;
void Copy_pixels_to_destination(FILE *fpf)
{
    int bytes_to_write;
    bytes_to_write=(h.width%4==0)?(h.width):(h.width+4-h.width%4);
    fseek(fpf,header.data_offset,0);
    for(int i=0; i<h.height; i++)
    {
            fwrite(i1.rgb[i],bytes_to_write,3,fpf);
    }
}
