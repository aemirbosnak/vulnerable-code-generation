//FormAI DATASET v1.0 Category: Image Editor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for image dimensions and color range
#define WIDTH 100
#define HEIGHT 100
#define COLOR_RANGE 255

// Struct for pixel data
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

// Function to load image data from file
Pixel** load_image(char* filename)
{
    FILE* f = fopen(filename, "rb");
    if (!f) {
        printf("Unable to open image file.\n");
        exit(1);
    }

    char header[54];
    fread(header, sizeof(char), 54, f);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    Pixel** image = (Pixel**)malloc(height * sizeof(Pixel*));
    for (int i = 0; i < height; i++) {
        image[i] = (Pixel*)malloc(width * sizeof(Pixel));
        fread(image[i], sizeof(Pixel), width, f);
    }

    fclose(f);
    return image;
}

// Function to save image data to file
void save_image(char* filename, Pixel** image)
{
    FILE* f = fopen(filename, "wb");
    if (!f) {
        printf("Unable to create image file.\n");
        exit(1);
    }

    char header[54];
    memset(header, 0, 54);
    header[0] = 'B';
    header[1] = 'M';
    *(int*)&header[2] = 54 + WIDTH * HEIGHT * 3;
    *(int*)&header[10] = 54;
    *(int*)&header[14] = 40;
    *(int*)&header[18] = WIDTH;
    *(int*)&header[22] = HEIGHT;
    *(short*)&header[26] = 1;
    *(short*)&header[28] = 24;
    fwrite(header, sizeof(char), 54, f);

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fwrite(&image[i][j].blue, sizeof(unsigned char), 1, f);
            fwrite(&image[i][j].green, sizeof(unsigned char), 1, f);
            fwrite(&image[i][j].red, sizeof(unsigned char), 1, f);
        }
    }

    fclose(f);
}

// Function to invert colors of image
void invert_colors(Pixel** image)
{
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image[i][j].red = COLOR_RANGE - image[i][j].red;
            image[i][j].green = COLOR_RANGE - image[i][j].green;
            image[i][j].blue = COLOR_RANGE - image[i][j].blue;
        }
    }
}

// Function to blur image using a simple box filter
void blur_image(Pixel** image)
{
    Pixel** temp = (Pixel**)malloc(HEIGHT * sizeof(Pixel*));
    for (int i = 0; i < HEIGHT; i++) {
        temp[i] = (Pixel*)malloc(WIDTH * sizeof(Pixel));
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int r_sum = 0;
            int g_sum = 0;
            int b_sum = 0;
            int count = 0;

            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (i + x >= 0 && i + x < HEIGHT && j + y >= 0 && j + y < WIDTH) {
                        r_sum += image[i + x][j + y].red;
                        g_sum += image[i + x][j + y].green;
                        b_sum += image[i + x][j + y].blue;
                        count++;
                    }
                }
            }

            temp[i][j].red = r_sum / count;
            temp[i][j].green = g_sum / count;
            temp[i][j].blue = b_sum / count;
        }
    }

    for (int i = 0; i < HEIGHT; i++) {
        free(image[i]);
        image[i] = temp[i];
    }

    free(temp);
}

int main()
{
    // Load image from file
    Pixel** image = load_image("input.bmp");

    // Invert colors
    invert_colors(image);

    // Blur image
    blur_image(image);

    // Save image to file
    save_image("output.bmp", image);

    // Clean up memory
    for (int i = 0; i < HEIGHT; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}