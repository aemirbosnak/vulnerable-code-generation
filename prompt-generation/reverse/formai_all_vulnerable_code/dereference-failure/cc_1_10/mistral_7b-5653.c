//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

void binary_string(unsigned char binary[]) {
    int i;
    for (i = 7; i >= 0; i--) {
        printf("%d", binary[i] & 1);
    }
    printf("\n");
}

void hex_string(unsigned char hex[]) {
    int i;
    static char hex_digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    for (i = 0; i < 2; i++) {
        int num = hex[i] >> 4;
        printf("%c", num < 10 ? hex_digits[num] : hex_digits[num + 0x6]);
        num = hex[i] & 0xF;
        printf("%c", hex_digits[num]);
    }
    printf("\n");
}

int main() {
    char input[MAX_LEN];
    unsigned char binary[3];
    unsigned char hex[3];

    printf("Enter a hexadecimal number: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    sscanf(input, "%2hhx", hex);

    for (int i = 0; i < 2; i++) {
        binary[i] = hex[i];
        for (int j = 0; j < 8; j++) {
            binary[i] <<= 1;
            if (hex[i] & (1 << (7 - j))) {
                binary[i]++;
            }
        }
    }

    printf("Hexadecimal: %02X%02X\n", hex[0], hex[1]);
    printf("Binary:     ");
    binary_string(binary);
    printf("Hexadecimal: ");
    hex_string(binary);

    return 0;
}