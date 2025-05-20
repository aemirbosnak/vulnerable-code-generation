//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Function to convert a decimal number to binary
char *dec_to_bin(int dec) {
    int rem, i = 0;
    char *bin = malloc(sizeof(char) * 33);

    while (dec != 0) {
        rem = dec % 2;
        bin[i++] = rem + '0';
        dec /= 2;
    }

    bin[i] = '\0';

    // Reverse the string
    int start = 0, end = i - 1;
    while (start < end) {
        char temp = bin[start];
        bin[start] = bin[end];
        bin[end] = temp;
        start++, end--;
    }

    return bin;
}

// Function to convert a binary number to decimal
int bin_to_dec(char *bin) {
    int dec = 0, i, len;

    len = strlen(bin);

    for (i = 0; i < len; i++) {
        if (bin[i] == '1') {
            dec += (1 << (len - i - 1));
        }
    }

    return dec;
}

// Main function
int main() {
    int dec;
    char *bin;

    printf("Enter a decimal number: ");
    scanf("%d", &dec);

    bin = dec_to_bin(dec);

    printf("Binary equivalent: %s\n", bin);

    dec = bin_to_dec(bin);

    printf("Decimal equivalent: %d\n", dec);

    return 0;
}