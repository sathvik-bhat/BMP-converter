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
    scanf("%s",path);   // input the source file
    FILE *fp = fopen(path, "rb");   // open the source file in read mode
    FILE *fpf = fopen("output.bmp", "wb");  // create and open the destination file in write mode
    read_source(fp);    // read the source file
    create_imageheader(fpf);    // create the header of destination file
    Image_pixel(fp,h.height,h.width);   // read source pixels
    fclose(fp);     // close the source file
    Gray_to_rgb(h.height,h.width);  // converting the 8-bit to 24-bit BMP
    Copy_pixels_to_destination(fpf);    // write the pixels in destination file 
    
    printf("\nConversion is successful. Target image is created in current directory with the name output.bmp\n");
    printf("\nSAMPLE IMAGE DATA\n");
    
    fopen(path,"rb");  // open the source file in read mode
    Print_header_details(fp);  // prints the header details of the source file
    printf("\nOUTPUT IMAGE DATA\n");
    FILE *fps = fopen("output.bmp","rb");  // opens the target file in read mode
    Print_header_details(fps);  // prints the header details of the target file
}
