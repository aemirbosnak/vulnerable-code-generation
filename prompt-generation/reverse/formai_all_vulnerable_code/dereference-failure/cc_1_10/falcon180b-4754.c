//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_NUM_LENGTH 32
#define BIN_NUM_LENGTH 8
#define HEX_NUM_LENGTH 2

typedef struct {
    char binary[MAX_NUM_LENGTH];
    char hex[HEX_NUM_LENGTH];
} Number;

void convert_binary_to_hex(char *binary, char *hex) {
    int i = 0;
    int j = 0;
    while (binary[i]) {
        if (isdigit(binary[i])) {
            hex[j] = binary[i] - '0';
            j++;
        } else if (binary[i] == 'A') {
            hex[j] = 10;
            j++;
        } else if (binary[i] == 'B') {
            hex[j] = 11;
            j++;
        } else {
            printf("Invalid binary number: %s\n", binary);
            exit(1);
        }
        i++;
    }
    hex[j] = '\0';
}

void convert_hex_to_binary(char *hex, char *binary) {
    int i = 0;
    int j = 0;
    while (hex[i]) {
        if (isdigit(hex[i])) {
            binary[j] = hex[i] + '0';
            j++;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            binary[j] = hex[i] - 'A' + 10;
            j++;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            binary[j] = hex[i] - 'a' + 10;
            j++;
        } else {
            printf("Invalid hexadecimal number: %s\n", hex);
            exit(1);
        }
        i++;
    }
    binary[j] = '\0';
}

int main() {
    char line[MAX_LINE_LENGTH];
    char binary_number[MAX_NUM_LENGTH];
    char hexadecimal_number[MAX_NUM_LENGTH];
    Number num;

    printf("Enter a binary number: ");
    fgets(line, MAX_LINE_LENGTH, stdin);
    strcpy(binary_number, line);

    printf("Enter a hexadecimal number: ");
    fgets(line, MAX_LINE_LENGTH, stdin);
    strcpy(hexadecimal_number, line);

    convert_binary_to_hex(binary_number, num.hex);
    convert_hex_to_binary(hexadecimal_number, num.binary);

    printf("Binary number: %s\n", num.binary);
    printf("Hexadecimal number: %s\n", num.hex);

    return 0;
}