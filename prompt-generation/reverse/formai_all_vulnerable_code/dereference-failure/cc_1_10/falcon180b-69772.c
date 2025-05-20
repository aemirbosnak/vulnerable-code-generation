//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR_NAME_LENGTH 80
#define MAX_COLOR_VALUE_LENGTH 7
#define MAX_COLOR_FORMAT_LENGTH 15
#define MAX_COLOR_NAMES 256

typedef struct {
    char *name;
    char *value;
    char *format;
} Color;

Color colors[MAX_COLOR_NAMES];
int num_colors = 0;

void add_color(char *name, char *value, char *format) {
    if (num_colors >= MAX_COLOR_NAMES) {
        printf("Error: Too many colors defined.\n");
        exit(1);
    }
    colors[num_colors].name = strdup(name);
    colors[num_colors].value = strdup(value);
    colors[num_colors].format = strdup(format);
    num_colors++;
}

int main() {
    char line[256];
    FILE *file;
    char *filename = "colors.txt";
    int i;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file '%s'.\n", filename);
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        char *name = strtok(line, ":");
        char *value = strtok(NULL, ":");
        char *format = strtok(NULL, ":");

        if (name == NULL || value == NULL || format == NULL) {
            printf("Error: Invalid color definition in file '%s'.\n", filename);
            exit(1);
        }

        add_color(name, value, format);
    }

    fclose(file);

    printf("Enter a color name: ");
    scanf("%s", line);

    for (i = 0; i < num_colors; i++) {
        if (strcmp(line, colors[i].name) == 0) {
            printf("Color name: %s\n", colors[i].name);
            printf("Color value: %s\n", colors[i].value);
            printf("Color format: %s\n", colors[i].format);
            return 0;
        }
    }

    printf("Error: Color not found.\n");
    return 1;
}