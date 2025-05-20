//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <jpeglib.h>

// Define a structure to hold image pixel data
typedef struct {
    unsigned char r, g, b;
} Pixel;

// Function to read a JPEG image and convert it to pixel data
Pixel **read_jpeg(const char *filename, int *width, int *height) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE *infile;
    
    // Open the input file
    if ((infile = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", filename);
        return NULL;
    }
    
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);
    
    *width = cinfo.output_width;
    *height = cinfo.output_height;
    
    // Allocate memory for the pixel data
    Pixel **image_data = malloc(*height * sizeof(Pixel *));
    for (int i = 0; i < *height; i++) {
        image_data[i] = malloc(*width * sizeof(Pixel));
    }
    
    // Read the pixels
    while (cinfo.output_scanline < cinfo.output_height) {
        unsigned char *buffer_array[1];
        buffer_array[0] = (unsigned char *)malloc(cinfo.output_width * cinfo.output_components);
        jpeg_read_scanlines(&cinfo, buffer_array, 1);
        
        for (int x = 0; x < *width; x++) {
            image_data[cinfo.output_scanline-1][x].r = buffer_array[0][x * 3];
            image_data[cinfo.output_scanline-1][x].g = buffer_array[0][x * 3 + 1];
            image_data[cinfo.output_scanline-1][x].b = buffer_array[0][x * 3 + 2];
        }
        free(buffer_array[0]);
    }
    
    jpeg_finish_decompress(&cinfo);
    fclose(infile);
    
    return image_data;
}

// Function to convert pixel data to ASCII
void convert_to_ascii(Pixel **image_data, int width, int height, const char *output_file) {
    const char *ascii_chars = "@%#*+=-:. "; // ASCII characters from dark to light
    
    FILE *outfile = fopen(output_file, "w");
    if (outfile == NULL) {
        fprintf(stderr, "Can't open %s\n", output_file);
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Normalize pixel to a value between 0 and 255
            unsigned char avg = (image_data[y][x].r + image_data[y][x].g + image_data[y][x].b) / 3;
            // Map pixel brightness to the ASCII character set
            int index = (int)((avg / 255.0) * (strlen(ascii_chars) - 1));
            fputc(ascii_chars[index], outfile);
        }
        fputc('\n', outfile); // Newline after each row
    }
    
    fclose(outfile);
}

// Function to free the allocated memory for image data
void free_image_data(Pixel **image_data, int height) {
    for (int i = 0; i < height; i++) {
        free(image_data[i]);
    }
    free(image_data);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_jpeg> <output_ascii>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int width, height;
    Pixel **image_data = read_jpeg(argv[1], &width, &height);
    if (image_data == NULL) {
        return EXIT_FAILURE;
    }
    
    convert_to_ascii(image_data, width, height, argv[2]);
    
    free_image_data(image_data, height);
    
    printf("Image conversion completed. Check the output in %s\n", argv[2]);
    return EXIT_SUCCESS;
}