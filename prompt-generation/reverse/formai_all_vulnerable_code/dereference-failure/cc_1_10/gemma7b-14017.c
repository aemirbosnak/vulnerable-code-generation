//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void steganography(char *image, char *message)
{
    FILE *fp;
    fp = fopen(image, "rb");
    if (fp == NULL)
    {
        perror("Error opening image file");
        exit(1);
    }

    char buffer[4096];
    size_t read_size = fread(buffer, 1, 4096, fp);
    fclose(fp);

    int i = 0;
    for (i = 0; i < read_size; i++)
    {
        // Calculate the parity of the pixel value
        int parity = buffer[i] % 2;

        // If the parity of the pixel value is not equal to the parity of the message character,
        // modify the pixel value
        if (parity != message[i] % 2)
        {
            buffer[i] ^= 1;
        }
    }

    fp = fopen(image, "wb");
    if (fp == NULL)
    {
        perror("Error writing to image file");
        exit(1);
    }

    fwrite(buffer, 1, read_size, fp);
    fclose(fp);
}

int main()
{
    char image[] = "image.jpg";
    char message[] = "Secret message";

    steganography(image, message);

    return 0;
}