//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CODE_LENGTH 7

typedef struct {
    char *name;
    int value;
} ColorCode;

ColorCode color_codes[] = {
    {"black", 0},
    {"red", 1},
    {"green", 2},
    {"yellow", 3},
    {"blue", 4},
    {"magenta", 5},
    {"cyan", 6},
    {"white", 7},
    {"bright_black", 8},
    {"bright_red", 9},
    {"bright_green", 10},
    {"bright_yellow", 11},
    {"bright_blue", 12},
    {"bright_magenta", 13},
    {"bright_cyan", 14},
    {"bright_white", 15}
};

int num_color_codes = sizeof(color_codes) / sizeof(ColorCode);

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <color_name>\n", argv[0]);
        return 1;
    }

    char *color_name = argv[1];
    int i;

    for (i = 0; i < num_color_codes; i++) {
        if (strcmp(color_name, color_codes[i].name) == 0) {
            printf("%s\n", color_codes[i].name);
            return 0;
        }
    }

    printf("Invalid color name.\n");
    return 1;
}