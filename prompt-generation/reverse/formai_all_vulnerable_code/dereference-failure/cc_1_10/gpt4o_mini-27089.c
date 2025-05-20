//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel* data;
} Image;

Image* read_ppm(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return NULL;
    }

    Image* img = malloc(sizeof(Image));
    if (!img) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return NULL;
    }

    char header[3];
    fscanf(file, "%s %d %d 255", header, &img->width, &img->height);
    fgetc(file); // To consume the newline character after the header

    img->data = malloc(img->width * img->height * sizeof(Pixel));
    if (!img->data) {
        fprintf(stderr, "Memory allocation for image data failed\n");
        free(img);
        fclose(file);
        return NULL;
    }

    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    return img;
}

void write_ppm(const char* filename, Image* img) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Could not open file %s for writing\n", filename);
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void flip_image(Image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            Pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[y * img->width + (img->width - 1 - x)];
            img->data[y * img->width + (img->width - 1 - x)] = temp;
        }
    }
}

void change_brightness(Image* img, int delta) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (unsigned char) fmin(fmax(img->data[i].r + delta, 0), 255);
        img->data[i].g = (unsigned char) fmin(fmax(img->data[i].g + delta, 0), 255);
        img->data[i].b = (unsigned char) fmin(fmax(img->data[i].b + delta, 0), 255);
    }
}

void change_contrast(Image* img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (unsigned char) fmin(fmax((int)(img->data[i].r * factor), 0), 255);
        img->data[i].g = (unsigned char) fmin(fmax((int)(img->data[i].g * factor), 0), 255);
        img->data[i].b = (unsigned char) fmin(fmax((int)(img->data[i].b * factor), 0), 255);
    }
}

void free_image(Image* img) {
    free(img->data);
    free(img);
}

void print_menu() {
    printf("Choose an operation:\n");
    printf("1. Flip Image\n");
    printf("2. Change Brightness\n");
    printf("3. Change Contrast\n");
    printf("4. Exit\n");
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image* img = read_ppm(argv[1]);
    if (!img) {
        return EXIT_FAILURE;
    }

    int choice;
    do {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                flip_image(img);
                printf("Image flipped!\n");
                break;
            case 2: {
                int delta;
                printf("Enter brightness change (-255 to 255): ");
                scanf("%d", &delta);
                change_brightness(img, delta);
                printf("Brightness changed!\n");
                break;
            }
            case 3: {
                float factor;
                printf("Enter contrast factor (0.0 to 3.0): ");
                scanf("%f", &factor);
                change_contrast(img, factor);
                printf("Contrast changed!\n");
                break;
            }
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);

    write_ppm(argv[2], img);
    free_image(img);
    return EXIT_SUCCESS;
}