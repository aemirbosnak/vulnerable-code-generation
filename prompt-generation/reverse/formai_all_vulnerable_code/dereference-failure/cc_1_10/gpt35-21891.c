//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  This program demonstrates a simple digital watermarking technique using C programming language. 
  The basic idea is to embed a hidden watermark message in an image by manipulating the least significant bits of the pixel values. 
  The watermark message is a short string of characters that is extracted by examining the same pixels from the marked image.
*/

// Define maximum length for the watermark message
#define MAX_WATERMARK_LEN 256

// Function to embed the watermark message in the image
void embed_watermark(const char* watermark, const char *original_file, const char* marked_file)
{
    // Open the original image file
    FILE *original_image = fopen(original_file, "rb");
    if (original_image == NULL)
    {
        printf("Error opening original file %s\n", original_file);
        exit(1);
    }

    // Create a new file for the marked image
    FILE *marked_image = fopen(marked_file, "wb");
    if (marked_image == NULL)
    {
        printf("Error creating marked file %s\n", marked_file);
        exit(1);
    }

    // Get the watermark message length
    size_t watermark_len = strlen(watermark);
    if (watermark_len > MAX_WATERMARK_LEN)
    {
        printf("Watermark message is too long (maximum length is %d)\n", MAX_WATERMARK_LEN);
        exit(1);
    }

    // Write the watermark length to the first byte of the marked image
    unsigned char len_byte = (unsigned char) watermark_len;
    fwrite(&len_byte, 1, 1, marked_image);

    // Embed the watermark message in the image by modifying the least significant bits of the pixel values
    unsigned char pixel[3];
    int bit_index = 0;
    int watermark_index = 0;
    while (fread(&pixel, 1, 3, original_image) == 3)
    {
        // Embed one bit of the watermark message in each pixel color component
        pixel[0] = ((pixel[0] & 0xFE) | ((watermark[watermark_index] >> bit_index) & 0x01));
        pixel[1] = ((pixel[1] & 0xFE) | ((watermark[watermark_index] >> bit_index) & 0x01));
        pixel[2] = ((pixel[2] & 0xFE) | ((watermark[watermark_index] >> bit_index) & 0x01));

        // Write the modified pixel values to the marked image
        fwrite(&pixel, 1, 3, marked_image);

        // Move to the next watermark bit
        bit_index = (bit_index + 1) % 8;
        watermark_index += (bit_index == 0);

        // Stop if the whole watermark message has been embedded
        if (watermark_index >= watermark_len)
            break;
    }

    // Copy the remaining pixels from the original image to the marked image
    while (fread(&pixel, 1, 3, original_image) == 3)
        fwrite(&pixel, 1, 3, marked_image);

    // Close the file handles
    fclose(original_image);
    fclose(marked_image);

    printf("Watermark embedded successfully!\n");
}

// Function to extract the watermark message from the marked image
void extract_watermark(const char* marked_file, char* watermark)
{
    // Open the marked image file
    FILE *marked_image = fopen(marked_file, "rb");
    if (marked_image == NULL)
    {
        printf("Error opening marked file %s\n", marked_file);
        exit(1);
    }

    // Read the watermark length from the first byte of the marked image
    unsigned char len_byte;
    fread(&len_byte, 1, 1, marked_image);
    size_t watermark_len = len_byte;

    // Extract the watermark message from the marked image by reading the least significant bits of the pixel values
    unsigned char pixel[3];
    int bit_index = 0;
    int watermark_index = 0;
    while (fread(&pixel, 1, 3, marked_image) == 3)
    {
        // Extract one bit of the watermark message from each pixel color component
        unsigned char watermark_bit = ((pixel[0] & 0x01) << bit_index) 
                                       | ((pixel[1] & 0x01) << bit_index) 
                                       | ((pixel[2] & 0x01) << bit_index);
        watermark[watermark_index] |= watermark_bit;

        // Move to the next watermark bit
        bit_index = (bit_index + 1) % 8;
        watermark_index += (bit_index == 0);

        // Stop if the whole watermark message has been extracted
        if (watermark_index >= watermark_len)
            break;
    }

    // Null-terminate the extracted watermark message
    watermark[watermark_len] = '\0';

    // Close the file handle
    fclose(marked_image);

    printf("Watermark extracted successfully: %s\n", watermark);
}

int main()
{
    char watermark[MAX_WATERMARK_LEN + 1];

    // Embed a watermark in the original image
    embed_watermark("This is a test watermark message!", "original_image.jpg", "marked_image.jpg");

    // Extract the watermark from the marked image
    extract_watermark("marked_image.jpg", watermark);

    return 0;
}