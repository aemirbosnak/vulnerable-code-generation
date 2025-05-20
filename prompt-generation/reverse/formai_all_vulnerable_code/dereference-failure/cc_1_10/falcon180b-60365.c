//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 1000

void print_usage() {
    printf("Usage:./program <hexadecimal_number>\n");
}

bool is_valid_hexadecimal(char *hexadecimal) {
    int i;
    for (i = 0; i < strlen(hexadecimal); i++) {
        if (!isxdigit(hexadecimal[i])) {
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        print_usage();
        return 1;
    }

    char hexadecimal[MAX_LENGTH];
    strcpy(hexadecimal, argv[1]);

    if (!is_valid_hexadecimal(hexadecimal)) {
        printf("Invalid hexadecimal number.\n");
        return 1;
    }

    int decimal = 0;
    int i;
    for (i = strlen(hexadecimal) - 1; i >= 0; i--) {
        if (isdigit(hexadecimal[i])) {
            decimal += hexadecimal[i] - '0';
        } else {
            decimal += hexadecimal[i] - 'A' + 10;
        }
        decimal *= 16;
    }

    printf("Decimal equivalent: %d\n", decimal);
    return 0;
}