//FormAI DATASET v1.0 Category: Data recovery tool ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char *input_filename = argv[1];
    char *output_filename = argv[2];

    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        printf("Error: could not open input file %s\n", input_filename);
        return 2;
    }

    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        printf("Error: could not open output file %s\n", output_filename);
        return 3;
    }

    char data[MAX_DATA_SIZE];
    int bytes_read = fread(data, 1, MAX_DATA_SIZE, input_file);
    if (bytes_read <= 0) {
        printf("Error: could not read from input file %s\n", input_filename);
        return 4;
    }

    int i;
    for (i = bytes_read - 1; i >= 0; i--) {
        if (data[i] == '\0') {
            int j;
            for (j = i + 1; j < bytes_read; j++) {
                fputc(data[j], output_file);
            }
            break;
        }
    }

    fclose(input_file);
    fclose(output_file);

    printf("File recovered successfully!\n");

    return 0;
}