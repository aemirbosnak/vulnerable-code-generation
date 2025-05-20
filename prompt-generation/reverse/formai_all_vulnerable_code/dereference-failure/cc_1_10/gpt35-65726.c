//FormAI DATASET v1.0 Category: Image Steganography ; Style: careful
#include<stdio.h>
#include<stdlib.h>

typedef long int li;

// Function to get the file size
li findSize(FILE *file) {
    li size;

    fseek(file, 0L, SEEK_END);
    size = ftell(file);
    fseek(file, 0L, SEEK_SET);

    return size;
}

// Function to convert char to binary string
void charToBinary(unsigned char character, char *binary) {
    for(int i = 7; i >= 0; i--) {
        binary[7 - i] = ((character & (1 << i)) ? '1' : '0');
    }
    binary[8] = '\0';
}

// Function to convert binary string to char
unsigned char binaryToChar(char* binary) {
    unsigned char character = 0;

    for(int i = 0; i < 8; i++) {
        character = character << 1;

        if(binary[i] == '1') {
            character = character | 1;
        }
    }

    return character;
}

int main(int argc, char **argv) {
    FILE *input_image = fopen(argv[1], "rb");
    FILE *output_image = fopen(argv[3], "wb");

    if(input_image == NULL || output_image == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Get file size
    li file_size = findSize(input_image);

    // Check if file is too large for image
    int max_size = file_size / 8;

    if(max_size > (atoi(argv[5]) * atoi(argv[6]))) {
        printf("Error: File too large for image!\n");
        exit(1);
    }

    // Read image header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, input_image);

    // Write header to output image
    fwrite(header, sizeof(unsigned char), 54, output_image);

    // Calculate number of bytes to encode in each row
    int bytes_per_row = atoi(argv[6]) * 3;

    // Calculate height and width of image
    int height = *(int*)&header[22];
    int width = *(int*)&header[18];

    // Create buffer to store one row of image data
    unsigned char row[bytes_per_row];
    char binary[9];

    // Set cursor to start of image data
    fseek(input_image, 54, SEEK_SET);

    // Write pixels to output image
    int k = 0, bits_written = 0, bytes_written = 0;

    while(k < file_size) {
        // Read one row of image data
        fread(row, sizeof(unsigned char), bytes_per_row, input_image);

        // Check if end of row has been reached
        if(bits_written >= bytes_per_row * 8) {
            bits_written = 0;
        }

        // Modify image data
        for(int i = 0; i < bytes_per_row; i += 3) {
            // Check if pixel has been modified enough
            if(bits_written >= (max_size * 8)) {
                break;
            }

            // Convert each color byte to binary
            charToBinary(row[i], binary);

            // Get bit of input data to hide
            char bit_to_hide = (char)(file_size & (1 << bits_written));

            // Hide bit in least significant bit of color byte
            if(bit_to_hide) {
                binary[7] = '1';
            } else {
                binary[7] = '0';
            }

            // Convert binary back to char and update image data
            row[i] = binaryToChar(binary);
            bits_written++;

            if(bits_written >= (max_size * 8)) {
                break;
            }

            // Convert each color byte to binary
            charToBinary(row[i + 1], binary);

            // Get bit of input data to hide
            bit_to_hide = (char)(file_size & (1 << bits_written));

            // Hide bit in least significant bit of color byte
            if(bit_to_hide) {
                binary[7] = '1';
            } else {
                binary[7] = '0';
            }

            // Convert binary back to char and update image data
            row[i + 1] = binaryToChar(binary);
            bits_written++;

            if(bits_written >= (max_size * 8)) {
                break;
            }

            // Convert each color byte to binary
            charToBinary(row[i + 2], binary);

            // Get bit of input data to hide
            bit_to_hide = (char)(file_size & (1 << bits_written));

            // Hide bit in least significant bit of color byte
            if(bit_to_hide) {
                binary[7] = '1';
            } else {
                binary[7] = '0';
            }

            // Convert binary back to char and update image data
            row[i + 2] = binaryToChar(binary);
            bits_written++;
        }

        // Write row of modified data to output image
        fwrite(row, sizeof(unsigned char), bytes_per_row, output_image);

        // Update bytes written counter
        bytes_written += bytes_per_row;

        if(bits_written >= (max_size * 8)) {
            break;
        }

        // Skip padding bytes
        for(int i = 0; i < (4 - (bytes_per_row % 4)); i++) {
            fputc(0x00, output_image);
            bytes_written++;
        }

        // Update input file pointer
        fseek(input_image, bytes_per_row, SEEK_CUR);

        k += bytes_per_row;
    }

    // Close files
    fclose(input_image);
    fclose(output_image);

    printf("Data encoded successfully!\n");

    return 0;
}