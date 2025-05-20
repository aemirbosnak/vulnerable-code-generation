//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LEN 7

typedef struct {
    char *code;
    int value;
} ColorCode;

ColorCode color_codes[] = {
    {"black", 0},
    {"maroon", 1},
    {"green", 2},
    {"olive", 3},
    {"navy", 4},
    {"purple", 5},
    {"teal", 6},
    {"silver", 7},
    {"gray", 8},
    {"red", 9},
    {"lime", 10},
    {"yellow", 11},
    {"blue", 12},
    {"fuchsia", 13},
    {"aqua", 14},
    {"white", 15}
};

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <color_name>\n", argv[0]);
        return 1;
    }

    char *color_name = argv[1];
    int color_value = -1;

    for (int i = 0; i < sizeof(color_codes) / sizeof(ColorCode); i++) {
        if (strcmp(color_name, color_codes[i].code) == 0) {
            color_value = color_codes[i].value;
            break;
        }
    }

    if (color_value == -1) {
        printf("Invalid color name\n");
        return 1;
    }

    printf("%s", color_name);
    for (int i = strlen(color_name); i < MAX_CODE_LEN; i++) {
        printf(" ");
    }
    printf("%d\n", color_value);

    return 0;
}