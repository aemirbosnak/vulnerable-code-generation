//FormAI DATASET v1.0 Category: Image Editor ; Style: immersive
/* Welcome to Pixel Pro, a simple yet powerful image editor written in C! */

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    unsigned char red, green, blue;
} pixel;

typedef struct {
    int width, height;
    pixel *data;
} image;

/* Function to read an image from a file */
image* read_image(char *file_name) {
    FILE *file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Error: Could not open file %s!", file_name);
        return NULL;
    }

    char format[3];
    fscanf(file, "%s\n", format);
    if (format[0] != 'P' || format[1] != '6') {
        printf("Error: Invalid file format! %s is not a valid PPM file.", file_name);
        return NULL;
    }

    int width, height;
    fscanf(file, "%d %d\n", &width, &height);

    int max_color;
    fscanf(file, "%d\n", &max_color);

    if (max_color > 255) {
        printf("Error: The image uses 16-bit colors, which are not supported by this editor.");
        return NULL;
    }

    image *img = (image*) malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->data = (pixel*) malloc(sizeof(pixel) * width * height);

    fread(img->data, sizeof(pixel), width * height, file);

    fclose(file);

    return img;
}

/* Function to write an image to a file */
void write_image(char *file_name, image *img) {
    FILE *file = fopen(file_name, "wb");
    if (file == NULL) {
        printf("Error: Could not create file %s!", file_name);
        return;
    }

    fprintf(file, "P6\n");
    fprintf(file, "%d %d\n", img->width, img->height);
    fprintf(file, "255\n");

    fwrite(img->data, sizeof(pixel), img->width * img->height, file);

    fclose(file);
}

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];

    printf("Welcome to Pixel Pro, an image editor written in C.\n\n");

    /* Read image from file */
    printf("Please enter the name of the image file you want to edit: ");
    scanf("%s", file_name);

    image *img = read_image(file_name);
    if (img == NULL) return 0;

    /* Apply filters */
    printf("\n");

    printf("1. Invert colors\n");
    printf("2. Grayscale\n");
    printf("3. Blur\n");
    printf("\n");

    int choice = 0;
    while (choice < 1 || choice > 3) {
        printf("Please choose a filter (1-3): ");
        scanf("%d", &choice);
    }

    if (choice == 1) {
        /* Invert colors */
        for (int i = 0; i < img->width * img->height; i++) {
            img->data[i].red = 255 - img->data[i].red;
            img->data[i].green = 255 - img->data[i].green;
            img->data[i].blue = 255 - img->data[i].blue;
        }
    } else if (choice == 2) {
        /* Grayscale */
        for (int i = 0; i < img->width * img->height; i++) {
            unsigned char gray = (img->data[i].red + img->data[i].green + img->data[i].blue) / 3;
            img->data[i].red = gray;
            img->data[i].green = gray;
            img->data[i].blue = gray;
        }
    } else if (choice == 3) {
        /* Blur */
        pixel *temp = (pixel*) malloc(sizeof(pixel) * img->width * img->height);

        for (int i = 0; i < img->width; i++) {
            for (int j = 0; j < img->height; j++) {
                int red = 0, green = 0, blue = 0, count = 0;

                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        if (x >= 0 && y >= 0 && x < img->width && y < img->height) {
                            red += img->data[y * img->width + x].red;
                            green += img->data[y * img->width + x].green;
                            blue += img->data[y * img->width + x].blue;
                            count++;
                        }
                    }
                }

                temp[j * img->width + i].red = red / count;
                temp[j * img->width + i].green = green / count;
                temp[j * img->width + i].blue = blue / count;
            }
        }

        free(img->data);
        img->data = temp;
    }

    /* Write image to file */
    printf("\n");

    printf("Please enter the name of the output file: ");
    scanf("%s", file_name);

    write_image(file_name, img);

    printf("\nThe edited image has been saved to %s.\n", file_name);

    free(img->data);
    free(img);

    return 0;
}