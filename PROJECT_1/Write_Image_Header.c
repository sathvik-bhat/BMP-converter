#include<stdio.h>
#include<math.h>
#include"structures.h"

struct Bitmap_Header header;
struct Info_Header h;

void create_imageheader(FILE *fpf) 
{
    int a=24;     
    int b=pow(2,24);
    
    /* Writing the Bitmap header of destination file */
    fwrite(header.signature,2,1,fpf);   // writing the signature of BMP file
    fwrite(&header.file_size,4,1,fpf);  // size of the file
    fwrite(&header.reserved,4,1,fpf);   
    fwrite(&header.data_offset,4,1,fpf);    // write the offset data pixel byte
    
    /* Writing the Bitmap Information header of destination file */
    fwrite(&h.size, 4, 1, fpf); // size of the bitmap info header
    fwrite(&h.width, 4, 1,fpf); // width of destination will be same as source
    fwrite(&h.height, 4, 1,fpf);    // height of destination will be same as source
    fwrite(&h.planes, 2, 1,fpf);    // colour planes which should be 1
    fwrite(&a,2,1,fpf); // assigning bits per pixel as 24 to the destination file
    fwrite(&h.compression, 4, 1,fpf);   // compression
    fwrite(&h.image_size, 4, 1,fpf);    // size of the image
    fwrite(&h.X_pixels_per_m, 4, 1,fpf);    // horizontal resolution
    fwrite(&h.Y_pixels_per_m, 4, 1,fpf);    // vertical resolution
    fwrite(&b, 4, 1,fpf);   // number of colours involved is 2^24
    fwrite(&h.important_colours, 4, 1,fpf);
}
