//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LEN 32

typedef enum {
    COLOR_RED,
    COLOR_GREEN,
    COLOR_BLUE,
    COLOR_YELLOW,
    COLOR_CYAN,
    COLOR_MAGENTA,
    COLOR_WHITE,
    COLOR_BLACK
} color_t;

typedef struct {
    char name[MAX_COLOR_NAME_LEN];
    color_t value;
} color_map_t;

color_map_t color_map[] = {
    {"red", COLOR_RED},
    {"green", COLOR_GREEN},
    {"blue", COLOR_BLUE},
    {"yellow", COLOR_YELLOW},
    {"cyan", COLOR_CYAN},
    {"magenta", COLOR_MAGENTA},
    {"white", COLOR_WHITE},
    {"black", COLOR_BLACK}
};

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <color_name>\n", argv[0]);
        return 1;
    }

    color_map_t *color = NULL;
    for (int i = 0; i < sizeof(color_map) / sizeof(color_map[0]); i++) {
        if (strcmp(color_map[i].name, argv[1]) == 0) {
            color = &color_map[i];
            break;
        }
    }

    if (color == NULL) {
        printf("Invalid color name\n");
        return 1;
    }

    printf("Color name: %s\n", color->name);
    printf("Color code: %d\n", color->value);

    return 0;
}