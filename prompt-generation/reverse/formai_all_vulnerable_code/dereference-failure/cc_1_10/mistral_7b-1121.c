//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 50

void print_hex(unsigned char hex) {
    if (hex > 9)
        printf("%c", hex + 55 - 10);
    else
        printf("%d", hex);
}

void decode_hex(char *input, unsigned char *output, int *length) {
    int i = 0, j = 0;
    unsigned char current_char;

    while (input[i] != '\0') {
        if (i % 2 == 0) {
            sscanf(&input[i], "%2hhx", &current_char);
            output[j++] = current_char;
        }
        i++;
    }

    *length = j;
}

void encode_hex(unsigned char *input, int length, char *output) {
    int i = 0;

    for (; i < length; i++) {
        print_hex(input[i] >> 4);
        print_hex(input[i] & 0xF);
        if (i < length - 1)
            output[i * 2 + 1] = ' ';
    }
}

int main(int argc, char *argv[]) {
    unsigned char hex_input[MAX_LENGTH];
    int length;
    char hex_output[MAX_LENGTH * 2 + 1] = {0};

    if (argc != 3) {
        printf("Usage: %s <hex_string> <output_file>\n", argv[0]);
        return 1;
    }

    strncpy(hex_input, argv[1], MAX_LENGTH);

    decode_hex(hex_input, hex_input, &length);

    encode_hex(hex_input, length, hex_output);

    FILE *output_file = fopen(argv[2], "wb");

    if (output_file == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    fwrite(hex_output, strlen(hex_output), 1, output_file);
    fclose(output_file);

    printf("Hexadecimal string '%s' decoded and encoded to '%s'.\n", argv[1], hex_output);

    return 0;
}