//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_SIZE 4096
#define MAX_CODE_TABLE_SIZE 4096

// Compression algorithm using Lempel-Ziv-Welch (LZW)
void lzw_compress(char* input_file, char* output_file) {
    FILE* input = fopen(input_file, "rb");
    if (!input) {
        printf("Error: Could not open input file.\n");
        return;
    }

    FILE* output = fopen(output_file, "wb");
    if (!output) {
        printf("Error: Could not open output file.\n");
        fclose(input);
        return;
    }

    // Initialize code table
    int code_size = 256;
    int code_table_size = 0;
    int* code_table = malloc(code_size * sizeof(int));
    for (int i = 0; i < code_size; i++) {
        code_table[i] = i;
    }

    // Write code table to output file
    fwrite(&code_size, sizeof(int), 1, output);
    for (int i = 0; i < code_size; i++) {
        fwrite(&code_table[i], sizeof(int), 1, output);
    }

    // Initialize variables
    int code = 0;
    int code_length = 0;
    int input_length = 0;
    int output_length = 0;

    // Read input file
    int input_buffer[4096];
    while (fread(input_buffer, sizeof(char), sizeof(input_buffer), input) > 0) {
        input_length += fread(input_buffer, sizeof(char), sizeof(input_buffer), input);

        // Reset code table
        if (code_table_size == code_size) {
            code_size *= 2;
            code_table = realloc(code_table, code_size * sizeof(int));
            for (int i = code_table_size; i < code_size; i++) {
                code_table[i] = i;
            }
        }

        int i = 0;
        while (i < input_length) {
            int c = input_buffer[i];
            if (c == '\n') {
                break;
            }

            // Output code
            if (code == 0) {
                fwrite(&code, sizeof(int), 1, output);
                code_table[code_table_size++] = code;
            }

            int next_code = code_table[c];
            if (next_code == 0) {
                fwrite(&c, sizeof(char), 1, output);
                code_table[code_table_size++] = c;
            } else {
                code = next_code;
            }

            i++;
        }
    }

    // Output final code
    if (code!= 0) {
        fwrite(&code, sizeof(int), 1, output);
    }

    // Write code table to output file
    fwrite(&code_size, sizeof(int), 1, output);
    for (int i = 0; i < code_size; i++) {
        fwrite(&code_table[i], sizeof(int), 1, output);
    }

    // Cleanup
    fclose(input);
    fclose(output);
}

int main() {
    char input_file[] = "input.txt";
    char output_file[] = "output.txt";

    lzw_compress(input_file, output_file);

    return 0;
}