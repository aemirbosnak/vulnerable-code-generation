//FormAI DATASET v1.0 Category: Image compression ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
   This program is an example of image compression using a simple algorithm. 
   The algorithm identifies runs of pixels with the same color value and 
   replaces them with a single pixel.
*/

/* Function declarations */
void compress_image(char* image_data, int width, int height);
int count_runs(char* row, int row_size);

/* Main function */
int main(void)
{
    /* Sample image data */
    char* image_data = "11111111112222222222333333333344444444445555555555"
                       "11111111112222222222333333333344444444445555555555"
                       "66666666667777777777888888888899999999990000000000"
                       "66666666667777777777888888888899999999990000000000"
                       "11111111112222222222333333333344444444445555555555"
                       "11111111112222222222333333333344444444445555555555"
                       "66666666667777777777888888888899999999990000000000"
                       "66666666667777777777888888888899999999990000000000";

    /* Image dimensions */
    int width = 10;
    int height = 8;

    /* Print original image data */
    printf("Original image data:\n%s\n\n", image_data);

    /* Compress image */
    compress_image(image_data, width, height);

    return 0;
}

/* Function to compress image data */
void compress_image(char* image_data, int width, int height)
{
    /* Allocate memory for compressed image */
    char* compressed_image = malloc(sizeof(char) * (width * height));
    memset(compressed_image, 0, sizeof(char) * (width * height));

    /* Loop through each row in the image */
    for (int i = 0; i < height; i++) {
        /* Get start and end pointers for each row */
        char* row_start = image_data + (i * width);
        char* row_end = row_start + width;

        /* Loop through each run in the row */
        int run_count = 0;
        while (row_start < row_end) {
            int run_size = count_runs(row_start, width - (row_start - image_data));
            /* Replace the run with a single pixel */
            *(compressed_image + (i * width) + run_count) = *row_start;
            /* Increment run counter */
            row_start += run_size;
            run_count++;
        }
    }

    /* Print compressed image data */
    printf("Compressed image data:\n%s\n", compressed_image);

    /* Free memory */
    free(compressed_image);
}

/* Function to count runs of pixels with the same color */
int count_runs(char* row, int row_size)
{
    int run_size = 1;
    char current_pixel = *row;
    while (*(row + run_size) == current_pixel && run_size < row_size) {
        run_size++;
    }
    return run_size;
}