//FormAI DATASET v1.0 Category: HTML beautifier ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INDENT_SIZE 4

typedef struct {
    char *name;
    char *content;
} HTMLTag;

void indent(FILE* fp, int level) {
    for(int i = 0; i < level * INDENT_SIZE; i++) {
        putc(' ', fp);
    }
}

void beautify(char *input_file, char *output_file, int indent_style) {
    FILE *input_fp = fopen(input_file, "r");
    FILE *output_fp = fopen(output_file, "w");

    if(input_fp == NULL || output_fp == NULL) {
        printf("Error: Unable to open file(s)\n");
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int level = 0;

    while((read = getline(&line, &len, input_fp)) != -1) {
        int tokens = 0;
        char *token;
        char *tag_name = NULL;
        char *content = NULL;
        HTMLTag *tag = NULL;
        int i;

        token = strtok(line, "<>");
        while(token != NULL) {
            if(tokens == 0) {
                tag_name = strdup(token);
            } else if(tokens == 1) {
                content = strdup(token);
            } else {
                printf("Error: Invalid HTML tag format\n");
                exit(EXIT_FAILURE);
            }
            tokens++;
            token = strtok(NULL, "<>");
        }

        if(tag_name != NULL && content != NULL) {
            tag = malloc(sizeof(HTMLTag));
            tag->name = tag_name;
            tag->content = content;

            indent(output_fp, level);
            fprintf(output_fp, "<%s>\n", tag->name);
            level++;
            indent(output_fp, level);
            fprintf(output_fp, "%s\n", tag->content);
            level--;
            indent(output_fp, level);
            fprintf(output_fp, "</%s>\n", tag->name);

            free(tag_name);
            free(content);
            free(tag);
        } else if(tag_name != NULL) {
            if(strncmp(tag_name, "/html", 5) == 0) {
                level--;
            }
            indent(output_fp, level);
            fprintf(output_fp, "<%s>\n", tag_name);
            if(strncmp(tag_name, "html", 4) == 0) {
                level++;
            }
            free(tag_name);
        } else {
            fprintf(output_fp, "\n");
        }

        free(line);
        line = NULL;
        len = 0;
    }

    fclose(input_fp);
    fclose(output_fp);
}

int main(int argc, char *argv[]) {
    if(argc < 3) {
        printf("Usage: %s input_file output_file [indent_style (1-4)]\n", argv[0]);
        exit(EXIT_SUCCESS);
    }

    int indent_style = 1;
    if(argc == 4) {
        indent_style = atoi(argv[3]);
    }

    beautify(argv[1], argv[2], indent_style);

    return 0;
}