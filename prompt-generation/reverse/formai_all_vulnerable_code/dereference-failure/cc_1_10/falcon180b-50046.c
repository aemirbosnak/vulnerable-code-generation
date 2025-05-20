//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    char *input = NULL;
    int input_len = 0;
    char *output = NULL;
    int output_len = 0;
    int i;

    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    input_len = ftell(input_file);
    rewind(input_file);

    input = malloc(input_len + 1);
    if (input == NULL) {
        printf("Error allocating memory for input.\n");
        fclose(input_file);
        return 1;
    }

    fread(input, 1, input_len, input_file);
    fclose(input_file);

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        free(input);
        return 1;
    }

    for (i = 0; i < input_len; i++) {
        char c = toupper(input[i]);
        if (isxdigit(c)) {
            sprintf(&output[output_len], "%02X ", c);
            output_len += 3;
        } else {
            sprintf(&output[output_len], ". ");
            output_len++;
        }
    }

    fwrite(output, 1, output_len, output_file);
    fclose(output_file);

    free(input);
    free(output);

    return 0;
}