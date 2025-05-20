//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE 7

typedef struct {
    char *name;
    char hex[MAX_COLOR_CODE];
} ColorCode;

ColorCode color_codes[] = {
    {"black", "#000000"},
    {"white", "#FFFFFF"},
    {"red", "#FF0000"},
    {"green", "#00FF00"},
    {"blue", "#0000FF"},
    {"yellow", "#FFFF00"},
    {"magenta", "#FF00FF"},
    {"cyan", "#00FFFF"}
};

int num_color_codes = sizeof(color_codes) / sizeof(ColorCode);

void print_usage(char *prog_name) {
    printf("Usage: %s [color_name]\n", prog_name);
    printf("Converts a color name to its hexadecimal code.\n");
    printf("Available color names:");
    for (int i = 0; i < num_color_codes; i++) {
        printf(" %s", color_codes[i].name);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        print_usage(argv[0]);
        return 1;
    }

    char *color_name = argv[1];
    int found = 0;

    for (int i = 0; i < num_color_codes; i++) {
        if (strcmp(color_name, color_codes[i].name) == 0) {
            printf("%s\n", color_codes[i].hex);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Error: Invalid color name.\n");
        return 1;
    }

    return 0;
}