//FormAI DATASET v1.0 Category: Image compression ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_PIXEL_VALUE 255
#define HEADER_SIZE 54

unsigned char* load_bitmap(char* filename, int* width, int* height);
void save_bitmap(char* filename, unsigned char* image, int width, int height);
unsigned char* compress_image(unsigned char* image, int width, int height, int* compressed_size);
unsigned char* decompress_image(unsigned char* compressed_image, int* width, int* height);

int main()
{
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the filename of the bitmap image to be compressed: ");
    scanf("%s", filename);

    int width, height;
    unsigned char* image = load_bitmap(filename, &width, &height);
    if (!image)
    {
        printf("Failed to load bitmap!\n");
        return 1;
    }

    int compressed_size;
    unsigned char* compressed_image = compress_image(image, width, height, &compressed_size);

    char new_filename[MAX_FILENAME_LENGTH];
    printf("Enter the filename to save the compressed image: ");
    scanf("%s", new_filename);
    save_bitmap(new_filename, compressed_image, width, height);

    unsigned char* decompressed_image = decompress_image(compressed_image, &width, &height);
    if (!decompressed_image)
    {
        printf("Failed to decompress image!\n");
        return 1;
    }

    printf("Image successfully compressed and decompressed.\n");

    free(image);
    free(compressed_image);
    free(decompressed_image);

    return 0;
}

unsigned char* load_bitmap(char* filename, int* width, int* height)
{
    FILE* fp = fopen(filename, "rb");
    if (!fp) return NULL;

    unsigned char header[HEADER_SIZE];
    fread(header, sizeof(unsigned char), HEADER_SIZE, fp);

    *width = *(int*)&header[18];
    *height = *(int*)&header[22];

    int padding = 0;
    while ((*width * 3 + padding) % 4 != 0) padding++;

    int data_size = (*width * 3 + padding) * (*height);
    unsigned char* image = (unsigned char*)malloc(sizeof(unsigned char) * data_size);

    fread(image, sizeof(unsigned char), data_size, fp);

    fclose(fp);

    return image;
}

void save_bitmap(char* filename, unsigned char* image, int width, int height)
{
    int padding = 0;
    while ((width * 3 + padding) % 4 != 0) padding++;

    int data_size = (width * 3 + padding) * height;
    unsigned char header[HEADER_SIZE] = {
        0x42, 0x4D, // signature
        0, 0, 0, 0, // file size
        0, 0, 0, 0, // reserved
        HEADER_SIZE, 0, 0, 0, // header size
        40, 0, 0, 0, // info size
        0, 0, 0, 0, // image width
        0, 0, 0, 0, // image height
        1, 0, // number of planes
        24, 0, // bits per pixel
        0, 0, 0, 0, // compression
        0, 0, 0, 0, // image size
        0x13, 0x0B, 0, 0, // horizontal resolution
        0x13, 0x0B, 0, 0, // vertical resolution
        0, 0, 0, 0, // number of colors in palette
        0, 0, 0, 0 // number of important colors
    };

    *(int*)&header[2] = data_size + HEADER_SIZE;
    *(int*)&header[18] = width;
    *(int*)&header[22] = height;
    *(int*)&header[34] = data_size;

    FILE* fp = fopen(filename, "wb");
    if (!fp) return;

    fwrite(header, sizeof(unsigned char), HEADER_SIZE, fp);
    fwrite(image, sizeof(unsigned char), data_size, fp);

    fclose(fp);
}

unsigned char* compress_image(unsigned char* image, int width, int height, int* compressed_size)
{
    int padding = 0;
    while ((width * 3 + padding) % 4 != 0) padding++;

    int data_size = (width * 3 + padding) * height;

    unsigned char* compressed_image = (unsigned char*)malloc(sizeof(unsigned char) * data_size);

    int k = 0;
    for (int i = 0; i < data_size;)
    {
        int count = 1;
        while (i + 3 < data_size && image[i] == image[i + 3] && image[i + 1] == image[i + 4] && image[i + 2] == image[i + 5])
        {
            count++;
            i += 3;
        }
        i += 3;

        int b1 = count & 0xFF;
        int b2 = (count >> 8) & 0xFF;
        int b3 = (count >> 16) & 0xFF;
        int b4 = (count >> 24) & 0xFF;

        compressed_image[k++] = b1;
        compressed_image[k++] = b2;
        compressed_image[k++] = b3;
        compressed_image[k++] = b4;

        compressed_image[k++] = image[i - 3];
        compressed_image[k++] = image[i - 2];
        compressed_image[k++] = image[i - 1];
    }

    *compressed_size = k;

    return compressed_image;
}

unsigned char* decompress_image(unsigned char* compressed_image, int* width, int* height)
{
    int padding = 0;
    while ((*width * 3 + padding) % 4 != 0) padding++;

    int compressed_size = (*width * 3 + padding) * (*height);

    unsigned char* image = (unsigned char*)malloc(sizeof(unsigned char) * compressed_size);

    int k = 0;
    for (int i = 0; i < compressed_size;)
    {
        int count = compressed_image[i++] | (compressed_image[i++] << 8) | (compressed_image[i++] << 16) | (compressed_image[i++] << 24);

        int b = compressed_image[i++];
        int g = compressed_image[i++];
        int r = compressed_image[i++];

        for (int j = 0; j < count; j++)
        {
            image[k++] = r;
            image[k++] = g;
            image[k++] = b;
        }
    }

    return image;
}