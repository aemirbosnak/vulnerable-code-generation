//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 10000

typedef struct {
    char* text;
    int length;
} Line;

typedef struct {
    Line* lines;
    int num_lines;
} Ebook;

Ebook* create_ebook() {
    Ebook* ebook = (Ebook*) malloc(sizeof(Ebook));
    ebook->lines = (Line*) malloc(MAX_NUM_LINES * sizeof(Line));
    ebook->num_lines = 0;
    return ebook;
}

void destroy_ebook(Ebook* ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        free(ebook->lines[i].text);
    }
    free(ebook->lines);
    free(ebook);
}

void add_line(Ebook* ebook, char* text) {
    if (ebook->num_lines >= MAX_NUM_LINES) {
        printf("Error: Ebook is full.\n");
        return;
    }
    Line line = {text, strlen(text)};
    ebook->lines[ebook->num_lines++] = line;
}

void print_ebook(Ebook* ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        printf("%s\n", ebook->lines[i].text);
    }
}

int main() {
    Ebook* ebook = create_ebook();
    char text[MAX_LINE_LENGTH];

    while (fgets(text, MAX_LINE_LENGTH, stdin)!= NULL) {
        int length = strlen(text);
        if (length > 0 && text[length - 1] == '\n') {
            text[--length] = '\0';
        }
        add_line(ebook, text);
    }

    print_ebook(ebook);
    destroy_ebook(ebook);

    return 0;
}