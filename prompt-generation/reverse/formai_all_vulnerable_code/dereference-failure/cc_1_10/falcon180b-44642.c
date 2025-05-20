//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512
#define IMAGE_SIZE (WIDTH*HEIGHT)
#define CHANNELS 3
#define WATERMARK_SIZE 50
#define MAX_VALUE 255

// Function to add watermark to image
void add_watermark(unsigned char* image, unsigned char* watermark) {
    int i, j, k;
    int x, y;
    int watermark_x, watermark_y;
    int watermark_size = strlen(watermark)/CHANNELS;
    int image_size = WIDTH*HEIGHT;

    for (i=0; i<CHANNELS; i++) {
        for (j=0; j<watermark_size; j++) {
            for (k=0; k<watermark_size; k++) {
                x = (i*WATERMARK_SIZE) + j;
                y = (k*WATERMARK_SIZE) + j;
                if (x < WIDTH && y < HEIGHT) {
                    int index = (y*WIDTH + x) * CHANNELS + i;
                    int watermark_index = (k*watermark_size + j) * CHANNELS + i;
                    image[index] += watermark[watermark_index];
                }
            }
        }
    }
}

// Function to read image file
unsigned char* read_image(char* filename) {
    FILE* fp;
    unsigned char* image;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    image = (unsigned char*) malloc(filesize);
    fread(image, filesize, 1, fp);

    fclose(fp);

    return image;
}

// Function to write image file
void write_image(char* filename, unsigned char* image) {
    FILE* fp;

    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fwrite(image, IMAGE_SIZE, 1, fp);

    fclose(fp);
}

// Function to generate random watermark
void generate_watermark(char* watermark) {
    int i;

    for (i=0; i<strlen(watermark); i++) {
        watermark[i] = rand() % 26 + 'a';
    }

    watermark[strlen(watermark)-1] = '\0';
}

// Function to get current time as string
char* get_current_time() {
    time_t now = time(NULL);
    struct tm* tm = localtime(&now);
    char time_str[80];

    strftime(time_str, 80, "%Y%m%d%H%M%S", tm);

    return strdup(time_str);
}

int main() {
    // Read image file
    unsigned char* image = read_image("image.bmp");

    // Generate random watermark
    char* watermark = (char*) malloc(WATERMARK_SIZE+1);
    generate_watermark(watermark);

    // Add watermark to image
    add_watermark(image, watermark);

    // Write watermarked image to file
    char* filename = (char*) malloc(100);
    sprintf(filename, "watermarked_%s.bmp", get_current_time());
    write_image(filename, image);

    printf("Watermarked image saved as %s\n", filename);

    free(watermark);
    free(filename);
    free(image);

    return 0;
}