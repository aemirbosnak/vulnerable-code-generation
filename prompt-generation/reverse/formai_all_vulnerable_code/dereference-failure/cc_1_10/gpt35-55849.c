//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT 256

char *hexToBinary(char hex) {
    char *binary = malloc(sizeof(char) * 5);
    switch (toupper(hex)) {
        case '0':
            binary = "0000";
            break;
        case '1':
            binary = "0001";
            break;
        case '2':
            binary = "0010";
            break;
        case '3':
            binary = "0011";
            break;
        case '4':
            binary = "0100";
            break;
        case '5':
            binary = "0101";
            break;
        case '6':
            binary = "0110";
            break;
        case '7':
            binary = "0111";
            break;
        case '8':
            binary = "1000";
            break;
        case '9':
            binary = "1001";
            break;
        case 'A':
            binary = "1010";
            break;
        case 'B':
            binary = "1011";
            break;
        case 'C':
            binary = "1100";
            break;
        case 'D':
            binary = "1101";
            break;
        case 'E':
            binary = "1110";
            break;
        case 'F':
            binary = "1111";
            break;
        default:
            fprintf(stderr, "Error: something went wrong with the hex to binary conversion\n");
            exit(EXIT_FAILURE);
    }
    return binary;
}

int main() {
    char hex[MAX_INPUT];
    char *binary;
    printf("Welcome to my cryptic hex to binary converter!\n");
    printf("Enter a hexadecimal number: ");
    fgets(hex, MAX_INPUT, stdin);
    printf("Binary equivalent: 0b");
    for (int i = 0; i < strlen(hex) - 1; i++) {
        binary = hexToBinary(hex[i]);
        printf("%s", binary);
        free(binary);
    }
    printf("\n");
    return 0;
}