//FormAI DATASET v1.0 Category: Image Steganography ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADER_SIZE 54
#define MAX_MSG_SIZE 248

// Function to perform image steganography 
void steganography(char* input_image, char* output_image, char* message) {
    FILE *fp_input, *fp_output;
    fp_input = fopen(input_image, "rb");
    fp_output = fopen(output_image, "wb");
    
    unsigned char header[HEADER_SIZE];
    unsigned char buffer;
    unsigned long int i, j, k, size, written_size = 0, msg_len;
    char msg_buf[MAX_MSG_SIZE];

    // Read and copy the image header into the output file
    fread(header, sizeof(unsigned char), HEADER_SIZE, fp_input);
    fwrite(header, sizeof(unsigned char), HEADER_SIZE, fp_output);

    // Read the image size and calculate the available space for steganography
    fseek(fp_input, 2, SEEK_SET);
    fread(&size, sizeof(unsigned long int), 1, fp_input);
    size -= HEADER_SIZE; // Substract header size
    msg_len = strlen(message);

    // Check if message will fit into the image or not
    if (msg_len > size * 8) {
        printf("Error: The message size is too big for the image size\n");
        exit(1);
    }

    // Convert message to binary using ASCII values
    for (i = 0; i < msg_len; i++) {
        for (j = 7, k = i * 8; j >= 0; j--, k++) {
            msg_buf[k] = ((message[i] >> j) & 1) + '0';
        }
    }
    msg_buf[k] = '\0'; // Add null terminator

    // Perform steganography
    fseek(fp_input, HEADER_SIZE, SEEK_SET); // Jump to the start of image data
    for (i = 0; i < size; i++) {
        fread(&buffer, sizeof(unsigned char), 1, fp_input);
        for (j = 7; j >= 0; j--) {
            if (written_size < strlen(msg_buf)) {
                if ((msg_buf[written_size] - '0') == ((buffer >> j) & 1)) {
                    // Do nothing
                } else {
                    if ((buffer >> j) & 1) {
                        buffer &= ~(1 << j); // Flip the last bit to 0
                    } else {
                        buffer |= (1 << j); // Flip the last bit to 1
                    }
                }
                written_size++;
            }
        }
        fwrite(&buffer, sizeof(unsigned char), 1, fp_output);
    }
    printf("Message has been successfully embedded in the image\n");

    // Close file pointers
    fclose(fp_input);
    fclose(fp_output);
}

int main() {
    char input_image[] = "input.bmp";
    char output_image[] = "output.bmp";
    char message[] = "Hello, I am a chatbot!";

    // Perform steganography operation
    steganography(input_image, output_image, message);

    return 0;
}