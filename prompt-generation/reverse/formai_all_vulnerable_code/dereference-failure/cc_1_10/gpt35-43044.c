//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to hexadecimal
char* toHexadecimal(int decimal) {
    char* hexadecimal = (char*)malloc(sizeof(char)*10);
    int i = 0, temp;
    while(decimal != 0) {
        temp = decimal % 16;
        // Convert integer to corresponding hexadecimal character
        if(temp < 10) {
            hexadecimal[i++] = temp + 48; 
        }
        else {
            hexadecimal[i++] = temp + 55; 
        }
        decimal /= 16;
    }
    hexadecimal[i] = '\0';
    // Reverse the hexadecimal string
    int j, len = strlen(hexadecimal);
    char swap;
    for(i=0, j=len-1 ; i<j ; i++, j--) {
        swap = hexadecimal[i];
        hexadecimal[i] = hexadecimal[j];
        hexadecimal[j] = swap;
    }
    return hexadecimal;
}

// Function to convert hexadecimal to decimal
int toDecimal(char* hexadecimal) {
    int decimal = 0;
    int i, len = strlen(hexadecimal);
    // Convert hexadecimal string to corresponding integer
    for(i=0 ; i<len ; i++) {
        if(hexadecimal[i]>='0' && hexadecimal[i]<='9') {
            decimal = decimal*16 + (hexadecimal[i] - 48);
        }
        else if(hexadecimal[i]>='A' && hexadecimal[i]<='F') {
            decimal = decimal*16 + (hexadecimal[i] - 55);
        }
    }
    return decimal;
}

int main() {
    int decimal;
    char* hexadecimal;

    // Decimal to hexadecimal conversion
    printf("Enter a positive integer: ");
    scanf("%d", &decimal);
    hexadecimal = toHexadecimal(decimal);
    printf("Hexadecimal equivalent: %s\n\n", hexadecimal);
    free(hexadecimal);

    // Hexadecimal to decimal conversion
    char input[10];
    printf("Enter a hexadecimal number: ");
    scanf("%s", input);
    decimal = toDecimal(input);
    printf("Decimal equivalent: %d\n\n", decimal);

    return 0;
}