//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: accurate
/* C Hexadecimal Converter */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LENGTH 1000

int main(int argc, char **argv) {
    char hex_string[MAX_HEX_LENGTH];
    char decimal_string[MAX_HEX_LENGTH];
    int hex_len = 0, decimal_len = 0;
    int i = 0;

    /* Check if command line argument is provided */
    if (argc < 2) {
        printf("Error: Please provide a hexadecimal string.\n");
        return 1;
    }

    /* Copy command line argument to hex_string */
    strcpy(hex_string, argv[1]);

    /* Remove leading and trailing whitespace from hex_string */
    while (isspace(hex_string[0])) {
        strcpy(&hex_string[0], &hex_string[1]);
    }
    while (isspace(hex_string[hex_len - 1])) {
        hex_len--;
        hex_string[hex_len] = '\0';
    }

    /* Convert hexadecimal to decimal */
    for (i = 0; i < hex_len; i++) {
        if (isxdigit(hex_string[i])) {
            if (isdigit(hex_string[i])) {
                decimal_string[decimal_len++] = hex_string[i];
            }
            else {
                int j;
                if (hex_string[i] >= 'A') {
                    j = hex_string[i] - 'A' + 10;
                }
                else {
                    j = hex_string[i] - 'a' + 10;
                }
                decimal_string[decimal_len++] = j;
            }
        }
        else {
            printf("Error: Invalid character in hexadecimal string.\n");
            return 1;
        }
    }
    decimal_string[decimal_len] = '\0';

    /* Print decimal string */
    printf("Decimal: %s\n", decimal_string);

    return 0;
}