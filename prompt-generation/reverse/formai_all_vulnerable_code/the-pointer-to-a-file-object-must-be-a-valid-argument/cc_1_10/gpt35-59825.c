//FormAI DATASET v1.0 Category: Compression algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

void compress(char *input_file, char *output_file) {
    FILE *in_file = fopen(input_file, "r");
    FILE *out_file = fopen(output_file, "w");
    char current_char;
    char prev_char = '\0';
    int count = 1;

    while ((current_char = fgetc(in_file)) != EOF) {
        if (current_char == prev_char) {
            count++;
        } else {
            if (prev_char != '\0') {
                fprintf(out_file, "%c%d", prev_char, count);
            }
            prev_char = current_char;
            count = 1;
        }
    }

    fprintf(out_file, "%c%d", prev_char, count);

    fclose(in_file);
    fclose(out_file);
}

void decompress(char *input_file, char *output_file) {
    FILE *in_file = fopen(input_file, "r");
    FILE *out_file = fopen(output_file, "w");
    char *buffer = malloc(MAX_LENGTH * sizeof(char));
    char current_char;
    int count = 0;

    while (fgets(buffer, MAX_LENGTH, in_file) != NULL) {
        for (int i = 0; i < strlen(buffer) - 1; i++) {
            if (buffer[i] >= '0' && buffer[i] <= '9') {
                count = count * 10 + (buffer[i] - '0');
            } else {
                current_char = buffer[i];
                for (int j = 0; j < count; j++) {
                    fprintf(out_file, "%c", current_char);
                }
                count = 0;
            }
        }
    }

    fclose(in_file);
    fclose(out_file);
    free(buffer);
}

int main() {
    char input_file[] = "input.txt";
    char compressed_file[] = "compressed.txt";
    char decompressed_file[] = "decompressed.txt";

    compress(input_file, compressed_file);
    decompress(compressed_file, decompressed_file);

    return 0;
}