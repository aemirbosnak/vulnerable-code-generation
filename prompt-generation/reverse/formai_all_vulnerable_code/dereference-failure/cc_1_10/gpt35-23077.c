//FormAI DATASET v1.0 Category: Color Code Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a hexadecimal value
#define MAX_HEX_LENGTH 8

// Define the maximum length of an RGB value
#define MAX_RGB_LENGTH 3

// Define the maximum length of a decimal value
#define MAX_DECIMAL_LENGTH 10

// Define a function to convert a hexadecimal value to decimal
int hex_to_decimal(char hex_value[MAX_HEX_LENGTH]) {
    int decimal_value = 0;
    int hex_length = strlen(hex_value);

    for (int i = 0; i < hex_length; i++) {
        int current_digit = hex_value[i];

        if (current_digit >= '0' && current_digit <= '9') {
            current_digit = current_digit - '0';
        } else if (current_digit >= 'a' && current_digit <= 'f') {
            current_digit = current_digit - 'a' + 10;
        } else if (current_digit >= 'A' && current_digit <= 'F') {
            current_digit = current_digit - 'A' + 10;
        } else {
            printf("Error: Invalid hexadecimal value\n");
            exit(1);
        }

        decimal_value = decimal_value * 16 + current_digit;
    }

    return decimal_value;
}

// Define a function to convert a decimal value to hexadecimal
char* decimal_to_hex(int decimal_value) {
    char* hex_value = (char*) malloc(MAX_HEX_LENGTH * sizeof(char));
    int current_digit = 0;

    while (decimal_value != 0) {
        int remainder = decimal_value % 16;

        if (remainder < 10) {
            hex_value[current_digit] = remainder + '0';
        } else {
            hex_value[current_digit] = remainder + 'a' - 10;
        }

        decimal_value /= 16;
        current_digit++;
    }

    if (current_digit == 0) {
        hex_value[current_digit] = '0';
        current_digit++;
    }

    hex_value[current_digit] = '\0';

    // Reverse the order of the characters in the hexadecimal value
    int hex_length = strlen(hex_value);

    for (int i = 0; i < hex_length / 2; i++) {
        char temp = hex_value[i];
        hex_value[i] = hex_value[hex_length - i - 1];
        hex_value[hex_length - i - 1] = temp;
    }

    return hex_value;
}

// Define a function to convert an RGB value to hexadecimal
char* rgb_to_hex(int red, int green, int blue) {
    char* hex_value = (char*) malloc(MAX_HEX_LENGTH * sizeof(char));
    char* red_hex = decimal_to_hex(red);
    char* green_hex = decimal_to_hex(green);
    char* blue_hex = decimal_to_hex(blue);

    strcpy(hex_value, red_hex);
    strcat(hex_value, green_hex);
    strcat(hex_value, blue_hex);

    free(red_hex);
    free(green_hex);
    free(blue_hex);

    return hex_value;
}

// Define a function to convert a hexadecimal value to an RGB value
void hex_to_rgb(char hex_value[MAX_HEX_LENGTH], int* red, int* green, int* blue) {
    int decimal_value = hex_to_decimal(hex_value);
    *red = (decimal_value >> 16) & 0xff;
    *green = (decimal_value >> 8) & 0xff;
    *blue = decimal_value & 0xff;
}

int main() {
    printf("Welcome to the paranoid color code converter!\n");
    printf("This program converts hexadecimal color codes to RGB color values and vice versa.\n");
    printf("Please input the type of color code you would like to convert:\n");
    printf("1. Hexadecimal to RGB\n");
    printf("2. RGB to hexadecimal\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter the hexadecimal color code (without the # symbol): ");
        char hex_value[MAX_HEX_LENGTH];
        scanf("%s", hex_value);

        int red, green, blue;
        hex_to_rgb(hex_value, &red, &green, &blue);

        printf("The RGB color value of #%s is (%d, %d, %d)\n", hex_value, red, green, blue);
    } else if (choice == 2) {
        printf("Enter the red value (0-255): ");
        int red;
        scanf("%d", &red);

        printf("Enter the green value (0-255): ");
        int green;
        scanf("%d", &green);

        printf("Enter the blue value (0-255): ");
        int blue;
        scanf("%d", &blue);

        char* hex_value = rgb_to_hex(red, green, blue);

        printf("The hexadecimal color code of (%d, %d, %d) is #%s\n", red, green, blue, hex_value);

        free(hex_value);
    } else {
        printf("Error: Invalid choice\n");
    }

    return 0;
}