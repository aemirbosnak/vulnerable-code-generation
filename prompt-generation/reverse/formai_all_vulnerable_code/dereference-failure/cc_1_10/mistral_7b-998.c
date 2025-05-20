//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BITS_PER_BYTE 8
#define BYTES_PER_LINE 16
#define LINES_PER_GROUP 5

char *binary_table = ".- -- ... --- -. .- .. --. .... .-- ...- .... .--. .--- ..- -.-- .--. .-.. .--- .--. .--. --- ..- -.-. .--. .--.";

void convert_binary_to_morse(char binary[]) {
    int i, j, index;
    char morse[BITS_PER_BYTE + 1];

    for (i = 0; i < strlen(binary); i += BITS_PER_BYTE) {
        memset(morse, ' ', BITS_PER_BYTE + 1);
        for (j = i; j < i + BITS_PER_BYTE; j++) {
            index = binary[j] - '0';
            morse[j - i] = binary_table[index];
        }
        printf("%s ", morse);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int i, j, k, binary_len;
    char binary[BYTES_PER_LINE * LINES_PER_GROUP + 1];

    if (argc != 2) {
        printf("Usage: %s <binary_data>\n", argv[0]);
        return 1;
    }

    strcpy(binary, argv[1]);

    for (i = 0; i < strlen(binary) && binary[i] != '\n'; i++);
    binary_len = i;

    for (j = 0; j < LINES_PER_GROUP; j++) {
        for (k = 0; k < BYTES_PER_LINE; k++) {
            if (binary_len - BYTES_PER_LINE * j - k >= 0) {
                convert_binary_to_morse(&binary[BYTES_PER_LINE * j + k]);
            }
        }
        printf("\n");
    }

    return 0;
}