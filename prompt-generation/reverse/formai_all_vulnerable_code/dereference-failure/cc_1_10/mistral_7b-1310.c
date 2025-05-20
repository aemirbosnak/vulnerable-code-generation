//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void hex2bin(char *hex, char *bin, int len) {
    int i;
    for (i = 0; i < len; i++) {
        if (isxdigit(hex[i])) {
            if (isdigit(hex[i]))
                bin[i] = hex[i] - '0';
            else if (isalpha(hex[i]))
                bin[i] = (hex[i] & 0xdf) - 'A' + 0x10;
        } else
            return;

        if (i && (i % 4) == 0)
            bin[i++] = ' ';
    }
    bin[i] = '\0';
}

void bin2hex(char *bin, char *hex, int len) {
    int i, j;
    char *p = hex;

    for (i = len; i--; ) {
        j = (bin[i] >> 4) & 0xf;
        *p++ = j > 9 ? j + 'A' - 10 : j + '0';

        j = bin[i] & 0xf;
        *p++ = j > 9 ? j + 'A' - 10 : j + '0';
    }
    *p = '\0';
}

int main(int argc, char *argv[]) {
    char hex[33], bin[65], temp[3];
    int len;

    if (argc != 2) {
        printf("Usage: %s <hex>\n", argv[0]);
        return 1;
    }

    strcpy(hex, argv[1]);
    len = strlen(hex);

    if (len % 2 == 1) {
        printf("Error: hex string must have even length.\n");
        return 1;
    }

    hex2bin(hex, bin, len / 2);
    printf("Binary representation of %s:\n", hex);
    puts(bin);

    bin2hex(bin, hex, len / 2);
    printf("Hexadecimal representation of binary %s:\n", bin);
    puts(hex);

    strcpy(temp, hex);
    printf("Why stop there? Let's convert hex back to hex!\n");
    hex2bin(hex, bin, len / 2);
    bin2hex(bin, temp, len / 2);
    printf("Result: %s\n", temp);

    return 0;
}