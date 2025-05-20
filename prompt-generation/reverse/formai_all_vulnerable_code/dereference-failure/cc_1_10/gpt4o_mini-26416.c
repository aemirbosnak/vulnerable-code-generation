//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

void print_help() {
    printf("Hexadecimal Converter\n");
    printf("Usage: hex_converter [options] <number>\n");
    printf("Options:\n");
    printf("  -h, --help        Show this help message\n");
    printf("  -d, --decimal     Convert from decimal to hexadecimal\n");
    printf("  -h, --hexadecimal Convert from hexadecimal to decimal\n");
}

void decimal_to_hexadecimal(int decimal) {
    char hex[10];
    int i = 0;

    // Handle special case for 0
    if (decimal == 0) {
        printf("Hexadecimal: 0\n");
        return;
    }

    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[i++] = remainder + '0';
        } else {
            hex[i++] = (remainder - 10) + 'A';
        }
        decimal /= 16;
    }

    // Print hexadecimal in reverse order
    printf("Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        putchar(hex[j]);
    }
    putchar('\n');
}

void hexadecimal_to_decimal(const char *hex) {
    int decimal = 0;
    while (*hex) {
        decimal *= 16;
        if (*hex >= '0' && *hex <= '9') {
            decimal += *hex - '0';
        } else if (*hex >= 'A' && *hex <= 'F') {
            decimal += *hex - 'A' + 10;
        } else if (*hex >= 'a' && *hex <= 'f') {
            decimal += *hex - 'a' + 10;
        } else {
            printf("Invalid hexadecimal number: %s\n", hex);
            return;
        }
        hex++;
    }
    printf("Decimal: %d\n", decimal);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        print_help();
        return 1;
    }

    if (strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "--decimal") == 0) {
        int decimal = atoi(argv[2]);
        decimal_to_hexadecimal(decimal);
    } else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--hexadecimal") == 0) {
        hexadecimal_to_decimal(argv[2]);
    } else {
        print_help();
        return 1;
    }

    return 0;
}