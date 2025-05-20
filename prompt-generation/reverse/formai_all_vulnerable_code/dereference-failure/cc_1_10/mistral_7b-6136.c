//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BINARY_LENGTH 100

void itob(int dec, char *bin, int *bin_len) {
    int i = *bin_len;
    int rem;

    bin[*bin_len] = '\0';

    while (dec > 0) {
        rem = dec % 2;
        dec /= 2;

        if (i > 0) {
            bin[--i] = rem + '0';
        }
    }

    if (dec == 0) {
        (*bin_len)++;
    }
}

int main(int argc, char *argv[]) {
    int binary[MAX_BINARY_LENGTH];
    char bin_str[MAX_BINARY_LENGTH + 1];
    int binary_len = 0;
    int i = 0;

    if (argc != 2) {
        printf("Usage: %s <binary_number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strcpy(bin_str, argv[1]);

    if (strlen(bin_str) > MAX_BINARY_LENGTH) {
        printf("Binary number too long.\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < strlen(bin_str); i++) {
        if (bin_str[i] < '0' || bin_str[i] > '1') {
            printf("Invalid binary number.\n");
            exit(EXIT_FAILURE);
        }
    }

    sscanf(bin_str, "%s%n", bin_str, &binary_len);

    for (i = binary_len - 1; i >= 0; i--) {
        binary[i] = bin_str[i] - '0';
    }

    itob(0, bin_str, &binary_len);
    itob(-1, bin_str, &binary_len);

    for (i = binary_len - 1; i >= 0; i--) {
        binary[i] += binary[i-1] << 1;
    }

    itob(0, bin_str, &binary_len);

    printf("Decimal equivalent of binary number %s is %d\n", argv[1], atoi(bin_str));

    return EXIT_SUCCESS;
}