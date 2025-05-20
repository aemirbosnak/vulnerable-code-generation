//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 256

typedef struct {
    char *name;
    int value;
} Color;

Color colors[MAX_COLORS];
int num_colors = 0;

void add_color(char *name, int value) {
    if (num_colors >= MAX_COLORS) {
        printf("Error: Too many colors defined.\n");
        exit(1);
    }
    colors[num_colors].name = strdup(name);
    colors[num_colors].value = value;
    num_colors++;
}

int main() {
    add_color("red", 0xff0000);
    add_color("green", 0x00ff00);
    add_color("blue", 0x0000ff);
    add_color("yellow", 0xffff00);
    add_color("purple", 0x00ffff);
    add_color("orange", 0xffa500);
    add_color("black", 0x000000);
    add_color("white", 0xffffff);
    add_color("gray", 0x808080);
    add_color("silver", 0xc0c0c0);
    add_color("maroon", 0x800000);
    add_color("olive", 0x808000);
    add_color("navy", 0x000080);
    add_color("teal", 0x008080);
    add_color("lime", 0x00ff00);

    char input[256];
    printf("Enter a color name: ");
    scanf("%s", input);

    int i;
    for (i = 0; i < num_colors; i++) {
        if (strcmp(input, colors[i].name) == 0) {
            printf("Value: %06x\n", colors[i].value);
            return 0;
        }
    }

    printf("Error: Color not found.\n");
    return 1;
}