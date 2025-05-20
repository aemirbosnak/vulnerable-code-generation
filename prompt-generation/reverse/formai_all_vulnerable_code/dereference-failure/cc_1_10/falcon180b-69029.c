//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *name;
    int value;
} Color;

Color colors[] = {
    {"red", 0xFF0000},
    {"green", 0x00FF00},
    {"blue", 0x0000FF},
    {"yellow", 0xFFFF00},
    {"cyan", 0x00FFFF},
    {"magenta", 0xFF00FF},
    {"black", 0x000000},
    {"white", 0xFFFFFF},
    {"gray", 0x808080},
    {"light gray", 0xC0C0C0},
    {"dark gray", 0x404040},
    {"light blue", 0xADD8E6},
    {"light green", 0x90EE90},
    {"light red", 0xF08080},
    {"orange", 0xFFA500},
    {"pink", 0xFFC0CB},
    {"purple", 0x800080},
    {"teal", 0x008080},
};

int num_colors = sizeof(colors) / sizeof(Color);

void print_usage(char *progname) {
    fprintf(stderr, "Usage: %s <color name or hex value>\n", progname);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        print_usage(argv[0]);
        return 1;
    }

    char *color_name = argv[1];
    int i;

    for (i = 0; i < num_colors; i++) {
        if (!strcmp(colors[i].name, color_name)) {
            printf("%s -> %06X\n", colors[i].name, colors[i].value);
            return 0;
        }
    }

    if (strlen(color_name)!= 7 || color_name[0]!= '#') {
        print_usage(argv[0]);
        return 1;
    }

    int hex_value = strtol(color_name + 1, NULL, 16);
    printf("%s -> %06X\n", color_name, hex_value);

    return 0;
}