//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to hexadecimal
char* decimalToHex(int n) {
    char* hex = (char*)malloc(sizeof(char)*100);
    int i = 0;
 
    while(n != 0) {
        int temp = 0;
        temp = n % 16;
        
        // Need to convert to corresponding character if it's above 9
        if(temp < 10) {
            hex[i] = temp + 48;
            i++;
        } else {
            hex[i] = temp + 55;
            i++;
        }
        n = n / 16;
    }
 
    // Adding null character at the end of hex string
    hex[i] = '\0';
 
    // Reversing the hex string
    char* reversedHex = (char*)malloc(sizeof(char)*100);
    int j = 0;

    for(int l = (int)strlen(hex) - 1; l >= 0; l--) {
        reversedHex[j] = hex[l];
        j++;
    }

    reversedHex[j] = '\0';

    free(hex); // Freeing up memory occupied by hex

    return reversedHex;
}

// Function to convert hexadecimal to decimal
int hexToDecimal(char hex[]) {
    int length = strlen(hex);
    int decimal = 0;
    int base = 1;
 
    for (int i = length - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - 48) * base;
            base = base * 16;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 55) * base;
            base = base * 16;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 87) * base;
            base = base * 16;
        }
    }
    return decimal;
}

int main() {
    int num;
    char hex[100];

    printf("Enter a decimal number: ");
    scanf("%d", &num);
    printf("Hexadecimal equivalent of %d is %s\n", num, decimalToHex(num));

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    printf("Decimal equivalent of %s is %d\n", hex, hexToDecimal(hex));

    return 0;
}