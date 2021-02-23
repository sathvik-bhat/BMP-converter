#include<stdio.h>
#include<math.h>
#include"structures.h"
struct Bitmap_Header header;
struct Info_Header h;
void create_imageheader(FILE *fpf) 
{
    int a=24;
    int b=pow(2,24);
    fwrite(header.signature,2,1,fpf);
    fwrite(&header.file_size,4,1,fpf);
    fwrite(&header.reserved,4,1,fpf);
    fwrite(&header.data_offset,4,1,fpf);
    fwrite(&h.size, 4, 1, fpf);
    fwrite(&h.width, 4, 1,fpf);
    fwrite(&h.height, 4, 1,fpf);
    fwrite(&h.planes, 2, 1,fpf);
    fwrite(&a,2,1,fpf);
    fwrite(&h.compression, 4, 1,fpf);
    fwrite(&h.image_size, 4, 1,fpf);
    fwrite(&h.X_pixels_per_m, 4, 1,fpf);
    fwrite(&h.Y_pixels_per_m, 4, 1,fpf);
    fwrite(&b, 4, 1,fpf);
    fwrite(&h.important_colours, 4, 1,fpf);
}