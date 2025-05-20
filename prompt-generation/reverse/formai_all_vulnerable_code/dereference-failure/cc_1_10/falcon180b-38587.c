//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LINE_NUMBER 10000

typedef struct {
    char *line;
    int line_number;
} Line;

typedef struct {
    Line *lines;
    int line_count;
} File;

void add_line(File *file, char *line) {
    if (file->line_count >= MAX_LINE_NUMBER) {
        printf("Error: Reached maximum line number.\n");
        exit(1);
    }

    Line *new_line = malloc(sizeof(Line));
    new_line->line = strdup(line);
    new_line->line_number = file->line_count;

    file->lines = realloc(file->lines, sizeof(Line) * ++file->line_count);
    file->lines[file->line_count - 1] = *new_line;
}

void print_file(File *file) {
    for (int i = 0; i < file->line_count; i++) {
        Line *line = &file->lines[i];
        printf("%d: %s", line->line_number, line->line);
    }
}

void beautify_html(File *file) {
    for (int i = 0; i < file->line_count; i++) {
        Line *line = &file->lines[i];

        char *tag_start = strstr(line->line, "<");
        char *tag_end = strstr(line->line, ">");

        if (tag_start && tag_end) {
            char *tag = malloc(tag_end - tag_start + 1);
            strncpy(tag, tag_start + 1, tag_end - tag_start - 2);
            tag[tag_end - tag_start - 3] = '\0';

            int tag_length = strlen(tag);
            int indent_spaces = 4 - tag_length % 4;

            char *new_line = malloc(tag_end - tag_start + indent_spaces + strlen(line->line) + 1);

            sprintf(new_line, "%s%*s%s", tag_start, indent_spaces, "", tag_end);

            free(line->line);
            line->line = new_line;
        }
    }
}

int main() {
    char buffer[MAX_LINE_LENGTH];
    File file = {0};

    while (fgets(buffer, MAX_LINE_LENGTH, stdin)!= NULL) {
        add_line(&file, buffer);
    }

    beautify_html(&file);

    print_file(&file);

    for (int i = 0; i < file.line_count; i++) {
        free(file.lines[i].line);
    }
    free(file.lines);

    return 0;
}