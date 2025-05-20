//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void embed_message(char *image_file, char *message)
{
    FILE *fp = fopen(image_file, "rb");
    if (fp == NULL)
    {
        perror("Error opening file");
        return;
    }

    unsigned char *image_data = (unsigned char *)malloc(1024);
    if (image_data == NULL)
    {
        perror("Error allocating memory");
        fclose(fp);
        return;
    }

    size_t image_size = fread(image_data, 1, 1024, fp);
    fclose(fp);

    int i = 0;
    for (i = 0; i < image_size; i++)
    {
        image_data[i] ^= (message[i] & 0x0F) << 2;
    }

    fp = fopen(image_file, "wb");
    if (fp == NULL)
    {
        perror("Error opening file");
        return;
    }

    fwrite(image_data, 1, image_size, fp);
    fclose(fp);

    free(image_data);
}

int main()
{
    char *image_file = "image.jpg";
    char *message = "Hello, world!";

    embed_message(image_file, message);

    printf("Image file modified successfully!\n");

    return 0;
}