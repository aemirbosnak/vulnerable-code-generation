//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

// Function prototypes
void print_ascii(char **ascii_image, int rows, int cols);
void convert_to_ascii(char **ascii_image, unsigned char *image, int rows, int cols, int ascii_rows, int ascii_cols);

int main() {
    char file_name[1000];
    printf("Enter the name of the image file: ");
    scanf("%s", file_name);

    // Open the image file for binary reading
    FILE *fp = fopen(file_name, "rb");
    if(fp == NULL) {
        printf("Error opening file! Ensure that the file path is correct.\n");
        return 1;
    }

    // Read the width and height of the image
    unsigned char width[4], height[4];
    fseek(fp, 18, SEEK_SET);
    fread(width, sizeof(unsigned char), 4, fp);
    fread(height, sizeof(unsigned char), 4, fp);
    int cols = (int) width[0] + (int) width[1]*256 + (int) width[2]*256*256 + (int) width[3]*256*256*256;
    int rows = (int) height[0] + (int) height[1]*256 + (int) height[2]*256*256 + (int) height[3]*256*256*256;
    printf("Image width: %d\n", cols);
    printf("Image height: %d\n", rows);

    // Determine the number of ASCII rows and cols
    int ascii_rows, ascii_cols;
    printf("Enter the number of rows of the ASCII image: ");
    scanf("%d", &ascii_rows);
    ascii_cols = (int) round((double) ascii_rows / rows * cols * 0.5);
    printf("Number of columns of the ASCII image: %d\n", ascii_cols);

    // Allocate memory for the ASCII image
    char **ascii_image = (char **) malloc(ascii_rows * sizeof(char *));
    for(int i=0; i<ascii_rows; i++) {
        ascii_image[i] = (char *) malloc(ascii_cols * sizeof(char));
    }

    // Read the image data
    unsigned char image[rows*cols*3];
    fseek(fp, 54, SEEK_SET);
    fread(image, sizeof(unsigned char), rows*cols*3, fp);

    // Close the file
    fclose(fp);

    // Convert the image to ASCII
    convert_to_ascii(ascii_image, image, rows, cols, ascii_rows, ascii_cols);

    // Print the ASCII image to the console
    print_ascii(ascii_image, ascii_rows, ascii_cols);

    // Free the memory
    for(int i=0; i<ascii_rows; i++) {
        free(ascii_image[i]);
    }
    free(ascii_image);
    return 0;
}

/*
 * This function converts the image to ASCII art by averaging the brightness 
 * values of each block of pixels and mapping the average to an ASCII character.
 */
void convert_to_ascii(char **ascii_image, unsigned char *image, int rows, int cols, int ascii_rows, int ascii_cols) {
    for(int i=0; i<ascii_rows; i++) {
        for(int j=0; j<ascii_cols; j++) {
            // Compute the average brightness of the block of pixels
            int block_sum = 0;
            int block_pixels = 0;
            for(int k=i*rows/ascii_rows; k<(i+1)*rows/ascii_rows; k++) {
                for(int l=j*cols/ascii_cols; l<(j+1)*cols/ascii_cols; l++) {
                    int index = k*cols*3 + l*3;
                    int R = image[index];
                    int G = image[index+1];
                    int B = image[index+2];
                    int brightness = (int) round((double) (R + G + B) / 3);
                    block_sum += brightness;
                    block_pixels++;
                }
            }
            int block_avg = (int) round((double) block_sum / block_pixels);

            // Map the average brightness to an ASCII character
            if(block_avg <= 25) {
                ascii_image[i][j] = '@';
            }
            else if(block_avg <= 50) {
                ascii_image[i][j] = '$';
            }
            else if(block_avg <= 75) {
                ascii_image[i][j] = '&';
            }
            else if(block_avg <= 100) {
                ascii_image[i][j] = '*';
            }
            else if(block_avg <= 125) {
                ascii_image[i][j] = '#';
            }
            else if(block_avg <= 150) {
                ascii_image[i][j] = 'X';
            }
            else if(block_avg <= 175) {
                ascii_image[i][j] = 'o';
            }
            else if(block_avg <= 200) {
                ascii_image[i][j] = ':';
            }
            else if(block_avg <= 225) {
                ascii_image[i][j] = '.';
            }
            else if(block_avg <= 250) {
                ascii_image[i][j] = ' ';
            }
            else {
                ascii_image[i][j] = ' ';
            }
        }
    }
}

/*
 * This function prints the ASCII image to the console.
 */
void print_ascii(char **ascii_image, int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%c", ascii_image[i][j]);
        }
        printf("\n");
    }
}