//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR_CODE_LENGTH 7
#define MAX_COLOR_NAME_LENGTH 16

typedef struct {
    char *color_name;
    char *color_code;
} ColorCode;

ColorCode color_codes[] = {
    {"black", "\033[0;30m"},
    {"red", "\033[0;31m"},
    {"green", "\033[0;32m"},
    {"yellow", "\033[0;33m"},
    {"blue", "\033[0;34m"},
    {"magenta", "\033[0;35m"},
    {"cyan", "\033[0;36m"},
    {"white", "\033[0;37m"},
    {"reset", "\033[0m"}
};

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <color_name> <text>\n", argv[0]);
        return 1;
    }

    char *color_name = argv[1];
    char *text = argv[2];

    ColorCode *color_code = NULL;
    for (int i = 0; i < sizeof(color_codes) / sizeof(ColorCode); i++) {
        if (strcmp(color_name, color_codes[i].color_name) == 0) {
            color_code = &color_codes[i];
            break;
        }
    }

    if (color_code == NULL) {
        printf("Invalid color name: %s\n", color_name);
        return 1;
    }

    printf("%s%s%s\n", color_code->color_code, text, "\033[0m");

    return 0;
}