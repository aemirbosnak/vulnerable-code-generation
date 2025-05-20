//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define HEX_DIGITS "0123456789ABCDEF"

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char input_buffer[MAX_LINE_LENGTH];
    char output_buffer[MAX_LINE_LENGTH * 3];
    int num_bytes_read, num_bytes_written;
    int i, j;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Could not open input file %s\n", argv[1]);
        exit(1);
    }

    output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error: Could not open output file %s\n", argv[2]);
        exit(1);
    }

    while ((num_bytes_read = fread(input_buffer, 1, MAX_LINE_LENGTH, input_file)) > 0) {
        num_bytes_written = 0;
        for (i = 0; i < num_bytes_read; i++) {
            if (isprint(input_buffer[i])) {
                sprintf(&output_buffer[num_bytes_written], "%02X ", input_buffer[i]);
                num_bytes_written += 3;
            } else {
                sprintf(&output_buffer[num_bytes_written], ".");
                num_bytes_written += 1;
            }
        }
        output_buffer[num_bytes_written] = '\0';
        fwrite(output_buffer, 1, num_bytes_written, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}