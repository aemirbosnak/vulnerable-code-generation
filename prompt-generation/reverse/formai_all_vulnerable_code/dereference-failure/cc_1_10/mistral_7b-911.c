//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

void hex_to_bin(char hex[], char bin[]) {
    int i;
    int hex_val;

    for(i = 0; i < strlen(hex) / 2; i++) {
        sscanf(&hex[2 * i], "%2x", &hex_val);

        for(int j = 0; j < 4; j++) {
            bin[3 - j - i] = hex_val & 0x01 ? '1' : '0';
            hex_val >>= 1;
        }
    }

    bin[strlen(hex)] = '\0';
}

void print_binary(char bin[]) {
    int i;

    printf("The binary representation of the hexadecimal number is: ");
    for(i = strlen(bin) - 1; i >= 0; i--) {
        printf("%c", bin[i]);
    }
    printf("\n");
}

void print_hex(char hex[]) {
    printf("The hexadecimal number is: %s\n", hex);
}

int main(int argc, char *argv[]) {
    char input_hex[BUFFER_SIZE];
    char output_bin[BUFFER_SIZE];

    if(argc != 2) {
        printf("Usage: %s <hexadecimal number>\n", argv[0]);
        return 1;
    }

    strcpy(input_hex, argv[1]);

    for(int i = 0; i < strlen(input_hex); i++) {
        if(isdigit(input_hex[i])) {
            input_hex[i] += 'A' - '0' - ((input_hex[i] - '0') >> 3);
        } else if(isalpha(input_hex[i])) {
            input_hex[i] += 32;
        }
    }

    hex_to_bin(input_hex, output_bin);
    print_hex(input_hex);
    print_binary(output_bin);

    return 0;
}