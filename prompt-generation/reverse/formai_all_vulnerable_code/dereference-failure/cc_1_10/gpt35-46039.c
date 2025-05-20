//FormAI DATASET v1.0 Category: Fractal Generation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int WIDTH = 800;
const int HEIGHT = 800;
const int MAX_ITERATIONS = 1000;

typedef struct
{
    double real;
    double imaginary;
} ComplexNumber;

int calculateMandelbrot(ComplexNumber c)
{
    ComplexNumber z = {0, 0};
    int iterations = 0;
    while (z.real * z.real + z.imaginary * z.imaginary <= 4 && iterations < MAX_ITERATIONS)
    {
        ComplexNumber temp = z;
        z.real = temp.real * temp.real - temp.imaginary * temp.imaginary + c.real;
        z.imaginary = 2 * temp.real * temp.imaginary + c.imaginary;
        iterations++;
    }
    return iterations;
}

void generateFractal(int **pixels)
{
    ComplexNumber center = {-0.75, 0};
    double zoom = 1;
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            double real = (x - WIDTH / 2) * 4.0 / WIDTH / zoom + center.real;
            double imaginary = (y - HEIGHT / 2) * 4.0 / HEIGHT / zoom + center.imaginary;
            ComplexNumber c = {real, imaginary};
            int iterations = calculateMandelbrot(c);
            pixels[x][y] = iterations % 256;
        }
    }
}

void saveBitmap(int **pixels, char *filename)
{
    FILE *file;
    int filesize = 54 + 3 * WIDTH * HEIGHT;
    char header[54] = {
        0x42, 0x4d, (char)(filesize), (char)(filesize >> 8), (char)(filesize >> 16), (char)(filesize >> 24), 0x00, 0x00, 0x00, 0x00,
        0x36, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, (char)(WIDTH), (char)(WIDTH >> 8), (char)(WIDTH >> 16), (char)(WIDTH >> 24), (char)(HEIGHT), (char)(HEIGHT >> 8), (char)(HEIGHT >> 16), (char)(HEIGHT >> 24),
        0x01, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    file = fopen(filename, "wb");
    fwrite(header, sizeof(char), 54, file);
    for (int y = HEIGHT - 1; y >= 0; y--)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            char color[3] = {(char)(pixels[x][y]), (char)(pixels[x][y]), (char)(pixels[x][y])};
            fwrite(color, sizeof(char), 3, file);
        }
    }
    fclose(file);
}

int main()
{
    int **pixels = malloc(WIDTH * sizeof(int *));
    for (int x = 0; x < WIDTH; x++)
    {
        pixels[x] = malloc(HEIGHT * sizeof(int));
    }
    generateFractal(pixels);
    saveBitmap(pixels, "fractal.bmp");
    for (int x = 0; x < WIDTH; x++)
    {
        free(pixels[x]);
    }
    free(pixels);
    return 0;
}