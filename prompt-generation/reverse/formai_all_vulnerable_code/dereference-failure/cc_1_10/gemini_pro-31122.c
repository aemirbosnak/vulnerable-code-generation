//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Let's investigate a photographic clue, shall we, Watson?
uint8_t *ReadImage(const char *filename, int *width, int *height)
{
    FILE *file = fopen(filename, "rb");
    if (!file)
    {
        fprintf(stderr, "Could not open file %s\n", filename);
        return NULL;
    }

    // Skip the header (18 bytes)
    fseek(file, 18, SEEK_SET);

    // Read the width and height
    fread(width, sizeof(int), 1, file);
    fread(height, sizeof(int), 1, file);

    // Allocate memory for the pixels
    uint8_t *pixels = malloc(*width * *height * sizeof(uint8_t));
    if (!pixels)
    {
        fprintf(stderr, "Could not allocate memory for pixels\n");
        fclose(file);
        return NULL;
    }

    // Read the pixels
    fread(pixels, *width * *height, sizeof(uint8_t), file);

    fclose(file);

    return pixels;
}

void WriteImage(const char *filename, const uint8_t *pixels, int width, int height)
{
    FILE *file = fopen(filename, "wb");
    if (!file)
    {
        fprintf(stderr, "Could not open file %s\n", filename);
        return;
    }

    // Write the header (18 bytes)
    fwrite("BM", 1, 2, file);
    fwrite(&width, sizeof(int), 1, file);
    fwrite(&height, sizeof(int), 1, file);

    // Write the pixels
    fwrite(pixels, width * height, sizeof(uint8_t), file);

    fclose(file);
}

// Flip the image vertically, revealing a clue
void FlipImage(uint8_t *pixels, int width, int height)
{
    for (int y = 0; y < height / 2; y++)
    {
        for (int x = 0; x < width; x++)
        {
            uint8_t temp = pixels[y * width + x];
            pixels[y * width + x] = pixels[(height - y - 1) * width + x];
            pixels[(height - y - 1) * width + x] = temp;
        }
    }
}

// Enhance the image by adjusting brightness and contrast, exposing the sinister truth
void AdjustBrightnessContrast(uint8_t *pixels, int width, int height, int brightness, int contrast)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int pixel = pixels[y * width + x];
            pixel += brightness;
            pixel *= contrast;
            pixel = pixel > 255 ? 255 : pixel;
            pixel = pixel < 0 ? 0 : pixel;
            pixels[y * width + x] = pixel;
        }
    }
}

int main(int argc, char **argv)
{
    // Let us examine the evidence, Watson
    if (argc != 5)
    {
        fprintf(stderr, "Usage: %s <input image> <output image> <brightness> <contrast>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int width, height;
    uint8_t *pixels = ReadImage(argv[1], &width, &height);
    if (!pixels)
        return EXIT_FAILURE;

    FlipImage(pixels, width, height);
    AdjustBrightnessContrast(pixels, width, height, atoi(argv[3]), atoi(argv[4]));
    WriteImage(argv[2], pixels, width, height);
    free(pixels);

    printf("The truth has been revealed, Watson. Check the output image.\n");
    return EXIT_SUCCESS;
}