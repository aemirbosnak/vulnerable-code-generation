//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_COLOR_NAMES 20
#define MAX_COLOR_VALUES 100

typedef struct {
    char name[MAX_COLOR_NAMES];
    int value;
} Color;

char *get_line(FILE *file) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if ((read = getline(&line, &len, file))!= -1) {
        line[strcspn(line, "\n")] = '\0';
    }

    return line;
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: cannot open file '%s'.\n", argv[1]);
        return 1;
    }

    Color colors[MAX_COLOR_NAMES];
    int num_colors = 0;

    char *line = get_line(file);
    while (line!= NULL) {
        if (num_colors >= MAX_COLOR_NAMES) {
            printf("Error: too many color names defined.\n");
            fclose(file);
            return 1;
        }

        if (sscanf(line, "#define %[^ ] %d", colors[num_colors].name, &colors[num_colors].value)!= 2) {
            printf("Error: invalid color definition.\n");
            fclose(file);
            return 1;
        }

        num_colors++;
        line = get_line(file);
    }

    fclose(file);

    if (num_colors == 0) {
        printf("Error: no color names defined.\n");
        return 1;
    }

    for (int i = 0; i < num_colors; i++) {
        printf("#define %s %d\n", colors[i].name, colors[i].value);
    }

    return 0;
}