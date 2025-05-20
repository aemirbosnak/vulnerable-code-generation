//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR_CODE_LENGTH 7 // maximum length of color code (including #)

// function to check if a string is a valid color code
int is_valid_color_code(char *color_code) {
    // check if string is the correct length
    if (strlen(color_code)!= MAX_COLOR_CODE_LENGTH) {
        return 0;
    }

    // check if string starts with #
    if (color_code[0]!= '#') {
        return 0;
    }

    // check if string contains only hexadecimal characters
    for (int i = 1; i < MAX_COLOR_CODE_LENGTH; i++) {
        if (!isxdigit(color_code[i])) {
            return 0;
        }
    }

    return 1; // string is a valid color code
}

// function to convert a color code to RGB values
void color_code_to_rgb(char *color_code, int *red, int *green, int *blue) {
    // check if string is a valid color code
    if (!is_valid_color_code(color_code)) {
        printf("Invalid color code.\n");
        exit(1);
    }

    // convert hexadecimal characters to decimal values
    int value;
    sscanf(color_code, "#%2x%2x%2x", &value, &value, &value);

    // assign RGB values
    *red = value;
    *green = value;
    *blue = value;
}

// function to print usage instructions
void print_usage() {
    printf("Usage:./color_code_converter <color_code>\n");
    printf("Where <color_code> is a valid color code (e.g. #FF0000 for red).\n");
}

int main(int argc, char *argv[]) {
    // check if correct number of arguments were provided
    if (argc!= 2) {
        print_usage();
        return 1;
    }

    // convert color code to RGB values
    char color_code[MAX_COLOR_CODE_LENGTH + 1] = {0};
    strcpy(color_code, argv[1]);
    int red, green, blue;
    color_code_to_rgb(color_code, &red, &green, &blue);

    // print RGB values
    printf("RGB values for %s:\n", argv[1]);
    printf("Red: %d\n", red);
    printf("Green: %d\n", green);
    printf("Blue: %d\n", blue);

    return 0;
}