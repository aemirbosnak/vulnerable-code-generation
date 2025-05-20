//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

int main()
{
    // Welcome the user to our digital watermarking program
    printf("Welcome to our digital watermarking program, mate!\n");
    
    // Get the input image from the user
    char input_image[MAX_LEN];
    printf("Enter the name of the input image: ");
    scanf("%s", input_image);

    // Get the watermark from the user
    char watermark[MAX_LEN];
    printf("Enter the watermark: ");
    scanf("%s", watermark);

    // Get the output image name from the user
    char output_image[MAX_LEN];
    printf("Enter the name of the output watermarked image: ");
    scanf("%s", output_image);

    // Read the input image into memory
    FILE *input_fp = fopen(input_image, "rb");
    if (input_fp == NULL) {
        printf("Error opening the input image file.\n");
        return -1;
    }

    fseek(input_fp, 0L, SEEK_END);
    long input_image_size = ftell(input_fp);
    rewind(input_fp);

    unsigned char *input_image_data = (unsigned char *)malloc(input_image_size);
    if (input_image_data == NULL) {
        printf("Error allocating memory for the input image data.\n");
        return -1;
    }

    fread(input_image_data, 1, input_image_size, input_fp);
    fclose(input_fp);

    // Embed the watermark into the input image
    long watermark_len = strlen(watermark);
    for (int i = 0; i < watermark_len; i++) {
        input_image_data[i] = input_image_data[i] ^ watermark[i];
    }

    // Write the watermarked image to a file
    FILE *output_fp = fopen(output_image, "wb");
    if (output_fp == NULL) {
        printf("Error opening the output image file.\n");
        return -1;
    }

    fwrite(input_image_data, 1, input_image_size, output_fp);
    fclose(output_fp);

    // Free the memory allocated for the input image data
    free(input_image_data);

    // Tell the user that the watermarking process is complete
    printf("Watermarking process complete. The watermarked image has been saved to %s.\n", output_image);

    return 0;
}