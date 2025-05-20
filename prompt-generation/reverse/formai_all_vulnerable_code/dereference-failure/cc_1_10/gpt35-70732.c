//FormAI DATASET v1.0 Category: Color Code Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define some constants to make things easier to read
#define MAX_HEX_LENGTH 7
#define MAX_RGB_VALUE 255

// Function declarations
void print_intro();
void convert_to_rgb(char hex[MAX_HEX_LENGTH]);
void convert_to_hex(int red, int green, int blue);
int hex_to_decimal(char hex);
void print_error();

int main() {
    char hex[MAX_HEX_LENGTH];

    // Print an introduction message to the user
    print_intro();

    // Prompt the user for a hex code and store it in hex
    printf("Enter a hex code: #");
    fgets(hex, MAX_HEX_LENGTH, stdin);

    // Remove new line character from hex input
    hex[strcspn(hex, "\r\n")] = '\0';

    // Ensure the input is a valid hex code
    if (strlen(hex) != 6) {
        print_error();
        return 1;
    }

    // Call convert_to_rgb to convert the hex code to RGB values
    convert_to_rgb(hex);

    return 0;
}

// Print an introduction message to the user
void print_intro() {
    printf("===============================\n");
    printf(" Hex to RGB Color Code Converter\n");
    printf("===============================\n\n");
}

// Convert a hex code to RGB values and print the result
void convert_to_rgb(char hex[MAX_HEX_LENGTH]) {
    int red, green, blue;

    // Convert the first two hex characters to decimal for the red value
    red = hex_to_decimal(hex[0]) * 16 + hex_to_decimal(hex[1]);

    // Convert the second two hex characters to decimal for the green value
    green = hex_to_decimal(hex[2]) * 16 + hex_to_decimal(hex[3]);

    // Convert the third two hex characters to decimal for the blue value
    blue = hex_to_decimal(hex[4]) * 16 + hex_to_decimal(hex[5]);

    // Print the RGB values to the user
    printf("RGB: %d, %d, %d\n\n", red, green, blue);

    // Call convert_to_hex to convert the RGB values back to hex
    convert_to_hex(red, green, blue);
}

// Convert RGB values to a hex code and print the result
void convert_to_hex(int red, int green, int blue) {
    char hex[MAX_HEX_LENGTH];

    // Convert red to hex and store it in hex
    sprintf(hex, "%02X", red);

    // Convert green to hex and concatenate it to hex
    sprintf(hex + strlen(hex), "%02X", green);

    // Convert blue to hex and concatenate it to hex
    sprintf(hex + strlen(hex), "%02X", blue);

    // Print the hex code to the user
    printf("Hex: #%s\n", hex);
}

// Convert a single hex character to decimal
int hex_to_decimal(char hex) {
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

// Print an error message to the user
void print_error() {
    printf("Invalid hex code entered. Please enter a 6-digit hexadecimal number.\n");
}