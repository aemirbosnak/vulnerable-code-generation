//FormAI DATASET v1.0 Category: Color Code Converter ; Style: grateful
// Welcome to the Color Code Converter program!
// Here, we will be converting Hexadecimal color codes to RGB color codes and vice versa. 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to convert hex to decimal
int hexToDec(char hex[]) {
    int len = strlen(hex);
    int base = 1;
    int dec = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec = dec + (hex[i] - 48) * base;
            base = base * 16;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec = dec + (hex[i] - 55) * base;
            base = base * 16;
        }
    }

    return dec;
}

// Function to convert decimal to hex
char* decToHex(int dec) {
    char hex[7];
    sprintf(hex, "%X", dec);
    return strdup(hex);
}

// Function to convert hexadecimal color code to RGB color code
char* hexToRgb(char hex[]) {
    char* rgb = (char*) malloc(13);
    int r = hexToDec(strncpy((char*) malloc(2), hex, 2));
    int g = hexToDec(strncpy((char*) malloc(2), hex + 2, 2));
    int b = hexToDec(strncpy((char*) malloc(2), hex + 4, 2));
    sprintf(rgb, "%d,%d,%d", r, g, b);
    return rgb;
}

// Function to convert RGB color code to hexadecimal color code
char* rgbToHex(int r, int g, int b) {
    char* hex = (char*) malloc(7);
    sprintf(hex, "%s%s%s", decToHex(r), decToHex(g), decToHex(b));
    return hex;
}

// Main function
int main() {
    char hex[7], rgb[13];
    int r, g, b;
    int choice;

    printf("Welcome to the Color Code Converter!\n");

    while(1) {
        printf("\nChoose an option:\n");
        printf("1. Convert hexadecimal color code to RGB color code\n");
        printf("2. Convert RGB color code to hexadecimal color code\n");
        printf("3. Exit program\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter a hexadecimal color code (without #): ");
                scanf("%s", hex);
                printf("RGB color code: %s\n", hexToRgb(hex));
                break;
            case 2:
                printf("\nEnter the RGB color code (in the format R,G,B): ");
                scanf("%d,%d,%d", &r, &g, &b);
                printf("Hexadecimal color code: #%s\n", rgbToHex(r, g, b));
                break;
            case 3:
                printf("\nThank you for using the Color Code Converter! Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid option selected. Please select again.\n");
        }
    }

    return 0;
}