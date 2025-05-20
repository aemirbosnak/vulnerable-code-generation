//FormAI DATASET v1.0 Category: Color Code Converter ; Style: portable
// A unique C Color Code Converter Example Program
// This program converts RGB color code to HEX and vice versa
// It is written in a portable style for easy integration into other projects

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
char* rgb_to_hex(int red, int green, int blue);
void hex_to_rgb(char* hex_code, int* red, int* green, int* blue);

// Main function
int main() {
    int red, green, blue;
    char hex_code[7];

    // RGB to HEX conversion
    printf("Enter the RGB color code (separated by spaces): ");
    scanf("%d %d %d", &red, &green, &blue);
    printf("The HEX color code is: %s\n", rgb_to_hex(red, green, blue));

    // HEX to RGB conversion
    printf("Enter the HEX color code (without the # symbol): ");
    scanf("%s", hex_code);
    hex_to_rgb(hex_code, &red, &green, &blue);
    printf("The RGB color code is: %d %d %d\n", red, green, blue);

    return 0;
}

// Function to convert RGB to HEX
char* rgb_to_hex(int red, int green, int blue) {
    char* hex_code = (char*) malloc(7 * sizeof(char));
    sprintf(hex_code, "#%02X%02X%02X", red, green, blue);
    return hex_code;
}

// Function to convert HEX to RGB
void hex_to_rgb(char* hex_code, int* red, int* green, int* blue) {
    char hex_values[3];
    hex_values[2] = '\0';
    
    // Extract Red value
    hex_values[0] = hex_code[0];
    hex_values[1] = hex_code[1];
    *red = strtol(hex_values, NULL, 16);
    
    // Extract Green value
    hex_values[0] = hex_code[2];
    hex_values[1] = hex_code[3];
    *green = strtol(hex_values, NULL, 16);
    
    // Extract Blue value
    hex_values[0] = hex_code[4];
    hex_values[1] = hex_code[5];
    *blue = strtol(hex_values, NULL, 16);
}