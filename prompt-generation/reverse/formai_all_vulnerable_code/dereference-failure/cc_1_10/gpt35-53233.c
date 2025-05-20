//FormAI DATASET v1.0 Category: HTML beautifier ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void write_indent(FILE* out, int level) {
    fputs("\n", out);

    for (int i = 0; i < level; i++) {
        fputs("\t", out);
    }
}

void beautifier_callback(FILE* out, char* tagName, char* attributes, int indentLevel) {
    write_indent(out, indentLevel);
    fprintf(out, "<%s", tagName);

    if (attributes) {
        fprintf(out, " %s", attributes);
    }

    fprintf(out, ">");
}

void beautify_html(char* input, char* output) {
    FILE* in = fopen(input, "r");
    FILE* out = fopen(output, "w");

    if (!in) {
        printf("Unable to open file %s.", input);
        return;
    }

    if (!out) {
        printf("Unable to create file %s.", output);
        return;
    }

    int indentLevel = 0;
    char line[1024];
    char* tagName = NULL;
    char* attributes = NULL;
    memset(line, 0, sizeof(line));

    while (fgets(line, sizeof(line), in)) {
        strtok(line, "\r\n");

        if (line[0] == '<') {
            attributes = strstr(line, " ");
            tagName = strtok(line + 1, " >");

            if (tagName[0] != '/') {
                beautifier_callback(out, tagName, attributes, indentLevel++);
            } else {
                beautifier_callback(out, tagName, NULL, --indentLevel);
            }
        } else {
            write_indent(out, indentLevel);
            fprintf(out, "%s", line);
        }
    }

    fclose(in);
    fclose(out);
}

int main() {
    beautify_html("input.html", "output.html");
    return 0;
}