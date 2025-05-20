//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define HEX_SIZE 32
#define BIN_SIZE 4 * HEX_SIZE

typedef struct {
    unsigned char hex[HEX_SIZE];
    unsigned char bin[BIN_SIZE];
} HexBin;

bool isHex(char c) {
    return (isdigit(c) || (isalpha(c) && isxdigit(tolower(c))));
}

bool hexStrToBin(HexBin *hb, const char *s) {
    memset(hb->bin, 0, BIN_SIZE);

    int hb_i = 0;
    for (int str_i = 0; s[str_i] != '\0'; str_i++) {
        if (!isHex(s[str_i])) {
            fprintf(stderr, "Invalid hexadecimal character %c\n", s[str_i]);
            return false;
        }

        unsigned char digit = tolower(s[str_i]);
        if (isdigit(digit)) {
            hb->hex[hb_i] = digit - '0';
        } else {
            hb->hex[hb_i] = (digit - 'a' + 10) << 4;
            hb->hex[hb_i] |= (s[++str_i] - '0');
        }

        int bit_i = 4 * hb_i;
        for (int bit_j = 3; bit_j >= 0; bit_j--) {
            hb->bin[bit_i + bit_j] = hb->hex[hb_i] & (1 << bit_j) ? 1 : 0;
        }

        hb_i++;
    }

    return true;
}

void printBin(const HexBin *hb) {
    for (int i = 0; i < BIN_SIZE; i += 4) {
        for (int j = i; j < i + 4 && j < BIN_SIZE; j++) {
            printf("%d", hb->bin[j]);
        }
        printf(" ");
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hexadecimal string>\n", argv[0]);
        return 1;
    }

    HexBin hb;
    if (!hexStrToBin(&hb, argv[1])) {
        return 1;
    }

    printBin(&hb);
    return 0;
}