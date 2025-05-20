//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1000000

struct Line {
    char *text;
    int length;
};

struct Ebook {
    struct Line *lines;
    int num_lines;
};

void init_ebook(struct Ebook *ebook) {
    ebook->lines = NULL;
    ebook->num_lines = 0;
}

void destroy_ebook(struct Ebook *ebook) {
    int i;
    for (i = 0; i < ebook->num_lines; i++) {
        free(ebook->lines[i].text);
    }
    free(ebook->lines);
    ebook->lines = NULL;
    ebook->num_lines = 0;
}

void add_line(struct Ebook *ebook, const char *text) {
    struct Line *new_line = malloc(sizeof(struct Line));
    new_line->text = strdup(text);
    new_line->length = strlen(text);
    ebook->lines = realloc(ebook->lines, sizeof(struct Line) * (ebook->num_lines + 1));
    ebook->lines[ebook->num_lines] = *new_line;
    ebook->num_lines++;
}

void print_ebook(const struct Ebook *ebook) {
    int i;
    for (i = 0; i < ebook->num_lines; i++) {
        printf("%s\n", ebook->lines[i].text);
    }
}

int main() {
    FILE *file;
    char buffer[MAX_LINE_LENGTH];
    struct Ebook ebook;

    init_ebook(&ebook);

    if ((file = fopen("example.txt", "r")) == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(buffer, MAX_LINE_LENGTH, file)!= NULL) {
        add_line(&ebook, buffer);
    }

    fclose(file);

    print_ebook(&ebook);

    destroy_ebook(&ebook);

    return 0;
}