//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

typedef struct Image
{
    int width;
    int height;
    unsigned char *data;
} Image;

Image *image_load(char *filename)
{
    Image *image = malloc(sizeof(Image));

    // Open the file
    FILE *file = fopen(filename, "rb");

    // Read the image header
    image->width = fread(&image->width, sizeof(int), 1, file);
    image->height = fread(&image->height, sizeof(int), 1, file);
    image->data = malloc(image->width * image->height * 3);

    // Read the image data
    fread(image->data, image->width * image->height * 3, 1, file);

    // Close the file
    fclose(file);

    return image;
}

void image_save(Image *image, char *filename)
{
    // Open the file
    FILE *file = fopen(filename, "wb");

    // Write the image header
    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);

    // Write the image data
    fwrite(image->data, image->width * image->height * 3, 1, file);

    // Close the file
    fclose(file);
}

int main()
{
    Image *image = image_load("image.jpg");
    image_save(image, "image_edited.jpg");

    return 0;
}