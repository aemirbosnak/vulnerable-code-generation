//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BLACK   "\033[1;30m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"
#define BOLD    "\033[1m"
#define UNDERLINE "\033[4m"
#define RESET   "\033[0m"

void hex_to_bin(unsigned char hex, char bin[3]) {
    unsigned char num = hex & 0xF;

    bin[0] = '0' + (num >> 1);
    bin[1] = '0' + (num & 0x01);
    bin[2] = '\0';
}

void bin_to_hex(char bin[3], unsigned char *hex) {
    unsigned char num = 0;

    for (int i = 0; i < 2; i++) {
        if (bin[i] == '1')
            num += pow(2, 2 - i);
    }

    *hex = num;
}

int main(int argc, char *argv[]) {
    char hex[11];
    char bin[5];
    unsigned char dec;

    if (argc != 2) {
        printf(RED "[ERROR] " RESET "Usage: %s <hexadecimal value>\n", argv[0]);
        return 1;
    }

    strcpy(hex, argv[1]);
    printf(GREEN "[INFO] " RESET "Converting Hexadecimal to Binary...\n");

    for (int i = 0; i < strlen(hex); i++) {
        if (isdigit(hex[i])) {
            hex_to_bin(hex[i] - '0', bin);
            printf(BOLD YELLOW "%s" RESET, bin);
        } else {
            hex_to_bin(hex[i] - 'A' + 10, bin);
            printf(BOLD MAGENTA "%s" RESET, bin);
        }

        strcpy(bin, " ");
    }

    printf(BLUE "[INFO] " RESET "Converting Binary to Decimal...\n");

    dec = 0;
    for (int i = 0; hex[i] != '\0'; i++) {
        char bin[3];
        hex_to_bin(hex[i], bin);
        bin_to_hex(bin, &dec);
        dec <<= 4;
    }

    printf(CYAN "[INFO] " RESET "Decimal value: %X\n", dec);

    return 0;
}