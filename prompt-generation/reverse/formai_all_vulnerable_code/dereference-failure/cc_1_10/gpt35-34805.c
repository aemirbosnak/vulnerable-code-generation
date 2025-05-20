//FormAI DATASET v1.0 Category: Audio processing ; Style: genious
/* Genius Audio Processing Example */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

/* Function to reverse the order of samples in a buffer */
void reverse_buffer(short* buffer, int length) {
    for(int i=0, j=length-1; i<j; i++, j--) {
        short temp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = temp;
    }
}

/* Main function */
int main(int argc, char** argv) {
    // Verify that input and output file names were provided
    if(argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    // Open input and output files
    FILE* in_file = fopen(argv[1], "rb");
    FILE* out_file = fopen(argv[2], "wb");

    // Verify that files were opened successfully
    if(in_file == NULL || out_file == NULL) {
        printf("Error opening files!\n");
        return 1;
    }

    // Create buffer to read audio data into
    short buffer[BUFFER_SIZE];

    // Read audio data into buffer and process
    while(!feof(in_file)) {
        size_t num_read = fread(buffer, sizeof(short), BUFFER_SIZE, in_file);

        // Reverse order of samples in buffer
        reverse_buffer(buffer, num_read);

        // Write processed audio data to output file
        fwrite(buffer, sizeof(short), num_read, out_file);
    }

    // Close input and output files
    fclose(in_file);
    fclose(out_file);

    printf("Audio processing complete!\n");

    return 0;
}