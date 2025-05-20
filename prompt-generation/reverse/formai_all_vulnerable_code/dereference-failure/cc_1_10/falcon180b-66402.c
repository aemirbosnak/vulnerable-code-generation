//Falcon-180B DATASET v1.0 Category: Error handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ERROR_LENGTH 256

// Function prototypes
void read_file(FILE *fp, char *buffer, size_t size);
void handle_error(const char *message);

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        handle_error("Usage:./program input_file output_file");
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        handle_error("Error opening input file");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        handle_error("Error opening output file");
        return 1;
    }

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, input_file)!= NULL) {
        fputs(buffer, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}

void read_file(FILE *fp, char *buffer, size_t size) {
    size_t bytes_read = fread(buffer, 1, size, fp);
    if (bytes_read!= size) {
        handle_error("Error reading file");
    }
}

void handle_error(const char *message) {
    printf("Error: %s\n", message);
    exit(1);
}