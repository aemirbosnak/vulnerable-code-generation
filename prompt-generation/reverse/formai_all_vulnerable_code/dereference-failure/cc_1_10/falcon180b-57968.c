//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 7

// Function to convert RGB color code to hexadecimal format
char* rgbToHex(int r, int g, int b) {
    char hex[MAX_CODE_LENGTH+1] = {0};
    sprintf(hex, "#%02x%02x%02x", r, g, b);
    return strdup(hex);
}

// Function to convert hexadecimal color code to RGB format
void hexToRgb(char* hex, int* r, int* g, int* b) {
    if (strlen(hex)!= MAX_CODE_LENGTH) {
        *r = *g = *b = 0;
        return;
    }
    *r = hex[1] * 16 + hex[2];
    *g = hex[3] * 16 + hex[4];
    *b = hex[5] * 16 + hex[6];
}

// Recursive function to convert color code
void colorCodeConverter(char* code, char** hex, char** rgb) {
    int i = 0;
    while (code[i]!= '\0') {
        if (code[i] == ',') {
            code[i] = '\0';
            *hex = rgbToHex(atoi(code), atoi(code+1), atoi(code+2));
            *rgb = strdup(code);
            return;
        }
        i++;
    }
    *hex = strdup(code);
    *rgb = NULL;
}

int main() {
    char input[100];
    printf("Enter a color code: ");
    scanf("%s", input);
    char* hex;
    char* rgb;
    colorCodeConverter(input, &hex, &rgb);
    if (rgb!= NULL) {
        printf("RGB Color Code: %s\n", rgb);
    } else {
        printf("Hexadecimal Color Code: %s\n", hex);
    }
    return 0;
}