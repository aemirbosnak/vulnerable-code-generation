//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 20
#define MAX_COLOR_CODE_LENGTH 7

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    char code[MAX_COLOR_CODE_LENGTH];
} Color;

Color colors[] = {
    {"Black", "000000"},
    {"White", "FFFFFF"},
    {"Red", "FF0000"},
    {"Green", "00FF00"},
    {"Blue", "0000FF"},
    {"Yellow", "FFFF00"},
    {"Cyan", "00FFFF"},
    {"Magenta", "FF00FF"},
    {"Gray", "808080"},
    {"Dark Red", "8B0000"},
    {"Dark Green", "006400"},
    {"Dark Blue", "00008B"},
    {"Dark Yellow", "8B8B00"},
    {"Dark Cyan", "008B8B"},
    {"Dark Magenta", "8B008B"},
    {"Dark Gray", "A9A9A9"}
};

int num_colors = sizeof(colors) / sizeof(Color);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <color name or code>\n", argv[0]);
        exit(1);
    }

    char input[MAX_COLOR_NAME_LENGTH + 1];
    strcpy(input, argv[1]);

    Color *color = NULL;
    for (int i = 0; i < num_colors; i++) {
        if (strcmp(colors[i].name, input) == 0) {
            color = &colors[i];
            break;
        }
    }

    if (color == NULL) {
        for (int i = 0; i < num_colors; i++) {
            if (strcmp(colors[i].code, input) == 0) {
                color = &colors[i];
                break;
            }
        }
    }

    if (color == NULL) {
        printf("Invalid color: %s\n", input);
        exit(1);
    }

    printf("Name: %s\nCode: %s\n", color->name, color->code);

    return 0;
}