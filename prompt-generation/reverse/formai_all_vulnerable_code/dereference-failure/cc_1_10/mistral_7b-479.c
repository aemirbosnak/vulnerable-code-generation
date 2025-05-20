//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIN_SIZE 51
#define ERROR_INVALID_BIN "Error: Invalid binary number.\n"
#define ERROR_EMPTY_BIN "Error: Binary number cannot be empty.\n"

int bin_to_dec(const char *bin, int *dec);
int is_valid_bin(const char *bin);

int main(int argc, char *argv[]) {
    int dec = 0;
    char bin[MAX_BIN_SIZE];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <binary number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strcpy(bin, argv[1]);

    if (!is_valid_bin(bin)) {
        fprintf(stderr, "%s", ERROR_INVALID_BIN);
        exit(EXIT_FAILURE);
    }

    if (strlen(bin) == 0) {
        fprintf(stderr, "%s", ERROR_EMPTY_BIN);
        exit(EXIT_FAILURE);
    }

    if (bin_to_dec(bin, &dec) != 0) {
        fprintf(stderr, "Error: Failed to convert binary number to decimal.\n");
        exit(EXIT_FAILURE);
    }

    printf("Decimal equivalent of binary number '%s': %d\n", bin, dec);
    return EXIT_SUCCESS;
}

int bin_to_dec(const char *bin, int *dec) {
    int len = strlen(bin), i, sum = 0;
    for (i = 0; i < len; ++i) {
        sum += (bin[i] - '0') * pow(2, len - i - 1);
    }
    *dec = sum;
    return 0;
}

int is_valid_bin(const char *bin) {
    int len = strlen(bin), i;
    for (i = 0; i < len; ++i) {
        if (bin[i] != '0' && bin[i] != '1') {
            return 0;
        }
    }
    return 1;
}