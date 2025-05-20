//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to embed watermark into image file
void embed_watermark(char* original_file, char* watermark_file) {
    FILE *infile, *outfile;
    unsigned char *img, *watermark;
    int len_img, len_watermark, i, j;

    // Open input files
    infile = fopen(original_file, "rb");
    watermark = (unsigned char*) malloc(sizeof(unsigned char) * 1000);
    infile = fopen(watermark_file, "rb");
    watermark = (unsigned char*) malloc(sizeof(unsigned char) * 1000);

    // Read original image file
    fread(&img, sizeof(unsigned char), 1000, infile);
    fclose(infile);

    // Read watermark file
    fread(&watermark, sizeof(unsigned char), 1000, infile);
    fclose(infile);

    // Set length of watermark
    len_watermark = 1000;

    // Update original image file with embedded watermark
    outfile = fopen(original_file, "wb");
    for (i = 0; i < 1000; i++) {
        if (i < len_watermark) {
            fprintf(outfile, "%02X", watermark[i]);
        } else {
            fprintf(outfile, "%02X", img[i]);
        }
    }
    fclose(outfile);
    free(img);
    free(watermark);
}

// Function to extract watermark from image file
void extract_watermark(char* original_file, char* output_file) {
    FILE *infile, *outfile;
    unsigned char *img, *watermark;
    int len_img, len_watermark, i, j;

    // Open input files
    infile = fopen(original_file, "rb");
    img = (unsigned char*) malloc(sizeof(unsigned char) * 1000);
    infile = fopen(output_file, "wb");
    watermark = (unsigned char*) malloc(sizeof(unsigned char) * 1000);

    // Read original image file
    fread(&img, sizeof(unsigned char), 1000, infile);
    fclose(infile);

    // Set length of watermark
    len_watermark = 1000;

    // Read watermark from original image file
    for (i = 0; i < 1000; i++) {
        if (i < len_watermark) {
            fprintf(outfile, "%02X", img[i]);
        } else {
            fprintf(outfile, "%02X", watermark[i]);
        }
    }
    fclose(outfile);
    free(img);
    free(watermark);
}

int main() {
    char original_file[] = "original.jpg";
    char watermark_file[] = "watermark.jpg";
    char output_file[] = "output.jpg";

    // Embed watermark into original image file
    embed_watermark(original_file, watermark_file);

    // Extract watermark from original image file
    extract_watermark(original_file, output_file);

    return 0;
}