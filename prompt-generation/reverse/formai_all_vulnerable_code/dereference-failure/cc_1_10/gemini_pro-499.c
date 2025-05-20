//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_CODE_LEN 7
#define COLOR_CODES 16

char *color_codes[COLOR_CODES] = {
    "black",
    "brown",
    "red",
    "orange",
    "yellow",
    "green",
    "blue",
    "violet",
    "gray",
    "white",
    "gold",
    "silver",
    "none",
    "violet-brown",
    "violet-gray",
    "violet-white"
};

int color_code_values[COLOR_CODES] = {
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    10,
    11,
    12,
    13,
    14,
    15
};

int main() {
    char input[COLOR_CODE_LEN + 1];
    int values[3];
    int multiplier;

    printf("Enter a color code (e.g. red-orange-brown): ");
    scanf("%s", input);

    // Parse the input string and extract the color codes
    char *token = strtok(input, "-");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < COLOR_CODES; j++) {
            if (strcmp(token, color_codes[j]) == 0) {
                values[i] = color_code_values[j];
                break;
            }
        }
        token = strtok(NULL, "-");
    }

    // Calculate the multiplier
    switch (values[2]) {
        case 10:
            multiplier = 10;
            break;
        case 11:
            multiplier = 100;
            break;
        case 12:
            multiplier = 1000;
            break;
        default:
            multiplier = 1;
            break;
    }

    // Calculate the resistance value
    int resistance = (values[0] * 10 + values[1]) * multiplier;

    // Print the resistance value
    printf("The resistance value is: %d ohms\n", resistance);

    return 0;
}