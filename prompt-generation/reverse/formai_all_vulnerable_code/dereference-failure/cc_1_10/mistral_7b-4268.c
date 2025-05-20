//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 32

void hex_string_to_bin(char *hex, unsigned char *bin, int length) {
    int i;
    unsigned char temp;
    for (i = 0; i < length; i++) {
        sscanf(hex + i * 2, "%2hhx", &temp);
        *bin++ = (temp << 4) | hex[i + 1];
        i++;
    }
}

void bin_to_hex(unsigned char *bin, char *hex, int length) {
    int i;
    char hex_digits[] = "0123456789ABCDEF";
    for (i = 0; i < length; i++) {
        hex[i * 2] = hex_digits[(bin[i] >> 4) & 0xF];
        hex[i * 2 + 1] = hex_digits[bin[i] & 0xF];
    }
    hex[length * 2] = '\0';
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <hex_string> <output_file>\n", argv[0]);
        return 1;
    }

    int len = strlen(argv[1]) / 2;
    unsigned char bin[SIZE];
    char hex[SIZE * 2 + 1];

    if (len > SIZE) {
        printf("Error: Hex string too long.\n");
        return 1;
    }

    hex_string_to_bin(argv[1], bin, len);

    FILE *fp = fopen(argv[2], "wb");
    if (!fp) {
        perror("Error opening output file.");
        return 1;
    }

    fwrite(bin, sizeof(unsigned char), len, fp);
    fclose(fp);

    bin_to_hex(bin, hex, len);
    printf("Converted hex string: %s\n", hex);

    return 0;
}

// Neon lights flicker in the dimly lit room
// The air is thick with the scent of burnt electronics and old tobacco
// Your cybernetic implants hum softly in the background
// You type in a command, the terminal comes alive with neon green text
// converter.exe <0xDEADBEEF> out.bin
// Data corrupted? Not on my watch.
// The binary data is saved to the output file
// The converted hex string is displayed for your confirmation
// Another day, another data corruption crisis averted.