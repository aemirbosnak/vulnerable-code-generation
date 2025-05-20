//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void steganography(char *cover_image, char *secret_message)
{
    FILE *fp;
    fp = fopen(cover_image, "rb");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    char buffer[1024];
    size_t read_size = fread(buffer, 1, 1024, fp);

    int i = 0;
    for (i = 0; i < read_size; i++)
    {
        // Calculate the parity of the secret message bit and the corresponding bit in the cover image
        int parity = secret_message[i] % 2;
        int image_bit = (buffer[i] & 0x80) >> 7;

        // Modify the image bit based on the parity bit
        if (parity == 0)
        {
            buffer[i] &= ~0x80;
        }
        else
        {
            buffer[i] |= 0x80;
        }
    }

    fclose(fp);

    fp = fopen(cover_image, "wb");
    if (fp == NULL)
    {
        perror("Error writing file");
        exit(1);
    }

    fwrite(buffer, 1, read_size, fp);
    fclose(fp);
}

int main()
{
    char *cover_image = "secret.jpg";
    char *secret_message = "This is a secret message.";

    steganography(cover_image, secret_message);

    return 0;
}