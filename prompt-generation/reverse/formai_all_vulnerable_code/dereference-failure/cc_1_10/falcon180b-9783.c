//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *hex;
    char *bin;
} hex_table_t;

static hex_table_t hex_table[] = {
    {"0", "0000"},
    {"1", "0001"},
    {"2", "0010"},
    {"3", "0011"},
    {"4", "0100"},
    {"5", "0101"},
    {"6", "0110"},
    {"7", "0111"},
    {"8", "1000"},
    {"9", "1001"},
    {"A", "1010"},
    {"B", "1011"},
    {"C", "1100"},
    {"D", "1101"},
    {"E", "1110"},
    {"F", "1111"}
};

int get_hex_value(char c) {
    for (int i = 0; i < sizeof(hex_table) / sizeof(hex_table[0]); i++) {
        if (hex_table[i].hex[0] == c) {
            return i;
        }
    }
    return -1;
}

void convert_hex_to_bin(char *hex, char *bin) {
    int hex_len = strlen(hex);
    int bin_len = hex_len * 4;
    bin[bin_len - 1] = '\0';
    for (int i = 0; i < hex_len; i++) {
        int hex_val = get_hex_value(hex[i]);
        if (hex_val == -1) {
            printf("Invalid hexadecimal character: %c\n", hex[i]);
            exit(1);
        }
        strcat(bin, hex_table[hex_val].bin);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <hexadecimal_number> <output_file>\n", argv[0]);
        return 1;
    }
    FILE *out_file = fopen(argv[2], "w");
    if (out_file == NULL) {
        printf("Error opening output file: %s\n", argv[2]);
        return 1;
    }
    char hex[100];
    strcpy(hex, argv[1]);
    char bin[400];
    convert_hex_to_bin(hex, bin);
    fprintf(out_file, "Binary representation: %s\n", bin);
    fclose(out_file);
    return 0;
}