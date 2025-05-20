//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 1024

typedef struct Image
{
    int width;
    int height;
    int **pixels;
} Image;

Image *load_image(char *filename)
{
    Image *image = malloc(sizeof(Image));
    image->width = 0;
    image->height = 0;
    image->pixels = NULL;

    FILE *file = fopen(filename, "r");
    if (file)
    {
        fscanf(file, "%d %d", &image->width, &image->height);
        image->pixels = malloc(image->height * image->width * sizeof(int));
        fread(image->pixels, image->height * image->width * sizeof(int), 1, file);
        fclose(file);
    }

    return image;
}

void convert_image_to_ascii(Image *image)
{
    for (int y = 0; y < image->height; y++)
    {
        for (int x = 0; x < image->width; x++)
        {
            int pixel_value = image->pixels[y * image->width + x];
            switch (pixel_value)
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(". ");
                    break;
                case 2:
                    printf(".. ");
                    break;
                case 3:
                    printf("... ");
                    break;
                case 4:
                    printf(".... ");
                    break;
                default:
                    printf("!!! ");
                    break;
            }
        }
        printf("\n");
    }
}

int main()
{
    Image *image = load_image("image.ppm");
    convert_image_to_ascii(image);
    free(image);

    return 0;
}