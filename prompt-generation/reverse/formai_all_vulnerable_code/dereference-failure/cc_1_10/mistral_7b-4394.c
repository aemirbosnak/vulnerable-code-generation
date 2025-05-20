//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_BINARY_LENGTH 64
#define MAX_DECIMAL_LENGTH 20

typedef struct {
    char binary[MAX_BINARY_LENGTH + 1];
    int decimal;
} binary_converter_t;

static void init_binary_converter(binary_converter_t* self) {
    memset(self->binary, '\0', sizeof(self->binary));
    self->decimal = 0;
}

static bool is_digit(char c) {
    return isdigit((unsigned char)c);
}

static bool convert_binary(binary_converter_t* self, const char* decimal_string) {
    init_binary_converter(self);

    int decimal = 0;
    int base = 1;
    bool negative = false;

    size_t length = strlen(decimal_string);

    if (decimal_string[0] == '-') {
        negative = true;
        decimal_string++;
        length--;
    }

    for (size_t i = length; i != 0; i--) {
        char digit = decimal_string[i];

        if (!is_digit(digit)) {
            self->decimal = -1;
            return false;
        }

        decimal += (isdigit(digit) ? (int)(digit - '0') : ((int)toupper(digit) - 'A' + 10));
        decimal *= base;
        base *= 10;
    }

    self->decimal = decimal;

    if (negative) {
        self->decimal = -self->decimal;
    }

    char binary[MAX_BINARY_LENGTH + 1];
    int index = 0;

    while (self->decimal != 0) {
        binary[index++] = self->decimal % 2 + '0';
        self->decimal /= 2;
    }

    if (index == 0) {
        binary[index++] = '0';
    }

    strncpy(self->binary, binary, index + 1);

    return true;
}

static void print_binary(const binary_converter_t* self) {
    printf("%s\n", self->binary);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <decimal number>\n", argv[0]);
        return 1;
    }

    binary_converter_t converter;

    if (!convert_binary(&converter, argv[1])) {
        printf("Invalid decimal number.\n");
        return 1;
    }

    print_binary(&converter);

    return 0;
}