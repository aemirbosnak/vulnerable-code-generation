//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>

typedef uint8_t byte;

void DecimalToHex(byte *input, size_t length) {
    char output[32];
    int index = 0;

    for (size_t i = 0; i < length; ++i) {
        input[i] = toupper((byte)input[i]);

        if (index > 27) {
            printf("Error: Output buffer is too small.\n");
            exit(EXIT_FAILURE);
        }

        if (input[i] < 10) {
            output[index++] = '0' + input[i];
            continue;
        }

        output[index++] = 'A' + (input[i] - 10);
    }

    output[index] = '\0';
    printf("%s\n", output);
}

void HexToDecimal(byte *input, size_t length) {
    int decimal = 0;
    size_t index = 0;

    for (; length > 0; --length) {
        if (isdigit(input[length])) {
            decimal += (input[length] - '0') * (int)pow(16, index);
        } else if (isalpha(input[length])) {
            decimal += (input[length] - 'A' + 10) * (int)pow(16, index);
        } else {
            printf("Error: Invalid character found in hexadecimal string.\n");
            exit(EXIT_FAILURE);
        }

        ++index;
    }

    printf("%d\n", decimal);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s [convert] [number]\n"
               "       convert: d for decimal to hex, h for hex to decimal\n", argv[0]);
        return EXIT_FAILURE;
    }

    byte mode = argv[1][0];
    byte *number_str = argv[2];
    size_t number_length = strlen(number_str);

    byte *number = malloc(number_length + 1);

    if (mode == 'd') {
        for (size_t i = 0; i < number_length; ++i) {
            number[i] = number_str[i];
        }

        DecimalToHex(number, number_length);
    } else if (mode == 'h') {
        for (size_t i = 0; i < number_length; ++i) {
            number[i] = toupper((byte)number_str[i]);
        }

        HexToDecimal(number, number_length);

        free(number);
    } else {
        printf("Error: Invalid conversion mode.\n");
        return EXIT_FAILURE;
    }

    free(number);
    return EXIT_SUCCESS;
}