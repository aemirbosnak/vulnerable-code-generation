//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the ASCII art characters based on intensity.
const char ascii_chars[] = "@%#*+=-:. "; // More dense to less dense

// Function to get the grayscale value from RGB values
int get_grayscale(int r, int g, int b) {
    return (r * 299 + g * 587 + b * 114) / 1000; // Using Luminosity method
}

// Function to map grayscale value to ASCII character
char map_to_ascii(int gray) {
    int index = gray * (sizeof(ascii_chars) - 2) / 255; // Normalize to size of ascii_chars
    return ascii_chars[index];
}

// Function to convert an RGB image to ASCII art
void image_to_ascii(char *input_file, char *output_file, int width, int height) {
    FILE *infile = fopen(input_file, "rb");
    if (!infile) {
        fprintf(stderr, "Error: Cannot open input file\n");
        exit(1);
    }
    
    FILE *outfile = fopen(output_file, "w");
    if (!outfile) {
        fclose(infile);
        fprintf(stderr, "Error: Cannot open output file\n");
        exit(1);
    }

    // Calculate size of pixel data
    int pixel_size = 3; // Assuming RGB
    unsigned char *image_data = (unsigned char*)malloc(width * height * pixel_size);
    fread(image_data, pixel_size, width * height, infile);

    // Process each pixel
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixel_index = (y * width + x) * pixel_size;
            int r = image_data[pixel_index];
            int g = image_data[pixel_index + 1];
            int b = image_data[pixel_index + 2];
            
            int gray_value = get_grayscale(r, g, b);
            char ascii_char = map_to_ascii(gray_value);
            fputc(ascii_char, outfile);
        }
        fputc('\n', outfile); // Newline at the end of each row
    }

    free(image_data);
    fclose(infile);
    fclose(outfile);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input_image> <output_ascii> <width> <height>\n", argv[0]);
        return 1;
    }
    
    char *input_file = argv[1];
    char *output_file = argv[2];
    int width = atoi(argv[3]);
    int height = atoi(argv[4]);

    image_to_ascii(input_file, output_file, width, height);
    printf("ASCII art generated successfully in %s\n", output_file);

    return 0;
}