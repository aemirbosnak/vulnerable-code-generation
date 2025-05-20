//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LINE_COUNT 1000

struct line {
    char *text;
    int length;
};

struct ebook {
    int num_lines;
    struct line *lines;
};

struct ebook *ebook_create(void) {
    struct ebook *ebook = malloc(sizeof(struct ebook));
    ebook->num_lines = 0;
    ebook->lines = NULL;
    return ebook;
}

void ebook_destroy(struct ebook *ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        free(ebook->lines[i].text);
    }
    free(ebook->lines);
    free(ebook);
}

void ebook_add_line(struct ebook *ebook, char *text) {
    struct line *line = malloc(sizeof(struct line));
    line->text = strdup(text);
    line->length = strlen(text);
    ebook->num_lines++;
    ebook->lines = realloc(ebook->lines, ebook->num_lines * sizeof(struct line));
    ebook->lines[ebook->num_lines - 1] = *line;
    free(line);
}

void ebook_print(struct ebook *ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        printf("%s\n", ebook->lines[i].text);
    }
}

int main() {
    struct ebook *ebook = ebook_create();
    char buffer[MAX_LINE_LENGTH];
    int num_lines = 0;

    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(buffer, MAX_LINE_LENGTH, file)!= NULL) {
        if (num_lines >= MAX_LINE_COUNT) {
            printf("Maximum line count reached.\n");
            break;
        }
        ebook_add_line(ebook, buffer);
        num_lines++;
    }

    fclose(file);

    ebook_print(ebook);

    ebook_destroy(ebook);

    return 0;
}