//FormAI DATASET v1.0 Category: Color Code Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hexToDecimal(char hex[]);
char* decimalToBinary(int decimal);
void printRGB(int red, int green, int blue);

int main() {
    char hex[7];
    printf("Enter a hex color code (ex: #FFA500): ");
    scanf("%s", hex);

    int red = hexToDecimal(strncpy(malloc(3), hex + 1, 2));
    int green = hexToDecimal(strncpy(malloc(3), hex + 3, 2));
    int blue = hexToDecimal(strncpy(malloc(3), hex + 5, 2));

    printf("RGB values: %d, %d, %d\n", red, green, blue);

    printf("Binary values: %s, %s, %s\n",
           decimalToBinary(red), decimalToBinary(green), decimalToBinary(blue));

    printRGB(red, green, blue);

    return 0;
}

int hexToDecimal(char hex[]) {
    int decimal = 0, base = 1, i;
    for (i = strlen(hex) - 1; i >= 0; i--, base *= 16) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += base * (int)(hex[i] - '0');
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += base * (int)(hex[i] - 'A' + 10);
        }
    }
    return decimal;
}

char* decimalToBinary(int decimal) {
    char* binary = malloc(9);
    int i;
    for (i = 0; i < 8; i++) {
        binary[7 - i] = (decimal % 2) + '0';
        decimal /= 2;
    }
    binary[8] = '\0';
    return binary;
}

void printRGB(int red, int green, int blue) {
    printf("RGB color code: \033[38;2;%d;%d;%dm%s\033[0m\n", red, green, blue,
           "Test Text"); // add in text to show the color
}