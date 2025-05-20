//FormAI DATASET v1.0 Category: Image Steganography ; Style: genious
#include<stdio.h>
#include<stdlib.h>

// Function to hide a message in an image
void hideMessage(char* input_file, char* output_file, char* message) {
    // Open input file in read mode
    FILE* fptr_in = fopen(input_file, "rb");
    if (fptr_in == NULL) {
        printf("Error: Couldn't open input file!\n");
        return;
    }

    // Open output file in write mode
    FILE* fptr_out = fopen(output_file, "wb");
    if (fptr_out == NULL) {
        printf("Error: Couldn't create output file!\n");
        return;
    }

    // Add message size to the output file
    int message_size = strlen(message);
    fwrite(&message_size, sizeof(message_size), 1, fptr_out);

    // Read each pixel value from input file and modify its least significant bit
    int pixel, bit_pos = 0;
    char bit_val;
    while (fread(&pixel, sizeof(pixel), 1, fptr_in) == 1) {
        if (bit_pos < message_size * 8) {
            bit_val = ((message[bit_pos / 8] & (1 << (bit_pos % 8))) != 0);
            pixel = (pixel & 0xFFFFFFFE) | bit_val;
        }
        fwrite(&pixel, sizeof(pixel), 1, fptr_out);
        bit_pos++;
    }

    // Close file pointers
    fclose(fptr_in);
    fclose(fptr_out);
}

// Function to extract a message from an image
void extractMessage(char* input_file, char* output_file) {
    // Open input file in read mode
    FILE* fptr_in = fopen(input_file, "rb");
    if (fptr_in == NULL) {
        printf("Error: Couldn't open input file!\n");
        return;
    }

    // Open output file in write mode
    FILE* fptr_out = fopen(output_file, "w");
    if (fptr_out == NULL) {
        printf("Error: Couldn't create output file!\n");
        return;
    }

    // Read message size from the input file
    int message_size;
    fread(&message_size, sizeof(message_size), 1, fptr_in);

    // Read each pixel value from input file and extract the least significant bit
    int pixel, bit_pos = 0;
    char bit_val, msg_byte = 0;
    while (fread(&pixel, sizeof(pixel), 1, fptr_in) == 1) {
        if (bit_pos < message_size * 8) {
            bit_val = pixel & 1;
            msg_byte |= (bit_val << (bit_pos % 8));
            if (bit_pos % 8 == 7) {
                fwrite(&msg_byte, 1, 1, fptr_out);
                msg_byte = 0;
            }
        }
        bit_pos++;
    }

    // Close file pointers
    fclose(fptr_in);
    fclose(fptr_out);
}

// Main function
int main() {
    char input_file[] = "image.bmp";
    char output_file[] = "output.bmp";

    // Hide message in the input file
    char message[] = "Hello World!";
    hideMessage(input_file, output_file, message);
    printf("Message hidden successfully!\n");

    // Extract message from the output file
    char extracted_file[] = "extracted.txt";
    extractMessage(output_file, extracted_file);
    printf("Message extracted successfully: ");
    FILE* fptr = fopen(extracted_file, "r");
    char ch;
    while ((ch = fgetc(fptr)) != EOF) {
        printf("%c", ch);
    }
    fclose(fptr);

    return 0;
}