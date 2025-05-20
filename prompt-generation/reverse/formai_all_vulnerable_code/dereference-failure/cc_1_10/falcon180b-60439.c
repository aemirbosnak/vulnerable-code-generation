//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 20
#define MAX_COLOR_CODE_LENGTH 7
#define MAX_COLOR_NAMES 1000

struct color_name {
    char name[MAX_COLOR_NAME_LENGTH];
    char code[MAX_COLOR_CODE_LENGTH];
};

int main() {
    FILE *file;
    char line[1024];
    struct color_name colors[MAX_COLOR_NAMES];
    int num_colors = 0;

    file = fopen("colors.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    // Read in color names and codes from file
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (num_colors >= MAX_COLOR_NAMES) {
            printf("Error: Maximum number of color names exceeded.\n");
            exit(1);
        }
        char *name_start = strchr(line, ',');
        if (name_start == NULL) {
            printf("Error: Invalid color name format.\n");
            exit(1);
        }
        strncpy(colors[num_colors].name, line, name_start - line);
        colors[num_colors].name[MAX_COLOR_NAME_LENGTH - 1] = '\0';
        strncpy(colors[num_colors].code, name_start + 1, MAX_COLOR_CODE_LENGTH - 1);
        colors[num_colors].code[MAX_COLOR_CODE_LENGTH - 1] = '\0';
        num_colors++;
    }

    fclose(file);

    // Convert color name to code
    char input_name[MAX_COLOR_NAME_LENGTH];
    printf("Enter a color name: ");
    fgets(input_name, sizeof(input_name), stdin);
    input_name[strcspn(input_name, "\n")] = '\0';

    struct color_name *color = NULL;
    for (int i = 0; i < num_colors; i++) {
        if (strcmp(colors[i].name, input_name) == 0) {
            color = &colors[i];
            break;
        }
    }

    if (color == NULL) {
        printf("Error: Color name not found.\n");
        exit(1);
    }

    printf("Color code: %s\n", color->code);

    return 0;
}