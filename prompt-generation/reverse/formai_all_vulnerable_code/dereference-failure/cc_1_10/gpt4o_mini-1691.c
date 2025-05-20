//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} Pixel;

typedef struct {
    Pixel *data;
    int width;
    int height;
} Image;

Image *create_image(int width, int height) {
    Image *img = (Image *)malloc(sizeof(Image));
    img->data = (Pixel *)malloc(width * height * sizeof(Pixel));
    img->width = width;
    img->height = height;
    return img;
}

void free_image(Image *img) {
    free(img->data);
    free(img);
}

void set_pixel(Image *img, int x, int y, uint8_t r, uint8_t g, uint8_t b) {
    if (x < 0 || x >= img->width || y < 0 || y >= img->height) return;
    img->data[y * img->width + x].r = r;
    img->data[y * img->width + x].g = g;
    img->data[y * img->width + x].b = b;
}

Pixel get_pixel(const Image *img, int x, int y) {
    if (x < 0 || x >= img->width || y < 0 || y >= img->height) {
        return (Pixel){0, 0, 0}; // Return black for out of bounds
    }
    return img->data[y * img->width + x];
}

void save_image(const char *filename, Image *img) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Error opening file");
        return;
    }
    
    // Write a simple PPM header
    fprintf(fp, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, fp);
    fclose(fp);
}

void apply_watermark(Image *img, const char *watermark, int wm_x, int wm_y) {
    for (int i = 0; i < strlen(watermark); i++) {
        // Simple watermarker: change pixel colors based on characters
        uint8_t r = (uint8_t)(watermark[i] % 256);
        uint8_t g = (uint8_t)((watermark[i] * 2) % 256);
        uint8_t b = (uint8_t)((watermark[i] * 5) % 256);
        
        set_pixel(img, wm_x + i, wm_y, r, g, b);
    }
}

void generate_image_with_watermark(const char *filename, const char *watermark) {
    Image *img = create_image(WIDTH, HEIGHT);
    
    // Fill the image with a gradient
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            set_pixel(img, x, y, (uint8_t)(x % 256), (uint8_t)(y % 256), 128);
        }
    }
    
    // Apply the watermark
    apply_watermark(img, watermark, 50, 50);
    
    // Save the image
    save_image(filename, img);
    
    // Clean up
    free_image(img);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <output_image.ppm> <watermark_text>\n", argv[0]);
        return EXIT_FAILURE;
    }

    generate_image_with_watermark(argv[1], argv[2]);
    printf("Image with watermark created: %s\n", argv[1]);
    
    return EXIT_SUCCESS;
}