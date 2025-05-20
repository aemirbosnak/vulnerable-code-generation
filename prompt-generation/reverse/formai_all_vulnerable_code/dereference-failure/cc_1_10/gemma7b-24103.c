//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char *secret_message = "This is a secret message hidden in an image.";
    char *stego_image = "image.jpg";
    char *watermarked_image = "watermarked_image.jpg";

    // Open the image file
    FILE *fp = fopen(stego_image, "rb");
    if (fp == NULL)
    {
        perror("Error opening image file");
        exit(1);
    }

    // Allocate memory for the watermark
    char *watermark = malloc(MAX_BUFFER_SIZE);

    // Read the image file into the watermark
    int watermark_size = fread(watermark, 1, MAX_BUFFER_SIZE, fp);
    fclose(fp);

    // Hide the secret message in the watermark
    hide_secret_message(secret_message, watermark, watermark_size);

    // Write the watermarked image to a new file
    fp = fopen(watermarked_image, "wb");
    if (fp == NULL)
    {
        perror("Error writing watermarked image");
        exit(1);
    }
    fwrite(watermark, 1, watermark_size, fp);
    fclose(fp);

    // Free the memory allocated for the watermark
    free(watermark);

    return 0;
}

int hide_secret_message(char *secret_message, char *watermark, int watermark_size)
{
    // Calculate the length of the secret message
    int secret_message_length = strlen(secret_message);

    // If the secret message is longer than the watermark, return an error
    if (secret_message_length > watermark_size)
    {
        return -1;
    }

    // Hide the secret message by modifying the LSB of the watermark pixels
    for (int i = 0; i < secret_message_length; i++)
    {
        // Convert the secret message character to an integer
        int message_character = secret_message[i] - 0;

        // Calculate the LSB of the watermark pixel
        int lsb = watermark[i] & 0x03;

        // Modify the LSB of the watermark pixel to match the secret message character
        watermark[i] = (watermark[i] & ~0x03) | (lsb ^ message_character);
    }

    return 0;
}