//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char* text;
    int length;
} Line;

typedef struct {
    Line* lines;
    int num_lines;
} Text;

void add_line(Text* text, char* line) {
    Line* new_line = malloc(sizeof(Line));
    new_line->text = line;
    new_line->length = strlen(line);
    text->lines = realloc(text->lines, sizeof(Line) * (text->num_lines + 1));
    text->lines[text->num_lines] = *new_line;
    text->num_lines++;
}

void print_text(Text* text) {
    for (int i = 0; i < text->num_lines; i++) {
        printf("%s\n", text->lines[i].text);
    }
}

int main() {
    FILE* file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    Text text = {NULL, 0};

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        add_line(&text, line);
    }

    print_text(&text);

    return 0;
}