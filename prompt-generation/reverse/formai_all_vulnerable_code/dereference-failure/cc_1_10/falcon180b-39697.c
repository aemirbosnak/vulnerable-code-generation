//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR_CODE_LENGTH 8
#define MAX_COLOR_NAME_LENGTH 32

enum {
    RED = 0,
    GREEN,
    BLUE,
    YELLOW,
    CYAN,
    MAGENTA,
    BLACK,
    WHITE,
    COLOR_NUM
};

typedef struct {
    char *name;
    char color_code[MAX_COLOR_CODE_LENGTH];
} Color;

Color colors[] = {
    {"Red", "\033[91m"},
    {"Green", "\033[92m"},
    {"Blue", "\033[94m"},
    {"Yellow", "\033[93m"},
    {"Cyan", "\033[96m"},
    {"Magenta", "\033[95m"},
    {"Black", "\033[30m"},
    {"White", "\033[97m"},
};

void print_usage() {
    printf("Usage: [color name]\n");
    printf("Valid color names are:\n");
    for (int i = 0; i < COLOR_NUM; i++) {
        printf("%s\n", colors[i].name);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage();
        exit(1);
    }

    char color_name[MAX_COLOR_NAME_LENGTH];
    strcpy(color_name, argv[1]);

    for (int i = 0; i < COLOR_NUM; i++) {
        if (strcmp(color_name, colors[i].name) == 0) {
            printf("%s", colors[i].color_code);
            break;
        }
    }

    return 0;
}