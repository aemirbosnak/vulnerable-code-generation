//FormAI DATASET v1.0 Category: Compression algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    char *input_filename = argv[1];
    char *output_filename = "output.cmp";

    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        printf("Unable to open input file %s\n", input_filename);
        return 1;
    }

    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        printf("Unable to open output file %s\n", output_filename);
        return 1;
    }

    unsigned char buffer[BUFFER_SIZE];
    int read_size = 0;

    while ((read_size = fread(buffer, 1, BUFFER_SIZE, input_file)) > 0) {
        int i = 0, j = 0;
        while (j < read_size) {
            int count = 0;

            for (i = j; i < read_size; i++) {
                if (buffer[i] != buffer[j]) {
                    break;
                }

                count++;
            }

            if (count >= 4) {
                int marker = count << 8 | buffer[j];

                fwrite(&marker, sizeof(int), 1, output_file);
                fwrite(&buffer[j + count], sizeof(char), 1, output_file);

                j += count;
            } else {
                fwrite(&buffer[j], sizeof(char), 1, output_file);

                j++;
            }
        }
    }

    fclose(input_file);
    fclose(output_file);

    printf("Compression complete. Output written to %s.\n", output_filename);

    return 0;
}