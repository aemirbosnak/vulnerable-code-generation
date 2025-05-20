//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char name[20];
    int hex_value;
    char rgb_value[8];
} Color;

Color colors[] = {
    {"black", 0x000000, "000000"},
    {"white", 0xFFFFFF, "FFFFFF"},
    {"red", 0xFF0000, "FF0000"},
    {"green", 0x00FF00, "00FF00"},
    {"blue", 0x0000FF, "0000FF"},
    {"yellow", 0xFFFF00, "FFFF00"},
    {"cyan", 0x00FFFF, "00FFFF"},
    {"magenta", 0xFF00FF, "FF00FF"},
    {"gray", 0x808080, "808080"},
    {"lightgray", 0xD3D3D3, "D3D3D3"},
    {"darkgray", 0xA9A9A9, "A9A9A9"},
    {"lightblue", 0xADD8E6, "ADD8E6"},
    {"lightgreen", 0x90EE90, "90EE90"},
    {"lightred", 0xFFA07A, "FFA07A"},
    {"orange", 0xFFA500, "FFA500"},
    {"purple", 0x800080, "800080"},
    {"teal", 0x008080, "008080"},
    {"navy", 0x000080, "000080"},
    {"maroon", 0x800000, "800000"}
};

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <color_name>\n", argv[0]);
        exit(1);
    }

    char *color_name = argv[1];
    int color_index = -1;

    for (int i = 0; i < sizeof(colors) / sizeof(Color); i++) {
        if (strcmp(colors[i].name, color_name) == 0) {
            color_index = i;
            break;
        }
    }

    if (color_index == -1) {
        printf("Invalid color name\n");
        exit(1);
    }

    Color color = colors[color_index];
    printf("Color name: %s\n", color.name);
    printf("Hex value: %X\n", color.hex_value);
    printf("RGB value: %s\n", color.rgb_value);

    return 0;
}