//FormAI DATASET v1.0 Category: Color Code Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Conversion function from hex to decimal
int hex_to_dec(char hex_val) {
    if(hex_val >= '0' && hex_val <= '9') {
        return hex_val - '0';
    } else if(hex_val >= 'A' && hex_val <= 'F') {
        return hex_val - 'A' + 10;
    } else if(hex_val >= 'a' && hex_val <= 'f') {
        return hex_val - 'a' + 10;
    }
    return -1;
}

// Conversion function from decimal to hex
char dec_to_hex(int dec_val) {
    if(dec_val >= 0 && dec_val <= 9) {
        return dec_val + '0';
    } else if(dec_val >= 10 && dec_val <= 15) {
        return dec_val - 10 + 'A';
    }
    return '-';
}

// Conversion function from RGB to hex
char* rgb_to_hex(int red, int green, int blue) {
    char* hex_code = (char*) malloc(7);
    sprintf(hex_code, "#%02X%02X%02X", red, green, blue);
    return hex_code;
}

// Conversion function from hex to RGB
int* hex_to_rgb(char* hex_code) {
    int* rgb = (int*) malloc(3 * sizeof(int));
    int hex_val;
    for(int i = 1; i < 7; i++) {
        hex_val = hex_to_dec(hex_code[i]);
        if(i % 2 == 1) {
            rgb[(i-1)/2] = 16 * hex_val;
        } else {
            rgb[(i-1)/2] += hex_val;
        }
    }
    return rgb;
}

// Main function
int main() {
    // Input RGB color values
    int red, green, blue;
    printf("Enter the RGB color values (0 to 255)\n");
    printf("Red: ");
    scanf("%d", &red);
    printf("Green: ");
    scanf("%d", &green);
    printf("Blue: ");
    scanf("%d", &blue);

    // RGB to Hex conversion
    char* hex_code = rgb_to_hex(red, green, blue);
    printf("The hex code for RGB (%d, %d, %d) is %s\n", red, green, blue, hex_code);

    // Hex to RGB conversion
    char* hex_input = (char*) malloc(7);
    printf("Enter a hex code (e.g. #FF00FF): ");
    scanf("%s", hex_input);
    int* rgb_values = hex_to_rgb(hex_input);
    printf("The RGB values for hex code %s are (%d, %d, %d)\n", hex_input, rgb_values[0], rgb_values[1], rgb_values[2]);

    // Freeing allocated memory
    free(hex_code);
    hex_code = NULL;
    free(hex_input);
    hex_input = NULL;
    free(rgb_values);
    rgb_values = NULL;

    return 0;
}