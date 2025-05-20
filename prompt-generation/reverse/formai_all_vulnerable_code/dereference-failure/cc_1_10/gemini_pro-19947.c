//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} ascii_art;

ascii_art *create_ascii_art(char *str) {
    ascii_art *art = malloc(sizeof(ascii_art));
    art->num_rows = 0;
    art->num_cols = 0;

    char *line = strtok(str, "\n");
    while (line != NULL) {
        art->num_rows++;
        art->num_cols = fmax(art->num_cols, strlen(line));
        line = strtok(NULL, "\n");
    }

    art->data = malloc(sizeof(char *) * art->num_rows);
    for (int i = 0; i < art->num_rows; i++) {
        art->data[i] = malloc(sizeof(char) * art->num_cols + 1);
        memset(art->data[i], ' ', art->num_cols);
        art->data[i][art->num_cols] = '\0';
    }

    line = strtok(str, "\n");
    int row = 0;
    while (line != NULL) {
        strcpy(art->data[row], line);
        row++;
        line = strtok(NULL, "\n");
    }

    return art;
}

void print_ascii_art(ascii_art *art) {
    for (int i = 0; i < art->num_rows; i++) {
        printf("%s\n", art->data[i]);
    }
}

void destroy_ascii_art(ascii_art *art) {
    for (int i = 0; i < art->num_rows; i++) {
        free(art->data[i]);
    }
    free(art->data);
    free(art);
}

int main() {
    char *str = "This is a test string.\nIt will be converted to ASCII art.";
    ascii_art *art = create_ascii_art(str);
    print_ascii_art(art);
    destroy_ascii_art(art);
    return 0;
}