//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* input;
    int input_len;
    char* output;
    int output_len;
} binary_t;

binary_t* binary_converter(char* input) {
    int input_len = strlen(input);
    int output_len = input_len * 8 + 1;
    binary_t* res = (binary_t*) malloc(sizeof(binary_t));
    res->input = input;
    res->input_len = input_len;
    res->output = (char*) malloc(output_len);
    res->output_len = output_len;
    res->output[output_len - 1] = '\0';
    int i = 0, j = 0;
    for (i = input_len - 1; i >= 0; i--) {
        char c = input[i];
        if (c == '0' || c == '1') {
            res->output[j++] = c;
        } else {
            printf("Invalid input\n");
            exit(1);
        }
    }
    for (; j < output_len; j++) {
        res->output[j] = '0';
    }
    return res;
}

void print_binary(binary_t* binary) {
    printf("Binary: ");
    printf("%s\n", binary->output);
}

int main() {
    char* input = "Hello, world! ";
    binary_t* binary = binary_converter(input);
    print_binary(binary);
    free(binary->input);
    free(binary->output);
    free(binary);
    return 0;
}