//FormAI DATASET v1.0 Category: Image Steganography ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define BYTE unsigned char   // define the BYTE type 

// Function to read bytes from the file
size_t readBytes(FILE* file, BYTE *buf, size_t bufsize) {
    size_t result = 0;
    int c;
    // To read single byte at a time
    while ((c = fgetc(file)) != EOF && result < bufsize) {
        buf[result++] = (BYTE) c;
    }
    return result;
}

// Function to write bytes to the file
void writeBytes(FILE* file, const BYTE *buf, size_t bufsize) {
    size_t i;
    // To write each byte to file
    for (i=0; i<bufsize; ++i) {
        fputc(buf[i], file);
    }
}

int main(int argc, char* argv[]) {
    // Check for proper arguments 
    if (argc != 4) {
        printf("Usage: %s -e/-d input_file output_file\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open input file
    FILE* in_file = fopen(argv[2], "rb");
    if (!in_file) {
        printf("Error: Could not open file: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    // Open output file
    FILE* out_file = fopen(argv[3], "wb");
    if (!out_file) {
        printf("Error: Could not open file: %s\n", argv[3]);
        fclose(in_file);
        return EXIT_FAILURE;
    }

    if (!strcmp(argv[1], "-e")) { // To encode image
        // Read the input file bytes
        BYTE *input_buf = (BYTE*) malloc(sizeof(BYTE) * 1024 * 1024); // Allocate buffer of size 1 MB
        size_t input_size = readBytes(in_file, input_buf, 1024 * 1024); // Read input bytes
        // Embed payload in 4th bit (Least significant nibble of each pixel)
        for (size_t i=0; i<input_size; ++i) {
            input_buf[i] = (input_buf[i] & 0xf0) | ((i%16) >> 2); // Embed payload in 4th bit (least significant nibble)
        }
        // Write the output bytes
        writeBytes(out_file, input_buf, input_size);
        printf("Encoding completed successfully!\n");
        free(input_buf);
    } else if (!strcmp(argv[1], "-d")) { // To decode image
        // Read the input file bytes 
        BYTE *input_buf = (BYTE*) malloc(sizeof(BYTE) * 1024 * 1024); // Allocate buffer of size 1 MB
        size_t input_size = readBytes(in_file, input_buf, 1024 * 1024); // Read input bytes
        // Recover payload from 4th bit (Least significant nibble of each pixel)
        size_t payload_size = (input_size >> 2); // Each pixel contains 4 bits, so payload size is equal to input_size / 4
        BYTE *payload_buf = (BYTE*) malloc(sizeof(BYTE) * payload_size);
        for (size_t i=0; i<payload_size; ++i) {
            payload_buf[i] = (input_buf[(i<<2)+3] & 0x0f) << 2; // Recover payload from 4th bit (least significant nibble)
        }
        // Write the output bytes
        writeBytes(out_file, payload_buf, payload_size);
        printf("Decoding completed successfully!\n");
        free(input_buf);
        free(payload_buf);
    } else {
        printf("Error: Invalid argument: %s\n", argv[1]);
        fclose(in_file);
        fclose(out_file);
        return EXIT_FAILURE;
    }

    fclose(in_file);
    fclose(out_file);
    return EXIT_SUCCESS;
}