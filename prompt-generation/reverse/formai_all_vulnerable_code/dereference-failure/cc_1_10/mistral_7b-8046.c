//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_SIZE 7

// Function to convert hexadecimal color code to RGB format
void hexToRgb(char hexColor[MAX_COLOR_SIZE]) {
    int r, g, b, i;
    char hex[3][2];

    for (i = 0; i < 3; i++) {
        hex[i][0] = hexColor[i * 2];
        hex[i][1] = hexColor[i * 2 + 1];

        if (hex[i][0] >= '0' && hex[i][0] <= '9')
            hex[i][0] -= '0';
        else if (hex[i][0] >= 'A' && hex[i][0] <= 'F')
            hex[i][0] -= 'A' - 10;
        else {
            printf("Invalid color code.\n");
            return;
        }

        if (hex[i][1] >= '0' && hex[i][1] <= '9')
            hex[i][1] -= '0';
        else if (hex[i][1] >= 'A' && hex[i][1] <= 'F')
            hex[i][1] -= 'A' - 10;
        else {
            printf("Invalid color code.\n");
            return;
        }
    }

    r = hex[0][0] << 4 | hex[0][1];
    g = hex[1][0] << 4 | hex[1][1];
    b = hex[2][0] << 4 | hex[2][1];

    printf("RGB values for the given hexadecimal color code: (%d, %d, %d)\n", r, g, b);
}

int main(int argc, char *argv[]) {
    char hexColor[MAX_COLOR_SIZE];

    if (argc != 2) {
        printf("Usage: %s <hexadecimal color code>\n", argv[0]);
        return 1;
    }

    strcpy(hexColor, argv[1]);
    hexToRgb(hexColor);

    return 0;
}