//FormAI DATASET v1.0 Category: Image Editor ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>

#define MAX_COLOR 255

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel* pixels;
} Image;

Pixel create_pixel(unsigned char r, unsigned char g, unsigned char b) {
    Pixel pix;
    pix.r = r;
    pix.g = g;
    pix.b = b;
    return pix;
}

Image* create_image(int width, int height) {
    Image* img = (Image*)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->pixels = (Pixel*)malloc(width*height*sizeof(Pixel));
    return img;
}

void set_pixel(Image* img, int x, int y, Pixel pix) {
    img->pixels[y*img->width + x] = pix;
}

Pixel get_pixel(Image* img, int x, int y) {
    return img->pixels[y*img->width + x];
}

Image* load_image(const char* filename){
    FILE* infile = fopen(filename, "rb");
    if (infile == NULL) {
        fprintf(stderr, "Error loading file %s\n", filename);
        exit(1);
    }
    char magic[3];
    fscanf(infile, "%2s\n", magic);
    if (strcmp(magic, "P6")) {
        fprintf(stderr, "Error loading file %s: Invalid PPM format (only P6 is supported)\n", filename);
        exit(1);
    }
    int width, height, max_color;
    fscanf(infile, "%d %d\n%d\n", &width, &height, &max_color);
    Image* img = create_image(width, height);
    unsigned char* data = (unsigned char*)malloc(3*width*height*sizeof(unsigned char));
    fread(data, sizeof(unsigned char), 3*width*height, infile);
    fclose(infile);

    int i, j;
    for (i = 0; i < height; ++i) {
        for (j = 0; j < width; ++j) {
            Pixel pix = create_pixel(data[3*(i*width + j)], data[3*(i*width+j)+1], data[3*(i*width+j)+2]);
            set_pixel(img,j,i,pix);
        }
    }

    free(data);
    return img;
}

void save_image(Image* img, const char* filename) {
    FILE* outfile = fopen(filename, "wb");
    fprintf(outfile, "P6\n%d %d\n%d\n", img->width, img->height, MAX_COLOR);
    fwrite(img->pixels, sizeof(unsigned char), 3*img->width*img->height, outfile);
    fclose(outfile);
}

void grayscale(Image* img) {
    int i, j;
    for (i = 0; i < img->height; ++i) {
        for (j = 0; j < img->width; ++j) {
            Pixel pix = get_pixel(img, j, i);
            unsigned char grayscale = 0.299*pix.r + 0.587*pix.g + 0.114*pix.b;
            set_pixel(img,j,i,create_pixel(grayscale,grayscale,grayscale));
        }
    }
}

void rotate(Image* img) {
    int i, j;
    Image* rotated = create_image(img->height, img->width);
    for (i = 0; i < img->height; ++i) {
        for (j = 0; j < img->width; ++j) {
            set_pixel(rotated, i, j, get_pixel(img, j, img->height-1-i));
        }
    }
    memcpy(img->pixels, rotated->pixels, img->width*img->height*sizeof(Pixel));
    img->width = rotated->width;
    img->height = rotated->height;
    free(rotated);
}

void color_swap(Image* img) {
    int i, j;
    for (i = 0; i < img->height; ++i) {
        for (j = 0; j < img->width; ++j) {
            Pixel pix = get_pixel(img, j, i);
            set_pixel(img,j,i,create_pixel(pix.g, pix.b, pix.r));
        }
    }
}

void invert_colors(Image* img) {
    int i, j;
    for (i = 0; i < img->height; ++i) {
        for (j = 0; j < img->width; ++j) {
            Pixel pix = get_pixel(img, j, i);
            set_pixel(img,j,i,create_pixel(255-pix.r, 255-pix.g, 255-pix.b));
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s inputfile outputfile\n", argv[0]);
        exit(1);
    }
    printf("Loading image...\n");
    Image* img = load_image(argv[1]);
    printf("Image loaded.\n");

    printf("Applying filter 1...\n");
    grayscale(img);
    printf("Filter applied.\n");

    printf("Applying filter 2...\n");
    rotate(img);
    printf("Filter applied.\n");

    printf("Applying filter 3...\n");
    color_swap(img);
    printf("Filter applied.\n");

    printf("Applying filter 4...\n");
    invert_colors(img);
    printf("Filter applied.\n");

    printf("Saving image...\n");
    save_image(img, argv[2]);
    printf("Image saved as %s.\n", argv[2]);
    free(img->pixels);
    free(img);
    return 0;
}