//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_COLOR_NAMES 1000

typedef struct {
    char *name;
    char *hex_code;
} Color;

int main() {
    FILE *input_file = fopen("color_names.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    int num_colors = 0;
    Color *colors = malloc(MAX_COLOR_NAMES * sizeof(Color));
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        if (num_colors >= MAX_COLOR_NAMES) {
            printf("Error: too many color names in input file.\n");
            exit(1);
        }

        int i = 0;
        char *color_name = strtok(line, "\t");
        colors[num_colors].name = malloc(strlen(color_name) + 1);
        strcpy(colors[num_colors].name, color_name);

        char *hex_code = strtok(NULL, "\n");
        colors[num_colors].hex_code = malloc(strlen(hex_code) + 1);
        strcpy(colors[num_colors].hex_code, hex_code);

        num_colors++;
    }

    fclose(input_file);

    char *input_color_name = "red";
    Color *input_color = NULL;

    for (int i = 0; i < num_colors; i++) {
        if (strcmp(colors[i].name, input_color_name) == 0) {
            input_color = &colors[i];
            break;
        }
    }

    if (input_color == NULL) {
        printf("Error: input color name not found in color names file.\n");
        exit(1);
    }

    printf("Input color name: %s\n", input_color->name);
    printf("Input color hex code: %s\n", input_color->hex_code);

    free(input_color_name);
    for (int i = 0; i < num_colors; i++) {
        free(colors[i].name);
        free(colors[i].hex_code);
    }
    free(colors);

    return 0;
}