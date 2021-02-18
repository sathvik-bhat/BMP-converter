#include<stdio.h>
#include<stdlib.h>
struct Bitmap_Header
{
    char signature[2];
    unsigned int file_size;
    int reserved;
    int data_offset; 
};
struct Info_Header
{
    unsigned int size;
    unsigned int width;
    unsigned int height;
    short int planes;
    short int bits_per_pixel;
    unsigned int compression;
    unsigned int image_size;
    unsigned int X_pixels_per_m;
    unsigned int Y_pixels_per_m;
    int colours_used;
    int important_colours;
};

struct Bitmap_Header header;
struct Info_Header h;

void read_source()
{
    FILE *fp = fopen("sample.bmp", "rb");

    fread(header.signature,2,1,fp);
    fread(&header.file_size,4,1,fp);
    fread(&header.reserved,4,1,fp);
    fread(&header.data_offset,4,1,fp);
    fread(&h.size, 4, 1, fp);
    fread(&h.width, 4, 1,fp);
    fread(&h.height, 4, 1,fp);
    fread(&h.planes, 2, 1,fp);
    fread(&h.bits_per_pixel,2,1,fp);
    fread(&h.compression, 4, 1,fp);
    fread(&h.image_size, 4, 1,fp);
    fread(&h.X_pixels_per_m, 4, 1,fp);
    fread(&h.Y_pixels_per_m, 4, 1,fp);
    fread(&h.colours_used, 4, 1,fp);
    fread(&h.important_colours, 4, 1,fp);

    printf("%c%c %u %d %d\n", header.signature[0],header.signature[1],header.file_size,header.reserved,h.bits_per_pixel);

    fclose(fp);
}

void read_output()
{
    FILE *fpo = fopen("output.bmp", "rb");

    fread(header.signature,2,1,fpo);
    fread(&header.file_size,4,1,fpo);
    fread(&header.reserved,4,1,fpo);
    fread(&header.data_offset,4,1,fpo);
    fread(&h.size, 4, 1, fpo);
    fread(&h.width, 4, 1,fpo);
    fread(&h.height, 4, 1,fpo);
    fread(&h.planes, 2, 1,fpo);
    fread(&h.bits_per_pixel,2,1,fpo);
    fread(&h.compression, 4, 1,fpo);
    fread(&h.image_size, 4, 1,fpo);
    fread(&h.X_pixels_per_m, 4, 1,fpo);
    fread(&h.Y_pixels_per_m, 4, 1,fpo);
    fread(&h.colours_used, 4, 1,fpo);
    fread(&h.important_colours, 4, 1,fpo);

    printf("%c%c %u %d %d \n", header.signature[0],header.signature[1],header.file_size,header.reserved,h.bits_per_pixel);

    fclose(fpo);
}


const int bmpfileheaderSize = 14;
const int bmpinfoheaderSize = 40;

void create_imageheader() //struct Bitmap_Header header, struct Info_Header h
{
	// unsigned char bmpfileheader[14] = {
	// 				'B', 'M',	// signature
	//        				0, 0, 0, 0, 	// file size
	// 				0, 0, 0, 0, 	// reserved
	// 				54, 0, 0, 0	// data offset
	// 				};
	
	// unsigned char bmpinfoheader[40] = {
	// 				40, 0, 0, 0,	// info header size
	// 				0, 0, 0, 0,	// width	
	// 				0, 0, 0, 0,	// height
	// 				1, 0,	// number colour planes
	// 				24, 0,	// bits per pixel
	// 				0, 0, 0, 0,	// compression is none
	// 				0, 0, 0, 0,	// image bits size
	// 				0x13, 0x0B, 0, 0,	// horizontal resolution in pixel
	// 				0x13, 0x0B, 0, 0,	// vertical resolution in pixel
	// 				0, 0, 0, 0,	// colours used
	// 				0, 0, 0, 0,	// important colours
	// 				};

	FILE *fpf = fopen("output.bmp", "wb");
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

	// fwrite(bmpfileheader, 1, bmpfileheaderSize, fpf);
	// fwrite(bmpinfoheader, 1, bmpinfoheaderSize, fpf);

	fclose(fpf);
}

void Copy_pixels_to_destination(int arr[h.height][h.width])
{
    FILE *fpf = fopen("output.bmp", "wb");
    fseek(fpf,0,header.data_offset);
    for(int i=0; i<h.height; i++)
    {
        for (int j=0; j<h.width; j++)
        {
            fwrite(&arr[i][j],3,1,fpf);
        }
    }
}

int main()
{
    // struct Bitmap_Header header; struct Info_Header h;
    read_source();
    create_imageheader();
    read_output();
}
