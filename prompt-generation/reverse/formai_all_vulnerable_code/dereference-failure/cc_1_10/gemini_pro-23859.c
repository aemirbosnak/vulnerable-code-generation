//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define LSB_MASK 0x1

void encode(const char *input_image, const char *input_text, const char *output_image) {
    // Read input image
    FILE *input_image_file = fopen(input_image, "rb");
    fseek(input_image_file, 0, SEEK_END);
    long input_image_size = ftell(input_image_file);
    rewind(input_image_file);
    uint8_t *input_image_data = malloc(input_image_size);
    fread(input_image_data, 1, input_image_size, input_image_file);
    fclose(input_image_file);

    // Read input text
    FILE *input_text_file = fopen(input_text, "rb");
    fseek(input_text_file, 0, SEEK_END);
    long input_text_size = ftell(input_text_file);
    rewind(input_text_file);
    char *input_text_data = malloc(input_text_size);
    fread(input_text_data, 1, input_text_size, input_text_file);
    fclose(input_text_file);

    // Encode text into image
    int text_index = 0;
    for (int i = 0; i < input_image_size; i++) {
        if (text_index < input_text_size) {
            uint8_t bit = (input_text_data[text_index] >> (7 - i % 8)) & LSB_MASK;
            input_image_data[i] = (input_image_data[i] & ~LSB_MASK) | bit;
            text_index++;
        }
    }

    // Write output image
    FILE *output_image_file = fopen(output_image, "wb");
    fwrite(input_image_data, 1, input_image_size, output_image_file);
    fclose(output_image_file);

    free(input_image_data);
    free(input_text_data);
}

void decode(const char *input_image, const char *output_text) {
    // Read input image
    FILE *input_image_file = fopen(input_image, "rb");
    fseek(input_image_file, 0, SEEK_END);
    long input_image_size = ftell(input_image_file);
    rewind(input_image_file);
    uint8_t *input_image_data = malloc(input_image_size);
    fread(input_image_data, 1, input_image_size, input_image_file);
    fclose(input_image_file);

    // Decode text from image
    int text_index = 0;
    char *output_text_data = malloc(input_image_size / 8 + 1);
    for (int i = 0; i < input_image_size; i++) {
        uint8_t bit = input_image_data[i] & LSB_MASK;
        output_text_data[text_index] = (output_text_data[text_index] << 1) | bit;
        if (i % 8 == 7) {
            text_index++;
        }
    }
    output_text_data[text_index] = '\0';

    // Write output text
    FILE *output_text_file = fopen(output_text, "wb");
    fwrite(output_text_data, 1, strlen(output_text_data), output_text_file);
    fclose(output_text_file);

    free(input_image_data);
    free(output_text_data);
}

int main() {
    // Encode text into image
    encode("input.bmp", "input.txt", "output.bmp");

    // Decode text from image
    decode("output.bmp", "output.txt");

    return 0;
}