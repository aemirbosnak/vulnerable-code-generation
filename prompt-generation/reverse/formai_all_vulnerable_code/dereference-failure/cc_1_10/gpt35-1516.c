//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: mind-bending
#include <stdio.h>

void convertToAscii(int pixel_value, char *ascii_char) {
    // Converts the given pixel value to ascii character
    // using a custom mapping

    int ascii_index = pixel_value / 25;
    *ascii_char = "@%#*+=-:. "[ascii_index];
}

void convertImageToAscii(unsigned char *image, int width, int height) {
    // Converts the given image to ascii art and prints to console
    
    char ascii_char;
    int pixel_index;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixel_index = (i * width + j) * 3;
            int pixel_value = (image[pixel_index] + image[pixel_index + 1] + image[pixel_index + 2]) / 3;
            convertToAscii(pixel_value, &ascii_char);
            printf("%c", ascii_char);
        }
        printf("\n");
    }
}

int main() {
    // Read image from file
    FILE *image_file = fopen("image.jpg", "rb");
    fseek(image_file, 0, SEEK_END);
    long file_size = ftell(image_file);
    fseek(image_file, 0, SEEK_SET);
    unsigned char *image_data = (unsigned char*) malloc(file_size * sizeof(unsigned char));
    fread(image_data, sizeof(unsigned char), file_size, image_file);
    fclose(image_file);

    // Image dimensions
    int width = 100;
    int height = 50;

    // Resize image to ascii art dimensions
    unsigned char *resized_image = (unsigned char*) malloc(width * height * sizeof(unsigned char));
    float width_ratio = (float)width / (float)(file_size / 3);
    float height_ratio = (float)height / (float)(file_size / 3);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int original_i = (int)(i / height_ratio);
            int original_j = (int)(j / width_ratio);
            int pixel_index = (original_i * (file_size / 3) + original_j) * 3;
            resized_image[i * width + j] = (image_data[pixel_index] + image_data[pixel_index + 1] + image_data[pixel_index + 2]) / 3;
        }
    }

    // Convert and print image to ascii art
    convertImageToAscii(resized_image, width, height);

    // Free memory
    free(image_data);
    free(resized_image);

    return 0;
}