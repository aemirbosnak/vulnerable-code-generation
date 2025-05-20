//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 50

void hextobin(char hex[], int *bin, int len) {
    int i, j, value;

    for (i = 0, j = 0; i < len; i++, j += 4) {
        value = hex[i] < 'A' ? (hex[i] & 0xF) : (toupper(hex[i]) - 'A' + 0x0F);
        *bin++ = value << 4;
        if (i < len - 1) {
            value = hex[i + 1] < 'A' ? (hex[i + 1] & 0xF) : (toupper(hex[i + 1]) - 'A' + 0x0F);
            *bin++ = value;
            i++;
        }
    }
}

void bintohex(int bin[], char hex[], int len) {
    int i, j, value;

    for (i = len - 1; i >= 0; i--) {
        value = (bin[i] >> 4) & 0xF;
        hex[j++] = value > 9 ? value + 0x37 : value + '0';

        value = bin[i] & 0xF;
        hex[j++] = value > 9 ? value + 0x37 : value + '0';
    }

    hex[j] = '\0';
}

int main(void) {
    char hex[MAX], bin[MAX * 4 + 1];
    int i, len, bin_len;

    printf("Enter hexadecimal number: ");
    fgets(hex, MAX, stdin);

    len = strlen(hex);
    hex[len < MAX ? len : MAX - 1] = '\0'; // trim newline character

    hextobin(hex, bin, len / 2 + len % 2);
    bin_len = (len / 2 + len % 2) * 4;

    printf("Enter binary number: ");
    fgets(bin, MAX * 4, stdin);

    bin[bin_len < MAX * 4 ? bin_len : MAX * 4 - 1] = '\0'; // trim newline character

    if (len != (bin_len / 4)) {
        printf("Error: Incorrect hexadecimal or binary number!\n");
        return 1;
    }

    for (i = 0; i < len; i += 2) {
        if (bin[i / 2 * 4 + i / 2] != (hex[i] < 'A' ? hex[i] - '0' : hex[i] - 'A' + 0x0A)) {
            printf("Error: Incorrect hexadecimal or binary number!\n");
            return 1;
        }
    }

    bintohex(bin, hex, bin_len / 4);
    printf("Hexadecimal equivalent: %s\n", hex);

    return 0;
}