//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        return NULL;
    }

    // Read the image header (Assuming a simple P6 PPM format without comments)
    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Error: Unsupported file format\n");
        fclose(file);
        return NULL;
    }

    Image *img = malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    int max_value;
    fscanf(file, "%d", &max_value);
    fgetc(file); // To consume the newline character after max_value

    img->data = malloc(img->width * img->height * sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);

    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: Unable to save image to %s\n", filename);
        return;
    }

    // Writing the image header
    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void apply_brightness(Image *img, int brightness) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (img->data[i].r + brightness > 255) ? 255 : (img->data[i].r + brightness < 0 ? 0 : img->data[i].r + brightness);
        img->data[i].g = (img->data[i].g + brightness > 255) ? 255 : (img->data[i].g + brightness < 0 ? 0 : img->data[i].g + brightness);
        img->data[i].b = (img->data[i].b + brightness > 255) ? 255 : (img->data[i].b + brightness < 0 ? 0 : img->data[i].b + brightness);
    }
}

void free_image(Image *img) {
    free(img->data);
    free(img);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <brightness>\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    int brightness = atoi(argv[3]);

    Image *img = load_image(input_file);
    if (!img) {
        fprintf(stderr, "Error: Failed to load image!\n");
        return 1;
    }

    printf("Loaded image: %s (%d x %d)\n", input_file, img->width, img->height);
    printf("Applying brightness: %d...\n", brightness);
    
    apply_brightness(img, brightness);
    
    save_image(output_file, img);
    
    printf("Image saved to: %s\n", output_file);

    free_image(img);
    printf("All done! Enjoy your edited image!\n");
    return 0;
}