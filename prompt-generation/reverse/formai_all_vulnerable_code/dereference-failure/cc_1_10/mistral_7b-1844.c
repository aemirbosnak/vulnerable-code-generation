//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 50

void print_usage_and_exit() {
    printf("Usage: hex_to_decimal [hex_string]\n");
    exit(1);
}

int hex_char_to_decimal(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    print_usage_and_exit();
    return -1;
}

int *hex_string_to_decimal_array(char *hex_string) {
    int *decimal_array = (int *)malloc(sizeof(int) * (strlen(hex_string) / 2 + 1));
    int index = 0;

    for (int i = 0; i < strlen(hex_string); i += 2) {
        decimal_array[index++] = hex_char_to_decimal(hex_string[i]) * 16;
        decimal_array[index++] = hex_char_to_decimal(hex_string[i + 1]);
        decimal_array[index++] += decimal_array[index - 1];
    }

    decimal_array = realloc(decimal_array, sizeof(int) * index);
    return decimal_array;
}

int main(int argc, char *argv[]) {
    if (argc != 2)
        print_usage_and_exit();

    int *decimal_array = hex_string_to_decimal_array(argv[1]);

    if (decimal_array == NULL) {
        fprintf(stderr, "Error: Invalid hexadecimal string\n");
        exit(1);
    }

    printf("Decimal equivalents:\n");
    for (int i = 0; i < strlen(argv[1]) / 2 + 1; i++) {
        printf("%d ", decimal_array[i]);
    }
    printf("\n");

    free(decimal_array);
    return 0;
}