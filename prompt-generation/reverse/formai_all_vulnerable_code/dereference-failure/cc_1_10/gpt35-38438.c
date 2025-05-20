//FormAI DATASET v1.0 Category: Image Editor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Color;

typedef struct {
    int width;
    int height;
    Color* pixels;
} Image;

Image* create_image(int width, int height) {
    Image* img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->pixels = malloc(sizeof(Color) * width * height);
    return img;
}

void destroy_image(Image* img) {
    free(img->pixels);
    free(img);
}

void set_pixel(Image* img, int x, int y, Color c) {
    if (x < 0 || x >= img->width) {
        return;
    }
    if (y < 0 || y >= img->height) {
        return;
    }
    img->pixels[y * img->width + x] = c;
}

Color get_pixel(Image* img, int x, int y) {
    if (x < 0 || x >= img->width) {
        return (Color) {0, 0, 0};
    }
    if (y < 0 || y >= img->height) {
        return (Color) {0, 0, 0};
    }
    return img->pixels[y * img->width + x];
}

void fill_image(Image* img, Color c) {
    int i, j;
    for (i = 0; i < img->width; i++) {
        for (j = 0; j < img->height; j++) {
            set_pixel(img, i, j, c);
        }
    }
}

Image* load_image(const char* filename) {
    FILE* f = fopen(filename, "rb");
    if (f == NULL) {
        return NULL;
    }

    int width, height, bpp;
    char header[54];

    // Read header
    fread(header, 54, 1, f);

    // Get dimensions
    width = *(int*)&header[18];
    height = *(int*)&header[22];
    bpp = *(int*)&header[28];

    // Allocate image
    Image* img = create_image(width, height);

    // Read pixels
    fread(img->pixels, width * height * bpp / 8, 1, f);

    fclose(f);

    return img;
}

int save_image(Image* img, const char* filename) {
    FILE* f = fopen(filename, "wb");
    if (f == NULL) {
        return 0;
    }

    // Create header
    char header[54] = {
        0x42, 0x4D,             // BMP signature
        0, 0, 0, 0,             // File size (set later)
        0, 0,                   // Reserved
        0, 0,                   // Reserved
        54, 0, 0, 0,            // Offset to pixel data
        40, 0, 0, 0,            // Header size
        0, 0, 0, 0,             // Image width (set later)
        0, 0, 0, 0,             // Image height (set later)
        1, 0,                   // Number of color planes
        24, 0,                  // Bits per pixel
        0, 0, 0, 0,             // Compression method
        0, 0, 0, 0,             // Image size (set later)
        0x13, 0x0B, 0, 0,       // Pixels per meter (set to 96 DPI)
        0x13, 0x0B, 0, 0,       // Pixels per meter (set to 96 DPI)
        0, 0, 0, 0,             // Number of colors
        0, 0, 0, 0,             // Number of important colors
    };

    // Fill in header fields
    *(int*)&header[2] = 54 + img->width * img->height * 3;
    *(int*)&header[18] = img->width;
    *(int*)&header[22] = img->height;
    *(int*)&header[34] = img->width * img->height * 3;

    // Write header
    fwrite(header, 54, 1, f);

    // Write pixels
    fwrite(img->pixels, img->width * img->height * 3, 1, f);

    fclose(f);

    return 1;
}

void scale_image(Image* img, int factor) {
    int i, j, x, y;
    Image* temp = create_image(img->width * factor, img->height * factor);

    for (i = 0; i < img->width; i++) {
        for (j = 0; j < img->height; j++) {
            Color c = get_pixel(img, i, j);
            for (x = 0; x < factor; x++) {
                for (y = 0; y < factor; y++) {
                    set_pixel(temp, i * factor + x, j * factor + y, c);
                }
            }
        }
    }

    destroy_image(img);
    img->width *= factor;
    img->height *= factor;
    img->pixels = temp->pixels;
    free(temp);
}

void grayscale(Image* img) {
    int i, j;
    for (i = 0; i < img->width; i++) {
        for (j = 0; j < img->height; j++) {
            Color c = get_pixel(img, i, j);
            unsigned char g = 0.299 * c.red + 0.587 * c.green + 0.114 * c.blue;
            set_pixel(img, i, j, (Color) {g, g, g});
        }
    }
}

void invert_colors(Image* img) {
    int i, j;
    for (i = 0; i < img->width; i++) {
        for (j = 0; j < img->height; j++) {
            Color c = get_pixel(img, i, j);
            set_pixel(img, i, j, (Color) {255 - c.red, 255 - c.green, 255 - c.blue});
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    Image* img = load_image(argv[1]);
    if (img == NULL) {
        printf("Failed to load image.\n");
        return 1;
    }

    printf("Loaded image with dimensions %d x %d.\n", img->width, img->height);

    // Modify image
    fill_image(img, (Color) {255, 0, 0});
    grayscale(img);
    invert_colors(img);
    scale_image(img, 2);

    if (!save_image(img, argv[2])) {
        printf("Failed to save image.\n");
        return 1;
    }

    printf("Saved image to %s.\n", argv[2]);

    destroy_image(img);

    return 0;
}