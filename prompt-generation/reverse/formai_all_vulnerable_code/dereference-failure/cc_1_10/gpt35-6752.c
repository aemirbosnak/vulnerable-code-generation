//FormAI DATASET v1.0 Category: Image compression ; Style: peaceful
/* 
    This program uses a simple image compression technique that reduces the file size of a given image.
    It works by grouping adjacent repeating pixels together and storing them as a single value with a count of how many times they occur.
    The resulting compressed image is stored in a new file with a .comp extension.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL_COUNT 255

typedef struct pixel {
    unsigned char r, g, b;
} Pixel;

int main() {
    FILE *input_file, *output_file;
    char *input_filename = "image.bmp"; // Change to the name of your input image file
    char *output_filename = "image.comp"; // Change to the name you want to give the compressed image file
    unsigned int width, height, row_size;
    Pixel *image_row;
    unsigned char *compressed_row;
    unsigned char count, current;
    unsigned int i, j, k, l, m;
    Pixel *last_pixel, *current_pixel;

    // Open input file for reading
    input_file = fopen(input_filename, "rb");
    if (!input_file) {
        printf("Error: Could not open input file %s\n", input_filename);
        return 1;
    }

    // Read in the header information
    fseek(input_file, 18, SEEK_SET);
    fread(&width, 4, 1, input_file);
    fread(&height, 4, 1, input_file);
    fseek(input_file, 28, SEEK_SET);
    fread(&row_size, 4, 1, input_file);

    // Allocate memory for storing one row of pixels and one row of compressed data
    image_row = (Pixel*)malloc(row_size * sizeof(Pixel));
    compressed_row = (unsigned char*)malloc(row_size * sizeof(unsigned char));

    // Open output file for writing
    output_file = fopen(output_filename, "wb");
    if (!output_file) {
        printf("Error: Could not open output file %s\n", output_filename);
        return 1;
    }

    // Write header information to the compressed file
    fwrite(&width, 4, 1, output_file);
    fwrite(&height, 4, 1, output_file);
    fwrite(&row_size, 4, 1, output_file);

    // Loop through each row of pixels in the input file
    for (i = 0; i < height; i++) {
        // Read in the row of pixels
        fread(image_row, sizeof(Pixel), row_size, input_file);

        // Loop through each pixel in the row
        last_pixel = &image_row[0];
        count = 1;
        k = 0; // Index of current pixel in compressed row
        for (j = 1; j < row_size; j++) {
            current_pixel = &image_row[j];

            // Check if current pixel is the same as the last one
            if (last_pixel->r == current_pixel->r && last_pixel->g == current_pixel->g && last_pixel->b == current_pixel->b) {
                // If it is, increment the count
                count++;

                // If we've reached the maximum count for a single pixel, write the current pixel and count to the compressed row and start over
                if (count == MAX_PIXEL_COUNT) {
                    compressed_row[k++] = last_pixel->r;
                    compressed_row[k++] = last_pixel->g;
                    compressed_row[k++] = last_pixel->b;
                    compressed_row[k++] = MAX_PIXEL_COUNT;
                    count = 1;
                }
            } else {
                // If the current pixel is different from the last one, write the last pixel and its count to the compressed row
                compressed_row[k++] = last_pixel->r;
                compressed_row[k++] = last_pixel->g;
                compressed_row[k++] = last_pixel->b;
                compressed_row[k++] = count;

                // Start counting the new pixel
                count = 1;
                last_pixel = current_pixel;
            }
        }

        // Write the last pixel and its count to the compressed row
        compressed_row[k++] = last_pixel->r;
        compressed_row[k++] = last_pixel->g;
        compressed_row[k++] = last_pixel->b;
        compressed_row[k++] = count;

        // Write the compressed row to the output file
        fwrite(compressed_row, sizeof(unsigned char), k, output_file);
    }

    // Free memory and close files
    free(compressed_row);
    free(image_row);
    fclose(input_file);
    fclose(output_file);

    printf("%s successfully created.\n", output_filename);

    return 0;
}