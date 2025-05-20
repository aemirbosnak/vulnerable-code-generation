//MISTRAL-7B DATASET v1.0 Category: HTML beautifier ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 256
#define TAB_SIZE 4

void indent(int *level) {
    for (int i = 0; i < *level * TAB_SIZE; i++) {
        putchar('\t');
    }
}

void process_tag(char *tag, int *level, char **attr) {
    if (tag[0] == '/' && tag[1] == '/') { // closing tag
        indent(level);
        puts(tag + 2);
        if (*attr) {
            free(*attr);
        }
        if (*level > 0) {
            (*level)--;
        }
        return;
    }

    if (tag[0] != '<') { // plain text
        indent(level);
        fputs(tag, stdout);
        return;
    }

    // opening tag
    indent(level);
    puts(tag);
    *level = *level + 1;

    // parse attributes
    char *token = strtok(*(attr = malloc(1024)), "=");
    while (token != NULL) {
        indent(level + 1);
        printf(" %s=\"%s\"", token, token + 1);
        token = strtok(NULL, ">");
    }

    if (tag[strlen(tag) - 1] != '>') { // self-closing tag
        puts("/>");
    }
}

int main(int argc, char *argv[]) {
    char *line = malloc(MAX_LINE);
    int level = 0;
    char *attr = NULL;

    while (fgets(line, MAX_LINE, stdin) != NULL) {
        char tag[1024];
        int i = 0, j = 0;

        // remove leading whitespace
        while (isspace(line[i])) {
            i++;
        }

        if (line[i] == '\'' || line[i] == '\""') { // skip single/double quote
            i++;
            while (line[i] != '\'' && line[i] != '\""') {
                i++;
            }
            i++;
            continue;
        }

        j = i;
        while (line[j] != ' ' && line[j] != '\t' && line[j] != '<') {
            j++;
        }

        if (j > i) { // copy tag name
            strncpy(tag, line + i, j - i);
            tag[j - i] = '\0';
            process_tag(tag, &level, &attr);
        }

        // copy remaining text
        if (j < (int)strlen(line)) {
            fwrite(line + j, 1, strlen(line) - j, stdout);
        }
    }

    free(line);
    if (attr) {
        free(attr);
    }

    return 0;
}