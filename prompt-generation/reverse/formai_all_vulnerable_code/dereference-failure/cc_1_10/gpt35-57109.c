//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMG_WIDTH 640
#define IMG_HEIGHT 480

typedef struct {
    unsigned char r, g, b; // Red, green, blue
} Pixel;

typedef struct {
    Pixel pixels[IMG_HEIGHT][IMG_WIDTH]; // 2D array of pixels
    int width, height;
} Image;

Image load_image(const char* filename) {
    FILE* fp;
    Image img;

    fp = fopen(filename, "rb");

    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file %s", filename);
        exit(EXIT_FAILURE);
    }

    // Read BMP header (54 bytes)
    fseek(fp, 18, SEEK_SET);
    img.width = fread(&img.width, sizeof(int), 1, fp);
    img.height = fread(&img.height, sizeof(int), 1, fp);
    fseek(fp, 28, SEEK_SET);
    int bits_per_pixel = 0;
    fread(&bits_per_pixel, sizeof(short), 1, fp);

    if (bits_per_pixel != 24) {
        fprintf(stderr, "Error: BMP file must have 24 bits per pixel\n");
        exit(EXIT_FAILURE);
    }

    // Read pixel data (3 bytes per pixel)
    fseek(fp, 54, SEEK_SET);

    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            Pixel p;
            fread(&p.b, 1, 1, fp);
            fread(&p.g, 1, 1, fp);
            fread(&p.r, 1, 1, fp);
            img.pixels[y][x] = p;
        }

        int extra_bytes = (4 - (img.width * 3) % 4) % 4;
        fseek(fp, extra_bytes, SEEK_CUR);
    }

    fclose(fp);
    return img;
}

void save_image(const char* filename, Image img) {
    FILE* fp;

    fp = fopen(filename, "wb");

    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file %s", filename);
        exit(EXIT_FAILURE);
    }

    // Write BMP header (54 bytes)
    int file_size = img.width * img.height * 3 + 54;
    char bmp_header[54] = {
        'B', 'M', // Magic number (2 bytes)
        file_size & 0xFF, (file_size >> 8) & 0xFF, (file_size >> 16) & 0xFF, (file_size >> 24) & 0xFF, // File size (4 bytes)
        0, 0, 0, 0, // Reserved (4 bytes)
        54, 0, 0, 0, // Data offset (4 bytes)
        40, 0, 0, 0, // Header size (4 bytes)
        img.width & 0xFF, (img.width >> 8) & 0xFF, (img.width >> 16) & 0xFF, (img.width >> 24) & 0xFF, // Image width (4 bytes)
        img.height & 0xFF, (img.height >> 8) & 0xFF, (img.height >> 16) & 0xFF, (img.height >> 24) & 0xFF, // Image height (4 bytes)
        1, 0, // Number of color planes (2 bytes)
        24, 0, // Bits per pixel (2 bytes)
        0, 0, 0, 0, // Compression (4 bytes)
        0, 0, 0, 0, // Image size (4 bytes)
        0, 0, 0, 0, // X pixels per meter (4 bytes)
        0, 0, 0, 0, // Y pixels per meter (4 bytes)
        0, 0, 0, 0, // Number of colors (4 bytes)
        0, 0, 0, 0  // Important colors (4 bytes)
    };
    fwrite(bmp_header, sizeof(char), 54, fp);

    // Write pixel data (3 bytes per pixel)
    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            fwrite(&img.pixels[y][x].b, 1, 1, fp);
            fwrite(&img.pixels[y][x].g, 1, 1, fp);
            fwrite(&img.pixels[y][x].r, 1, 1, fp);
        }

        int extra_bytes = (4 - (img.width * 3) % 4) % 4;

        for (int i = 0; i < extra_bytes; i++) {
            fputc(0, fp);
        }
    }

    fclose(fp);
}

Image flip_image(Image img) {
    Image flipped_img = img;

    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width / 2; x++) {
            Pixel temp = flipped_img.pixels[y][x];
            flipped_img.pixels[y][x] = flipped_img.pixels[y][img.width - x - 1];
            flipped_img.pixels[y][img.width - x - 1] = temp;
        }
    }

    return flipped_img;
}

Image adjust_brightness(Image img, int brightness) {
    Image adjusted_img = img;

    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            adjusted_img.pixels[y][x].r = fmin(255, fmax(0, img.pixels[y][x].r + brightness));
            adjusted_img.pixels[y][x].g = fmin(255, fmax(0, img.pixels[y][x].g + brightness));
            adjusted_img.pixels[y][x].b = fmin(255, fmax(0, img.pixels[y][x].b + brightness));
        }
    }

    return adjusted_img;
}

Image adjust_contrast(Image img, float contrast) {
    Image adjusted_img = img;

    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            adjusted_img.pixels[y][x].r = fmin(255, fmax(0, ((img.pixels[y][x].r - 127.5) * contrast + 127.5)));
            adjusted_img.pixels[y][x].g = fmin(255, fmax(0, ((img.pixels[y][x].g - 127.5) * contrast + 127.5)));
            adjusted_img.pixels[y][x].b = fmin(255, fmax(0, ((img.pixels[y][x].b - 127.5) * contrast + 127.5)));
        }
    }

    return adjusted_img;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <input_file> [output_file]\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* input_file = argv[1];
    const char* output_file;

    if (argc < 3) {
        output_file = "output.bmp";
    } else {
        output_file = argv[2];
    }

    Image img = load_image(input_file);

    // Flip image
    Image flipped_img = flip_image(img);
    save_image("flipped.bmp", flipped_img);

    // Adjust brightness
    Image brightened_img = adjust_brightness(img, 50);
    save_image("brightened.bmp", brightened_img);

    // Adjust contrast
    Image contrasted_img = adjust_contrast(img, 1.5);
    save_image("contrasted.bmp", contrasted_img);

    return EXIT_SUCCESS;
}