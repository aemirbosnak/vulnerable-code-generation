//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 4096

unsigned char buffer[BLOCK_SIZE];

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char* input_filename = argv[1];
    char* output_filename = "recovered_data.bin";

    FILE* input_file = fopen(input_filename, "rb");
    FILE* output_file = fopen(output_filename, "wb");

    if (!input_file) {
        printf("Error: Could not open file %s\n", input_filename);
        return 1;
    }

    int input_file_size;
    fseek(input_file, 0L, SEEK_END);
    input_file_size = ftell(input_file);
    fseek(input_file, 0L, SEEK_SET);

    int no_of_blocks = input_file_size / BLOCK_SIZE;
    if (input_file_size % BLOCK_SIZE != 0)
        no_of_blocks++;

    for (int block_index = 0; block_index < no_of_blocks; block_index++) {

        fseek(input_file, block_index * BLOCK_SIZE, SEEK_SET);

        int bytes_read = fread(buffer, sizeof(unsigned char), BLOCK_SIZE, input_file);

        for (int i = 0; i < bytes_read; i++) {
            if (buffer[i] == 0) {
                buffer[i] = 1;
            }
        }

        fwrite(buffer, sizeof(unsigned char), BLOCK_SIZE, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Data recovery complete! Recovered data written to file %s\n", output_filename);

    return 0;
}