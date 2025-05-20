//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal string to an integer
int hexToInt(char *hex) {
    int value = 0;
    int len = strlen(hex);
    for (int i = 0; i < len; i++) {
        char c = hex[i];
        if (c >= '0' && c <= '9') {
            value = value * 16 + (c - '0');
        } else if (c >= 'A' && c <= 'F') {
            value = value * 16 + (c - 'A' + 10);
        } else if (c >= 'a' && c <= 'f') {
            value = value * 16 + (c - 'a' + 10);
        } else {
            printf("Invalid hexadecimal character: %c\n", c);
            exit(1);
        }
    }
    return value;
}

// Function to convert an integer to a hexadecimal string
char *intToHex(int value) {
    char *hex = malloc(8 * sizeof(char));
    sprintf(hex, "%X", value);
    return hex;
}

// Function to convert a hexadecimal string to a color code
char *hexToColorCode(char *hex) {
    char *colorCode = malloc(8 * sizeof(char));
    sprintf(colorCode, "#%s", hex);
    return colorCode;
}

int main() {
    char *hex;
    printf("Enter a hexadecimal color code: ");
    scanf("%s", hex);

    // Convert the hexadecimal string to an integer
    int value = hexToInt(hex);

    // Convert the integer to a color code string
    char *colorCode = hexToColorCode(intToHex(value));

    // Print the color code string
    printf("The color code is: %s\n", colorCode);

    return 0;
}