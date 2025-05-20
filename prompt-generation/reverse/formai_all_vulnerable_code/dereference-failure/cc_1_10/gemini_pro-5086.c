//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE  1000000

// Function to hide text in an image
void hide_text(char *image_file, char *text_file, char *out_image_file)
{
    // Open the image and text files
    FILE *image = fopen(image_file, "rb");
    FILE *text = fopen(text_file, "rb");
    FILE *out = fopen(out_image_file, "wb");

    // Check if the files were opened successfully
    if (!image || !text || !out)
    {
        printf("Error opening files\n");
        return;
    }

    // Get the size of the image
    fseek(image, 0, SEEK_END);
    int image_size = ftell(image);
    rewind(image);
    
    // Get the size of the text
    fseek(text, 0, SEEK_END);
    int text_size = ftell(text);
    rewind(text);
    
    // Check if the image is large enough to hold the text
    if (image_size < text_size)
    {
        printf("Error: Image is too small to hold the text\n");
        return;
    }

    // Read the image into a buffer
    unsigned char *image_buffer = malloc(image_size);
    fread(image_buffer, 1, image_size, image);

    // Read the text into a buffer
    unsigned char *text_buffer = malloc(text_size);
    fread(text_buffer, 1, text_size, text);

    // Hide the text in the image
    for (int i = 0; i < text_size; i++)
    {
        image_buffer[i] = (image_buffer[i] & 0xF8) | ((text_buffer[i] & 0x07) << 3);
    }

    // Write the modified image to file
    fwrite(image_buffer, 1, image_size, out);

    // Free the buffers
    free(image_buffer);
    free(text_buffer);

    // Close the files
    fclose(image);
    fclose(text);
    fclose(out);
}

// Function to extract text from an image
void extract_text(char *image_file, char *out_text_file)
{
    // Open the image and text files
    FILE *image = fopen(image_file, "rb");
    FILE *out = fopen(out_text_file, "wb");

    // Check if the files were opened successfully
    if (!image || !out)
    {
        printf("Error opening files\n");
        return;
    }

    // Get the size of the image
    fseek(image, 0, SEEK_END);
    int image_size = ftell(image);
    rewind(image);

    // Read the image into a buffer
    unsigned char *image_buffer = malloc(image_size);
    fread(image_buffer, 1, image_size, image);

    // Extract the text from the image
    int text_size = (image_size / 3) * 3;
    unsigned char *text_buffer = malloc(text_size);
    for (int i = 0; i < text_size; i++)
    {
        text_buffer[i] = (image_buffer[i] & 0x07) << 5;
    }

    // Write the extracted text to file
    fwrite(text_buffer, 1, text_size, out);

    // Free the buffers
    free(image_buffer);
    free(text_buffer);

    // Close the files
    fclose(image);
    fclose(out);
}

int main()
{
    // Hide text in an image
    hide_text("image.jpg", "text.txt", "out_image.jpg");

    // Extract text from an image
    extract_text("out_image.jpg", "out_text.txt");

    return 0;
}