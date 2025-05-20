//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100
#define BIN_SIZE 8

void bin_to_dec(char *bin, int *dec) {
    *dec = 0;
    int pos = 1;
    for (int i = 0; bin[i] != '\0'; i++) {
        if (bin[i] == '1')
            *dec += pow(2, pos);
        pos++;
        if (pos >= BIN_SIZE) {
            pos = 1;
        }
    }
}

void dec_to_bin(int dec, char *bin) {
    int rem;

    for (int i = BIN_SIZE; i > 0; i--) {
        rem = dec % 2;
        dec /= 2;
        bin[BIN_SIZE - i] = rem + '0';
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <decimal number> <output binary file>\n", argv[0]);
        return 1;
    }

    int dec_num = atoi(argv[1]);
    char bin_file[MAX_SIZE] = {0};
    strcpy(bin_file, argv[2]);

    char bin[BIN_SIZE + 1] = {0};

    int dec;
    bin_to_dec(argv[1], &dec);

    dec_to_bin(dec, bin);

    FILE *fp = fopen(bin_file, "w");
    if (fp == NULL) {
        printf("Error opening output file: %s\n", bin_file);
        return 1;
    }

    fwrite(bin, sizeof(char), BIN_SIZE + 1, fp);
    fclose(fp);

    printf("Binary equivalent of decimal number %d saved to %s\n", dec_num, bin_file);

    return 0;
}