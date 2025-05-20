//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: automated
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *data;
} Image;

Image* load_ppm(const char *filename);
void save_ppm(const char *filename, Image *img);
void flip_image(Image *img);
void adjust_brightness(Image *img, int amount);
void adjust_contrast(Image *img, float factor);
void free_image(Image *img);

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s <input.ppm> <output.ppm> <brightness> <contrast>\n", argv[0]);
        return 1;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    int brightness = atoi(argv[3]);
    float contrast = atof(argv[4]);

    Image *img = load_ppm(input_filename);
    if (!img) {
        fprintf(stderr, "Failed to load image.\n");
        return 1;
    }

    flip_image(img);
    adjust_brightness(img, brightness);
    adjust_contrast(img, contrast);
    
    save_ppm(output_filename, img);
    free_image(img);

    printf("Image processing completed. Output saved to %s\n", output_filename);
    return 0;
}

Image* load_ppm(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("File opening failed");
        return NULL;
    }
    
    char buffer[16];
    int width, height, max_color;
    
    if (!fgets(buffer, sizeof(buffer), file)) {
        perror("Failed to read image");
        fclose(file);
        return NULL;
    }
    
    if (buffer[0] != 'P' || buffer[1] != '6') {
        fprintf(stderr, "Not a valid PPM file.\n");
        fclose(file);
        return NULL;
    }

    fscanf(file, "%d %d %d", &width, &height, &max_color);
    fgetc(file); // consume the newline character after max_color

    Image *img = malloc(sizeof(Image));
    if (!img) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(file);
        return NULL;
    }

    img->width = width;
    img->height = height;
    img->data = malloc(width * height * sizeof(Pixel));
    
    if (!img->data) {
        free(img);
        fprintf(stderr, "Memory allocation failed for image data.\n");
        fclose(file);
        return NULL;
    }

    fread(img->data, sizeof(Pixel), width * height, file);
    fclose(file);
    return img;
}

void save_ppm(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("File opening failed");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void flip_image(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            Pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[y * img->width + (img->width - 1 - x)];
            img->data[y * img->width + (img->width - 1 - x)] = temp;
        }
    }
}

void adjust_brightness(Image *img, int amount) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (img->data[i].r + amount > 255) ? 255 : (img->data[i].r + amount < 0) ? 0 : img->data[i].r + amount;
        img->data[i].g = (img->data[i].g + amount > 255) ? 255 : (img->data[i].g + amount < 0) ? 0 : img->data[i].g + amount;
        img->data[i].b = (img->data[i].b + amount > 255) ? 255 : (img->data[i].b + amount < 0) ? 0 : img->data[i].b + amount;
    }
}

void adjust_contrast(Image *img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (unsigned char)((((img->data[i].r / 255.0) - 0.5) * factor + 0.5) * 255);
        img->data[i].g = (unsigned char)((((img->data[i].g / 255.0) - 0.5) * factor + 0.5) * 255);
        img->data[i].b = (unsigned char)((((img->data[i].b / 255.0) - 0.5) * factor + 0.5) * 255);
    }
}

void free_image(Image *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}