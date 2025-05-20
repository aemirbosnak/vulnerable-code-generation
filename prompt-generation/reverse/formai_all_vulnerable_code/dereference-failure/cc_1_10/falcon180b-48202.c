//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 7

// Function to convert hex color code to RGB values
void hexToRgb(char *hex, int *r, int *g, int *b) {
    if (strlen(hex)!= 7) {
        printf("Error: Invalid hex color code.\n");
        exit(1);
    }

    *r = strtol(hex, NULL, 16);
    *g = strtol(&hex[3], NULL, 16);
    *b = strtol(&hex[5], NULL, 16);
}

// Function to convert RGB values to hex color code
void rgbToHex(int r, int g, int b, char *hex) {
    sprintf(hex, "#%02X%02X%02X", r, g, b);
}

// Function to print usage instructions
void printUsage() {
    printf("Usage:./color_converter [OPTION]\n");
    printf("Options:\n");
    printf("-h [HEX_COLOR] : Convert hex color code to RGB values\n");
    printf("-r [R] [G] [B] : Convert RGB values to hex color code\n");
    printf("-q : Quit\n");
}

// Main function
int main() {
    char input[MAX_COLORS];
    char *hex;
    int r, g, b;

    while (1) {
        printf("Enter your choice: ");
        fgets(input, MAX_COLORS, stdin);
        sscanf(input, "%s", hex);

        switch (*hex) {
        case 'h':
            hexToRgb(hex + 1, &r, &g, &b);
            printf("RGB values: %d %d %d\n", r, g, b);
            break;
        case 'r':
            sscanf(input, "%s %d %d %d", hex, &r, &g, &b);
            rgbToHex(r, g, b, hex);
            printf("Hex color code: %s\n", hex);
            break;
        case 'q':
            printf("Exiting...\n");
            return 0;
        default:
            printUsage();
        }
    }

    return 0;
}