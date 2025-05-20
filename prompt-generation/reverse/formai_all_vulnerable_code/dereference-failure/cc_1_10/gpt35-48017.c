//FormAI DATASET v1.0 Category: Image Steganography ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

/* Structure to hold RGB values */
typedef struct RGB_Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} RGB_Pixel;

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <cover image> <secret image> <output image>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    /* Read the cover image */
    FILE *cover_image_fp = fopen(argv[1], "rb");
    if (cover_image_fp == NULL) {
        printf("Unable to open cover image.\n");
        exit(EXIT_FAILURE);
    }
    /* Get image dimensions */
    int cover_image_width, cover_image_height;
    fseek(cover_image_fp, 18, SEEK_SET);
    int bytes_read = fread(&cover_image_width, sizeof(int), 1, cover_image_fp);
    bytes_read = fread(&cover_image_height, sizeof(int), 1, cover_image_fp);
    /* Skip image info */
    fseek(cover_image_fp, 28, SEEK_SET);
    
    /* Read the secret image */
    FILE *secret_image_fp = fopen(argv[2], "rb");
    if (secret_image_fp == NULL) {
        printf("Unable to open secret image.\n");
        exit(EXIT_FAILURE);
    }
    /* Get image dimensions */
    int secret_image_width, secret_image_height;
    fseek(secret_image_fp, 18, SEEK_SET);
    bytes_read = fread(&secret_image_width, sizeof(int), 1, secret_image_fp);
    bytes_read = fread(&secret_image_height, sizeof(int), 1, secret_image_fp);
    /* Skip image info */
    fseek(secret_image_fp, 28, SEEK_SET);
    
    if (cover_image_width * cover_image_height < secret_image_width * secret_image_height) {
        printf("Secret image is too large for cover image.\n");
        exit(EXIT_FAILURE);
    }
    
    /* Create output file */
    FILE *output_image_fp = fopen(argv[3], "wb");
    if (output_image_fp == NULL) {
        printf("Unable to create output image.\n");
        exit(EXIT_FAILURE);
    }
    
    /* Write cover image info to output image */
    fseek(cover_image_fp, 0, SEEK_SET);
    unsigned char buffer[54];
    bytes_read = fread(buffer, sizeof(unsigned char), 54, cover_image_fp);
    bytes_read = fwrite(buffer, sizeof(unsigned char), 54, output_image_fp);
    
    for (int i = 0; i < secret_image_height; i++) {
        for (int j = 0; j < secret_image_width; j++) {
            /* Read pixel from cover image */
            RGB_Pixel cover_pixel;
            bytes_read = fread(&cover_pixel.blue, sizeof(unsigned char), 1, cover_image_fp);
            bytes_read = fread(&cover_pixel.green, sizeof(unsigned char), 1, cover_image_fp);
            bytes_read = fread(&cover_pixel.red, sizeof(unsigned char), 1, cover_image_fp);
            
            /* Read pixel from secret image */
            RGB_Pixel secret_pixel;
            bytes_read = fread(&secret_pixel.blue, sizeof(unsigned char), 1, secret_image_fp);
            bytes_read = fread(&secret_pixel.green, sizeof(unsigned char), 1, secret_image_fp);
            bytes_read = fread(&secret_pixel.red, sizeof(unsigned char), 1, secret_image_fp);
            
            /* Change the least significant bit in blue color to the secret image's bit */
            cover_pixel.blue = (cover_pixel.blue & 0xFE) | (secret_pixel.blue >> 7);
            
            /* Write the new pixel to the output image */
            bytes_read = fwrite(&cover_pixel.blue, sizeof(unsigned char), 1, output_image_fp);
            bytes_read = fwrite(&cover_pixel.green, sizeof(unsigned char), 1, output_image_fp);
            bytes_read = fwrite(&cover_pixel.red, sizeof(unsigned char), 1, output_image_fp);
        }
        /* Skip any extra pixels in the cover image */
        fseek(cover_image_fp, (cover_image_width - secret_image_width) * 3, SEEK_CUR);
    }
    
    /* Copy any remaining pixels from the cover image to the output image */
    while (!feof(cover_image_fp)) {
        unsigned char buffer[3];
        bytes_read = fread(buffer, sizeof(unsigned char), 3, cover_image_fp);
        bytes_read = fwrite(buffer, sizeof(unsigned char), 3, output_image_fp);
    }
    
    /* Close files and exit */
    fclose(cover_image_fp);
    fclose(secret_image_fp);
    fclose(output_image_fp);
    printf("Steganography completed.\n");
    return 0;
}