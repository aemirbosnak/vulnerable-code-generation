//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 256

typedef struct {
    char name[10];
    int value;
} Color;

Color colors[MAX_COLORS];
int num_colors;

void load_colors() {
    FILE *file = fopen("colors.txt", "r");
    if (file == NULL) {
        printf("Error loading colors.\n");
        exit(1);
    }

    char line[80];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *name = strtok(line, ",");
        int value = atoi(strtok(NULL, ","));

        int i;
        for (i = 0; i < num_colors; i++) {
            if (strcmp(colors[i].name, name) == 0) {
                printf("Duplicate color name: %s\n", name);
                exit(1);
            }
        }

        strncpy(colors[num_colors].name, name, sizeof(colors[num_colors].name));
        colors[num_colors].value = value;
        num_colors++;
    }

    fclose(file);
}

int main() {
    load_colors();

    char input[80];
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        char *color_name = strtok(input, " ");

        int i;
        for (i = 0; i < num_colors; i++) {
            if (strcmp(colors[i].name, color_name) == 0) {
                printf("%s\n", colors[i].name);
                break;
            }
        }

        if (i == num_colors) {
            printf("Invalid color name: %s\n", color_name);
        }
    }

    return 0;
}