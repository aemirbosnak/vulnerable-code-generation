//FormAI DATASET v1.0 Category: Image compression ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to C Image Compression program!!\n");  
    printf("This program will take in an uncompressed picture and compress it by reducing its size.\n");
    printf("Exciting, isn't it?\n");

    FILE *infile, *outfile;
    char original_image[] = "original_image.bmp";
    char compressed_image[] = "compressed_image.bmp";
    long file_size, width, height;
    unsigned char *header;

    infile = fopen(original_image, "rb");
    outfile = fopen(compressed_image, "wb");

    if (infile == NULL) {
        printf("Error: couldn't open %s.\n", original_image);
        return 1;
    }

    if (outfile == NULL) {
        printf("Error: couldn't open %s.\n", compressed_image);
        return 1;
    }

    // Get the file size
    fseek(infile, 0, SEEK_END);
    file_size = ftell(infile);
    fseek(infile, 0, SEEK_SET);

    // Read the header
    header = (unsigned char*) malloc(sizeof(unsigned char)*54);
    fread(header, sizeof(unsigned char), 54, infile);

    // Get the width and height of the image
    width = *(int*)&header[18];
    height = *(int*)&header[22];

    printf("The original image is %ld bytes in size.\n", file_size);
    printf("The original image is %ld pixels wide and %ld pixels tall.\n", width, height);

    // Compress the image
    unsigned char *buffer;
    long new_size, compressed_width, compressed_height, i, j, k;
    int count;

    compressed_width = width / 2;
    compressed_height = height / 2;
    new_size = compressed_width * compressed_height * 3;

    buffer = (unsigned char*) malloc(sizeof(unsigned char) * width * height * 3);
    fread(buffer, sizeof(unsigned char), width * height * 3, infile);

    unsigned char *compressed;
    compressed = (unsigned char*) malloc(sizeof(unsigned char) * new_size);

    count = 0;
    for (i = 0; i < height; i += 2) {
        for (j = 0; j < width; j += 2) {
            for (k = 0; k < 3; k++) {
                compressed[count] = buffer[(i * width + j) * 3 + k];
                compressed[count+1] = buffer[(i * width + j+1) * 3 + k];
                compressed[count+2] = buffer[((i+1) * width + j) * 3 + k];
                compressed[count+3] = buffer[((i+1) * width + j+1) * 3 + k];
                count += 4;
            }
        }
    }

    fwrite(header, sizeof(unsigned char), 54, outfile);
    fwrite(compressed, sizeof(unsigned char), new_size, outfile);

    fclose(infile);
    fclose(outfile);
    free(header);
    free(buffer);
    free(compressed);

    printf("\nThe compressed image is successfully generated and saved in %s!!\n", compressed_image);
    printf("The compressed image is %ld bytes in size.\n", new_size);

    return 0;
}