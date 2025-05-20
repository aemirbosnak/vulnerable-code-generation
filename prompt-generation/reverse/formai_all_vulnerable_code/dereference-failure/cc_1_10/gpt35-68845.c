//FormAI DATASET v1.0 Category: Image Editor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define BMP_HEADER_SIZE 54
#define BMP_COLOR_TABLE_SIZE 1024

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} pixel;

typedef struct {
    int width;
    int height;
    pixel* pixels;
} image;

image* read_bmp(char* filename);
void write_bmp(char* filename, image* img);
image* apply_filter(image* img, char* filter_name);

int main(int argc, char** argv) {
    if(argc != 4) {
        fprintf(stderr, "Usage: ./image_editor [input_filename] [output_filename] [filter_name]\n");
        return 1;
    }

    char* input_filename = argv[1];
    char* output_filename = argv[2];
    char* filter_name = argv[3];

    image* img = read_bmp(input_filename);
    if(img == NULL) {
        fprintf(stderr, "Unable to read input image file.\n");
        return 1;
    }

    image* filtered_img = apply_filter(img, filter_name);
    if(filtered_img == NULL) {
        fprintf(stderr, "Invalid filter name. Available filters are: grayscale, sepia, negative, blur.\n");
        return 1;
    }

    write_bmp(output_filename, filtered_img);

    free(img->pixels);
    free(img);
    free(filtered_img->pixels);
    free(filtered_img);

    return 0;
}

image* read_bmp(char* filename) {
    FILE* fp = fopen(filename, "rb");
    if(fp == NULL) {
        return NULL;
    }

    uint8_t header[BMP_HEADER_SIZE];
    fread(header, sizeof(uint8_t), BMP_HEADER_SIZE, fp);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bpp = *(uint16_t*)&header[28];

    if(bpp != 24) {
        fclose(fp);
        return NULL;
    }

    pixel* pixels = malloc(sizeof(pixel)*width*height);

    fseek(fp, BMP_HEADER_SIZE, SEEK_SET);
    int row_padding = (4 - (width * sizeof(pixel)) % 4) % 4;
    for(int i = height - 1; i >= 0; i--) {
        for(int j = 0; j < width; j++) {
            fread(&pixels[i*width+j].blue, sizeof(uint8_t), 1, fp);
            fread(&pixels[i*width+j].green, sizeof(uint8_t), 1, fp);
            fread(&pixels[i*width+j].red, sizeof(uint8_t), 1, fp);
        }
        fseek(fp, row_padding, SEEK_CUR);
    }

    fclose(fp);

    image* img = malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->pixels = pixels;

    return img;
}

void write_bmp(char* filename, image* img) {
    FILE* fp = fopen(filename, "wb");

    uint8_t header[BMP_HEADER_SIZE];
    memset(header, 0, BMP_HEADER_SIZE);

    int file_size = img->width*img->height*sizeof(pixel)
                  + BMP_HEADER_SIZE
                  + BMP_COLOR_TABLE_SIZE;

    header[0] = 'B';
    header[1] = 'M';
    *(int*)&header[2] = file_size;
    *(int*)&header[10] = BMP_HEADER_SIZE + BMP_COLOR_TABLE_SIZE;
    *(int*)&header[14] = BMP_HEADER_SIZE;
    *(int*)&header[18] = img->width;
    *(int*)&header[22] = img->height;
    *(uint16_t*)&header[26] = 1;
    *(uint16_t*)&header[28] = 24;

    fwrite(header, sizeof(uint8_t), BMP_HEADER_SIZE, fp);

    uint8_t color_table[BMP_COLOR_TABLE_SIZE];
    memset(color_table, 0, BMP_COLOR_TABLE_SIZE);
    fwrite(color_table, sizeof(uint8_t), BMP_COLOR_TABLE_SIZE, fp);

    int row_padding = (4 - (img->width * sizeof(pixel)) % 4) % 4;
    for(int i = img->height - 1; i >= 0; i--) {
        for(int j = 0; j < img->width; j++) {
            fwrite(&img->pixels[i*img->width+j].blue, sizeof(uint8_t), 1, fp);
            fwrite(&img->pixels[i*img->width+j].green, sizeof(uint8_t), 1, fp);
            fwrite(&img->pixels[i*img->width+j].red, sizeof(uint8_t), 1, fp);
        }
        uint8_t padding[3] = {0};
        fwrite(padding, sizeof(uint8_t), row_padding, fp);
    }

    fclose(fp);
}

image* apply_filter(image* img, char* filter_name) {
    if(strcmp(filter_name, "grayscale") == 0) {
        for(int i = 0; i < img->width*img->height; i++) {
            uint8_t avg = (img->pixels[i].red + img->pixels[i].green + img->pixels[i].blue)/3;
            img->pixels[i].red = avg;
            img->pixels[i].green = avg;
            img->pixels[i].blue = avg;
        }
    } else if(strcmp(filter_name, "sepia") == 0) {
        for(int i = 0; i < img->width*img->height; i++) {
            uint8_t old_r = img->pixels[i].red;
            uint8_t old_g = img->pixels[i].green;
            uint8_t old_b = img->pixels[i].blue;
            uint8_t new_r = 0.393*old_r + 0.769*old_g + 0.189*old_b;
            uint8_t new_g = 0.349*old_r + 0.686*old_g + 0.168*old_b;
            uint8_t new_b = 0.272*old_r + 0.534*old_g + 0.131*old_b;
            img->pixels[i].red = new_r > 255 ? 255 : new_r;
            img->pixels[i].green = new_g > 255 ? 255 : new_g;
            img->pixels[i].blue = new_b > 255 ? 255 : new_b;
        }
    } else if(strcmp(filter_name, "negative") == 0) {
        for(int i = 0; i < img->width*img->height; i++) {
            img->pixels[i].red = 255 - img->pixels[i].red;
            img->pixels[i].green = 255 - img->pixels[i].green;
            img->pixels[i].blue = 255 - img->pixels[i].blue;
        }
    } else if(strcmp(filter_name, "blur") == 0) {
        pixel* new_pixels = malloc(sizeof(pixel)*img->width*img->height);
        for(int i = 0; i < img->width*img->height; i++) {
            pixel* current_pixel = &img->pixels[i];
            int sum_r = 0;
            int sum_g = 0;
            int sum_b = 0;
            int count = 0;
            for(int j = i-2*img->width; j <= i+2*img->width; j += img->width) {
                for(int k = j-2; k <= j+2; k++) {
                    if(k >= 0 && k < img->width*img->height) {
                        pixel* neighboring_pixel = &img->pixels[k];
                        sum_r += neighboring_pixel->red;
                        sum_g += neighboring_pixel->green;
                        sum_b += neighboring_pixel->blue;
                        count++;
                    }
                }
            }
            new_pixels[i].red = sum_r / count;
            new_pixels[i].green = sum_g / count;
            new_pixels[i].blue = sum_b / count;
        }
        free(img->pixels);
        img->pixels = new_pixels;
    } else {
        return NULL;
    }
    return img;
}