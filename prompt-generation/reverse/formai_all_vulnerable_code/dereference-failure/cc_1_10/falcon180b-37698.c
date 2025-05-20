//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 16
#define MAX_COLOR_CODE_LENGTH 7

typedef struct {
    char *name;
    char code[MAX_COLOR_CODE_LENGTH + 1];
} Color;

Color color_names[] = {
    {"black", "\033[30m"},
    {"red", "\033[31m"},
    {"green", "\033[32m"},
    {"yellow", "\033[33m"},
    {"blue", "\033[34m"},
    {"magenta", "\033[35m"},
    {"cyan", "\033[36m"},
    {"white", "\033[37m"},
};

int num_colors = sizeof(color_names) / sizeof(Color);

void print_usage(char *program_name) {
    printf("Usage: %s [color_name]\n", program_name);
    printf("Color names: ");
    for (int i = 0; i < num_colors; i++) {
        printf("%s ", color_names[i].name);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage(argv[0]);
        return 1;
    }

    char *color_name = argv[1];
    int color_index = -1;

    for (int i = 0; i < num_colors; i++) {
        if (strcmp(color_names[i].name, color_name) == 0) {
            color_index = i;
            break;
        }
    }

    if (color_index == -1) {
        printf("Invalid color name: %s\n", color_name);
        return 1;
    }

    printf("%s", color_names[color_index].code);

    for (int i = strlen(color_names[color_index].code); i < MAX_COLOR_CODE_LENGTH; i++) {
        printf(" ");
    }

    printf("\033[0m");

    return 0;
}