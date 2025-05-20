//FormAI DATASET v1.0 Category: Image Editor ; Style: careful
/* C Image Editor */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to read the image file */
int * readImage(char* filename, int *rows, int *cols) {
    FILE *fp;
    int temp, i, j;
    int *img;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error Opening File: %s\n", filename);
        return NULL;
    }

    fscanf(fp, "%d %d", rows, cols);  // read the dimensions of the image
    img = (int*)malloc(sizeof(int) * (*rows) * (*cols));  // allocate memory for the image

    for (i = 0; i < (*rows); i++) {
        for (j = 0; j < (*cols); j++) {
            fscanf(fp, "%d", &temp);
            *(img + i*(*cols) + j) = temp;  // assign pixel values to the image array
        }
    }

    fclose(fp);
    return img;
}

/* Function to write the image file */
void writeImage(int *img, int rows, int cols, char* filename) {
    FILE *fp;
    int i, j;

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error Opening File: %s\n", filename);
        return;
    }

    fprintf(fp, "%d %d\n", rows, cols);  // write the dimensions of the image

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            fprintf(fp, "%d ", *(img + i*cols + j));  // write pixel values to the file
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

/* Function to flip the image vertically */
void flipVertical(int *img, int rows, int cols) {
    int i, j, temp;

    for (i = 0; i < rows/2; i++) {
        for (j = 0; j < cols; j++) {
            temp = *(img + i*cols + j);
            *(img + i*cols + j) = *(img + (rows-i-1)*cols + j);
            *(img + (rows-i-1)*cols + j) = temp;  // swapping values
        }
    }
}

/* Function to apply grayscale filter to the image */
void grayscaleFilter(int *img, int rows, int cols) {
    int i, j, avg;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            avg = (*(img + i*cols + j) & 0xff) + ((*(img + i*cols + j) >> 8) & 0xff) + ((*(img + i*cols + j) >> 16) & 0xff);
            avg /= 3;
            *(img + i*cols + j) = (avg << 16) | (avg << 8) | avg;  // averaging RGB values and assigning back to the pixel
        }
    }
}

/* Main function */
int main() {
    int *img, rows, cols, choice;
    char filename[50];

    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    img = readImage(filename, &rows, &cols);  // reading the image file
    if (img == NULL) {
        printf("Program Exiting...\n");
        return 1;
    }

    printf("\nImage Dimensions: %d x %d\n", rows, cols);

    printf("\nWhat operation do you want to perform on the image?\n");
    printf("1. Flip the Image Vertically\n");
    printf("2. Apply Grayscale Filter\n");
    printf("3. Save the Image\n");
    printf("4. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                flipVertical(img, rows, cols);
                printf("\nImage Flipped Vertically.\n");
                break;

            case 2:
                grayscaleFilter(img, rows, cols);
                printf("\nGrayscale Filter Applied.\n");
                break;

            case 3:
                printf("\nEnter the name of the output file: ");
                scanf("%s", filename);
                writeImage(img, rows, cols, filename);
                printf("\nImage Saved Successfully.\n");
                break;

            case 4:
                printf("\nProgram Exiting...\n");
                break;

            default:
                printf("\nInvalid Choice. Please Try Again.\n");
                break;
        }
    } while (choice != 4);

    free(img);  // freeing the memory allocated for the image

    return 0;
}