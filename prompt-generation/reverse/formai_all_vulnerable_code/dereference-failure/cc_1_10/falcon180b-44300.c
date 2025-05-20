//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

typedef struct {
    char **lines;
    int num_lines;
} Text;

Text load_text(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    Text text = {NULL, 0};
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file))!= -1) {
        text.lines = realloc(text.lines, sizeof(char *) * ++text.num_lines);
        text.lines[text.num_lines - 1] = strdup(line);
    }

    free(line);
    fclose(file);

    return text;
}

void free_text(Text text) {
    for (int i = 0; i < text.num_lines; i++) {
        free(text.lines[i]);
    }
    free(text.lines);
}

void print_text(const Text text) {
    for (int i = 0; i < text.num_lines; i++) {
        printf("%s\n", text.lines[i]);
    }
}

void print_ascii_art(const Text text) {
    int max_width = 0;

    for (int i = 0; i < text.num_lines; i++) {
        int line_width = strlen(text.lines[i]);
        if (line_width > max_width) {
            max_width = line_width;
        }
    }

    for (int i = 0; i < text.num_lines; i++) {
        int line_width = strlen(text.lines[i]);
        int padding = (max_width - line_width) / 2;

        printf("%.*s", padding, "");
        printf("%s\n", text.lines[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Text text = load_text(argv[1]);
    print_text(text);
    print_ascii_art(text);

    free_text(text);

    return 0;
}