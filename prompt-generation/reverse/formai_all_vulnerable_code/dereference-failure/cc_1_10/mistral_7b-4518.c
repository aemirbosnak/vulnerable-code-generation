//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct RGB {
    int r, g, b;
} RGB;

RGB hexToRGB(char* hex) {
    RGB rgb;
    int dec;

    hex[strlen(hex) - 1] = '\0'; // remove the last '}' character

    sscanf(hex, "#%x%x%x", &dec, &dec, &dec);

    rgb.r = dec;
    rgb.g = dec >> 3;
    rgb.b = dec >> 6;

    return rgb;
}

void rgbToHex(RGB rgb, char* hex) {
    int r = rgb.r, g = rgb.g, b = rgb.b;

    sprintf(hex, "#%02x%02x%02x", r >> 3, g >> 3, b >> 3);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <hex_color> <output_file>\n", argv[0]);
        return 1;
    }

    char input[10], output[10];
    strcpy(input, argv[1]);
    strcpy(output, argv[2]);

    RGB color = hexToRGB(input);

    char hex[10];
    rgbToHex(color, hex);

    FILE* file = fopen(output, "w");
    fprintf(file, "%s", hex);
    fclose(file);

    printf("Color converted successfully! Output saved to: %s\n", output);

    return 0;
}