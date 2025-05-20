//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char **pixels;
    int width;
    int height;
} Image;

Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open the file");
        return NULL;
    }

    char header[3];
    fscanf(file, "%s", header);
    if (strcmp(header, "P2") != 0) {
        fprintf(stderr, "Unsupported file format. Only P2 (grayscale) supported.\n");
        fclose(file);
        return NULL;
    }

    Image *image = (Image *)malloc(sizeof(Image));
    fscanf(file, "%d %d", &image->width, &image->height);
    int maxval;
    fscanf(file, "%d", &maxval);

    image->pixels = (unsigned char **)malloc(image->height * sizeof(unsigned char *));
    for (int i = 0; i < image->height; ++i) {
        image->pixels[i] = (unsigned char *)malloc(image->width * sizeof(unsigned char));
        for (int j = 0; j < image->width; ++j) {
            fscanf(file, "%hhu", &image->pixels[i][j]);
        }
    }

    fclose(file);
    return image;
}

void save_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open the file for writing");
        return;
    }

    fprintf(file, "P2\n%d %d\n255\n", image->width, image->height);
    for (int i = 0; i < image->height; ++i) {
        for (int j = 0; j < image->width; ++j) {
            fprintf(file, "%hhu ", image->pixels[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

void invert_image(Image *image) {
    for (int i = 0; i < image->height; ++i) {
        for (int j = 0; j < image->width; ++j) {
            image->pixels[i][j] = 255 - image->pixels[i][j];
        }
    }
}

void free_image(Image *image) {
    for (int i = 0; i < image->height; ++i) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
}

void print_usage(const char *progname) {
    fprintf(stderr, "Usage: %s <input_image.pgm> <output_image.pgm>\n", progname);
    fprintf(stderr, "       %s -invert <input_image.pgm> <output_image.pgm>\n", progname);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];

    Image *img = NULL;

    if (strcmp(argv[1], "-invert") == 0) {
        if (argc != 4) {
            print_usage(argv[0]);
            return EXIT_FAILURE;
        }
        input_file = argv[2];
        output_file = argv[3];
        img = load_image(input_file);
        if (!img) {
            return EXIT_FAILURE;
        }
        invert_image(img);
    } else {
        img = load_image(input_file);
        if (!img) {
            return EXIT_FAILURE;
        }
    }

    save_image(output_file, img);
    free_image(img);

    return EXIT_SUCCESS;
}