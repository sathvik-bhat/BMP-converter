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
    // int compression;
    unsigned int compression;
    unsigned int X_pixels_per_m;
    unsigned int Y_pixels_per_m;
    int colours_used;
    int important_colours;
};


void read()
{
    FILE *fp = fopen("sample.bmp","rb");
    struct Bitmap_Header header;
    struct Info_Header h;

    fread(header.signature,2,1,fp);
    fread(&header.file_size,4,1,fp);
    fread(&header.reserved,4,1,fp);
    fread(&h,18,1,fp);
    fread(&h.bits_per_pixel,2,1,fp);


    printf("%c%c %u %d %d", header.signature[0],header.signature[1],header.file_size,header.reserved,h.bits_per_pixel);
}

void write()
{
    FILE *fpf = fopen("final.bmp","wb");
    // struct Bitmap_Header header;
    

    FILE *fp = fopen("screenshot.bmp","rb");
    struct Bitmap_Header header;
    fread(header.signature,2,1,fp);
    fread(&header.file_size,4,1,fp);
    fread(&header.reserved,4,1,fp);
    fread(&header.data_offset,4,1,fp);

    printf("%c%c %u %d %d\n", header.signature[0],header.signature[1],header.file_size,header.reserved,header.data_offset);


    fwrite(header.signature,2,1,fpf);
    fwrite(&header.file_size,4,1,fpf);
    fwrite(&header.reserved,4,1,fpf);
    
    fwrite(&header.data_offset,4,1,fpf);
}


int main()
{
    // write();
    read();
    // printf("%ld",sizeof(short int));
}

