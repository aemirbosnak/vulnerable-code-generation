//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define HEX_LENGTH 2

void die(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

void hex_str_to_bin(char *hex_str, unsigned char *bin_arr, int *len) {
    int i = 0, j = 0, hex_val;
    char *hex_end;

    *len = 0;
    memset(bin_arr, 0, 256);

    while (hex_str[i] != '\0') {
        if (sscanf(&hex_str[i], "%2hhx", &hex_val) != 1) {
            die("Invalid hex string\n");
        }

        for (j = 0; j < HEX_LENGTH; j++) {
            bin_arr[*len] = (hex_val >> (4 * j)) & 0x0F;
            bin_arr[*len] <<= (8 * (3 - j));
            (*len)++;
        }

        i += HEX_LENGTH;
    }
}

void bin_to_hex(unsigned char *bin_arr, int len, char *hex_str) {
    int i = 0;
    char hex[3];

    memset(hex_str, 0, BUFFER_SIZE);

    while (i < len) {
        sprintf(hex, "%02x", bin_arr[i]);
        strcat(hex_str, hex);
        i++;
    }
}

int main(int argc, char **argv) {
    char hex_str[BUFFER_SIZE];
    unsigned char bin_arr[256];
    int len;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hex string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strcpy(hex_str, argv[1]);

    hex_str_to_bin(hex_str, bin_arr, &len);
    bin_to_hex(bin_arr, len, hex_str);

    printf("Original hex string: %s\n", argv[1]);
    printf("Binary representation: ");
    for (int i = 0; i < len; i++) {
        printf("%u", bin_arr[i]);
    }
    printf("\n");
    printf("Converted hex string: %s\n", hex_str);

    return EXIT_SUCCESS;
}