//FormAI DATASET v1.0 Category: Image Editor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_IMAGE_WIDTH 1920
#define MAX_IMAGE_HEIGHT 1080

//Structure to hold pixel data for each pixel
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel_t;

//Structure to hold image data
typedef struct {
    pixel_t *pixels;
    int width;
    int height;
} image_t;

//Function to read image from file
int read_image(const char* filename, image_t *img) {
    FILE *fp = fopen(filename, "rb");
    if(fp == NULL) {
        fprintf(stderr, "Error: Could not open file %s: %s\n", filename, strerror(errno));
        return -1;
    }

    //Reading header of BMP file
    fseek(fp, 0x12, SEEK_SET); //Skip 18 bytes
    img->width = fgetc(fp);
    img->width |= fgetc(fp) << 8;
    img->height = fgetc(fp);
    img->height |= fgetc(fp) << 8;
    fseek(fp, 0x2e, SEEK_SET); //Skip 46 bytes

    //Allocating memory for pixel data
    img->pixels = malloc(img->width * img->height * sizeof(pixel_t));
    if(img->pixels == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for image pixels\n");
        fclose(fp);
        return -1;
    }

    //Reading pixel data
    int i,j,k;
    for(i = 0; i < img->height; i++) {
        for(j = 0; j < img->width; j++) {
            k = img->width * (img->height - i - 1) + j;
            img->pixels[k].blue = fgetc(fp);
            img->pixels[k].green = fgetc(fp);
            img->pixels[k].red = fgetc(fp);
        }
        fseek(fp, img->width % 4, SEEK_CUR); //Skip padding bytes
    }

    fclose(fp);
    return 0;
}

//Function to write image to file
int write_image(const char* filename, image_t img) {
    FILE *fp = fopen(filename, "wb");
    if(fp == NULL) {
        fprintf(stderr, "Error: Could not open file %s: %s\n", filename, strerror(errno));
        return -1;
    }

    //Writing header of BMP file
    fputc('B', fp);
    fputc('M', fp);
    int file_size = 54 + 3 * img.width * img.height + (img.width % 4) * img.height;
    fputc(file_size, fp);
    fputc(file_size >> 8, fp);
    fputc(file_size >> 16, fp);
    fputc(file_size >> 24, fp);
    fputc(0, fp);
    fputc(0, fp);
    fputc(0, fp);
    fputc(0, fp);
    int data_offset = 54;
    fputc(data_offset, fp);
    fputc(data_offset >> 8, fp);
    fputc(data_offset >> 16, fp);
    fputc(data_offset >> 24, fp);
    int dib_header_size = 40;
    fputc(dib_header_size, fp);
    fputc(dib_header_size >> 8, fp);
    fputc(dib_header_size >> 16, fp);
    fputc(dib_header_size >> 24, fp);
    fputc(img.width, fp);
    fputc(img.width >> 8, fp);
    fputc(img.width >> 16, fp);
    fputc(img.width >> 24, fp);
    fputc(img.height, fp);
    fputc(img.height >> 8, fp);
    fputc(img.height >> 16, fp);
    fputc(img.height >> 24, fp);
    fputc(1, fp);
    fputc(0, fp);
    int bpp = 24;
    fputc(bpp, fp);
    fputc(bpp >> 8, fp);
    fputc(0, fp);
    fputc(0, fp);
    int data_size = 3 * img.width * img.height + (img.width % 4) * img.height;
    fputc(data_size, fp);
    fputc(data_size >> 8, fp);
    fputc(data_size >> 16, fp);
    fputc(data_size >> 24, fp);
    fputc(0, fp);
    fputc(0, fp);
    fputc(0, fp);
    fputc(0, fp);
    int i,j,k;
    for(i = 0; i < img.height; i++) {
        for (j = 0; j < img.width; j++) {
            k = img.width * (img.height - i - 1) + j;
            fputc(img.pixels[k].blue, fp);
            fputc(img.pixels[k].green, fp);
            fputc(img.pixels[k].red, fp);
        }
        int padding = img.width % 4;
        while (padding != 0) {
            fputc(0, fp);
            padding--;
        }
    }
    fclose(fp);
    return 0;
}

//Function to apply gray scale filter to image
void gray_scale_filter(image_t *img) {
    int i,j,k;
    for(i = 0; i < img->height; i++) {
        for(j = 0; j < img->width; j++) {
            k = img->width * i + j;
            unsigned char gray = (img->pixels[k].red + img->pixels[k].green + img->pixels[k].blue) / 3;
            img->pixels[k].red = gray;
            img->pixels[k].green = gray;
            img->pixels[k].blue = gray;
        }
    }
}

//Function to apply color invert filter to image
void color_invert_filter(image_t *img) {
    int i,j,k;
    for(i = 0; i < img->height; i++) {
        for(j = 0; j < img->width; j++) {
            k = img->width * i + j;
            img->pixels[k].red = 255 - img->pixels[k].red;
            img->pixels[k].green = 255 - img->pixels[k].green;
            img->pixels[k].blue = 255 - img->pixels[k].blue;
        }
    }
}

int main(int argc, char* argv[]) {
    char input_file[MAX_FILE_NAME_LENGTH];
    char output_file[MAX_FILE_NAME_LENGTH];
    image_t img;
    int choice;
    if (argc != 3) {
        printf("ERROR: Please provide two arguments - the input file and the output file\n");
        return -1;
    }
    strncpy(input_file, argv[1], MAX_FILE_NAME_LENGTH);
    strncpy(output_file, argv[2], MAX_FILE_NAME_LENGTH);

    if(read_image(input_file, &img) == -1) {
        return -1;
    }

    printf("Choose a filter to apply to the image:\n");
    printf("1. Gray Scale Filter\n");
    printf("2. Color Invert Filter\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1: {
            gray_scale_filter(&img);
            break;
        }
        case 2: {
            color_invert_filter(&img);
            break;
        }
        default: {
            printf("Invalid choice\n");
            return -1;
        }
    }

    if(write_image(output_file, img) == -1) {
        return -1;
    }

    free(img.pixels);
    return 0;
}