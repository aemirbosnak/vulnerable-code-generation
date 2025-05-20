//FormAI DATASET v1.0 Category: Color Code Converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hexToInt(char hex[]) {  // converts hex to integer
    int len = strlen(hex);
    int base = 1;
    int result = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            result += (hex[i] - '0') * base;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            result += (hex[i] - 'a' + 10) * base;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            result += (hex[i] - 'A' + 10) * base;
        }
        base *= 16;
    }
    return result;
}

void intToHex(int value, char hex[]) {  // converts integer to hex
    sprintf(hex, "%02X", value);
}

int main() {
    char code[8];
    char command[10];
    printf("Enter hex code or RGB value (separated by spaces) to convert: ");
    fgets(command, 10, stdin);
    if (strcmp(command, "hex\n") == 0) {  // hex to RGB
        printf("Enter hex code: ");
        fgets(code, 8, stdin);
        int r = hexToInt(strncpy(code, code, 2));
        int g = hexToInt(strncpy(code + 2, code + 2, 2));
        int b = hexToInt(strncpy(code + 4, code + 4, 2));
        printf("RGB value: %d %d %d\n", r, g, b);
    } else if (strcmp(command, "RGB\n") == 0) {  // RGB to hex
        int r, g, b;
        printf("Enter RGB values (0-255) separated by spaces: ");
        scanf("%d %d %d", &r, &g, &b);
        char hex[8];
        intToHex(r, strncpy(hex, hex, 2));
        intToHex(g, strncpy(hex + 2, hex + 2, 2));
        intToHex(b, strncpy(hex + 4, hex + 4, 2));
        printf("Hex value: #%s\n", hex);
    } else {
        printf("Invalid command!\n");
    }
    return 0;
}