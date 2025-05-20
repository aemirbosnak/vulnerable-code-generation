//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Function to load a PGM image
Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    char format[3];
    fscanf(file, "%2s", format);
    if (strcmp(format, "P5") != 0) {
        fclose(file);
        fprintf(stderr, "Unsupported image format. Only P5 (PGM) is supported.\n");
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    fscanf(file, "%d %d", &(image->width), &(image->height));
    int max_val;
    fscanf(file, "%d", &max_val);
    fgetc(file); // read the newline character

    image->data = (unsigned char *)malloc(image->width * image->height);
    fread(image->data, 1, image->width * image->height, file);
    fclose(file);
    return image;
}

// Function to save a PGM image
void save_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }

    fprintf(file, "P5\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, 1, image->width * image->height, file);
    fclose(file);
}

// Function to invert the image colors
void invert_image(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i] = 255 - image->data[i];
    }
}

// Function to free the image memory
void free_image(Image *image) {
    if (image) {
        free(image->data);
        free(image);
    }
}

// Function to print the menu
void print_menu() {
    printf("Image Editor Menu:\n");
    printf("1. Invert Image\n");
    printf("2. Save Image\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_image.pgm> <output_image.pgm>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    int choice;
    while (1) {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                invert_image(image);
                printf("Image inverted successfully.\n");
                break;
            case 2:
                save_image(argv[2], image);
                printf("Image saved successfully as %s.\n", argv[2]);
                break;
            case 3:
                free_image(image);
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    free_image(image);
    return 0;
}