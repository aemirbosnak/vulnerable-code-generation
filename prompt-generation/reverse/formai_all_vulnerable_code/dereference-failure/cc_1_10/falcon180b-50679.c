//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

    char *hex = NULL;
    int hex_len = 0;

    printf("Enter hexadecimal string: ");
    fgets(hex, 100, stdin);

    hex_len = strlen(hex);

    if (hex_len!= 0) {

        int i = 0;
        int decimal = 0;
        int power = 0;

        while (i < hex_len) {

            if (isxdigit(hex[i])) {

                if (isdigit(hex[i])) {

                    decimal += (hex[i] - '0') * (int) pow(16, hex_len - i - 1);

                } else {

                    int num = hex[i] - 'A' + 10;

                    decimal += num * (int) pow(16, hex_len - i - 1);

                }

            } else {

                printf("Invalid character '%c' found in hexadecimal string.\n", hex[i]);
                exit(1);

            }

            i++;

        }

        printf("Decimal equivalent: %d\n", decimal);

    } else {

        printf("Empty hexadecimal string entered.\n");

    }

    return 0;

}