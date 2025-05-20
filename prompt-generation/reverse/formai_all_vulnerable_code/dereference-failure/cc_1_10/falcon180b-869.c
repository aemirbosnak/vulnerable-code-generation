//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 4096

typedef struct {
    char *text;
    int length;
} Line;

Line *read_file(FILE *fp) {
    Line *lines = NULL;
    Line line = {.text = NULL,.length = 0};
    char *buffer = NULL;
    size_t buffer_size = 0;
    int c;

    while ((c = fgetc(fp))!= EOF) {
        if (line.length + 1 >= buffer_size) {
            buffer_size += MAX_LINE;
            buffer = realloc(buffer, buffer_size);
        }

        if (isspace(c)) {
            line.text = strndup(buffer, line.length);
            line.length = 0;
        } else {
            buffer[line.length++] = c;
        }
    }

    if (line.length) {
        line.text = strndup(buffer, line.length);
        lines = realloc(lines, sizeof(Line));
        lines[0] = line;
    }

    return lines;
}

void write_file(FILE *fp, Line *lines) {
    for (int i = 0; lines[i].text; i++) {
        fprintf(fp, "%s\n", lines[i].text);
    }
}

void indent(int level, FILE *fp) {
    for (int i = 0; i < level * 4; i++) {
        fputc(' ', fp);
    }
}

void beautify_html(FILE *input_file, FILE *output_file) {
    Line *lines = read_file(input_file);
    int level = 0;

    for (int i = 0; lines[i].text; i++) {
        if (strstr(lines[i].text, "<html")) {
            fprintf(output_file, "%s", lines[i].text);
            level++;
        } else if (strstr(lines[i].text, "</html")) {
            level--;
            fprintf(output_file, "%s", lines[i].text);
        } else if (strstr(lines[i].text, "<body")) {
            fprintf(output_file, "%s", lines[i].text);
            level++;
        } else if (strstr(lines[i].text, "</body")) {
            level--;
            fprintf(output_file, "%s", lines[i].text);
        } else if (strstr(lines[i].text, "<head")) {
            fprintf(output_file, "%s", lines[i].text);
            level++;
        } else if (strstr(lines[i].text, "</head")) {
            level--;
            fprintf(output_file, "%s", lines[i].text);
        } else if (strstr(lines[i].text, "<title")) {
            fprintf(output_file, "%s", lines[i].text);
            level++;
        } else if (strstr(lines[i].text, "</title")) {
            level--;
            fprintf(output_file, "%s", lines[i].text);
        } else if (level) {
            indent(level, output_file);
            fprintf(output_file, "%s", lines[i].text);
        } else {
            fprintf(output_file, "%s", lines[i].text);
        }

        fprintf(output_file, "\n");
    }

    free(lines);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        fprintf(stderr, "Error opening input file: %s\n", argv[1]);
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (!output_file) {
        fprintf(stderr, "Error opening output file: %s\n", argv[2]);
        fclose(input_file);
        return 1;
    }

    beautify_html(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}