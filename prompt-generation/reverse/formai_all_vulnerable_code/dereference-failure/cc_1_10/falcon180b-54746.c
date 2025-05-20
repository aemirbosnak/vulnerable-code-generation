//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *hex;
    char *rgb;
    char *name;
} color_t;

color_t colors[] = {
    {"#000000", "rgb(0,0,0)", "black"},
    {"#ffffff", "rgb(255,255,255)", "white"},
    {"#ff0000", "rgb(255,0,0)", "red"},
    {"#00ff00", "rgb(0,255,0)", "green"},
    {"#0000ff", "rgb(0,0,255)", "blue"},
    {"#ffff00", "rgb(255,255,0)", "yellow"},
    {"#00ffff", "rgb(0,255,255)", "cyan"},
    {"#ff00ff", "rgb(255,0,255)", "magenta"},
    {"#000000", "rgb(0,0,0)", "black"},
    {"#888888", "rgb(136,136,136)", "gray"},
    {"#ff8888", "rgb(255,136,136)", "red"},
    {"#88ff88", "rgb(136,255,136)", "green"},
    {"#8888ff", "rgb(136,136,255)", "blue"},
    {"#ffff88", "rgb(255,255,136)", "yellow"},
    {"#88ffff", "rgb(136,255,255)", "cyan"},
    {"#ff88ff", "rgb(255,136,255)", "magenta"}
};

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <hex/rgb/name>\n", argv[0]);
        return 1;
    }

    char *input = argv[1];
    color_t *color;

    for (int i = 0; i < sizeof(colors)/sizeof(color_t); i++) {
        if (!strcmp(input, colors[i].hex) ||!strcmp(input, colors[i].rgb) ||!strcmp(input, colors[i].name)) {
            color = &colors[i];
            break;
        }
    }

    if (!color) {
        printf("Invalid color\n");
        return 1;
    }

    printf("HEX: %s\n", color->hex);
    printf("RGB: %s\n", color->rgb);
    printf("Name: %s\n", color->name);

    return 0;
}