//FormAI DATASET v1.0 Category: Compression algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void compress(char* input_file, char* output_file) {
    FILE *in_file = fopen(input_file, "rb");
    FILE *out_file = fopen(output_file, "wb");
    
    char buffer[BUFFER_SIZE];
    size_t read_bytes;
    size_t write_bytes;

    while ((read_bytes = fread(buffer, sizeof(char), BUFFER_SIZE, in_file)) > 0) {
        char last_char = buffer[0];
        int count = 1;

        for (int i = 1; i < read_bytes; i++) {
            if (buffer[i] == last_char) {
                count++;
            } else {
                fwrite(&count, sizeof(int), 1, out_file);
                fwrite(&last_char, sizeof(char), 1, out_file);
                last_char = buffer[i];
                count = 1;
            }
        }

        fwrite(&count, sizeof(int), 1, out_file);
        fwrite(&last_char, sizeof(char), 1, out_file);
    }

    fclose(in_file);
    fclose(out_file);
}

void decompress(char* input_file, char* output_file) {
    FILE *in_file = fopen(input_file, "rb");
    FILE *out_file = fopen(output_file, "wb");

    int count;
    while (fread(&count, sizeof(int), 1, in_file) > 0) {
        char c;
        fread(&c, sizeof(char), 1, in_file);
        for (int i = 0; i < count; i++) {
            fwrite(&c, sizeof(char), 1, out_file);
        }
    }

    fclose(in_file);
    fclose(out_file);
}

int main(int argc, char* argv[]) {
    char* input_file = argv[1];
    char* output_file = argv[2];
    char* command = argv[3];

    if (strcmp(command, "compress") == 0) {
        compress(input_file, output_file);
    } else if (strcmp(command, "decompress") == 0) {
        decompress(input_file, output_file);
    }

    return 0;
}