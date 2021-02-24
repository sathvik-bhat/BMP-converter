#include<stdio.h>
#include<stdlib.h>
#include"structures.h"

struct Greyscale g;
struct Bitmap_Header header;
struct Image_8_bit read_pixel;
struct Info_Header h;

void Image_pixel(FILE *fp, int height, int width)
{	
    fseek(fp,header.data_offset,0);	// taking the cursor to offset byte
	read_pixel.g = (struct Greyscale**) malloc(height*sizeof(void*));	// dynamically alloating memory equal to (height*sizeof(void)) to read_pixel.g with initial pointer at Grescale**
	read_pixel.height = height;
	read_pixel.width=(h.width%4==0)?(h.width):(h.width+4-h.width%4);	// allocating the width such that it must be multiple of 4
	for(int i = (height-1);i>=0;i--)
	{	read_pixel.g[i] = (struct Greyscale*) malloc((read_pixel.width)*sizeof(void*));		
		fread(read_pixel.g[i],read_pixel.width,1,fp);	// reading the source pixels
	}
}
