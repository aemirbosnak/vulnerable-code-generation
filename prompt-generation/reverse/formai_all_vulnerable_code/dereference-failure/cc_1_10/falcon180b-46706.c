//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 256

typedef struct {
    char *name;
    char hex[8];
} Color;

Color color_table[MAX_COLOR_NAMES];
int color_count = 0;

void add_color(char *name, char *hex) {
    if (color_count >= MAX_COLOR_NAMES) {
        printf("Error: Too many colors defined.\n");
        exit(1);
    }

    color_table[color_count].name = strdup(name);
    strcpy(color_table[color_count].hex, hex);
    color_count++;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), input_file)!= NULL) {
        char *pos = line;
        while ((pos = strstr(pos, "#"))!= NULL) {
            *pos = '\0';
            char *color_name = line;
            char *color_hex = pos + 1;
            add_color(color_name, color_hex);
            strcat(pos, " ");
        }

        fprintf(output_file, "%s", line);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}