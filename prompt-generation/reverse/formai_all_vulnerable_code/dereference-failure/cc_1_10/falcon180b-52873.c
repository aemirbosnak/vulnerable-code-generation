//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

typedef struct {
    char **lines;
    int width;
    int height;
} TextArt;

void init_text_art(TextArt *art) {
    art->lines = calloc(MAX_HEIGHT, sizeof(char *));
    art->width = 0;
    art->height = 0;
}

void add_line(TextArt *art, char *line) {
    if (art->height >= MAX_HEIGHT) {
        printf("Error: Maximum height of %d lines reached.\n", MAX_HEIGHT);
        return;
    }

    if (strlen(line) > art->width) {
        art->width = strlen(line);
    }

    art->lines[art->height] = strdup(line);
    art->height++;
}

void print_text_art(TextArt *art) {
    for (int i = 0; i < art->height; i++) {
        printf("%s\n", art->lines[i]);
    }
}

void convert_to_ascii_art(TextArt *art) {
    for (int i = 0; i < art->height; i++) {
        char *line = art->lines[i];
        int j = 0;

        while (line[j]) {
            if (isalpha(line[j])) {
                line[j] = toupper(line[j]);
            }
            j++;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    TextArt art;
    init_text_art(&art);

    char *text = argv[1];
    char *line = strtok(text, "\n");

    while (line!= NULL) {
        add_line(&art, line);
        line = strtok(NULL, "\n");
    }

    printf("Original Text:\n");
    print_text_art(&art);

    convert_to_ascii_art(&art);

    printf("\nASCII Art:\n");
    print_text_art(&art);

    return 0;
}