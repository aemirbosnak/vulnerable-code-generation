//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    char **lines;
    int width;
    int height;
} TextArt;

void art_init(TextArt *art) {
    art->lines = (char **)malloc(MAX_HEIGHT * sizeof(char *));
    art->width = 0;
    art->height = 0;
}

void art_free(TextArt *art) {
    for (int i = 0; i < art->height; i++) {
        free(art->lines[i]);
    }
    free(art->lines);
}

void art_add_line(TextArt *art, const char *line) {
    char *copy = strdup(line);
    art->lines[art->height++] = copy;
    int len = strlen(copy);
    art->width = art->width > len? art->width : len;
}

void art_print(const TextArt *art) {
    for (int i = 0; i < art->height; i++) {
        printf("%s\n", art->lines[i]);
    }
}

void art_center(TextArt *art) {
    int pad = (art->width - strlen(art->lines[0])) / 2;
    for (int i = 0; i < art->height; i++) {
        int len = strlen(art->lines[i]);
        art->lines[i] = (char *)realloc(art->lines[i], len + pad + 1);
        memmove(art->lines[i] + pad, art->lines[i], len);
        art->lines[i][len + pad] = '\0';
    }
    art->width += pad * 2;
}

int main() {
    TextArt art;
    art_init(&art);

    art_add_line(&art, "ASCII Art Generator");
    art_add_line(&art, "By The Curious Programmer");

    art_center(&art);

    art_print(&art);

    art_free(&art);

    return 0;
}