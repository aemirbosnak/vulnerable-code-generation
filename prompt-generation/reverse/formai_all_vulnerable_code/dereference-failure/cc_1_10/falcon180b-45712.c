//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1000
#define HEX_DIGITS "0123456789ABCDEF"

int main(int argc, char *argv[]) {
    FILE *in_file, *out_file;
    char input_line[MAX_LINE_SIZE], output_line[MAX_LINE_SIZE], hex_val[3];
    int line_num = 0, hex_len = 0;

    if (argc!= 3) {
        printf("Error: Invalid number of arguments\n");
        return 1;
    }

    in_file = fopen(argv[1], "r");
    if (in_file == NULL) {
        printf("Error: Could not open input file\n");
        return 1;
    }

    out_file = fopen(argv[2], "w");
    if (out_file == NULL) {
        printf("Error: Could not open output file\n");
        fclose(in_file);
        return 1;
    }

    while (fgets(input_line, MAX_LINE_SIZE, in_file)!= NULL) {
        line_num++;
        hex_len = 0;

        // Convert each character in input line to hexadecimal
        for (int i = 0; input_line[i]!= '\0'; i++) {
            if (isprint(input_line[i])) {
                sprintf(hex_val, "%02X", input_line[i]);
                strcat(output_line, hex_val);
                hex_len += 2;
            } else {
                sprintf(hex_val, ".");
                strcat(output_line, hex_val);
                hex_len++;
            }
        }

        // Add newline character to output line
        strcat(output_line, "\n");
        hex_len++;

        // Write output line to output file
        fprintf(out_file, "%s", output_line);
    }

    fclose(in_file);
    fclose(out_file);

    printf("Conversion completed successfully\n");
    return 0;
}