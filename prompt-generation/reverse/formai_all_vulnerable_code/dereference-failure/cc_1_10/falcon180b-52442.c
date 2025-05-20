//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLOR_NAME_LENGTH 100
#define MAX_COLOR_VALUE_LENGTH 10

typedef struct {
    char *name;
    char *value;
} Color;

Color *parse_color(char *line) {
    Color *color = malloc(sizeof(Color));
    char *name = strtok(line, ":");
    char *value = strtok(NULL, ":");

    if (name == NULL || value == NULL) {
        free(color);
        return NULL;
    }

    int value_len = strlen(value);
    if (value_len > MAX_COLOR_VALUE_LENGTH) {
        free(color);
        return NULL;
    }

    color->name = malloc(value_len + 1);
    strcpy(color->name, name);
    color->value = malloc(value_len + 1);
    strcpy(color->value, value);

    return color;
}

void print_color(Color *color) {
    printf("Name: %s\nValue: %s\n", color->name, color->value);
}

void free_color(Color *color) {
    free(color->name);
    free(color->value);
    free(color);
}

int main() {
    FILE *file = fopen("colors.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    Color *colors = NULL;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        Color *color = parse_color(line);
        if (color!= NULL) {
            colors = realloc(colors, sizeof(Color) * (count_colors(colors) + 1));
            colors[count_colors(colors) - 1] = *color;
            free_color(color);
        }
    }

    fclose(file);

    for (int i = 0; i < count_colors(colors); i++) {
        print_color(&colors[i]);
    }

    free(colors);

    return 0;
}

int count_colors(Color *colors) {
    return colors == NULL? 0 : 1 + count_colors(colors + 1);
}