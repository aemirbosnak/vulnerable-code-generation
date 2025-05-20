//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Function to hide a message in an image file
void hide_message(const char *image_filename, const char *message, const char *stego_filename)
{
    // Read the cover image
    FILE *image_file = fopen(image_filename, "rb");
    if (!image_file)
    {
        printf("Error opening image file.\n");
        return;
    }

    // Read the message
    FILE *message_file = fopen(message, "rb");
    if (!message_file)
    {
        printf("Error opening message file.\n");
        fclose(image_file);
        return;
    }

    // Read the image and store the pixels
    unsigned char pixel[3];
    int width = 0, height = 0;
    fseek(image_file, 0, SEEK_END);
    width = ftell(image_file);
    rewind(image_file);
    fseek(message_file, 0, SEEK_END);
    height = ftell(message_file);
    rewind(message_file);

    unsigned char *stego_image = (unsigned char *)malloc(width * height * 3);
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            fread(pixel, sizeof(unsigned char), 3, image_file);
            for (int i = 0; i < 3; i++)
            {
                stego_image[3 * (y * width + x) + i] = pixel[i] & 0x01;
            }
        }
    }

    // Write the stego image
    FILE *stego_file = fopen(stego_filename, "wb");
    if (!stego_file)
    {
        printf("Error opening stego file.\n");
        free(stego_image);
        fclose(image_file);
        fclose(message_file);
        return;
    }
    fwrite(stego_image, sizeof(unsigned char), width * height * 3, stego_file);
    fclose(stego_file);
    fclose(image_file);
    fclose(message_file);

    printf("Hiding message %s in image %s completed successfully.\n", message, image_filename);
}

// Function to extract a message from a stego image
void extract_message(const char *stego_filename, const char *message_filename)
{
    // Read the stego image
    FILE *stego_file = fopen(stego_filename, "rb");
    if (!stego_file)
    {
        printf("Error opening stego file.\n");
        return;
    }

    // Read the message
    FILE *message_file = fopen(message_filename, "wb");
    if (!message_file)
    {
        printf("Error opening message file.\n");
        fclose(stego_file);
        return;
    }

    unsigned char *stego_image = (unsigned char *)malloc(sizeof(unsigned char) * 3 * (640 * 480));
    fread(stego_image, sizeof(unsigned char), 3 * (640 * 480), stego_file);
    fclose(stego_file);

    for (int y = 0; y < 480; y++)
    {
        for (int x = 0; x < 640; x++)
        {
            unsigned char pixel = 0;
            for (int i = 0; i < 3; i++)
            {
                pixel |= stego_image[3 * (y * 640 + x) + i];
            }
            fwrite(&pixel, sizeof(unsigned char), 1, message_file);
        }
    }
    fclose(message_file);

    free(stego_image);

    printf("Extracted message %s from stego image %s successfully.\n", message_filename, stego_filename);
}

// Main function
int main(int argc, char **argv)
{
    if (argc!= 5)
    {
        printf("Usage: %s <cover image> <message> <stego image> <message file>\n", argv[0]);
        return 1;
    }

    hide_message(argv[1], argv[2], argv[3]);
    extract_message(argv[3], argv[4]);

    return 0;
}