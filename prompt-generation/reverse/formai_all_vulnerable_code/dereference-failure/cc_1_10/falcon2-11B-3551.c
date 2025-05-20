//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLORS 100
#define MAX_LENGTH 10

typedef struct {
    char name[MAX_LENGTH];
    int r, g, b;
} Color;

typedef struct {
    Color colors[MAX_COLORS];
    int num_colors;
} ColorDictionary;

ColorDictionary* create_color_dictionary() {
    ColorDictionary* dictionary = (ColorDictionary*) malloc(sizeof(ColorDictionary));
    dictionary->num_colors = 0;
    return dictionary;
}

void add_color(ColorDictionary* dictionary, const char* name, int r, int g, int b) {
    if (dictionary->num_colors == MAX_COLORS) {
        fprintf(stderr, "Error: Color dictionary is full\n");
        return;
    }

    Color* new_color = &(dictionary->colors[dictionary->num_colors]);
    strcpy(new_color->name, name);
    new_color->r = r;
    new_color->g = g;
    new_color->b = b;

    dictionary->num_colors++;
}

void print_color_dictionary(ColorDictionary* dictionary) {
    printf("Color dictionary:\n");
    for (int i = 0; i < dictionary->num_colors; i++) {
        printf("Color: %s (r=%d, g=%d, b=%d)\n", dictionary->colors[i].name, dictionary->colors[i].r, dictionary->colors[i].g, dictionary->colors[i].b);
    }
}

int main() {
    ColorDictionary* dictionary = create_color_dictionary();

    add_color(dictionary, "Red", 255, 0, 0);
    add_color(dictionary, "Blue", 0, 0, 255);
    add_color(dictionary, "Green", 0, 255, 0);
    add_color(dictionary, "Yellow", 255, 255, 0);

    print_color_dictionary(dictionary);

    return 0;
}