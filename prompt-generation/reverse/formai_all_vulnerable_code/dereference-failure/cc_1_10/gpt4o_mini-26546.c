//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Function to load PGM images
Image* loadPGM(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }
    
    Image *img = malloc(sizeof(Image));
    char buffer[16];
    
    if (!fgets(buffer, sizeof(buffer), file)) {
        perror("Not a valid PGM file");
        return NULL;
    }
    
    if (buffer[0] != 'P' || buffer[1] != '5') {
        perror("Not a valid PGM file");
        return NULL;
    }

    // Read image size
    fscanf(file, "%d %d\n255\n", &img->width, &img->height);
    img->data = malloc(img->width * img->height);
    fread(img->data, img->width * img->height, 1, file);
    fclose(file);
    return img;
}

// Function to save PGM images
void savePGM(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }
    
    fprintf(file, "P5\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, img->width * img->height, 1, file);
    fclose(file);
}

// Function to embed watermark in an image
void embedWatermark(Image *img, Image *watermark, int x_offset, int y_offset) {
    for (int y = 0; y < watermark->height; y++) {
        for (int x = 0; x < watermark->width; x++) {
            if (x + x_offset < img->width && y + y_offset < img->height) {
                // Simple averaging of pixel values for watermarking
                img->data[(y + y_offset) * img->width + (x + x_offset)] = 
                    (img->data[(y + y_offset) * img->width + (x + x_offset)] + 
                    watermark->data[y * watermark->width + x]) / 2;
            }
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s <image.pgm> <watermark.pgm> <output.pgm> <x_offset> <y_offset>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *image = loadPGM(argv[1]);
    if (!image) return EXIT_FAILURE;

    Image *watermark = loadPGM(argv[2]);
    if (!watermark) {
        free(image->data);
        free(image);
        return EXIT_FAILURE;
    }

    int x_offset = atoi(argv[4]);
    int y_offset = atoi(argv[5]);

    embedWatermark(image, watermark, x_offset, y_offset);
    savePGM(argv[3], image);

    // Clean up memory
    free(image->data);
    free(image);
    free(watermark->data);
    free(watermark);

    printf("Watermark embedded successfully!\n");
    return EXIT_SUCCESS;
}