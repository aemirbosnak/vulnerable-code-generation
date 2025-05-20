//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: Alan Turing
// Alan Turing's Binary Converter

#include <stdio.h>
#include <stdlib.h>

// Binary-to-decimal conversion function
int bin_to_dec(char *bin) {
    int dec = 0;
    int len = strlen(bin);
    for (int i = 0; i < len; i++) {
        dec += (bin[i] - '0') * (1 << (len - i - 1));
    }
    return dec;
}

// Decimal-to-binary conversion function
char *dec_to_bin(int dec) {
    char *bin = (char *)malloc(33 * sizeof(char));
    int i = 0;
    while (dec > 0) {
        bin[i++] = (dec % 2) + '0';
        dec /= 2;
    }
    bin[i] = '\0';
    // Reverse the string
    char *rev_bin = (char *)malloc(33 * sizeof(char));
    int j = 0;
    for (i = strlen(bin) - 1; i >= 0; i--) {
        rev_bin[j++] = bin[i];
    }
    rev_bin[j] = '\0';
    free(bin);
    return rev_bin;
}

int main() {
    // Binary-to-decimal conversion
    char *bin = "101011";
    int dec = bin_to_dec(bin);
    printf("Binary: %s\n", bin);
    printf("Decimal: %d\n\n", dec);

    // Decimal-to-binary conversion
    dec = 13;
    bin = dec_to_bin(dec);
    printf("Decimal: %d\n", dec);
    printf("Binary: %s\n", bin);

    return 0;
}