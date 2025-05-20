//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char hex[100], ascii[100];
    int i, j, k, len;
    char *p;

    // Check if argument is provided
    if (argc < 2) {
        printf("Usage: %s <hexadecimal>\n", argv[0]);
        exit(1);
    }

    // Convert hexadecimal to uppercase
    strcpy(hex, argv[1]);
    for (i = 0; i < strlen(hex); i++) {
        if (isxdigit(hex[i]) == 0) {
            printf("Invalid hexadecimal character: %c\n", hex[i]);
            exit(1);
        }
        if (isdigit(hex[i])) {
            hex[i] = hex[i] - 48;
        } else {
            hex[i] = hex[i] - 55;
        }
    }

    // Convert hexadecimal to ASCII
    len = strlen(hex);
    for (i = 0, j = 0; i < len; i += 2) {
        if (i + 1 >= len) {
            ascii[j] = hex[i];
            j++;
            break;
        }
        p = strchr("0123456789ABCDEF", toupper(hex[i]));
        if (p == NULL) {
            printf("Invalid hexadecimal character: %c\n", hex[i]);
            exit(1);
        }
        ascii[j] = p - 'A' + 10;
        j++;
    }
    ascii[j] = '\0';

    // Print the result
    printf("Hexadecimal: %s\n", hex);
    printf("ASCII: %s\n", ascii);

    return 0;
}