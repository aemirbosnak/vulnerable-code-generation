//FormAI DATASET v1.0 Category: Image Steganography ; Style: retro
#include<stdio.h>
#include<stdlib.h>

// Function to hide the message
void hide_message(char* image_path, char* message_path, char* output_path) {
    FILE *image_file, *message_file, *output_file;
    unsigned char byte_image, byte_message, masked_byte_image;
    int bit_message, i;

    // open the input files in binary mode
    image_file = fopen(image_path, "rb");
    message_file = fopen(message_path, "rb");

    // check if the files opened successfully
    if (image_file == NULL || message_file == NULL) {
        printf("Error opening input files.\n");
        exit(1);
    }

    // open the output file in binary mode
    output_file = fopen(output_path, "wb");

    // check if the output file opened successfully
    if (output_file == NULL) {
        printf("Error creating output file.\n");
        exit(1);
    }

    // read and write the header bytes from the image file to the output file
    for (i = 0; i < 54; i++) {
        fread(&byte_image, sizeof(unsigned char), 1, image_file); // read a byte from image file
        fwrite(&byte_image, sizeof(unsigned char), 1, output_file); // write the byte to the output file
    }

    // read each byte of the message file, hide its bits in the image bytes, and write the updated image bytes to the output file
    while (fread(&byte_message, sizeof(unsigned char), 1, message_file)) {
        // hide each bit of the message byte in the last bit of each image byte
        for (i = 0; i < 8; i++) {
            // read a byte from image file and extract its last bit
            fread(&byte_image, sizeof(unsigned char), 1, image_file);
            masked_byte_image = byte_image & 0xFE;

            // get the i-th bit of the message byte
            bit_message = (byte_message >> i) & 1;

            // set the last bit of the masked image byte to the i-th bit of the message byte
            masked_byte_image |= bit_message;

            // write the updated image byte to the output file
            fwrite(&masked_byte_image, sizeof(unsigned char), 1, output_file);
        }
    }

    // read and write the remaining bytes from the image file to the output file
    while (fread(&byte_image, sizeof(unsigned char), 1, image_file)) {
        fwrite(&byte_image, sizeof(unsigned char), 1, output_file);
    }

    // close all the files
    fclose(image_file);
    fclose(message_file);
    fclose(output_file);
}

// Function to recover the message
void recover_message(char* input_path, char* output_path) {
    FILE *input_file, *output_file;
    unsigned char byte_input, masked_byte_input;
    int bit_output;

    // open the input file in binary mode
    input_file = fopen(input_path, "rb");

    // check if the file opened successfully
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // open the output file in binary mode
    output_file = fopen(output_path, "wb");

    // check if the output file opened successfully
    if (output_file == NULL) {
        printf("Error creating output file.\n");
        exit(1);
    }

    // read the header bytes from the input file and write them to the output file
    for (int i = 0; i < 54; i++) {
        fread(&byte_input, sizeof(unsigned char), 1, input_file); // read a byte from input file
        fwrite(&byte_input, sizeof(unsigned char), 1, output_file); // write the byte to the output file
    }

    // read each byte of the input file, extract its last bit, and write the recovered message to the output file
    masked_byte_input = 0x01;
    byte_input = 0x00;
    while (fread(&byte_input, sizeof(unsigned char), 1, input_file)) {
        // extract the last bit of the input byte
        bit_output = byte_input & masked_byte_input;

        // shift bit to the correct position and add it to the recovered message byte
        byte_input = (bit_output << 7) | (byte_input >> 1);

        // write the recovered message byte to the output file if 8 bits have been recovered
        if (masked_byte_input == 0x80) {
            fwrite(&byte_input, sizeof(unsigned char), 1, output_file);

            // reset the recovered message byte
            byte_input = 0x00;
        }

        // update the mask for the next bit extraction
        masked_byte_input <<= 1;
    }

    // close all the files
    fclose(input_file);
    fclose(output_file);
}

int main() {
    char *image_path = "image.bmp";
    char *message_path = "message.txt";
    char *output_path = "output.bmp";
    char *recovered_path = "recovered.txt";
    
    // hide the message in the image
    hide_message(image_path, message_path, output_path);
    printf("Message hidden successfully in the image.\n");

    // recover the message from the image
    recover_message(output_path, recovered_path);
    printf("Message recovered successfully from the image.\n");

    return 0;
}