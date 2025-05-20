//FormAI DATASET v1.0 Category: Image Editor ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function to convert RGB to grayscale
void grayscale(unsigned char* image, int width, int height) {
    int i, j;
    unsigned char red, green, blue, gray;

    // convert each pixel to grayscale
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            red = image[(i * width + j) * 3];
            green = image[(i * width + j) * 3 + 1];
            blue = image[(i * width + j) * 3 + 2];

            gray = (unsigned char)((float)red * 0.3 + (float)green * 0.59 + (float)blue * 0.11);

            image[(i * width + j) * 3] = gray;
            image[(i * width + j) * 3 + 1] = gray;
            image[(i * width + j) * 3 + 2] = gray;
        }
    }

    printf("Grayscale operation done!\n");
}

// function to flip the image horizontally
void flip_horizontal(unsigned char* image, int width, int height) {
    int i, j;
    unsigned char temp;

    // flip each column of pixels
    for(i = 0; i < height; i++) {
        for(j = 0; j < width / 2; j++) {
            temp = image[(i * width + j) * 3];
            image[(i * width + j) * 3] = image[(i * width + (width - j - 1)) * 3];
            image[(i * width + (width - j - 1)) * 3] = temp;

            temp = image[(i * width + j) * 3 + 1];
            image[(i * width + j) * 3 + 1] = image[(i * width + (width - j - 1)) * 3 + 1];
            image[(i * width + (width - j - 1)) * 3 + 1] = temp;

            temp = image[(i * width + j) * 3 + 2];
            image[(i * width + j) * 3 + 2] = image[(i * width + (width - j - 1)) * 3 + 2];
            image[(i * width + (width - j - 1)) * 3 + 2] = temp;
        }
    }

    printf("Horizontal flip operation done!\n");
}

// function to flip the image vertically
void flip_vertical(unsigned char* image, int width, int height) {
    int i, j;
    unsigned char temp;

    // flip each row of pixels
    for(i = 0; i < height / 2; i++) {
        for(j = 0; j < width; j++) {
            temp = image[(i * width + j) * 3];
            image[(i * width + j) * 3] = image[((height - i - 1) * width + j) * 3];
            image[((height - i - 1) * width + j) * 3] = temp;

            temp = image[(i * width + j) * 3 + 1];
            image[(i * width + j) * 3 + 1] = image[((height - i - 1) * width + j) * 3 + 1];
            image[((height - i - 1) * width + j) * 3 + 1] = temp;

            temp = image[(i * width + j) * 3 + 2];
            image[(i * width + j) * 3 + 2] = image[((height - i - 1) * width + j) * 3 + 2];
            image[((height - i - 1) * width + j) * 3 + 2] = temp;
        }
    }

    printf("Vertical flip operation done!\n");
}

int main() {
    FILE *file;
    char input_file_name[50], output_file_name[50], operation[20];
    int width, height, depth, i, j;
    unsigned char *image;

    printf("Enter input image file name (with extension): ");
    scanf("%s", input_file_name);

    file = fopen(input_file_name, "rb");
    if(!file) {
        printf("Error opening file!\n");
        return 1;
    }

    // read the header of the image
    fscanf(file, "P6\n%d %d\n%d\n", &width, &height, &depth);

    // allocate memory for the image
    image = (unsigned char*)malloc(width * height * 3);

    // read the image data
    fread(image, sizeof(unsigned char), width * height * 3, file);

    fclose(file);

    printf("Enter output image file name (with extension): ");
    scanf("%s", output_file_name);

    printf("Enter operation (grayscale or flip): ");
    scanf("%s", operation);

    if(strcmp(operation, "grayscale") == 0) {
        grayscale(image, width, height);
    }
    else if(strcmp(operation, "flip") == 0) {
        printf("Enter flip direction (horizontal or vertical): ");
        scanf("%s", operation);

        if(strcmp(operation, "horizontal") == 0) {
            flip_horizontal(image, width, height);
        }
        else if(strcmp(operation, "vertical") == 0) {
            flip_vertical(image, width, height);
        }
        else {
            printf("Invalid flip direction!\n");
            return 1;
        }
    }
    else {
        printf("Invalid operation!\n");
        return 1;
    }

    // write the modified image to file
    file = fopen(output_file_name, "wb");
    if(!file) {
        printf("Error opening file!\n");
        return 1;
    }

    // write the header of the image
    fprintf(file, "P6\n%d %d\n%d\n", width, height, depth);

    // write the modified image data
    fwrite(image, sizeof(unsigned char), width * height * 3, file);

    fclose(file);

    free(image);

    return 0;
}