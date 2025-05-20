//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 32

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    int red;
    int green;
    int blue;
} Color;

Color* create_color(char* name, int red, int green, int blue) {
    Color* color = malloc(sizeof(Color));
    strcpy(color->name, name);
    color->red = red;
    color->green = green;
    color->blue = blue;
    return color;
}

void print_color(Color* color) {
    printf("Color: %s\n", color->name);
    printf("Red: %d\n", color->red);
    printf("Green: %d\n", color->green);
    printf("Blue: %d\n", color->blue);
}

int main(int argc, char** argv) {
    Color* colors[] = {
        create_color("Romeo", 255, 0, 0),
        create_color("Juliet", 0, 255, 0),
        create_color("Tybalt", 0, 0, 255)
    };

    int num_colors = sizeof(colors) / sizeof(colors[0]);

    char* input_color_name;
    int input_red, input_green, input_blue;

    printf("Enter a color name: ");
    scanf("%s", input_color_name);

    Color* input_color = NULL;
    for (int i = 0; i < num_colors; i++) {
        if (strcmp(colors[i]->name, input_color_name) == 0) {
            input_color = colors[i];
            break;
        }
    }

    if (input_color == NULL) {
        printf("Invalid color name.\n");
        return 1;
    }

    printf("Color: %s\n", input_color->name);
    printf("Red: %d\n", input_color->red);
    printf("Green: %d\n", input_color->green);
    printf("Blue: %d\n", input_color->blue);

    return 0;
}