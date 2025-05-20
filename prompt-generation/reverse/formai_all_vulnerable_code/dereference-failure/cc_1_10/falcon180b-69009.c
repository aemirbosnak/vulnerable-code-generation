//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 256
#define MAX_COLOR_CODES 256

typedef struct {
    char *name;
    char *hex;
    int red;
    int green;
    int blue;
} Color;

Color colors[MAX_COLOR_NAMES];
int num_colors = 0;

void add_color(char *name, char *hex, int red, int green, int blue) {
    if (num_colors >= MAX_COLOR_NAMES) {
        printf("Error: Too many colors!\n");
        exit(1);
    }
    colors[num_colors].name = strdup(name);
    colors[num_colors].hex = strdup(hex);
    colors[num_colors].red = red;
    colors[num_colors].green = green;
    colors[num_colors].blue = blue;
    num_colors++;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <color_name|color_code>\n", argv[0]);
        return 1;
    }

    char *input = argv[1];
    int input_len = strlen(input);

    if (input_len == 7 && input[0] == '#') {
        // Input is a hex color code
        char hex_code[9];
        strcpy(hex_code, input);
        hex_code[7] = '\0'; // Remove the '#' character

        int red, green, blue;
        sscanf(hex_code, "#%02x%02x%02x", &red, &green, &blue);

        for (int i = 0; i < num_colors; i++) {
            if (colors[i].red == red && colors[i].green == green && colors[i].blue == blue) {
                printf("%s\n", colors[i].name);
                return 0;
            }
        }

        printf("Error: Color not found!\n");
        return 1;
    } else {
        // Input is a color name
        for (int i = 0; i < num_colors; i++) {
            if (strcmp(input, colors[i].name) == 0) {
                printf("%s\n", colors[i].hex);
                return 0;
            }
        }

        printf("Error: Color not found!\n");
        return 1;
    }
}