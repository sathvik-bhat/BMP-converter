#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"structures.h"
#include"Function_Declarations.h"
struct Info_Header h;
int main()
{
    char path[255];
    printf("Enter Name or Path of Image: ");
    scanf("%s",path);
    FILE *fp = fopen(path, "rb");
    FILE *fpf = fopen("output.bmp", "wb");
    read_source(fp);
    create_imageheader(fpf);
    Image_pixel(fp,h.height,h.width);
    fclose(fp);
    Gray_to_rgb(h.height,h.width);
    Copy_pixels_to_destination(fpf);
    printf("\nConversion is successful. Target image is created in current directory with the name output.bmp\n");
    printf("\nSAMPLE IMAGE DATA\n");
    fopen("sample2.bmp","rb");
    Print_header_details(fp);
    printf("\nOUTPUT IMAGE DATA\n");
    FILE *fps = fopen("output.bmp","rb");
    Print_header_details(fps);
}
