//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Function prototypes
Image *load_image(const char *filename);
void save_image(const char *filename, Image *img);
void invert_colors(Image *img);
void display_image(Image *img);
void free_image(Image *img);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *img = load_image(argv[1]);
    if (img == NULL) {
        fprintf(stderr, "Unable to load image: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    printf("Loaded image (%d x %d)\n", img->width, img->height);
    display_image(img);

    invert_colors(img);
    printf("Inverted colors\n");
    display_image(img);

    save_image(argv[2], img);
    free_image(img);

    return EXIT_SUCCESS;
}

// Load a PPM image
Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) return NULL;

    char magic[3];
    if (fscanf(fp, "%2s", magic) != 1 || strcmp(magic, "P6") != 0) {
        fclose(fp);
        return NULL;
    }

    int width, height, maxval;
    fscanf(fp, "%d %d %d", &width, &height, &maxval);
    fgetc(fp); // consume whitespace

    Image *img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = malloc(3 * width * height); // RGB

    fread(img->data, 3, width * height, fp);
    fclose(fp);
    return img;
}

// Save a PPM image
void save_image(const char *filename, Image *img) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) return;

    fprintf(fp, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, 3, img->width * img->height, fp);
    fclose(fp);
}

// Invert the colors of an image
void invert_colors(Image *img) {
    for (int i = 0; i < img->width * img->height * 3; i++) {
        img->data[i] = 255 - img->data[i];
    }
}

// Display image data in text form (simulated)
void display_image(Image *img) {
    printf("Displaying image content (first 10 pixels):\n");
    for (int i = 0; i < 10 && i < img->width * img->height; i++) {
        printf("Pixel %d: R=%d G=%d B=%d\n", i,
            img->data[i * 3],
            img->data[i * 3 + 1],
            img->data[i * 3 + 2]);
    }
    printf("... (more pixels)\n");
}

// Free image memory
void free_image(Image *img) {
    free(img->data);
    free(img);
}