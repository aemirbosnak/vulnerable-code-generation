//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>

/* Function declarations */
void flip_image(int rows, int cols, unsigned char image[rows][cols]);
void change_brightness(int rows, int cols, unsigned char image[rows][cols], int brightness);

/* Function definitions */

/* Function to flip the given image horizontally */
void flip_image(int rows, int cols, unsigned char image[rows][cols]) {
    int i, j;
    unsigned char temp;

    for(i=0; i<rows; i++) {
        for(j=0; j<cols/2; j++) {
            temp = image[i][j];
            image[i][j] = image[i][cols-j-1];
            image[i][cols-j-1] = temp;
        }
    }
}

/* Function to change the brightness and contrast of the given image */
void change_brightness(int rows, int cols, unsigned char image[rows][cols], int brightness) {
    int i, j;
    float factor = (259.0 * (brightness + 255.0)) / (255.0 * (259.0 - brightness));

    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            image[i][j] = (unsigned char)(factor * (image[i][j] - 128.0) + 128.0);
        }
    }
}

/* Main function */
int main() {
    int choice, brightness;
    bool flag = false;
    char ch;
    FILE *fp;
    int rows, cols, maxval;

    /* Read the image file */
    fp = fopen("image.pgm", "rb");
    if(fp == NULL) {
        printf("Cannot open image file\n");
        exit(1);
    }
    ch = getc(fp);
    if(ch != 'P' && ch != 'p') {
        printf("Invalid image format\n");
        exit(1);
    }
    ch = getc(fp);
    if(ch != '5') {
        printf("Invalid image format\n");
        exit(1);
    }
    ch = getc(fp);
    while(ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
        ch = getc(fp);
    }
    if(ch == '#') {
        while(ch == '#') {
            while(getc(fp) != '\n');
            ch = getc(fp);
        }
    }
    fseek(fp, -1, SEEK_CUR);
    fscanf(fp, "%d %d %d", &cols, &rows, &maxval);
    while(getc(fp) != '\n');
    if(maxval != 255) {
        printf("Image format not supported\n");
        exit(1);
    }
    unsigned char image[rows][cols];
    fread(image, sizeof(unsigned char), rows * cols, fp);
    fclose(fp);

    /* Display menu and take user choice */
    while(true) {
        printf("\n\nImage Processing Menu\n");
        printf("----------------------\n");
        printf("1. Flip Horizontally\n");
        printf("2. Change Brightness and Contrast\n");
        printf("3. Save Image\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: flip_image(rows, cols, image);
                    printf("Image flipped horizontally\n");
                    break;

            case 2: printf("Enter brightness value (-255 to 255): ");
                    scanf("%d", &brightness);
                    change_brightness(rows, cols, image, brightness);
                    printf("Brightness and contrast changed\n");
                    break;

            case 3: printf("Enter file name to save image: ");
                    scanf("%s", &ch);
                    fp = fopen(ch, "wb");
                    if(fp == NULL) {
                        printf("Cannot open output file\n");
                        exit(1);
                    }
                    fprintf(fp, "P5\n%d %d\n%d\n", cols, rows, maxval);
                    fwrite(image, sizeof(unsigned char), rows * cols, fp);
                    printf("Image saved to file\n");
                    fclose(fp);
                    break;

            case 4: flag = true;
                    break;

            default:printf("Invalid choice\n");
                    break;
        }

        if(flag == true) {
            break;
        }
    }

    printf("\nThank you for using our Image Processing software\n");
    return 0;
}