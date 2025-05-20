//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int is_hex(char ch) {
    return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F');
}

int hex_to_int(char* str) {
    int i = 0;
    int result = 0;

    while (str[i]!= '\0') {
        if (is_hex(str[i])) {
            result = (result << 4) | (str[i] - '0');
        } else {
            return -1;
        }

        i++;
    }

    return result;
}

char* int_to_hex(int num) {
    int i = 0;
    char* hex_str = (char*)malloc(3 * sizeof(char));
    sprintf(hex_str, "%02x", num);

    while (i < 2) {
        hex_str[i] = hex_str[i] - '0';
    }

    return hex_str;
}

int main() {
    char* hex_str;

    printf("Enter a hexadecimal string: ");
    fgets(hex_str, 100, stdin);

    int num = hex_to_int(hex_str);
    if (num < 0) {
        printf("Invalid hexadecimal string\n");
    } else {
        printf("Hexadecimal to decimal: %d\n", num);
        printf("Decimal to hexadecimal: %s\n", int_to_hex(num));
    }

    free(hex_str);
    return 0;
}