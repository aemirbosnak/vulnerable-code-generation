//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_SIZE 1000
#define MAX_COLOR_NAME_SIZE 20
#define MAX_COLOR_VALUE_SIZE 10

// Define color names and their corresponding values
struct color_t {
    char name[MAX_COLOR_NAME_SIZE];
    char value[MAX_COLOR_VALUE_SIZE];
};

static struct color_t colors[] = {
    {"black", "#000000"},
    {"white", "#FFFFFF"},
    {"red", "#FF0000"},
    {"green", "#00FF00"},
    {"blue", "#0000FF"},
    {"yellow", "#FFFF00"},
    {"cyan", "#00FFFF"},
    {"magenta", "#FF00FF"},
    {"gray", "#808080"}
};

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <color_name>\n", argv[0]);
        exit(1);
    }

    struct color_t *color = NULL;

    // Find the color by name
    for (int i = 0; i < sizeof(colors) / sizeof(colors[0]); i++) {
        if (strcmp(colors[i].name, argv[1]) == 0) {
            color = &colors[i];
            break;
        }
    }

    if (color == NULL) {
        printf("Invalid color name.\n");
        exit(1);
    }

    // Convert color name to hex value
    char hex_value[MAX_COLOR_VALUE_SIZE];
    sprintf(hex_value, "%s", color->value);

    printf("Color name: %s\n", argv[1]);
    printf("Color value: %s\n", hex_value);

    return 0;
}