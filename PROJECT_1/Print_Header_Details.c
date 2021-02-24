/* prints details of the image of which pointer is passed */
#include<stdio.h>
#include<stdlib.h>
#include"structures.h"
struct Bitmap_Header header;
struct Info_Header h;
void Print_header_details(FILE *fp)
{
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
    printf("The header signature is: %c%c\n",header.signature[0],header.signature[1]);
    printf("The size of image is: %u\n",header.file_size);
    printf("Reserved: %d\n",header.reserved);
    printf("The bits per pixel of image: %d\n",h.bits_per_pixel);
    printf("Data Offset: %d\n",header.data_offset);
    printf("Size: %u\n",h.size);
    printf("Width: %u\n",h.width);
    printf("Height: %u\n",h.height);
    printf("Planes: %d\n",h.planes);
    printf("Compression: %u\n",h.compression);
    printf("Image size: %u\n",h.image_size);
    printf("X_pixels_per_m: %u\n",h.X_pixels_per_m);
    printf("Y_pixels_per_m: %u\n",h.Y_pixels_per_m);
    printf("Colours_used: %d\n",h.colours_used);
    printf("Important_colours: %d\n",h.important_colours);
   
}
