//FormAI DATASET v1.0 Category: Image Steganography ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// function to hide message in the image
void hideMessage(char* input_path, char* output_path, char* message)
{
    // open input and output files as binary files
    FILE* input_file = fopen(input_path, "rb");
    FILE* output_file = fopen(output_path, "wb");

    // find size of input file
    fseek(input_file, 0L, SEEK_END);
    int input_size = ftell(input_file);
    fseek(input_file, 0L, SEEK_SET);

    // allocate memory for buffer
    unsigned char* buffer = (unsigned char*) malloc(input_size * sizeof(unsigned char));

    // read input file into buffer
    fread(buffer, sizeof(unsigned char), input_size, input_file);

    // get size of message
    int message_size = strlen(message);

    // add message size to buffer
    for (int i = 0; i < sizeof(int); i++) {
        buffer[i] = (message_size >> (8 * i)) & 0xFF;
    }

    // add message to buffer
    for (int i = 0; i < message_size; i++) {
        buffer[sizeof(int) + i] = message[i];
    }

    // write buffer to output file
    fwrite(buffer, sizeof(unsigned char), input_size, output_file);

    // free memory and close files
    free(buffer);
    fclose(input_file);
    fclose(output_file);

    printf("Message successfully hidden in image!");
}

// function to extract message from the image
void extractMessage(char* image_path)
{
    // open image file as binary file
    FILE* file = fopen(image_path, "rb");

    // find size of file
    fseek(file, 0L, SEEK_END);
    int size = ftell(file);
    fseek(file, 0L, SEEK_SET);

    // allocate memory for buffer
    unsigned char* buffer = (unsigned char*) malloc(size * sizeof(unsigned char));

    // read file into buffer
    fread(buffer, sizeof(unsigned char), size, file);

    // get message size
    int message_size = 0;
    for (int i = 0; i < sizeof(int); i++) {
        message_size |= (buffer[i] << (8 * i));
    }

    // allocate memory for message
    char* message = (char*) malloc(message_size * sizeof(char));

    // extract message from buffer
    for (int i = 0; i < message_size; i++) {
        message[i] = buffer[sizeof(int) + i];
    }

    // print message and free memory
    printf("Extracted message: %s\n", message);
    free(buffer);
    free(message);
    fclose(file);
}

int main()
{
    char* input_path = "image.bmp";
    char* output_path = "image_with_message.bmp";
    char* message = "This is a secret message!";

    hideMessage(input_path, output_path, message);
    extractMessage(output_path);

    return 0;
}