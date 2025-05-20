//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    Pixel *data;
    int width, height;
} Image;

// Function prototypes
Image* read_ppm(const char *filename);
int write_ppm(const char *filename, const Image *img);
void invert_colors(Image *img);
void free_image(Image *img);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input.ppm> <output.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *img = read_ppm(argv[1]);
    if (img == NULL) {
        return EXIT_FAILURE;
    }

    invert_colors(img);
    
    if (write_ppm(argv[2], img) != 0) {
        free_image(img);
        return EXIT_FAILURE;
    }

    free_image(img);
    printf("Image processing done successfully!\n");
    return EXIT_SUCCESS;
}

// Function to read PPM file
Image* read_ppm(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    char buffer[16];
    if (!fgets(buffer, sizeof(buffer), file)) {
        perror("Error reading file");
        fclose(file);
        return NULL;
    }

    if (strncmp(buffer, "P6", 2) != 0) {
        fprintf(stderr, "Unsupported file format\n");
        fclose(file);
        return NULL;
    }

    int width, height, maxval;
    fscanf(file, "%d %d %d%*c", &width, &height, &maxval);
    
    Image *img = (Image *)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = (Pixel *)malloc(width * height * sizeof(Pixel));
    
    if (fread(img->data, sizeof(Pixel), width * height, file) != width * height) {
        perror("Error reading pixel data");
        free_image(img);
        fclose(file);
        return NULL;
    }

    fclose(file);
    return img;
}

// Function to write PPM file
int write_ppm(const char *filename, const Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    return 0;
}

// Function to invert colors of the image
void invert_colors(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = 255 - img->data[i].r;
        img->data[i].g = 255 - img->data[i].g;
        img->data[i].b = 255 - img->data[i].b;
    }
}

// Function to free image memory
void free_image(Image *img) {
    free(img->data);
    free(img);
}