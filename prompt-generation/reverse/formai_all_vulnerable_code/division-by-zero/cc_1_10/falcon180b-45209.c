//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000000

int main() {
    char message[MAX_SIZE];
    char image_name[100];
    char output_name[100];
    FILE *fp, *fp_out;
    int i, j, k, pixel_value, byte_value;
    int image_width, image_height;
    int message_length, message_index;
    int stego_image_size;
    unsigned char *stego_image, *pixels;

    // Read message from user
    printf("Enter your message: ");
    fgets(message, MAX_SIZE, stdin);
    message_length = strlen(message);

    // Read image name from user
    printf("Enter the name of the image file: ");
    scanf("%s", image_name);

    // Open image file
    fp = fopen(image_name, "rb");
    if (fp == NULL) {
        printf("Error opening image file.\n");
        exit(1);
    }

    // Read image dimensions
    fseek(fp, 18, SEEK_SET);
    fread(&image_width, 4, 1, fp);
    fread(&image_height, 4, 1, fp);

    // Calculate stego image size
    stego_image_size = image_width * image_height * 3;

    // Allocate memory for stego image and image pixels
    stego_image = (unsigned char *)malloc(stego_image_size);
    pixels = (unsigned char *)malloc(image_width * image_height * 3);

    // Read image pixels
    fseek(fp, 54, SEEK_SET);
    fread(pixels, 3, image_width * image_height, fp);

    // Close image file
    fclose(fp);

    // Initialize message index
    message_index = 0;

    // Embed message in image
    for (i = 0; i < image_height; i++) {
        for (j = 0; j < image_width; j++) {
            pixel_value = pixels[(i * image_width + j) * 3];
            byte_value = message[message_index % message_length];

            // If message is a space, skip embedding
            if (isblank(byte_value)) {
                message_index++;
                continue;
            }

            // Embed message in least significant bit of pixel value
            if (byte_value == '0') {
                pixel_value = pixel_value | 1;
            } else {
                pixel_value = pixel_value & ~1;
            }

            stego_image[(i * image_width + j) * 3] = pixel_value;

            message_index++;
        }
    }

    // Save stego image
    strcpy(output_name, image_name);
    strcat(output_name, "_stego");
    fp_out = fopen(output_name, "wb");
    if (fp_out == NULL) {
        printf("Error creating output file.\n");
        exit(1);
    }

    fwrite(stego_image, 3, stego_image_size, fp_out);
    fclose(fp_out);

    printf("Stego image created successfully.\n");

    return 0;
}