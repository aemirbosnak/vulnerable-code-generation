//FormAI DATASET v1.0 Category: Image Editor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

/* Function to get the value of a pixel */
int get_pixel_value(unsigned char *image, int x, int y, int width, int height) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        return -1;
    }
    return (int) image[y * width + x];
}

/* Function to set the value of a pixel */
void set_pixel_value(unsigned char *image, int x, int y, int value, int width, int height) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        return;
    }
    image[y * width + x] = (unsigned char) value;
}

/* Function to invert the colors of an image */
void invert_colors(unsigned char *image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int value = get_pixel_value(image, j, i, width, height);
            if (value != -1) {
                int inverted_value = 255 - value;
                set_pixel_value(image, j, i, inverted_value, width, height);
            }
        }
    }
}

/* Function to blur an image with a 3x3 kernel */
void blur_image(unsigned char *image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int value1 = get_pixel_value(image, j, i - 1, width, height);
            int value2 = get_pixel_value(image, j - 1, i, width, height);
            int value3 = get_pixel_value(image, j, i, width, height);
            int value4 = get_pixel_value(image, j + 1, i, width, height);
            int value5 = get_pixel_value(image, j, i + 1, width, height);
            if (value1 != -1 && value2 != -1 && value3 != -1 && value4 != -1 && value5 != -1) {
                int average_value = (value1 + value2 + value3 + value4 + value5) / 5;
                set_pixel_value(image, j, i, average_value, width, height);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: image_editor [operation] [input_file] [output_file]\n");
        printf("Available operations: invert, blur\n");
        return 1;
    }
    
    char *operation = argv[1];
    char *input_file_name = argv[2];
    char *output_file_name = argv[3];
    
    FILE *input_file = fopen(input_file_name, "rb");
    if (input_file == NULL) {
        printf("Error: could not open input file '%s'.\n", input_file_name);
        return 1;
    }
    
    fseek(input_file, 0, SEEK_END);
    long input_file_size = ftell(input_file);
    rewind(input_file);
    
    unsigned char *input_image = malloc(input_file_size);
    if (input_image == NULL) {
        printf("Error: could not allocate memory for input image.\n");
        return 1;
    }
    
    if (fread(input_image, 1, input_file_size, input_file) != input_file_size) {
        printf("Error: could not read input file '%s'.\n", input_file_name);
        return 1;
    }
    
    fclose(input_file);
    
    int width = input_image[18] + input_image[19] * 256;
    int height = input_image[22] + input_image[23] * 256;
    
    if (strcmp(operation, "invert") == 0) {
        invert_colors(input_image, width, height);
    } else if (strcmp(operation, "blur") == 0) {
        blur_image(input_image, width, height);
    } else {
        printf("Error: unsupported operation '%s'.\n", operation);
        return 1;
    }
    
    FILE *output_file = fopen(output_file_name, "wb");
    if (output_file == NULL) {
        printf("Error: could not open output file '%s'.\n", output_file_name);
        return 1;
    }
    
    fwrite(input_image, 1, input_file_size, output_file);
    
    fclose(output_file);
    
    free(input_image);
    
    return 0;
}