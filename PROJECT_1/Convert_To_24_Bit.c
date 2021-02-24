#include"structures.h"
#include<stdlib.h>
struct RGB rgb;
struct Image_24_bit i1;
struct Image_8_bit read_pixel;
void Gray_to_rgb(int height,int width)
{
    i1.rgb = (struct RGB**) malloc(3*height*sizeof(void*));    // dynamically alloating memory equal to 3*height to i1.rgb with initial pointer at RGB**
	for(int i=0;i<height;i++)
	{		
        i1.rgb[i] = (struct RGB*) malloc(3*(read_pixel.width)*sizeof(void*));   // dynamically alloating memory equal to width to i1.rgb with initial pointer at RGB**
		for(int j=0 ;j<read_pixel.width ;j++)
		{
        		i1.rgb[i][j].Blue=read_pixel.g[i][j].greyscale;
				i1.rgb[i][j].Green=read_pixel.g[i][j].greyscale;   // To get grayscale value R=G=B= grayscale value
				i1.rgb[i][j].Red=read_pixel.g[i][j].greyscale;
		}
	}
}
