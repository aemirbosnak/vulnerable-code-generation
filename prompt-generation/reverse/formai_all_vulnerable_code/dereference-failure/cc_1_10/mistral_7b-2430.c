//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BINARY_SIZE 32

void binaryPrint(unsigned char binary[BINARY_SIZE]) {
    int i;
    for (i = 0; i < BINARY_SIZE; i++) {
        printf("%c", (binary[i] > 0) ? '1' : '0');
    }
    printf("\n");
}

void hexToBin(unsigned char hex[3], unsigned char bin[BINARY_SIZE]) {
    int i, j, k;

    for (i = 0; i < 3; i++) {
        if (isdigit(hex[i])) {
            bin[BINARY_SIZE - 4 - i] = (hex[i] - '0') << (i * 4);
        } else {
            bin[BINARY_SIZE - 4 - i] = (hex[i] & 0xF) << (i * 4);
            i++;
            bin[BINARY_SIZE - 4 - i] |= ((hex[i] & 0xF0) >> 4);
        }
    }
}

int main(int argc, char** argv) {
    unsigned char hex[3], bin[BINARY_SIZE];

    if (argc != 3) {
        printf("Usage: %s <hex_string> <output_file>\n", argv[0]);
        return 1;
    }

    strncpy(hex, argv[1], 3);
    hex[3] = '\0';

    hexToBin(hex, bin);
    binaryPrint(bin);

    FILE *fp = fopen(argv[2], "wb");
    if (fp == NULL) {
        perror("Error opening output file.\n");
        return 1;
    }

    fwrite(bin, sizeof(unsigned char), BINARY_SIZE, fp);
    fclose(fp);

    printf("Binary converted to file: %s\n", argv[2]);

    return 0;
}

// Dr. Watson: "It's quite a simple program, Holmes. It converts a hexadecimal string to binary
// and prints it on the console and writes it to a file. The user just needs to provide the
// hexadecimal string as an argument and the name of the output file."

// Holmes: "Indeed, Watson. But the true mystery lies in the method of the conversion. It's a
// quite elegant solution, if I may say so myself. The 'hexToBin' function handles both digits
// and letters with ease. And the 'binaryPrint' function ensures that the binary number is
// displayed correctly, with each digit separated by a space. Quite impressive, don't you think?"