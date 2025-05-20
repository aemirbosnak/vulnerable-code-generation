//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_DIGITS 32

typedef struct {
    char* decimal;
    char* binary;
    int decimal_len;
    int binary_len;
} num_t;

num_t* num_create(char* decimal) {
    num_t* n = (num_t*)malloc(sizeof(num_t));
    n->decimal = decimal;
    n->decimal_len = strlen(decimal);
    n->binary_len = n->decimal_len * 8 + 1;
    n->binary = (char*)malloc(sizeof(char) * n->binary_len);
    memset(n->binary, 0, n->binary_len);
    return n;
}

void num_destroy(num_t* n) {
    free(n->decimal);
    free(n->binary);
    free(n);
}

void num_to_binary(num_t* n) {
    int i, j, carry;
    char* binary = n->binary;
    int binary_len = n->binary_len;

    for (i = 0, j = 0; i < n->decimal_len; i++) {
        carry = 0;
        int digit = n->decimal[i] - '0';
        while (digit > 0) {
            int bit = digit % 2;
            binary[j++] = (char)(bit + '0');
            carry = digit / 2;
            digit = carry;
        }
    }

    while (j < binary_len) {
        binary[j++] = '0';
    }
}

int main() {
    char input[MAX_NUM_DIGITS];
    printf("Enter a decimal number: ");
    scanf("%s", input);

    num_t* n = num_create(input);
    num_to_binary(n);

    printf("Decimal: %s\n", n->decimal);
    printf("Binary: ");
    for (int i = 0; i < n->binary_len; i++) {
        printf("%c", n->binary[i]);
    }
    printf("\n");

    num_destroy(n);
    return 0;
}