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
	char Reseved;
};

struct Image_24_bit
{
	int height;
	int width;
	struct RGB **rgb;
};