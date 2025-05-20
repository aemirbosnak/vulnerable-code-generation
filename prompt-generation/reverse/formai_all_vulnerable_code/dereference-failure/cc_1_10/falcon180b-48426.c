//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CODE_LENGTH 7
#define MAX_COLOR_NAMES 7

typedef struct {
    char *name;
    int code;
} Color;

Color colors[] = {
    {"Black", 0},
    {"White", 7},
    {"Red", 1},
    {"Green", 2},
    {"Blue", 3},
    {"Yellow", 4},
    {"Magenta", 5},
    {"Cyan", 6}
};

int main() {
    srand(time(NULL));
    int num_colors = rand() % MAX_COLOR_NAMES + 1;
    int code_length = rand() % MAX_CODE_LENGTH + 1;

    char *color_code = malloc(code_length + 1);
    for (int i = 0; i < code_length; i++) {
        color_code[i] = '0' + rand() % 10;
    }
    color_code[code_length] = '\0';

    int code = 0;
    for (int i = 0; i < code_length; i++) {
        code = code * 10 + (color_code[i] - '0');
    }

    Color *selected_color = NULL;
    for (int i = 0; i < MAX_COLOR_NAMES; i++) {
        if (colors[i].code == code) {
            selected_color = &colors[i];
            break;
        }
    }

    if (selected_color == NULL) {
        printf("Invalid color code: %s\n", color_code);
    } else {
        printf("Color: %s\n", selected_color->name);
    }

    free(color_code);
    return 0;
}