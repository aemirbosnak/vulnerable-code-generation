//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: rigorous
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

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        return NULL;
    }

    image->width = 10;
    image->height = 10;
    image->data = malloc(image->width * image->height);

    fscanf(file, "%d %d", &image->width, &image->height);
    fread(image->data, image->width * image->height, 1, file);

    fclose(file);

    return image;
}

void image_convert_to_ascii(Image *image)
{
    for (int y = 0; y < image->height; y++)
    {
        for (int x = 0; x < image->width; x++)
        {
            int pixel_value = image->data[y * image->width + x];
            switch (pixel_value)
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(". ");
                    break;
                case 2:
                    printf("o ");
                    break;
                case 3:
                    printf("O ");
                    break;
                case 4:
                    printf("* ");
                    break;
                default:
                    printf("Error ");
            }
        }

        printf("\n");
    }
}

int main()
{
    Image *image = image_load("image.jpg");
    image_convert_to_ascii(image);

    free(image->data);
    free(image);

    return 0;
}