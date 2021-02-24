/* Bitmap header which is of the size 14 bytes */
struct Bitmap_Header
{
    char signature[2];	// Magic identifier that specifies the file type i.e. BM for any bitmap file
    unsigned int file_size;	// size of the file
    int reserved;
    int data_offset; 	// specifies the offset in bytes from the bitmapfileheader to the bitmap bits
};

/* Bitmap Information header is of the size 40 bytes*/
struct Info_Header
{
    unsigned int size;	// size of the info header
    unsigned int width;	// width of the pixels
    unsigned int height;	// height of the pixels
    short int planes;	// specifies the number of color planes, must be 1
    short int bits_per_pixel;	// specifies the number of bit per pixel
    unsigned int compression;	// spcifies the type of compression
    unsigned int image_size;	// spcifies the type of compression
    unsigned int X_pixels_per_m;	// number of pixels per meter in x axis
    unsigned int Y_pixels_per_m;	// number of pixels per meter in y axis
    int colours_used;	// number of colors used by the bitmap
    int important_colours;	// number of colors that are important

};

struct Greyscale
{
	char greyscale;
};

struct Image_8_bit
{	
	int height;
	int width;
	struct Greyscale **g;
};

struct RGB
{
	char Blue;
	char Green;
	char Red;
	// char Reseved;
};

struct Image_24_bit
{
	int height;
	int width;
	struct RGB **rgb;
};
