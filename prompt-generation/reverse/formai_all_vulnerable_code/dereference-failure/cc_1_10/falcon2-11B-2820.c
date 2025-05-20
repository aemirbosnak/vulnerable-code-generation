//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_SIZE 1000
#define MAX_IMAGE_SIZE 1024

typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    if (argc!= 3)
    {
        printf("Usage: steg <image> <message>\n");
        return 1;
    }

    FILE *image = fopen(argv[1], "rb");
    FILE *message = fopen(argv[2], "rb");

    if (!image ||!message)
    {
        printf("Failed to open file\n");
        return 1;
    }

    BYTE pixel[3];
    BYTE messageByte;
    int messageIndex = 0;
    int imageIndex = 0;

    while (fread(pixel, sizeof(pixel), 1, image) == 1)
    {
        messageByte = fgetc(message);
        if (messageByte == -1)
        {
            printf("Error reading message\n");
            return 1;
        }

        for (int i = 0; i < 3; i++)
        {
            pixel[i] = pixel[i] ^ messageByte;
        }

        fwrite(pixel, sizeof(pixel), 1, image);
        imageIndex++;
    }

    fclose(image);
    fclose(message);

    printf("Steganography successful!\n");

    return 0;
}