//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1000

typedef struct {
    char *text;
    int length;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} Ebook;

Ebook *ebook_create() {
    Ebook *ebook = malloc(sizeof(Ebook));
    assert(ebook!= NULL);
    ebook->lines = NULL;
    ebook->num_lines = 0;
    return ebook;
}

void ebook_destroy(Ebook *ebook) {
    int i;
    for (i = 0; i < ebook->num_lines; i++) {
        free(ebook->lines[i].text);
    }
    free(ebook->lines);
    free(ebook);
}

void ebook_add_line(Ebook *ebook, const char *line) {
    Line *new_line = malloc(sizeof(Line));
    assert(new_line!= NULL);
    new_line->text = strdup(line);
    new_line->length = strlen(line);
    ebook->lines = realloc(ebook->lines, sizeof(Line) * (ebook->num_lines + 1));
    assert(ebook->lines!= NULL);
    ebook->lines[ebook->num_lines] = *new_line;
    ebook->num_lines++;
}

void ebook_print(const Ebook *ebook) {
    int i;
    for (i = 0; i < ebook->num_lines; i++) {
        printf("%s\n", ebook->lines[i].text);
    }
}

int main() {
    Ebook *ebook = ebook_create();
    ebook_add_line(ebook, "Hello, world!");
    ebook_add_line(ebook, "This is a test.");
    ebook_print(ebook);
    ebook_destroy(ebook);
    return 0;
}