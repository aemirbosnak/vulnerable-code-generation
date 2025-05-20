//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define ASCII_ART_FILE "ascii_art.txt"

typedef struct {
    char **lines;
    int num_lines;
    int max_width;
} AsciiArt;

void load_ascii_art(AsciiArt *art) {
    FILE *file = fopen(ASCII_ART_FILE, "r");
    if (file == NULL) {
        printf("Error: could not open %s\n", ASCII_ART_FILE);
        exit(1);
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    art->lines = malloc(MAX_HEIGHT * sizeof(char*));
    art->num_lines = 0;

    while ((read = getline(&line, &len, file))!= -1) {
        if (art->num_lines >= MAX_HEIGHT) {
            printf("Error: ascii art is too tall\n");
            exit(1);
        }

        char *trimmed_line = strndup(line, MAX_WIDTH);
        art->lines[art->num_lines++] = trimmed_line;
    }

    fclose(file);

    art->max_width = strlen(art->lines[0]);
}

void print_ascii_art(AsciiArt *art) {
    for (int i = 0; i < art->num_lines; i++) {
        printf("%s\n", art->lines[i]);
    }
}

void free_ascii_art(AsciiArt *art) {
    for (int i = 0; i < art->num_lines; i++) {
        free(art->lines[i]);
    }
    free(art->lines);
}

int main() {
    AsciiArt art;
    load_ascii_art(&art);
    printf("ASCII art:\n");
    print_ascii_art(&art);
    free_ascii_art(&art);
    return 0;
}