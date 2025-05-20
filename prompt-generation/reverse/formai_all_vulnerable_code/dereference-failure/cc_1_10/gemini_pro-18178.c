//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the supported color codes
#define COLOR_RED     "#FF0000"
#define COLOR_GREEN   "#00FF00"
#define COLOR_BLUE    "#0000FF"
#define COLOR_WHITE   "#FFFFFF"
#define COLOR_BLACK   "#000000"

// Define the maximum length of a color code
#define MAX_COLOR_CODE_LENGTH 7

// Define the error codes
#define ERROR_INVALID_COLOR_CODE -1
#define ERROR_INVALID_HEX_VALUE   -2
#define ERROR_INVALID_COLOR_NAME -3

// Convert a hexadecimal color code to a decimal value
int hex_to_dec(char hex) {
    if (hex >= '0' && hex <= '9') {
        return hex - '0';
    } else if (hex >= 'A' && hex <= 'F') {
        return hex - 'A' + 10;
    } else if (hex >= 'a' && hex <= 'f') {
        return hex - 'a' + 10;
    } else {
        return -1;
    }
}

// Convert a color code to a decimal value
int color_code_to_dec(char *color_code) {
    int dec_value = 0;

    // Check if the color code is valid
    if (strlen(color_code) != MAX_COLOR_CODE_LENGTH || color_code[0] != '#') {
        return ERROR_INVALID_COLOR_CODE;
    }

    // Convert the color code to a decimal value
    for (int i = 1; i < MAX_COLOR_CODE_LENGTH; i++) {
        int hex_value = hex_to_dec(color_code[i]);
        if (hex_value == -1) {
            return ERROR_INVALID_HEX_VALUE;
        }
        dec_value = dec_value * 16 + hex_value;
    }

    return dec_value;
}

// Convert a color name to a decimal value
int color_name_to_dec(char *color_name) {
    // Define the supported color names
    char *color_names[] = {"red", "green", "blue", "white", "black"};
    int color_values[] = {0xFF0000, 0x00FF00, 0x0000FF, 0xFFFFFF, 0x000000};

    // Check if the color name is valid
    for (int i = 0; i < 5; i++) {
        if (strcmp(color_name, color_names[i]) == 0) {
            return color_values[i];
        }
    }

    return ERROR_INVALID_COLOR_NAME;
}

// Convert a decimal value to a color code
char *dec_to_color_code(int dec_value) {
    char *color_code = malloc(MAX_COLOR_CODE_LENGTH);

    // Check if the decimal value is valid
    if (dec_value < 0 || dec_value > 0xFFFFFF) {
        return NULL;
    }

    // Convert the decimal value to a color code
    sprintf(color_code, "#%06X", dec_value);

    return color_code;
}

// Convert a color code to a color name
char *color_code_to_name(char *color_code) {
    // Define the supported color codes
    char *color_codes[] = {COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_WHITE, COLOR_BLACK};
    char *color_names[] = {"red", "green", "blue", "white", "black"};

    // Check if the color code is valid
    for (int i = 0; i < 5; i++) {
        if (strcmp(color_code, color_codes[i]) == 0) {
            return color_names[i];
        }
    }

    return NULL;
}

// Print the usage of the program
void print_usage() {
    printf("Usage: color_code_converter [OPTION] [COLOR]\n");
    printf("Options:\n");
    printf("  -h, --help          Print this help message and exit\n");
    printf("  -c, --color-code    Convert a color code to a color name\n");
    printf("  -n, --color-name    Convert a color name to a color code\n");
    printf("  -d, --decimal       Convert a decimal value to a color code\n");
    printf("  -x, --hex           Convert a hexadecimal color code to a decimal value\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Parse the command line arguments
    if (argc < 2) {
        print_usage();
        return 1;
    }

    char *option = argv[1];
    char *color = argv[2];

    // Convert the color code to a decimal value
    int dec_value = 0;
    if (strcmp(option, "-c") == 0 || strcmp(option, "--color-code") == 0) {
        dec_value = color_code_to_dec(color);
    } else if (strcmp(option, "-n") == 0 || strcmp(option, "--color-name") == 0) {
        dec_value = color_name_to_dec(color);
    } else if (strcmp(option, "-d") == 0 || strcmp(option, "--decimal") == 0) {
        dec_value = atoi(color);
    } else if (strcmp(option, "-x") == 0 || strcmp(option, "--hex") == 0) {
        dec_value = hex_to_dec(color);
    } else {
        print_usage();
        return 1;
    }

    // Check if the conversion was successful
    if (dec_value == ERROR_INVALID_COLOR_CODE) {
        printf("Error: Invalid color code\n");
        return 1;
    } else if (dec_value == ERROR_INVALID_HEX_VALUE) {
        printf("Error: Invalid hexadecimal value\n");
        return 1;
    } else if (dec_value == ERROR_INVALID_COLOR_NAME) {
        printf("Error: Invalid color name\n");
        return 1;
    }

    // Convert the decimal value to a color code
    char *color_code = dec_to_color_code(dec_value);

    // Convert the color code to a color name
    char *color_name = color_code_to_name(color_code);

    // Print the result
    printf("Color code: %s\n", color_code);
    printf("Color name: %s\n", color_name);

    return 0;
}