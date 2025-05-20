//FormAI DATASET v1.0 Category: Image Editor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert image to grayscale
void grayscale(unsigned char *image, int width, int height) {
    int i, j;
    unsigned char *pixel;

    // iterate through all pixels of the image
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            // get address of current pixel
            pixel = image + (i * width + j) * 3;

            // calculate grayscale value
            unsigned char gray_value = (pixel[0] + pixel[1] + pixel[2]) / 3;

            // set all color channels to the grayscale value
            pixel[0] = gray_value;
            pixel[1] = gray_value;
            pixel[2] = gray_value;
        }
    }
}

// function to flip image horizontally
void flip_horizontal(unsigned char *image, int width, int height) {
    int i, j;
    unsigned char *row1, *row2;

    // iterate through all rows of the image
    for(i = 0; i < height; i++) {
        // get address of current row and the row opposite to it
        row1 = image + i * width * 3;
        row2 = image + (i + 1) * width * 3 - 3;

        // iterate through all pixels of the row
        for(j = 0; j < width / 2; j++) {
            // swap the pixels on the two sides of the row
            row1 = row1 + 3;
            row2 = row2 - 3;
            unsigned char temp = row1[0];
            row1[0] = row2[0];
            row2[0] = temp;
            temp = row1[1];
            row1[1] = row2[1];
            row2[1] = temp;
            temp = row1[2];
            row1[2] = row2[2];
            row2[2] = temp;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./image_editor input_image_path output_image_path\n");
        return 0;
    }

    // read input image file and get its width and height
    char *input_file_path = argv[1];
    FILE *input_file = fopen(input_file_path, "rb");
    if (input_file == NULL) {
        printf("Error: Input file not found.\n");
        return 0;
    }
    fseek(input_file, 18, SEEK_SET);
    int width, height;
    fread(&width, 4, 1, input_file);
    fread(&height, 4, 1, input_file);

    // allocate memory for image data and read it from input file
    unsigned char *image = (unsigned char*)malloc(width * height * 3);
    fseek(input_file, 54, SEEK_SET);
    fread(image, 3, width * height, input_file);
    fclose(input_file);

    // apply image editing operations
    grayscale(image, width, height);
    flip_horizontal(image, width, height);

    // write image data to output file
    char *output_file_path = argc >= 3 ? argv[2] : "output.bmp";
    FILE *output_file = fopen(output_file_path, "wb");
    if (output_file == NULL) {
        printf("Error: Could not create output file.\n");
        return 0;
    }
    unsigned char header[54];
    memset(header, 0, 54);
    header[0] = 'B';
    header[1] = 'M';
    int image_size = width * height * 3;
    header[2] = (unsigned char)(image_size);
    header[3] = (unsigned char)(image_size >> 8);
    header[4] = (unsigned char)(image_size >> 16);
    header[5] = (unsigned char)(image_size >> 24);
    header[10] = 54;
    header[14] = 40;
    header[18] = (unsigned char)(width);
    header[19] = (unsigned char)(width >> 8);
    header[20] = (unsigned char)(width >> 16);
    header[21] = (unsigned char)(width >> 24);
    header[22] = (unsigned char)(height);
    header[23] = (unsigned char)(height >> 8);
    header[24] = (unsigned char)(height >> 16);
    header[25] = (unsigned char)(height >> 24);
    header[26] = 1;
    header[28] = 24;
    fwrite(header, 1, 54, output_file);
    fwrite(image, 3, width * height, output_file);
    fclose(output_file);

    free(image);

    printf("Image editing complete! Check the output file %s\n", output_file_path);
    return 0;
}