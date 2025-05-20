//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* read_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = malloc(size + 1);
    if (!buffer) {
        fprintf(stderr, "Error: Could not allocate memory\n");
        exit(1);
    }

    fread(buffer, 1, size, file);
    buffer[size] = '\0';

    fclose(file);
    return buffer;
}

int main() {
    char* input_file = read_file("input.txt");
    char* output_file = read_file("output.txt");

    int num_lines = 0;
    int num_chars = 0;

    FILE* output = fopen("output.txt", "w");
    if (!output) {
        fprintf(stderr, "Error: Could not open file output.txt\n");
        exit(1);
    }

    char* line = strtok(input_file, "\n");
    while (line) {
        num_lines++;
        num_chars += strlen(line);

        fprintf(output, "%d: %s", num_lines, line);

        line = strtok(NULL, "\n");
    }

    fprintf(output, "\nTotal lines: %d\nTotal characters: %d", num_lines, num_chars);

    fclose(output);
    free(input_file);
    free(output_file);

    return 0;
}