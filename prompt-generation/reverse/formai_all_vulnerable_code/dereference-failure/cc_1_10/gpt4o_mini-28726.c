//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jpeglib.h>
#include <ctype.h>
#include <dirent.h>
#include <math.h>

#define MAX_IMAGES 100
#define IMAGE_WIDTH 128
#define IMAGE_HEIGHT 128

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    Pixel pixels[IMAGE_WIDTH][IMAGE_HEIGHT];
} Image;

char *categories[] = {"cat", "dog", "bird", "fish", "horse", "unknown"};
int num_categories = sizeof(categories) / sizeof(categories[0]);

Image *load_image(const char *filename) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    
    FILE *infile;
    unsigned char *buffer;
    Image *img;

    if ((infile = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "Error opening file %s!\n", filename);
        return NULL;
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    if (cinfo.output_width != IMAGE_WIDTH || cinfo.output_height != IMAGE_HEIGHT) {
        fprintf(stderr, "Image %s is not the correct size (expected %dx%d)\n",
                filename, IMAGE_WIDTH, IMAGE_HEIGHT);
        jpeg_destroy_decompress(&cinfo);
        fclose(infile);
        return NULL;
    }

    img = (Image *)malloc(sizeof(Image));
    buffer = (unsigned char *)malloc(cinfo.output_width * cinfo.output_height * 3);

    while (cinfo.output_scanline < cinfo.output_height) {
        unsigned char *buffer_array[] = {buffer + (cinfo.output_scanline) * cinfo.output_width * 3};
        jpeg_read_scanlines(&cinfo, buffer_array, 1);
    }

    for (int y = 0; y < IMAGE_HEIGHT; y++) {
        for (int x = 0; x < IMAGE_WIDTH; x++) {
            int idx = (y * cinfo.output_width + x) * 3;
            img->pixels[x][y].r = buffer[idx];
            img->pixels[x][y].g = buffer[idx + 1];
            img->pixels[x][y].b = buffer[idx + 2];
        }
    }

    free(buffer);
    jpeg_destroy_decompress(&cinfo);
    fclose(infile);
    
    return img;
}

double calculate_color_variance(Image *image) {
    double r_mean = 0, g_mean = 0, b_mean = 0;
    double r_var = 0, g_var = 0, b_var = 0;
    int total_pixels = IMAGE_WIDTH * IMAGE_HEIGHT;

    for (int y = 0; y < IMAGE_HEIGHT; y++) {
        for (int x = 0; x < IMAGE_WIDTH; x++) {
            r_mean += image->pixels[x][y].r;
            g_mean += image->pixels[x][y].g;
            b_mean += image->pixels[x][y].b;
        }
    }

    r_mean /= total_pixels;
    g_mean /= total_pixels;
    b_mean /= total_pixels;

    for (int y = 0; y < IMAGE_HEIGHT; y++) {
        for (int x = 0; x < IMAGE_WIDTH; x++) {
            r_var += pow(image->pixels[x][y].r - r_mean, 2);
            g_var += pow(image->pixels[x][y].g - g_mean, 2);
            b_var += pow(image->pixels[x][y].b - b_mean, 2);
        }
    }

    r_var /= total_pixels;
    g_var /= total_pixels;
    b_var /= total_pixels;

    return (r_var + g_var + b_var) / 3.0;
}

int classify_image(Image *image) {
    double variance = calculate_color_variance(image);

    if (variance < 65000) {
        return 0; // Cat
    } else if (variance < 85000) {
        return 1; // Dog
    } else if (variance < 105000) {
        return 2; // Bird
    } else if (variance < 125000) {
        return 3; // Fish
    } else {
        return 4; // Horse
    }
}

void classify_images_in_directory(const char *directory) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(directory)) == NULL) {
        fprintf(stderr, "Could not open directory %s\n", directory);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            char filepath[256];
            sprintf(filepath, "%s/%s", directory, entry->d_name);

            Image *img = load_image(filepath);
            if (img) {
                int classification = classify_image(img);
                printf("Image: %s classified as %s\n", entry->d_name, categories[classification]);
                free(img);
            }
        }
    }
    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    classify_images_in_directory(argv[1]);
    return EXIT_SUCCESS;
}