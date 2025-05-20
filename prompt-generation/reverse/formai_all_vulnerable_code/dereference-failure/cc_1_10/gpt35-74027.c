//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_FILENAME_SIZE 256
#define MAX_PIXEL_VALUE 255
#define MIN_PIXEL_VALUE 0

typedef struct {
    int rows;
    int cols;
    unsigned char *data;
} Image;

void image_read(Image *img, char *filename) {
    FILE *fp;
    char magic_number[128];
    int max_value;

    fp = fopen(filename, "rb");
    if (!fp) {
        printf("Failed to open file: %s\n", filename);
        exit(1);
    }

    fgets(magic_number, sizeof(magic_number), fp);
    if (strncmp(magic_number, "P5", 2) != 0) {
        printf("File format not supported: %s\n", magic_number);
        exit(1);
    }

    while (isspace(fgetc(fp)));
    fseek(fp, -1, SEEK_CUR);

    fscanf(fp, "%d %d\n", &img->cols, &img->rows);
    fscanf(fp, "%d\n", &max_value);

    img->data = (unsigned char *)malloc(img->rows * img->cols * sizeof(unsigned char));
    if (!img->data) {
        printf("Failed to allocate memory!\n");
        exit(1);
    }

    fread(img->data, sizeof(char), img->rows * img->cols, fp);

    fclose(fp);
}

void image_write(Image *img, char *filename) {
    FILE *fp;

    fp = fopen(filename, "wb");
    if (!fp) {
        printf("Failed to open file: %s\n", filename);
        exit(1);
    }

    fprintf(fp, "P5\n");
    fprintf(fp, "%d %d\n", img->cols, img->rows);
    fprintf(fp, "%d\n", MAX_PIXEL_VALUE);

    fwrite(img->data, sizeof(char), img->rows * img->cols, fp);

    fclose(fp);
}

void image_free(Image *img) {
    free(img->data);
    img->rows = 0;
    img->cols = 0;
    img->data = NULL;
}

void image_flip_horizontally(Image *img) {
    unsigned char temp;
    int row, col;

    for (row = 0; row < img->rows; row++) {
        for (col = 0; col < img->cols / 2; col++) {
            temp = img->data[row * img->cols + col];
            img->data[row * img->cols + col] = img->data[row * img->cols + (img->cols - col - 1)];
            img->data[row * img->cols + (img->cols - col - 1)] = temp;
        }
    }
}

void image_flip_vertically(Image *img) {
    unsigned char temp;
    int row, col;

    for (col = 0; col < img->cols; col++) {
        for (row = 0; row < img->rows / 2; row++) {
            temp = img->data[row * img->cols + col];
            img->data[row * img->cols + col] = img->data[(img->rows - row - 1) * img->cols + col];
            img->data[(img->rows - row - 1) * img->cols + col] = temp;
        }
    }
}

void image_adjust_brightness(Image *img, int level) {
    int row, col;
    int value;

    for (row = 0; row < img->rows; row++) {
        for (col = 0; col < img->cols; col++) {
            value = img->data[row * img->cols + col] + level;
            img->data[row * img->cols + col] = (unsigned char)fmax(MIN_PIXEL_VALUE, fmin(value, MAX_PIXEL_VALUE));
        }
    }
}

void image_adjust_contrast(Image *img, float level) {
    int row, col;
    float value;

    for (row = 0; row < img->rows; row++) {
        for (col = 0; col < img->cols; col++) {
            value = (img->data[row * img->cols + col] - 128.0) * level + 128.0;
            img->data[row * img->cols + col] = (unsigned char)fmax(MIN_PIXEL_VALUE, fmin(value, MAX_PIXEL_VALUE));
        }
    }
}

int main(int argc, char **argv) {
    Image img;
    char input_filename[MAX_FILENAME_SIZE], output_filename[MAX_FILENAME_SIZE];
    int option, level;
    float factor;

    printf("Enter the input filename: ");
    scanf("%s", input_filename);
    image_read(&img, input_filename);

    printf("Enter the output filename: ");
    scanf("%s", output_filename);

    printf("Choose an option:\n");
    printf("1. Flip Horizontally\n");
    printf("2. Flip Vertically\n");
    printf("3. Adjust Brightness\n");
    printf("4. Adjust Contrast\n");
    printf("5. Exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                image_flip_horizontally(&img);
                printf("Image flipped horizontally!\n");
                break;
            case 2:
                image_flip_vertically(&img);
                printf("Image flipped vertically!\n");
                break;
            case 3:
                printf("Enter the brightness level (-255 to 255): ");
                scanf("%d", &level);
                image_adjust_brightness(&img, level);
                printf("Brightness adjusted!\n");
                break;
            case 4:
                printf("Enter the contrast level (0.0 to 2.0): ");
                scanf("%f", &factor);
                image_adjust_contrast(&img, factor);
                printf("Contrast adjusted!\n");
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid option! Try again.\n");
        }

        if (option >= 1 && option <= 4) {
            image_write(&img, output_filename);
            printf("Output written to %s\n", output_filename);
        }

    } while (option != 5);

    image_free(&img);

    return 0;
}