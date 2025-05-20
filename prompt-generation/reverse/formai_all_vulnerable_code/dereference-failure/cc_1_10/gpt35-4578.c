//FormAI DATASET v1.0 Category: Color Code Converter ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to convert hexadecimal string to integer
int hexToInt(char* hex) {
    int result = 0;

    // Loop through each character in the hexadecimal string
    for (int i = 0; i < strlen(hex); i++) {
        // Convert the character to its integer value
        char currentChar = *(hex + i);
        int currentValue = 0;
        if (currentChar >= '0' && currentChar <= '9') {
            currentValue = currentChar - '0';
        } else if (currentChar >= 'a' && currentChar <= 'f') {
            currentValue = currentChar - 'a' + 10;
        } else if (currentChar >= 'A' && currentChar <= 'F') {
            currentValue = currentChar - 'A' + 10;
        }

        // Shift the result to the left by 4 bits
        result = result << 4;

        // Add the current value to the result
        result = result + currentValue;
    }

    return result;
}

// Function to convert integer to binary string
char* intToBinary(int n) {
    char* binary = malloc(sizeof(char) * 33);
    int index = 0;

    // Loop through each bit in the integer and add a 0 or 1 to the string
    for (int i = 31; i >= 0; i--) {
        int bit = (n >> i) & 1;
        *(binary + index) = bit + '0';
        index++;
    }

    *(binary + 32) = '\0';

    return binary;
}

// Function to convert RGB values to hexadecimal
char* rgbToHex(int r, int g, int b) {
    char* hex = malloc(sizeof(char) * 7);

    // Convert each RGB value to its hexadecimal string form
    char* hexR = malloc(sizeof(char) * 3);
    char* hexG = malloc(sizeof(char) * 3);
    char* hexB = malloc(sizeof(char) * 3);
    sprintf(hexR, "%02x", r);
    sprintf(hexG, "%02x", g);
    sprintf(hexB, "%02x", b);

    // Combine the RGB values into a single string
    strcpy(hex, "#");
    strcat(hex, hexR);
    strcat(hex, hexG);
    strcat(hex, hexB);

    free(hexR);
    free(hexG);
    free(hexB);

    return hex;
}

// Function to convert hexadecimal color code to RGB values
void hexToRgb(char* hex, int* r, int* g, int* b) {
    // Remove the # symbol from the beginning of the hexadecimal string
    char* hexValue = hex + 1;

    // Extract the red, green, and blue values from the hex string
    char hexR[3];
    char hexG[3];
    char hexB[3];
    memcpy(hexR, hexValue, 2);
    hexR[2] = '\0';
    memcpy(hexG, hexValue + 2, 2);
    hexG[2] = '\0';
    memcpy(hexB, hexValue + 4, 2);
    hexB[2] = '\0';

    // Convert the hexadecimal values to integers
    int intR = hexToInt(hexR);
    int intG = hexToInt(hexG);
    int intB = hexToInt(hexB);

    // Store the RGB values in the provided output variables
    *r = intR;
    *g = intG;
    *b = intB;
}

int main() {
    // Convert RGB values to hexadecimal
    char* hexCode = rgbToHex(255, 0, 0);
    printf("Red: %s\n", hexCode);

    // Convert hexadecimal color code to RGB values
    int r, g, b;
    hexToRgb("#00ff00", &r, &g, &b);
    printf("Green: %d, %d, %d\n", r, g, b);

    // Convert integer to binary string
    char* binary = intToBinary(42);
    printf("42 in binary: %s\n", binary);

    free(hexCode);
    free(binary);

    return 0;
}