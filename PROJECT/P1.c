#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"structures.h"

struct Bitmap_Header header;
struct Info_Header h;
struct Greyscale g;
struct RGB rgb;
struct Image_8_bit read_pixel;
struct Image_24_bit i1;

void Image_pixel(FILE *fp, int height, int width)
{	
    fseek(fp,header.data_offset,0);
	read_pixel.g = (struct Greyscale**) malloc(height*sizeof(void*));
	read_pixel.height = height;
	read_pixel.width = width;
	for(int i = (height-1);i>=0;i--)
	{	read_pixel.g[i] = (struct Greyscale*) malloc(width*sizeof(void*));
		fread(read_pixel.g[i],h.width,1,fp);
	}
}

void Gray_to_rgb(int height,int width)
{
    i1.rgb = (struct RGB**) malloc(3*height*sizeof(void*));
	for(int i=0;i<height;i++)
	{		
        i1.rgb[i] = (struct RGB*) malloc(3*width*sizeof(void*));
		for(int j=0 ;j<width ;j++)
		{
        		i1.rgb[i][j].Blue=read_pixel.g[i][j].greyscale;
				i1.rgb[i][j].Green=read_pixel.g[i][j].greyscale;
				i1.rgb[i][j].Red=read_pixel.g[i][j].greyscale;
		}
	}
}

void read_source(FILE* fp)
{
    fread(header.signature,2,1,fp);
    if(header.signature[0]!='B' || header.signature[1]!='M')
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
    if(h.bits_per_pixel !=8)
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

void Copy_pixels_to_destination(FILE *fpf)
{
    fseek(fpf,header.data_offset,0);
    for(int i=0; i<h.height; i++)
    {
            fwrite(i1.rgb[i],h.width,3,fpf);
    }
}

int main()
{
    char path[100];
    printf("Enter name or path of source file: ");
    scanf("%s",path);
    FILE *fp = fopen(path, "rb");
    FILE *fpf = fopen("output.bmp", "wb");
    read_source(fp);
    create_imageheader(fpf);
    Image_pixel(fp,h.height,h.width);
    Gray_to_rgb(h.height,h.width);
    Copy_pixels_to_destination(fpf);
}
