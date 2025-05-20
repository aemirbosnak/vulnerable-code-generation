//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct RGB {
    int r, g, b;
} RGB;

RGB hexToRGB(char *hex) {
    RGB rgb;
    int i;

    if (strlen(hex) != 7) {
        printf("Invalid hex color code.\n");
        exit(1);
    }

    sscanf(hex, "#%2x%2x%2x", &rgb.r, &rgb.g, &rgb.b);

    return rgb;
}

void printRGB(RGB rgb) {
    printf("RGB: (%d, %d, %d)\n", rgb.r, rgb.g, rgb.b);
}

char *rgbToHex(RGB rgb) {
    char hex[8];
    int i;

    for (i = 0; i < 3; i++) {
        sprintf(hex + i * 2, "%02x", rgb.r >> (i * 6));
        rgb.r &= ~(0xF << (i * 6));
    }

    return strcat(strcat(strcpy(malloc(7), "#"), hex), "\0");
}

int main(int argc, char *argv[]) {
    char *colorHex;
    RGB colorRGB;

    if (argc != 2) {
        printf("Usage: %s <hex color code>\n", argv[0]);
        exit(1);
    }

    colorHex = argv[1];
    colorRGB = hexToRGB(colorHex);
    printRGB(colorRGB);
    printf("Converted RGB color code: %s\n", rgbToHex(colorRGB));

    free(rgbToHex(colorRGB));
    return 0;
}