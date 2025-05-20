//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CODE_LENGTH 7
#define MAX_COLOR_NAMES 256

typedef struct {
    char *name;
    char code[MAX_CODE_LENGTH];
} Color;

Color colors[MAX_COLOR_NAMES];
int num_colors = 0;

void add_color(char *name, char *code) {
    if (num_colors >= MAX_COLOR_NAMES) {
        printf("Error: Too many colors defined.\n");
        exit(1);
    }

    strcpy(colors[num_colors].name, name);
    strcpy(colors[num_colors].code, code);

    num_colors++;
}

int main() {
    FILE *input_file;
    char line[1024];
    char *filename = "colors.txt";
    input_file = fopen(filename, "r");

    if (input_file == NULL) {
        printf("Error: Unable to open %s.\n", filename);
        exit(1);
    }

    while (fgets(line, sizeof(line), input_file)!= NULL) {
        char *name = strtok(line, ",");
        char *code = strtok(NULL, ",");

        if (name == NULL || code == NULL) {
            printf("Error: Invalid color definition.\n");
            exit(1);
        }

        add_color(name, code);
    }

    fclose(input_file);

    printf("Enter a color name: ");
    scanf("%s", line);

    int i;
    for (i = 0; i < num_colors; i++) {
        if (strcmp(line, colors[i].name) == 0) {
            printf("%s\n", colors[i].code);
            return 0;
        }
    }

    printf("Error: Color not found.\n");
    return 1;
}