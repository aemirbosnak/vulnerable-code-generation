//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert hexadecimal number to decimal number
int hexToDec(char hex[]) {
    int length = strlen(hex);
    int decimal = 0;
    int base = 1;
    int i;
    for(i = length - 1; i >= 0; i--) {
        if(hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - 48) * base;
            base *= 16;
        }
        else if(hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 87) * base;
            base *= 16;
        }
        else if(hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 55) * base;
            base *= 16;
        }
        else {
            printf("Invalid hexadecimal input!\n");
            exit(0);
        }
    }
    return decimal;
}

// Function to convert decimal number to hexadecimal number
char* decToHex(int decimal) {
    int remainder;
    char *hex = (char*)malloc(sizeof(char));
    int i = 1;
    while(decimal != 0) {
        remainder = decimal % 16;
        if(remainder < 10) {
            hex[i++] = remainder + 48;
        }
        else {
            hex[i++] = remainder + 55;
        }
        decimal /= 16;
    }
    hex[0] = '0';
    hex[i] = '\0';
    // Reverse the hexadecimal number
    int j, k;
    for(j = 0, k = strlen(hex) - 1; j < k; j++, k--) {
        char temp = hex[j];
        hex[j] = hex[k];
        hex[k] = temp;
    }
    return hex;
}

int main() {
    printf("\t*** Hexadecimal Converter ***\n\n");
    while(1) { // Run the program in a continuous loop
        printf("\tEnter '1' to convert hexadecimal to decimal.\n");
        printf("\tEnter '2' to convert decimal to hexadecimal.\n");
        printf("\tEnter '3' to exit the program.\n\n");
        int option;
        printf("\tEnter your option: ");
        scanf("%d", &option);
        printf("\n");
        switch(option) {
            case 1:
                printf("\tEnter a hexadecimal number: ");
                char hex[100];
                scanf("%s", hex);
                int decimal = hexToDec(hex);
                printf("\tThe decimal equivalent of %s is %d.\n\n", hex, decimal);
                break;
            case 2:
                printf("\tEnter a decimal number: ");
                int decimalInput;
                scanf("%d", &decimalInput);
                char *hexOutput = decToHex(decimalInput);
                printf("\tThe hexadecimal equivalent of %d is %s.\n\n", decimalInput, hexOutput);
                free(hexOutput);
                break;
            case 3:
                printf("\tExiting program...\n");
                exit(0);
            default:
                printf("\tInvalid option. Try again. \n\n");
        }
    }
    return 0;
}