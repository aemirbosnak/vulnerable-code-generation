//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CODE_LENGTH 7

typedef struct {
    char *name;
    int code;
} Color;

Color colors[] = {
    {"black", 0},
    {"white", 7},
    {"red", 1},
    {"green", 2},
    {"yellow", 3},
    {"blue", 4},
    {"magenta", 5},
    {"cyan", 6}
};

int num_colors = sizeof(colors) / sizeof(Color);

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <color_name>\n", argv[0]);
        return 1;
    }

    char *color_name = argv[1];
    int color_code = -1;

    for (int i = 0; i < num_colors; i++) {
        if (strcmp(color_name, colors[i].name) == 0) {
            color_code = colors[i].code;
            break;
        }
    }

    if (color_code == -1) {
        printf("Invalid color name\n");
        return 1;
    }

    printf("Color name: %s\n", color_name);
    printf("Color code: %d\n", color_code);

    return 0;
}