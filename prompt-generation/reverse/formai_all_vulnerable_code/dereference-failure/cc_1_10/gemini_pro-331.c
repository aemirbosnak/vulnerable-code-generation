//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: optimized
// Example Color Code Converter

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANSI_COLOR_RESET "\x1B[0m"
#define ANSI_COLOR_BLACK "\x1B[30m"
#define ANSI_COLOR_RED "\x1B[31m"
#define ANSI_COLOR_GREEN "\x1B[32m"
#define ANSI_COLOR_YELLOW "\x1B[33m"
#define ANSI_COLOR_BLUE "\x1B[34m"
#define ANSI_COLOR_MAGENTA "\x1B[35m"
#define ANSI_COLOR_CYAN "\x1B[36m"
#define ANSI_COLOR_WHITE "\x1B[37m"

typedef struct {
    char *name;
    char *code;
} color_code;

color_code color_codes[] = {
    {"black", ANSI_COLOR_BLACK},
    {"red", ANSI_COLOR_RED},
    {"green", ANSI_COLOR_GREEN},
    {"yellow", ANSI_COLOR_YELLOW},
    {"blue", ANSI_COLOR_BLUE},
    {"magenta", ANSI_COLOR_MAGENTA},
    {"cyan", ANSI_COLOR_CYAN},
    {"white", ANSI_COLOR_WHITE},
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <color name>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *color_name = argv[1];

    for (int i = 0; i < sizeof(color_codes) / sizeof(color_code); i++) {
        if (strcmp(color_name, color_codes[i].name) == 0) {
            printf("%s\n", color_codes[i].code);
            return EXIT_SUCCESS;
        }
    }

    printf("Invalid color name '%s'\n", color_name);
    return EXIT_FAILURE;
}