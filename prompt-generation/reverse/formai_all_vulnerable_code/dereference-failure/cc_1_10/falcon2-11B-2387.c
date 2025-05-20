//Falcon2-11B DATASET v1.0 Category: Binary Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* input;
    char* output;
} BinaryConverter;

void convert_to_binary(BinaryConverter* converter) {
    int num_bits = strlen(converter->input);
    int i;
    char* bin_str = malloc(num_bits * sizeof(char));
    if (bin_str == NULL) {
        fprintf(stderr, "Error allocating memory for binary string\n");
        exit(1);
    }
    for (i = 0; i < num_bits; i++) {
        char digit = converter->input[i];
        if (digit == '0') {
            bin_str[i] = '0';
        } else {
            bin_str[i] = '1';
        }
    }
    converter->output = bin_str;
}

void print_binary(BinaryConverter* converter) {
    printf("%s\n", converter->output);
}

void free_binary_converter(BinaryConverter* converter) {
    free(converter->output);
    free(converter);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <input>\n", argv[0]);
        exit(1);
    }
    BinaryConverter converter = {
       .input = argv[1],
       .output = NULL,
    };
    convert_to_binary(&converter);
    printf("Input: %s\n", converter.input);
    print_binary(&converter);
    free_binary_converter(&converter);
    return 0;
}