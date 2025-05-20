//FormAI DATASET v1.0 Category: Image Steganography ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // maximum file size in bytes

// function to convert decimal to binary
void dec2bin(int decimal, int* binary) {
    int i = 0;
    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }
}

// function to hide data in image using LSB technique
void hide_data_in_image(FILE* image_file, char* data_file) {
    // open data file
    FILE* data = fopen(data_file, "rb");
    if (data == NULL) {
        printf("Error: could not open data file\n");
        return;
    }

    // read data file into buffer
    fseek(data, 0L, SEEK_END);
    int data_size = ftell(data);
    if (data_size >= MAX_FILE_SIZE) {
        printf("Error: data file is too large\n");
        fclose(data);
        return;
    }
    rewind(data);
    char* buffer = (char*) malloc(data_size * sizeof(char));
    fread(buffer, sizeof(char), data_size, data);
    fclose(data);

    // open image file for writing data
    fseek(image_file, 54L, SEEK_SET); // skip bitmap header
    int hidden_bytes = 0;
    int byte_index = 0;
    int bit_index = 0;
    int binary[8] = { 0 };
    char byte;

    while (hidden_bytes < data_size) {
        byte_index = ftell(image_file);
        fread(&byte, sizeof(char), 1, image_file);
        dec2bin(byte, binary);

        binary[0] = buffer[hidden_bytes] >> bit_index & 1; // set least significant bit to data
        byte = 0;
        int multiplier = 1;
        for (int i = 0; i < 8; i++) {
            byte += binary[i] * multiplier;
            multiplier *= 2;
        }
        fseek(image_file, byte_index, SEEK_SET);
        fwrite(&byte, sizeof(char), 1, image_file);

        if (bit_index == 7) {
            hidden_bytes++;
            bit_index = 0;
        } else {
            bit_index++;
        }
    }
    free(buffer);
}

// function to retrieve data from image using LSB technique
void retrieve_data_from_image(FILE* image_file, char* output_file) {
    // open output file for writing data
    FILE* output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error: could not open output file\n");
        return;
    }

    // seek to start of data in image
    fseek(image_file, 54L, SEEK_SET);

    char byte = 0;
    int binary[8] = { 0 };
    int bit_index = 0;

    while (1) {
        if (bit_index == 8) {
            bit_index = 0;
            byte = 0;
            int multiplier = 1;
            for (int i = 0; i < 8; i++) {
                byte += binary[i] * multiplier;
                multiplier *= 2;
            }
            if (byte == '\0') {
                break;
            } else {
                fwrite(&byte, sizeof(char), 1, output);
            }
        }
        int byte_index = ftell(image_file);
        fread(&byte, sizeof(char), 1, image_file);
        dec2bin(byte, binary);
        bit_index++;
    }

    fclose(output);
}

int main() {
    // open image file
    FILE* image_file = fopen("image.bmp", "rb+");
    if (image_file == NULL) {
        printf("Error: could not open image file\n");
        return 1;
    }

    // hide data in image
    hide_data_in_image(image_file, "secret.txt");

    // retrieve data from image
    retrieve_data_from_image(image_file, "output.txt");

    fclose(image_file);
    return 0;
}