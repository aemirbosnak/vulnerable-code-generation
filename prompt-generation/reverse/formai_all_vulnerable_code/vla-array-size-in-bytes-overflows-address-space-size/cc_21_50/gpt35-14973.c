//FormAI DATASET v1.0 Category: Image Editor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MAX_PIXEL_VALUE 255

typedef struct {
    int width;
    int height;
    int pixels[MAX_SIZE][MAX_SIZE];
} Image;

int main() {
    char input_file_name[100];
    char output_file_name[100];
    int operation;
    Image image;

    // Read input file name
    printf("Enter input file name: ");
    scanf("%s", input_file_name);

    // Read image from file
    FILE *fp = fopen(input_file_name, "r");
    if (fp == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }
    fscanf(fp, "%d %d", &image.width, &image.height);
    for (int i = 0; i < image.height; i++) {
        for (int j = 0; j < image.width; j++) {
            fscanf(fp, "%d", &image.pixels[i][j]);
        }
    }
    fclose(fp);

    // Choose operation
    printf("Choose operation:\n");
    printf("1. Invert colors\n");
    printf("2. Grayscale\n");
    printf("3. Blur\n");
    scanf("%d", &operation);

    // Perform operation
    if (operation == 1) { // Invert colors
        for (int i = 0; i < image.height; i++) {
            for (int j = 0; j < image.width; j++) {
                image.pixels[i][j] = MAX_PIXEL_VALUE - image.pixels[i][j];
            }
        }
    } else if (operation == 2) { // Grayscale
        for (int i = 0; i < image.height; i++) {
            for (int j = 0; j < image.width; j++) {
                int gray = (int) (0.299 * image.pixels[i][j] + 0.587 * image.pixels[i][j] + 0.114 * image.pixels[i][j]);
                image.pixels[i][j] = gray;
            }
        }
    } else if (operation == 3) { // Blur
        int kernel_size;
        printf("Enter kernel size: ");
        scanf("%d", &kernel_size);

        int kernel[kernel_size][kernel_size];
        int kernel_sum = 0;
        for (int i = 0; i < kernel_size; i++) {
            for (int j = 0; j < kernel_size; j++) {
                printf("Enter value for kernel[%d][%d]: ", i, j);
                scanf("%d", &kernel[i][j]);
                kernel_sum += kernel[i][j];
            }
        }

        for (int i = 0; i < image.height; i++) {
            for (int j = 0; j < image.width; j++) {
                int sum = 0;
                for (int k = -kernel_size / 2; k <= kernel_size / 2; k++) {
                    for (int l = -kernel_size / 2; l <= kernel_size / 2; l++) {
                        int ii = i + k;
                        int jj = j + l;
                        if (ii >= 0 && ii < image.height && jj >= 0 && jj < image.width) {
                            sum += kernel[k + kernel_size / 2][l + kernel_size / 2] * image.pixels[ii][jj];
                        }
                    }
                }
                image.pixels[i][j] = sum / kernel_sum;
            }
        }
    } else {
        printf("Invalid operation\n");
        exit(1);
    }

    // Write output file name
    printf("Enter output file name: ");
    scanf("%s", output_file_name);

    // Write image to file
    fp = fopen(output_file_name, "w");
    if (fp == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }
    fprintf(fp, "%d %d\n", image.width, image.height);
    for (int i = 0; i < image.height; i++) {
        for (int j = 0; j < image.width; j++) {
            fprintf(fp, "%d ", image.pixels[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);

    return 0;
}