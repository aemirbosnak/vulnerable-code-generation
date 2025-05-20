//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_LEN 1024

typedef struct ImageData
{
    unsigned char* pixels;
    int width;
    int height;
} ImageData;

ImageData* image_load(char* filename)
{
    ImageData* image = (ImageData*)malloc(sizeof(ImageData));

    image->pixels = (unsigned char*)malloc(MAX_DATA_LEN);
    image->width = 0;
    image->height = 0;

    FILE* file = fopen(filename, "rb");

    if (file)
    {
        image->width = fread(&image->width, sizeof(int), 1, file);
        image->height = fread(&image->height, sizeof(int), 1, file);
        fread(image->pixels, MAX_DATA_LEN, 1, file);
        fclose(file);
    }

    return image;
}

void image_save(ImageData* image, char* filename)
{
    FILE* file = fopen(filename, "wb");

    if (file)
    {
        fwrite(&image->width, sizeof(int), 1, file);
        fwrite(&image->height, sizeof(int), 1, file);
        fwrite(image->pixels, MAX_DATA_LEN, 1, file);
        fclose(file);
    }
}

int main()
{
    char* image_filename = "image.jpg";
    char* secret_message = "This is a secret message";

    ImageData* image = image_load(image_filename);

    int data_len = strlen(secret_message) + 1;
    image->pixels = (unsigned char*)realloc(image->pixels, MAX_DATA_LEN);

    for (int i = 0; i < data_len; i++)
    {
        image->pixels[image->height * image->width + i] = (secret_message[i] >> 4) & 0x0F;
        image->pixels[image->height * image->width + i] |= (secret_message[i] & 0x0F) << 4;
    }

    image_save(image, "steganogram.jpg");

    return 0;
}