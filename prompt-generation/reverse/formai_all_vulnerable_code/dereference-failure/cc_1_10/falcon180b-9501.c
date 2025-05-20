//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 100

struct color_name {
    char *name;
    int hex;
};

struct color_name color_names[MAX_COLOR_NAMES] = {
    {"black", 0},
    {"white", 16777215},
    {"red", 16711680},
    {"lime", 65280},
    {"blue", 255},
    {"yellow", 16776960},
    {"cyan", 65535},
    {"magenta", 16711935},
    {"silver", 12632256},
    {"gray", 8421504},
    {"maroon", 8388608},
    {"olive", 8421376},
    {"green", 32768},
    {"purple", 8388736},
    {"teal", 32896},
    {"navy", 128},
    {"aqua", 65535}
};

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <color_name>\n", argv[0]);
        return 1;
    }

    char *color_name = argv[1];
    int i;

    for (i = 0; i < MAX_COLOR_NAMES; i++) {
        if (strcmp(color_names[i].name, color_name) == 0) {
            printf("%s: #%06X\n", color_name, color_names[i].hex);
            return 0;
        }
    }

    printf("%s not found\n", color_name);
    return 1;
}