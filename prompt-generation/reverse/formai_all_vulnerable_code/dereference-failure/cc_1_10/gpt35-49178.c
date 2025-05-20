//FormAI DATASET v1.0 Category: Image Editor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for Image
typedef struct Image 
{
    int width, height;
    unsigned char *data;
} Image;

// Function to create a new Image
Image* createImage(int width, int height) 
{
    Image *img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = calloc(width * height, sizeof(char));
    return img;
}

// Function to load an existing Image from a file
Image* loadImage(char *filename) 
{
    FILE *file;
    file = fopen(filename, "rb");

    if(file == NULL) 
    {
        printf("Unable to open file '%s'\n", filename);
        exit(1);
    }

    char type[3];
    fread(&type, 1, 2, file);

    if(strcmp(type, "P5") != 0) 
    {
        printf("Invalid file format - only PGM grayscale images are supported\n");
        exit(1);
    }

    int width, height, maxVal;
    fscanf(file, "%d %d %d\n", &width, &height, &maxVal);

    if(maxVal != 255) 
    {
        printf("Invalid file format - only PGM grayscale images with max value of 255 are supported\n");
        exit(1);
    }

    Image *img = createImage(width, height);
    fread(img->data, 1, width * height, file);

    fclose(file);
    return img;
}

// Function to save an Image to a file
void saveImage(Image *img, char *filename) 
{
    FILE *file;
    file = fopen(filename, "wb");

    if(file == NULL) 
    {
        printf("Unable to create file '%s'\n", filename);
        exit(1);
    }

    fprintf(file, "P5\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, 1, img->width * img->height, file);

    fclose(file);
}

// Function to apply a filter to an Image
void applyFilter(Image *img, float filter[3][3]) 
{
    int x, y, i, j;
    int width = img->width;
    int height = img->height;
    unsigned char *buffer = calloc(width * height, sizeof(char));
    float sum;

    for(y = 0; y < height; y++) 
    {
        for(x = 0; x < width; x++) 
        {
            sum = 0;
            for(j = -1; j <= 1; j++) 
            {
                for(i = -1; i <= 1; i++) 
                {
                    if(x + i >= 0 && x + i < width && y + j >= 0 && y + j < height) 
                    {
                        sum += filter[j + 1][i + 1] * img->data[(y + j) * width + (x + i)];
                    }
                }
            }
            buffer[y * width + x] = sum;
        }
    }
    memcpy(img->data, buffer, width * height * sizeof(char));
    free(buffer);
}

int main(int argc, char **argv) 
{
    if(argc != 3) 
    {
        printf("Usage: %s input.pgm output.pgm\n", argv[0]);
        exit(1);
    }

    Image *img = loadImage(argv[1]);

    // Apply a filter to the Image
    float filter[3][3] = {
        {0.11, 0.11, 0.11},
        {0.11, 0.11, 0.11},
        {0.11, 0.11, 0.11}
    };
    applyFilter(img, filter);

    saveImage(img, argv[2]);

    return 0;
}