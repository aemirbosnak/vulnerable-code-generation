//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define MAX_DIGITS 64

void error(char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

char *read_line(FILE *input) {
    char *line = NULL;
    size_t size = 0;
    getline(&line, &size, input);
    if (line == NULL) {
        error("Unexpected end of file");
    }
    return line;
}

int is_binary(char *line) {
    int i;
    for (i = 0; i < strlen(line); i++) {
        if (!isdigit(line[i])) {
            return 0;
        }
    }
    return 1;
}

char *convert_binary(char *binary, int length) {
    char *decimal = malloc(MAX_LENGTH);
    int i, j, k;
    decimal[0] = '\0';
    for (i = length - 1, j = 0; i >= 0; i--, j++) {
        if (binary[i] == '1') {
            k = j + 1;
            while (k <= MAX_DIGITS - 1) {
                decimal[k] = '0';
                k++;
            }
        }
        decimal[j] = binary[i];
    }
    return decimal;
}

void write_decimal(char *decimal, FILE *output) {
    fprintf(output, "%s\n", decimal);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        error("Usage:./binary_converter input_file output_file");
    }
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        error("Cannot open input file");
    }
    FILE *output = fopen(argv[2], "w");
    if (output == NULL) {
        error("Cannot open output file");
    }
    char *line;
    while ((line = read_line(input))!= NULL) {
        if (!is_binary(line)) {
            error("Invalid binary input");
        }
        char *decimal = convert_binary(line, strlen(line));
        write_decimal(decimal, output);
        free(decimal);
    }
    fclose(input);
    fclose(output);
    return 0;
}