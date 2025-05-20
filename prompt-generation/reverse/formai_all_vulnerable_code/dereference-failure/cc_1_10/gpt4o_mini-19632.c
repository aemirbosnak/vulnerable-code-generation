//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *data;
} Image;

Image* load_ppm(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        return NULL;
    }

    char header[3];
    fscanf(file, "%2s", header);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Error: Unsupported PPM format\n");
        fclose(file);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    fscanf(file, "%d %d", &image->width, &image->height);
    fscanf(file, "%*d");  // Skip the max color value (assumed as 255)

    size_t size = image->width * image->height;
    image->data = malloc(size * sizeof(Pixel));
    fread(image->data, sizeof(Pixel), size, file);
    
    fclose(file);
    return image;
}

void save_ppm(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: Cannot write to file %s\n", filename);
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, sizeof(Pixel), image->width * image->height, file);
    
    fclose(file);
}

void flip_horizontal(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            Pixel temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[y * image->width + (image->width - 1 - x)];
            image->data[y * image->width + (image->width - 1 - x)] = temp;
        }
    }
}

void convert_to_grayscale(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        unsigned char gray = (image->data[i].r + image->data[i].g + image->data[i].b) / 3;
        image->data[i].r = gray;
        image->data[i].g = gray;
        image->data[i].b = gray;
    }
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

void print_menu() {
    printf("Simple PPM Image Editor\n");
    printf("1. Load Image\n");
    printf("2. Flip Image Horizontally\n");
    printf("3. Convert to Grayscale\n");
    printf("4. Save Image\n");
    printf("5. Exit\n");
}

int main() {
    Image *image = NULL;
    char filename[256];
    int choice;

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the image filename (including .ppm): ");
                scanf("%s", filename);
                image = load_ppm(filename);
                if (image) {
                    printf("Loaded image: %s (%dx%d)\n", filename, image->width, image->height);
                }
                break;
            case 2:
                if (image) {
                    flip_horizontal(image);
                    printf("Image flipped horizontally.\n");
                } else {
                    printf("Load an image first!\n");
                }
                break;
            case 3:
                if (image) {
                    convert_to_grayscale(image);
                    printf("Image converted to grayscale.\n");
                } else {
                    printf("Load an image first!\n");
                }
                break;
            case 4:
                if (image) {
                    printf("Enter the output filename (including .ppm): ");
                    scanf("%s", filename);
                    save_ppm(filename, image);
                    printf("Image saved as: %s\n", filename);
                } else {
                    printf("Load an image first!\n");
                }
                break;
            case 5:
                free_image(image);
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}