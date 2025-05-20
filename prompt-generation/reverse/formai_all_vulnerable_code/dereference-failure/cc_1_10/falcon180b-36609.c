//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEX_SIZE 16
#define DEC_SIZE 10
#define BUF_SIZE 100

void hex_to_dec(char *hex, char *dec) {
    int i, j;
    for (i = 0, j = 0; i < strlen(hex); i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec[j++] = hex[i];
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec[j++] = hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            dec[j++] = hex[i] - 'a' + 10;
        } else {
            printf("Invalid character in hexadecimal number.\n");
            exit(1);
        }
    }
    dec[j] = '\0';
}

void dec_to_hex(char *dec, char *hex) {
    int i, j;
    for (i = 0, j = 0; i < strlen(dec); i++) {
        if (dec[i] >= '0' && dec[i] <= '9') {
            hex[j++] = dec[i];
        } else {
            printf("Invalid character in decimal number.\n");
            exit(1);
        }
    }
    hex[j] = '\0';
}

int main(int argc, char *argv[]) {
    char hex[HEX_SIZE], dec[DEC_SIZE];
    char buf[BUF_SIZE];

    printf("Enter a hexadecimal number: ");
    fgets(buf, BUF_SIZE, stdin);
    strcpy(hex, buf);

    hex_to_dec(hex, dec);

    printf("Decimal equivalent: %s\n", dec);

    return 0;
}