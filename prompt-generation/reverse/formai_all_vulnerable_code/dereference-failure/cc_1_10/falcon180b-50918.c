//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 7
#define COLOR_NAMES_LENGTH 11

typedef struct {
    char name[COLOR_NAMES_LENGTH];
    unsigned char code[MAX_CODE_LENGTH];
} Color;

Color colors[] = {
    {"Black", {0x00, 0x00, 0x00}},
    {"Maroon", {0x80, 0x00, 0x00}},
    {"Green", {0x00, 0x80, 0x00}},
    {"Olive", {0x80, 0x80, 0x00}},
    {"Navy", {0x00, 0x00, 0x80}},
    {"Purple", {0x80, 0x00, 0x80}},
    {"Teal", {0x00, 0x80, 0x80}},
    {"Gray", {0x80, 0x80, 0x80}}
};

int num_colors = sizeof(colors) / sizeof(Color);

void print_usage(void)
{
    printf("Usage: color_code <color_name>\n");
}

int main(int argc, char **argv)
{
    if (argc!= 2) {
        print_usage();
        return 1;
    }

    char *color_name = argv[1];
    Color *color = NULL;

    for (int i = 0; i < num_colors; i++) {
        if (strcmp(color_name, colors[i].name) == 0) {
            color = &colors[i];
            break;
        }
    }

    if (color == NULL) {
        printf("Invalid color name\n");
        return 1;
    }

    printf("Color code for %s: ", color_name);

    for (int i = 0; i < color->code[MAX_CODE_LENGTH - 1]; i++) {
        printf("%02X", color->code[i]);
    }

    printf("\n");

    return 0;
}