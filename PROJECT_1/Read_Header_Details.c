#include<stdio.h>
#include<stdlib.h>
#include"structures.h"

struct Bitmap_Header header;
struct Info_Header h;

void read_source(FILE* fp)
{
    fread(header.signature,2,1,fp);
    if(header.signature[0]!='B' || header.signature[1]!='M')	// condition for the file to be BMP
    {
	    printf("Invalid image format");
	    exit(0);
    }
    fread(&header.file_size,4,1,fp);
    fread(&header.reserved,4,1,fp);
    fread(&header.data_offset,4,1,fp);
    fread(&h.size, 4, 1, fp);
    fread(&h.width, 4, 1,fp);
    fread(&h.height, 4, 1,fp);
    fread(&h.planes, 2, 1,fp);
    fread(&h.bits_per_pixel,2,1,fp);
    if(h.bits_per_pixel !=8)	// check if the source file is 8-bit BMP or not
    {
	    printf("Image format should be 8 bit BMP");
	    exit(1);
    }
    fread(&h.compression, 4, 1,fp);
    fread(&h.image_size, 4, 1,fp);
    fread(&h.X_pixels_per_m, 4, 1,fp);
    fread(&h.Y_pixels_per_m, 4, 1,fp);
    fread(&h.colours_used, 4, 1,fp);
    fread(&h.important_colours, 4, 1,fp);

}
