//FormAI DATASET v1.0 Category: Image Editor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Function to read the image file from disk
void read_image(FILE *fp, unsigned char *buffer, int size) {
    fread(buffer, size, 1, fp);
}

// Function to write the modified image to disk
void write_image(FILE *fp, unsigned char *buffer, int size) {
    fwrite(buffer, size, 1, fp);
}

// Function to invert the colors of the image
void invert_colors(unsigned char *buffer, int size) {
    for (int i = 0; i < size; i++) {
        buffer[i] = 255 - buffer[i];
    }
}

// Function to blur the image
// Takes in a 1D buffer and returns a new buffer
unsigned char* blur_image(unsigned char *buffer, int height, int width) {
    unsigned char *new_buffer = (unsigned char*)malloc(height * width * sizeof(unsigned char));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel_sum = 0;
            int num_pixels = 0;
            int avg_pixel = 0;

            // Compute the sum of the pixel values around each pixel (including itself)
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    int x = i + k;
                    int y = j + l;

                    if ((x < 0) || (y < 0) || (x >= height) || (y >= width))
                        continue;

                    pixel_sum += buffer[x * width + y];
                    num_pixels++;
                }
            }

            // Compute the average pixel value of the surrounding pixels
            avg_pixel = pixel_sum / num_pixels;
            new_buffer[i * width + j] = avg_pixel;
        }
    }

    return new_buffer;
}

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    unsigned char *image_buffer, *new_buffer;
    int height, width, size;

    // Check if command line arguments are provided correctly
    if (argc < 3) {
        printf("Not enough arguments provided.\n");
        exit(1);
    }

    // Open input file
    input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Could not open input file.\n");
        exit(1);
    }

    // Open output file
    output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Could not open output file.\n");
        exit(1);
    }

    // Get the height and width of the image
    fseek(input_file, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, input_file);
    fread(&height, sizeof(int), 1, input_file);

    // Calculate the image size in bytes
    size = height * width;

    // Allocate memory for image buffer
    image_buffer = (unsigned char*)malloc(size * sizeof(unsigned char));

    // Read the image into the buffer
    read_image(input_file, image_buffer, size);

    // Invert the colors of the image
    invert_colors(image_buffer, size);

    // Blur the image
    new_buffer = blur_image(image_buffer, height, width);

    // Write the modified image to the output file
    write_image(output_file, new_buffer, size);

    // Free memory
    free(image_buffer);
    free(new_buffer);

    // Close the files
    fclose(input_file);
    fclose(output_file);

    // Exit the program
    return 0;
}