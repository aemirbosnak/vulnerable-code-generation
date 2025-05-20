//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (1024*1024*10) // 10MB

void encrypt(FILE* input_file, FILE* output_file) {
    char input_buffer[MAX_FILE_SIZE];
    char output_buffer[MAX_FILE_SIZE];
    int buffer_size;

    while ((buffer_size = fread(input_buffer, 1, MAX_FILE_SIZE, input_file)) > 0) {
        // Encrypt the buffer
        for (int i = 0; i < buffer_size; i++) {
            if (isalpha(input_buffer[i])) {
                output_buffer[i] = input_buffer[i] ^ 'k'; // XOR with key 'k'
            } else {
                output_buffer[i] = input_buffer[i];
            }
        }

        // Write the encrypted buffer to output file
        fwrite(output_buffer, 1, buffer_size, output_file);
    }
}

int main(int argc, char** argv) {
    if (argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE* output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    char key = argv[3][0];
    encrypt(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully!\n");
    return 0;
}