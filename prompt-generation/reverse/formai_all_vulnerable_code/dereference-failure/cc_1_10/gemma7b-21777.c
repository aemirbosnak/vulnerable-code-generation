//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 10

typedef struct Color
{
    char name[20];
    int r, g, b, a;
} Color;

Color colors[MAX_COLORS] =
{
    {"Red", 255, 0, 0, 255},
    {"Green", 0, 255, 0, 255},
    {"Blue", 0, 0, 255, 255},
    {"Yellow", 255, 255, 0, 255},
    {"Orange", 255, 165, 0, 255},
    {"Pink", 255, 192, 203, 255},
    {"Sky", 135, 206, 235, 255},
    {"Lavender", 138, 130, 238, 255},
    {"Maroon", 138, 0, 23, 255},
    {"Olive", 102, 102, 0, 255}
};

void convert_color(char *color_name, int *r, int *g, int *b, int *a)
{
    for (int i = 0; i < MAX_COLORS; i++)
    {
        if (strcmp(colors[i].name, color_name) == 0)
        {
            *r = colors[i].r;
            *g = colors[i].g;
            *b = colors[i].b;
            *a = colors[i].a;
            return;
        }
    }

    printf("Error: Color name not found.\n");
    exit(1);
}

int main()
{
    char *color_name;
    int r, g, b, a;

    printf("Enter color name: ");
    scanf("%s", &color_name);

    convert_color(color_name, &r, &g, &b, &a);

    printf("RGB values: (%d, %d, %d)\n", r, g, b);
    printf("Alpha value: %d\n", a);

    return 0;
}