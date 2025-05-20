//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK_SIZE 32   // watermark size in bits
#define PIXEL_SIZE 3        // pixel size in bytes (for RGB image)
#define MAX_FILENAME 100    // max filename length

// function to hide watermark in an image
void hide_watermark(char *image_filename, char *watermark, char *output_filename) {
    FILE *image_file, *output_file;    // file pointers
    unsigned char header[54];           // BMP header
    int width, height, padding, image_size, watermark_index;
    unsigned char *image_data, *watermark_bits, *output_data;

    // open image file for reading in binary mode
    image_file = fopen(image_filename, "rb");
    if (image_file == NULL) {
        printf("Error: could not open image file %s\n", image_filename);
        exit(EXIT_FAILURE);
    }

    // read BMP header
    fread(header, sizeof(unsigned char), 54, image_file);
    width = *(int *)&header[18];        // extract width from header
    height = *(int *)&header[22];       // extract height from header
    padding = (4 - (width * PIXEL_SIZE) % 4) % 4;   // calculate padding
    image_size = (width * PIXEL_SIZE + padding) * height;  // calculate image size
    image_data = (unsigned char *)malloc(image_size);     // allocate memory for image data
    fread(image_data, sizeof(unsigned char), image_size, image_file);   // read image data
    fclose(image_file);

    // open output file for writing in binary mode
    output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("Error: could not open output file %s\n", output_filename);
        exit(EXIT_FAILURE);
    }

    // allocate memory for output data
    output_data = (unsigned char *)malloc(image_size);

    // copy BMP header to output file
    fwrite(header, sizeof(unsigned char), 54, output_file);

    // convert watermark string into bit array
    watermark_bits = (unsigned char *)malloc(WATERMARK_SIZE);
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        watermark_bits[i] = (watermark[i/8] >> (i%8)) & 1;
    }

    // hide watermark in LSB of each color channel of each pixel
    watermark_index = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < PIXEL_SIZE; k++) {
                output_data[(i*width*PIXEL_SIZE) + (j*PIXEL_SIZE) + k] = image_data[(i*width*PIXEL_SIZE) + (j*PIXEL_SIZE) + k];
                if (watermark_index < WATERMARK_SIZE) {
                    // overwrite least significant bit with watermark bit
                    output_data[(i*width*PIXEL_SIZE) + (j*PIXEL_SIZE) + k] &= 0xFE;    // set LSB to 0
                    output_data[(i*width*PIXEL_SIZE) + (j*PIXEL_SIZE) + k] |= watermark_bits[watermark_index];  // set LSB to watermark bit
                    watermark_index++;
                }
            }
        }
        // skip padding bytes
        for (int k = 0; k < padding; k++) {
            output_data[(i*width*PIXEL_SIZE) + (width*PIXEL_SIZE) + k] = 0;
        }
    }

    // write output data to output file
    fwrite(output_data, sizeof(unsigned char), image_size, output_file);

    // close output file
    fclose(output_file);

    // free memory
    free(image_data);
    free(output_data);
    free(watermark_bits);
}

// function to extract watermark from an image
char *extract_watermark(char *image_filename) {
    FILE *image_file;   // file pointer
    unsigned char header[54];           // BMP header
    int width, height, padding, image_size, watermark_index;
    unsigned char *image_data, *watermark_bits;
    char *watermark;

    // open image file for reading in binary mode
    image_file = fopen(image_filename, "rb");
    if (image_file == NULL) {
        printf("Error: could not open image file %s\n", image_filename);
        exit(EXIT_FAILURE);
    }

    // read BMP header
    fread(header, sizeof(unsigned char), 54, image_file);
    width = *(int *)&header[18];        // extract width from header
    height = *(int *)&header[22];       // extract height from header
    padding = (4 - (width * PIXEL_SIZE) % 4) % 4;   // calculate padding
    image_size = (width * PIXEL_SIZE + padding) * height;  // calculate image size
    image_data = (unsigned char *)malloc(image_size);     // allocate memory for image data
    fread(image_data, sizeof(unsigned char), image_size, image_file);   // read image data
    fclose(image_file);

    // convert LSB of each color channel of each pixel into bit array
    watermark_bits = (unsigned char *)malloc(WATERMARK_SIZE);
    watermark_index = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < PIXEL_SIZE; k++) {
                if (watermark_index < WATERMARK_SIZE) {
                    // extract LSB from color channel and store in bit array
                    watermark_bits[watermark_index] = image_data[(i*width*PIXEL_SIZE) + (j*PIXEL_SIZE) + k] & 1;
                    watermark_index++;
                }
            }
        }
        // skip padding bytes
        for (int k = 0; k < padding; k++) {
            image_data[(i*width*PIXEL_SIZE) + (width*PIXEL_SIZE) + k] = 0;
        }
    }

    // convert bit array into string
    watermark = (char *)malloc(WATERMARK_SIZE/8 + 1);
    watermark[WATERMARK_SIZE/8] = '\0';
    for (int i = 0; i < WATERMARK_SIZE/8; i++) {
        watermark[i] = 0;
        for (int j = 0; j < 8; j++) {
            watermark[i] |= watermark_bits[(i*8)+j] << j;
        }
    }

    // free memory and return watermark string
    free(image_data);
    free(watermark_bits);
    return watermark;
}

int main() {
    char image_filename[MAX_FILENAME], watermark[MAX_FILENAME], output_filename[MAX_FILENAME];

    // get image filename from user
    printf("Enter image filename: ");
    scanf("%s", image_filename);

    // get watermark string from user
    printf("Enter watermark string: ");
    scanf("%s", watermark);

    // hide watermark in image and save to output file
    sprintf(output_filename, "%s_watermarked.bmp", image_filename);
    hide_watermark(image_filename, watermark, output_filename);
    printf("Watermark hidden in %s and saved to %s\n", image_filename, output_filename);

    // extract watermark from image
    printf("Extracting watermark from %s...\n", output_filename);
    char *extracted_watermark = extract_watermark(output_filename);
    printf("Extracted watermark: %s\n", extracted_watermark);

    // free memory
    free(extracted_watermark);

    return 0;
}