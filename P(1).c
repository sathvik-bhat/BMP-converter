#include<stdio.h>
#include<stdlib.h>
#include"structures.h"

struct Bitmap_Header header;
struct Info_Header h;
struct Greyscale g;
struct RGB rgb;
struct Image_8_bit read_pixel;
struct Image_24_bit i1;

void Image_pixel(FILE *fp, int height, int width)
{	
    fseek(fp,0,header.data_offset);
	int i,numofgray,total_bytes;
	read_pixel.g = (struct Greyscale**) malloc(height*sizeof(void*));
	read_pixel.height = height;
	read_pixel.width = width;
	total_bytes=((8*h.width+31)/32)*4;
	numofgray=total_bytes/sizeof(struct Greyscale);
	for(i=(height-1);i>=0;i--)
	{	read_pixel.g[i] = (struct Greyscale*) malloc(numofgray*sizeof(struct Greyscale));
		fread(read_pixel.g[i],1,total_bytes,fp);
	}
}

void Gray_to_rgb(int height,int width)
{	int numofrgb,total_rgb_bytes;
	total_rgb_bytes=((24*h.height+31)/32)*4;
	numofrgb=total_rgb_bytes/sizeof(struct RGB);
    i1.rgb = (struct RGB**) malloc(3*width*sizeof(void*));
	for(int i=(height-1);i>=0;i--)
	{		
        i1.rgb[i] = (struct RGB*) malloc(width*(sizeof(struct RGB)));
		for(int j=width-1;j>=0;j--)
		{		i1.rgb[i][j].Red=read_pixel.g[i][j].greyscale;
				i1.rgb[i][j].Green=read_pixel.g[i][j].greyscale;
				i1.rgb[i][j].Blue=read_pixel.g[i][j].greyscale;
		}
	}
}

void read_source(FILE* fp)
{
    fread(header.signature,2,1,fp);
    if(header.signature[0]!='B' || header.signature[1]!='M')
    {
	    printf("Invalid image format");
	    exit(1);
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

    printf("%c%c %u %d %d %d\n", header.signature[0],header.signature[1],header.file_size,header.reserved,h.height,h.width);
    fseek(fp,header.data_offset,SEEK_SET);
}

void create_imageheader(FILE *fpf) 
{
    int a=24;
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
    fwrite(&h.colours_used, 4, 1,fpf);
    fwrite(&h.important_colours, 4, 1,fpf);
}

void Copy_pixels_to_destination(FILE *fpf)
{
    fseek(fpf,header.data_offset,SEEK_SET);
    for(int i=h.height-1; i>=0; i--)
    {
        fwrite(i1.rgb[i],h.width,3,fpf);
    }
}

int main()
{
    FILE *fp = fopen("sample.bmp", "rb");
    FILE *fpf = fopen("output.bmp", "wb");
    read_source(fp);
    create_imageheader(fpf);
    Image_pixel(fp,h.height,h.width);
    Gray_to_rgb(h.height,h.width);
    Copy_pixels_to_destination(fpf);

}
