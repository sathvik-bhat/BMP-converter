#include<stdio.h>
#include<stdlib.h>
#include"structures.h"
struct Greyscale g;
struct Bitmap_Header header;
struct Image_8_bit read_pixel;
struct Info_Header h;
void Image_pixel(FILE *fp, int height, int width)
{	
    fseek(fp,header.data_offset,0);
	int bytes_to_read,num_of_gray;
	read_pixel.g = (struct Greyscale**) malloc(height*sizeof(void*));
	read_pixel.height = height;
	read_pixel.width = width;
	bytes_to_read=((8*h.width+31)/32)*4;
	num_of_gray=bytes_to_read/sizeof(struct Greyscale) + 1;
	for(int i = (height-1);i>=0;i--)
	{	read_pixel.g[i] = (struct Greyscale*) malloc(num_of_gray*sizeof(void*));
		fread(read_pixel.g[i],bytes_to_read,1,fp);
	}
}
