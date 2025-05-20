//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 80
#define MAX_ROWS 25

struct ascii_art {
    char text[MAX_ROWS][MAX_COLS];
    int num_rows;
    int num_cols;
};

struct ascii_art *create_ascii_art(const char *text) {
    struct ascii_art *art = malloc(sizeof(struct ascii_art));
    if (art == NULL) {
        return NULL;
    }

    // Split the text into lines
    char *line = strtok((char *)text, "\n");
    int num_rows = 0;
    while (line != NULL) {
        strcpy(art->text[num_rows], line);
        num_rows++;
        line = strtok(NULL, "\n");
    }

    // Set the number of rows and columns
    art->num_rows = num_rows;
    art->num_cols = strlen(art->text[0]);

    return art;
}

void free_ascii_art(struct ascii_art *art) {
    free(art);
}

void print_ascii_art(const struct ascii_art *art) {
    for (int i = 0; i < art->num_rows; i++) {
        printf("%s\n", art->text[i]);
    }
}

int main(void) {
    // Create the ASCII art
    struct ascii_art *art = create_ascii_art("Hello, world!");

    // Print the ASCII art
    print_ascii_art(art);

    // Free the ASCII art
    free_ascii_art(art);

    return 0;
}