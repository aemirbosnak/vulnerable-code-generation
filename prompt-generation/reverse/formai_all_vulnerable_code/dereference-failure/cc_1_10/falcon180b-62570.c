//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 10
#define MAX_COLOR_CODES 100

struct color_name {
    char name[10];
    char code[8];
};

struct color_name color_names[MAX_COLOR_NAMES] = {
    {"AliceBlue", "#F0F8FF"},
    {"AntiqueWhite", "#FAEBD7"},
    {"Aqua", "#00FFFF"},
    {"Aquamarine", "#7FFFD4"},
    {"Azure", "#F0FFFF"},
    {"Beige", "#F5F5DC"},
    {"Bisque", "#FFE4C4"},
    {"Black", "#000000"},
    {"BlanchedAlmond", "#FFEBCD"},
    {"Blue", "#0000FF"}
};

int num_color_names = sizeof(color_names) / sizeof(struct color_name);

void print_usage() {
    printf("Usage:./color_code_converter [color_name]\n");
    printf("Example:./color_code_converter AliceBlue\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage();
        return 1;
    }

    char *color_name = argv[1];
    int i;

    for (i = 0; i < num_color_names; i++) {
        if (strcmp(color_names[i].name, color_name) == 0) {
            printf("%s\n", color_names[i].code);
            return 0;
        }
    }

    print_usage();
    return 1;
}