//FormAI DATASET v1.0 Category: Color Code Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convertToHex(int num) {
    char* hexVal;
    if(num == 0) {
        hexVal = (char*) malloc(sizeof(char)*2);
        hexVal[0] = '0';
        hexVal[1] = '\0';
        return hexVal;
    }
    int rem = num%16;
    if(rem < 10) {
        hexVal = convertToHex(num/16);
        int len = strlen(hexVal);
        hexVal[len] = rem + 48;
        hexVal[len+1] = '\0';
    } else {
        hexVal = convertToHex(num/16);
        int len = strlen(hexVal);
        hexVal[len] = rem + 55;
        hexVal[len+1] = '\0';
    }
    return hexVal;
}

int main() {
    int red, green, blue;
    char* hexRed;
    char* hexGreen;
    char* hexBlue;

    printf("Enter RGB values (0-255): \n");
    printf("Red: ");
    scanf("%d", &red);
    printf("Green: ");
    scanf("%d", &green);
    printf("Blue: ");
    scanf("%d", &blue);

    hexRed = convertToHex(red);
    hexGreen = convertToHex(green);
    hexBlue = convertToHex(blue);

    printf("Hex Color Code: #%s%s%s\n", hexRed, hexGreen, hexBlue);

    free(hexRed);
    free(hexGreen);
    free(hexBlue);

    return 0;
}