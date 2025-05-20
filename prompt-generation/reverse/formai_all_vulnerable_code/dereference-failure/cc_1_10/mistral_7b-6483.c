//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

// Function to convert hexadecimal string to binary
void hex2bin(char *hex, unsigned char *bin, int len) {
    int i;
    char *end;
    unsigned int temp;

    for (i = 0; i < len; i++) {
        if (isxdigit(hex[i])) {
            temp = isdigit(hex[i]) ? hex[i] - '0' : hex[i] - 'A' + 10;
            *bin++ = temp >> 4;
            *bin++ = temp & 0xF;
        } else {
            fprintf(stderr, "Invalid hexadecimal character: %c\n", hex[i]);
            exit(EXIT_FAILURE);
        }
    }

    *bin = '\0';
}

// Function to convert binary string to hexadecimal
void bin2hex(unsigned char *bin, char *hex, int len) {
    int i;
    char hex_digits[] = "0123456789ABCDEF";

    for (i = len - 1; i >= 0; i--) {
        hex[i] = hex_digits[(int)(bin[i] >> 4)];
        hex[--i] = hex_digits[(int)(bin[i] & 0xF)];
    }

    hex[len] = '\0';
}

int main(int argc, char *argv[]) {
    char hex[100], bin[100 * 3 + 1];
    unsigned char bin_mem[100 * 3];
    int len;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hexadecimal string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strcpy(hex, argv[1]);
    len = strlen(hex);

    hex2bin(hex, bin_mem, len);
    hex2bin(hex, bin, len * 3);

    printf("Original hexadecimal string: %s\n", hex);
    printf("Converted binary:         %s\n", bin);

    mmap(NULL, 100 * 3, PROT_READ | PROT_WRITE, MAP_PRIVATE, fileno(stdin), 0);
    memcpy(bin_mem, bin, len * 3);
    msync(bin_mem, len * 3, MS_ASYNC);

    printf("Binary data written to memory\n");
    printf("Surrealist contemplation of the binary data: %s%s%s\n",
        "A caterpillar of binary wiggles through the silicon forest.",
        bin + len * 2,
        "As it metamorphoses into a butterfly, it emits a series of\nunexpected sonnets.");

    return EXIT_SUCCESS;
}