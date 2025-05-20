//Falcon2-11B DATASET v1.0 Category: Color Code Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void convertColor(char *input) {
    char *colorCode;
    int red, green, blue;
    int i;

    // Convert input to lowercase
    for (i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }

    // Check for valid input format
    if (strlen(input)!= 6 && strlen(input)!= 8) {
        printf("Invalid input format\n");
        return;
    }

    // Convert input to integer values
    colorCode = strdup(input);
    if (strncmp(colorCode, "#", 1) == 0) {
        red = (colorCode[1] - '0') * 16 + (colorCode[2] - '0');
        green = (colorCode[3] - '0') * 16 + (colorCode[4] - '0');
        blue = (colorCode[5] - '0') * 16 + (colorCode[6] - '0');
    } else if (strncmp(colorCode, "rgb", 3) == 0) {
        red = atoi(colorCode + 3);
        green = atoi(colorCode + 6);
        blue = atoi(colorCode + 9);
    } else {
        printf("Invalid input format\n");
        return;
    }

    // Convert to decimal values
    if (red > 255 || red < 0 || green > 255 || green < 0 || blue > 255 || blue < 0) {
        printf("Invalid input format\n");
        return;
    }

    printf("Input: %s\n", input);
    printf("RGB: (%d, %d, %d)\n", red, green, blue);
    printf("Hex: #%02X%02X%02X\n", red, green, blue);
    printf("Decimal: %d, %d, %d\n", red, green, blue);
}

int main() {
    char input[9];

    printf("Enter a color code (e.g. #FF0000, rgb(255, 0, 0)): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    convertColor(input);
    return 0;
}