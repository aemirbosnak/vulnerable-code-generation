//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <float.h>

#define BINARY_MAX 1024
#define BINARY_STR_MAX 32

typedef struct binary_t {
    int value;
    int length;
} binary_t;

binary_t* binary_alloc(int value, int length) {
    binary_t* bin = malloc(sizeof(binary_t));
    bin->value = value;
    bin->length = length;
    return bin;
}

void binary_free(binary_t* bin) {
    free(bin);
}

int binary_to_decimal(binary_t* bin) {
    int decimal = 0;
    for (int i = 0; i < bin->length; i++) {
        decimal += (bin->value >> i) & 1;
    }
    return decimal;
}

binary_t* decimal_to_binary(int decimal) {
    int length = 0;
    binary_t* bin = malloc(sizeof(binary_t));
    while (decimal != 0) {
        bin->value = (decimal & 1) << length++;
        decimal >>= 1;
    }
    bin->length = length;
    return bin;
}

int main() {
    srand(time(NULL));

    // Generate some random binary numbers
    for (int i = 0; i < 10; i++) {
        binary_t* bin = binary_alloc(rand() % 2 ? 1 : 0, rand() % 8 + 1);
        printf("%s", bin->value == 0 ? "0" : "1");
        binary_free(bin);
    }

    // Convert some decimal numbers to binary
    for (int i = 0; i < 10; i++) {
        int decimal = rand() % 100;
        binary_t* bin = decimal_to_binary(decimal);
        printf("%s", bin->value == 0 ? "0" : "1");
        binary_free(bin);
    }

    return 0;
}