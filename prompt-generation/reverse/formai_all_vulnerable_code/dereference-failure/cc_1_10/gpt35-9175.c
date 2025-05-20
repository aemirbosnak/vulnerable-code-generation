//FormAI DATASET v1.0 Category: Image Steganography ; Style: Linus Torvalds
/*
 * Image Steganography Example Program
 * 
 * Author: Linus Torvalds
 * 
 * This program takes an input image and hides a secret message in it using steganography. 
 * The steganography algorithm used here is simple LSB (Least Significant Bit) Substitution.
 * 
 * Expected usage: ./stegano input_image.bmp secret_message.txt output_image.bmp
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADER_SIZE 54 // BMP header is 54 bytes
#define BYTE_SIZE 8 // 8 bits per byte

// Function to read BMP header and extract necessary image information
void read_header(FILE *image, int *width, int *height, int *data_offset) {
    fseek(image, 18, SEEK_SET); // Move to width position
    fread(width, sizeof(int), 1, image); // Read the width value
    
    fseek(image, 22, SEEK_SET); // Move to height position
    fread(height, sizeof(int), 1, image); // Read the height value
    
    fseek(image, 10, SEEK_SET); // Move to data offset position
    fread(data_offset, sizeof(int), 1, image); // Read the data offset value
}

// Function to encode the binary message into the image pixels
void encode_message(FILE *image, FILE *message, int data_offset) {
    int width, height, byte_read, bit_count = 0;
    unsigned char pixel_data, new_pixel_data = 0;
    
    read_header(image, &width, &height, &data_offset); // Get image info

    // Read byte by byte from secret message and embed into pixel data bits
    while((byte_read = fgetc(message)) != EOF) {
        for(int i = 0; i < BYTE_SIZE; i++) {
            if(bit_count % 3 == 0) { // Ignore alpha value
                pixel_data = fgetc(image);
                new_pixel_data = (pixel_data & 0xFE) | ((byte_read >> (2 - bit_count%3)) & 0x01); // Get the last bit from byte_read and change pixel_data's last bit bit with it
                fseek(image, -1, SEEK_CUR); // Set the cursor back (we read one byte into pixel_data which needs to be changed)
                fputc(new_pixel_data, image); // Write modified pixel data back to the image
            }
            bit_count++;
        }
    }
}

// Function to decode secret message from the image pixels
void decode_message(FILE *image) {
    int width, height, data_offset, byte_count = 0, bit_count = 0;
    unsigned char pixel_data, byte_read = 0;
    
    read_header(image, &width, &height, &data_offset); // Get image info

    // Traverse through the image pixel data and extract message bits
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            fseek(image, data_offset + (i * width * 3) + (j * 3), SEEK_SET); // Move to the pixel data of (i,j)
            pixel_data = fgetc(image); // Read pixel data (ignore alpha channel)

            if(bit_count % 3 == 0) { // Reset byte_read every 3 bits
                byte_read <<= 1; // Shift byte_read one left to make space for next bit
            }
            byte_read |= pixel_data & 0x01; // Add the last bit of pixel_data to byte_read
            
            if(bit_count % BYTE_SIZE == 7) { // Byte read is complete
                if(byte_read == '\0') { // Found '\0' character, end of message
                    return;
                }
                printf("%c", byte_read); // Print byte read as character
                byte_read = 0;
                byte_count++;
            }
            bit_count++;
        }
    }
}

int main(int argc, char** argv) {
    if(argc < 4) {
        printf("Usage: %s <input_image.bmp> <secret_message.txt> <output_image.bmp>\n", argv[0]);
        return 1;
    }

    // Open the necessary files
    FILE *image = fopen(argv[1], "r+b");
    FILE *message = fopen(argv[2], "rb");
    FILE *output = fopen(argv[3], "w+b");

    if(!image) {
        printf("Could not open input image file.\n");
        return 1;
    }

    if(!message) {
        printf("Could not open secret message file.\n");
        return 1;
    }

    if(!output) {
        printf("Could not create output image file.\n");
        return 1;
    }

    int data_offset;
    read_header(image, NULL, NULL, &data_offset); // Read image data offset

    // Copy BMP header to the output image file
    fseek(image, 0, SEEK_SET);
    for(int i = 0; i < HEADER_SIZE; i++) {
        fputc(fgetc(image), output);
    }

    // Check if user wants to encode or decode message
    char choice;
    printf("Enter 'e' to encode or 'd' to decode: ");
    scanf("%c", &choice);

    if(choice == 'e') { // Encode secret message to the image
        encode_message(image, message, data_offset);
        printf("Secret message encoded successfully!\n");
    }
    else if(choice == 'd') { // Decode secret message from the image
        decode_message(image);
        printf("Secret message decoded successfully!\n");
    }
    else {
        printf("Invalid choice. Please try again.\n");
        return 1;
    }

    // Copy the rest of the image data to the output image file
    fseek(image, data_offset, SEEK_SET);
    while(!feof(image)) {
        fputc(fgetc(image), output);
    }

    // Close all files and cleanup
    fclose(image);
    fclose(message);
    fclose(output);

    printf("Output image file created successfully!\n");

    return 0;
}