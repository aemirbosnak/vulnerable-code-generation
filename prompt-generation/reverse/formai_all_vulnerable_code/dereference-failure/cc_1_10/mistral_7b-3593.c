//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 32

void die(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    char input[MAX_INPUT_LENGTH];
    char *end;
    unsigned long result;
    int base;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <decimal number> <base>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strcpy(input, argv[1]);
    base = strtoul(argv[2], &end, 0);

    if (*end != '\0') {
        die("Invalid base.\n");
    }

    // Convert decimal number to hexadecimal
    result = strtoul(input, NULL, 0);

    if (base < 1 || base > 36) {
        die("Invalid base. Supported bases are 1-36.\n");
    }

    if (base > 10) {
        // Print the prefix "0x" for bases greater than 10
        printf("0x");
    }

    // Convert decimal number to hexadecimal and print it
    for (; result != 0; result >>= 4) {
        int digit = result & 0xF;

        if (digit < 10) {
            putchar('0' + digit);
        } else {
            putchar('A' + (digit - 10));
        }
    }

    putchar('\n');

    return EXIT_SUCCESS;
}