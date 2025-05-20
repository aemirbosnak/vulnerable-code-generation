//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <time.h>

typedef struct HexData {
    unsigned char hex[3];
    unsigned int decimal;
} HexData;

void convert_hex_to_decimal(const char *hex_str, HexData *hex_data) {
    unsigned char hex[3];
    unsigned int decimal = 0;

    sscanf(hex_str, "%2hhx", &hex[0]);
    sscanf(hex_str + 2, "%2hhx", &hex[1]);

    hex_data->decimal = (hex[0] << 4) | hex[1];
    strncpy(hex_data->hex, hex_str, 3);
}

void print_hex_data(const HexData *hex_data) {
    printf("%s = %#x\n", hex_data->hex, hex_data->decimal);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hex_string>\n", argv[0]);
        return 1;
    }

    HexData hex_data;
    convert_hex_to_decimal(argv[1], &hex_data);

    clock_t start = clock();

    for (int i = 0; i < 100000; i++) {
        hex_data.decimal++;
    }

    clock_t end = clock();
    double time_taken = (end - start) / (double) CLOCKS_PER_SEC;

    printf("\nHexadecimal value %s converted to decimal and back, new decimal value: %#x\n", hex_data.hex, hex_data.decimal);
    printf("Time taken to perform this conversion: %f seconds\n", time_taken);

    print_hex_data(&hex_data);

    munmap(hex_data.hex, 3);

    return 0;
}