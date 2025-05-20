//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 256

typedef struct {
    char *name;
    int value;
} Color;

Color colors[MAX_COLORS];
int num_colors = 0;

void add_color(char *name, int value) {
    if (num_colors >= MAX_COLORS) {
        fprintf(stderr, "Error: Too many colors defined.\n");
        exit(1);
    }

    colors[num_colors].name = name;
    colors[num_colors].value = value;
    num_colors++;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Could not open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error: Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), input_file)!= NULL) {
        char *color_name = strtok(line, " ");
        int r = strtol(strtok(NULL, " "), NULL, 10);
        int g = strtol(strtok(NULL, " "), NULL, 10);
        int b = strtol(strtok(NULL, " "), NULL, 10);

        int value = (r << 16) | (g << 8) | b;

        Color *color = NULL;
        for (int i = 0; i < num_colors; i++) {
            if (colors[i].value == value) {
                color = &colors[i];
                break;
            }
        }

        if (color == NULL) {
            add_color(color_name, value);
            color = &colors[num_colors - 1];
        }

        fprintf(output_file, "%s = %s\n", color_name, color->name);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}