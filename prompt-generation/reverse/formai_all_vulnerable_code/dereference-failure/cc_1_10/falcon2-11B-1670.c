//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Convert a hexadecimal string to an integer
int hex_to_int(const char* hex) {
    int i = 0;
    int num = 0;
    for (; *hex!= '\0'; hex++) {
        if (*hex >= '0' && *hex <= '9') {
            num += (*hex - '0') * 16;
        } else if (*hex >= 'A' && *hex <= 'F') {
            num += (*hex - 'A' + 10) * 16;
        } else if (*hex >= 'a' && *hex <= 'f') {
            num += (*hex - 'a' + 10) * 16;
        } else {
            return 0; // Invalid hexadecimal character
        }
    }
    return num;
}

// Convert an integer to a hexadecimal string
char* int_to_hex(int n) {
    static char hex_str[16];
    int i = 0;
    int j = 0;
    while (n > 0) {
        if (n >= 16) {
            hex_str[i++] = '0' + n % 16;
            n /= 16;
        } else if (n >= 10) {
            hex_str[i++] = '0' + n;
            n = 0;
        } else {
            hex_str[i++] = '0' + n;
            n = 0;
        }
    }
    hex_str[i] = '\0';
    return hex_str;
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <hexadecimal>\n", argv[0]);
        return 1;
    }
    int n = hex_to_int(argv[1]);
    if (n == 0) {
        printf("Invalid hexadecimal input\n");
        return 1;
    }
    char* hex_str = int_to_hex(n);
    printf("%s\n", hex_str);
    return 0;
}