//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 1000

typedef struct {
    char *name;
    char color_code[7];
} ColorName;

ColorName color_names[MAX_COLOR_NAMES];
int num_colors = 0;

void add_color_name(char *name, char *color_code) {
    if (num_colors >= MAX_COLOR_NAMES) {
        printf("Error: Maximum number of color names reached.\n");
        return;
    }

    strcpy(color_names[num_colors].name, name);
    strcpy(color_names[num_colors].color_code, color_code);

    num_colors++;
}

int main() {
    add_color_name("red", "#FF0000");
    add_color_name("green", "#00FF00");
    add_color_name("blue", "#0000FF");

    char input[100];
    while (1) {
        printf("Enter a color name or type 'exit' to quit: ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        int i;
        for (i = 0; i < num_colors; i++) {
            if (strcmp(input, color_names[i].name) == 0) {
                printf("%s\n", color_names[i].color_code);
                break;
            }
        }

        if (i == num_colors) {
            printf("Color not found.\n");
        }
    }

    return 0;
}