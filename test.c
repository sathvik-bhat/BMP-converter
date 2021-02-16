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

void read_source()
{
    FILE *fp = fopen("final.bmp", "rb");

    struct Bitmap_Header header;
    struct Info_Header h;
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

    fclose(fp);
}

const int bmpfileheaderSize = 14;
const int bmpinfoheaderSize = 40;

void create_imageheader()
{
	unsigned char bmpfileheader[14] = {
					'B', 'M',	// signature
	       				0, 0, 0, 0, 	// file size
					0, 0, 0, 0, 	// reserved
					54, 0, 0, 0	// data offset
					};
	
	unsigned char bmpinfoheader[40] = {
					40, 0, 0, 0,	// info header size
					0, 0, 0, 0,	// width	
					0, 0, 0, 0,	// height
					1, 0,	// number colour planes
					24, 0	// bits per pixel
					0, 0, 0, 0,	// compression is none
					0, 0, 0, 0,	// image bits size
					0x13, 0x0B, 0, 0,	// horizontal resolution in pixel
					0x13, 0x0B, 0, 0,	// vertical resolution in pixel
					0, 0, 0, 0,	// colours used
					0, 0, 0, 0,	// important colours
					};

	FILE *fpf = fopen("output.bmp", "wb");

	fwrite(bmpfileheader, 1, bmpfileheaderSize, fpf);
	fwrite(bmpinfoheader, 1, bmpinfoheaderSize, fpf);

	fclose(fpf);
}
