//Falcon-180B DATASET v1.0 Category: Text processing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LINES 1000

typedef struct {
    char *text;
    int length;
} Line;

Line lines[MAX_LINES];
int num_lines = 0;

void add_line(char *text) {
    if (num_lines >= MAX_LINES) {
        printf("Error: Maximum number of lines reached.\n");
        return;
    }

    Line *line = &lines[num_lines];
    line->text = malloc(strlen(text) + 1);
    strcpy(line->text, text);
    line->length = strlen(text);

    num_lines++;
}

void print_lines() {
    for (int i = 0; i < num_lines; i++) {
        printf("%d: %s\n", i+1, lines[i].text);
    }
}

int main() {
    char text[MAX_LINE_LENGTH] = "";
    char *line = NULL;
    size_t len = 0;

    while ((line = fgets(text, MAX_LINE_LENGTH, stdin))!= NULL) {
        len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
            len--;
        }

        add_line(line);
    }

    printf("Number of lines: %d\n", num_lines);
    print_lines();

    for (int i = 0; i < num_lines; i++) {
        free(lines[i].text);
    }

    return 0;
}