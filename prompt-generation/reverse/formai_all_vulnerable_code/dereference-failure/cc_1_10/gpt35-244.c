//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Functions to flip and change brightness/contrast of an image */

/* Flip image horizontally */
void flip_horizontally(unsigned char image[], int width, int height, int channels)
{
    int i, j, k;
    unsigned char temp;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width/2; j++) {
            for (k = 0; k < channels; k++) {
                temp = image[i*width*channels + j*channels + k];
                image[i*width*channels + j*channels + k] = image[i*width*channels + (width-j-1)*channels + k];
                image[i*width*channels + (width-j-1)*channels + k] = temp;
            }
        }
    }
}

/* Increase or decrease brightness of image */
void adjust_brightness(unsigned char image[], int width, int height, int channels, double factor)
{
    int i, j, k;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            for (k = 0; k < channels; k++) {
                image[i*width*channels + j*channels + k] = (unsigned char)(factor*image[i*width*channels + j*channels + k]);
            }
        }
    }
}

/* Increase or decrease contrast of image */
void adjust_contrast(unsigned char image[], int width, int height, int channels, double factor)
{
    int i, j, k;
    double avg;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            avg = 0.0;
            for (k = 0; k < channels; k++) {
                avg += (double)image[i*width*channels + j*channels + k];
            }
            avg /= (double)channels;
            for (k = 0; k < channels; k++) {
                image[i*width*channels + j*channels + k] = (unsigned char)(factor*(image[i*width*channels + j*channels + k] - avg) + avg);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    char *filename;
    FILE *fp;
    unsigned char *image;
    int width, height, channels, file_size;
    double brightness_factor, contrast_factor;
    if (argc < 5) {
        printf("Usage: %s <filename> <brightness factor> <contrast factor> <0 or 1 to flip horizontally>\n", argv[0]);
        return 1;
    }
    filename = argv[1];
    brightness_factor = atof(argv[2]);
    contrast_factor = atof(argv[3]);
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Could not open file: %s\n", filename);
        return 2;
    }
    fseek(fp, 0L, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    image = (unsigned char*)malloc(file_size);
    fread(image, 1, file_size, fp);
    fclose(fp);
    /* Extract image metadata */
    width = (*(int*)&image[18]);
    height = (*(int*)&image[22]);
    channels = ((int)image[28])/8;
    /* Perform operations */
    if (atoi(argv[4]) == 1) {
        flip_horizontally(image+54, width, height, channels);
    }
    adjust_brightness(image+54, width, height, channels, brightness_factor);
    adjust_contrast(image+54, width, height, channels, contrast_factor);
    /* Save modified image */
    fp = fopen("modified_image.bmp", "wb");
    fwrite(image, 1, file_size, fp);
    fclose(fp);
    free(image);
    return 0;
}