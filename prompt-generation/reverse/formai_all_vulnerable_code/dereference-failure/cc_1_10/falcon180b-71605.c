//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_LEN 1024
#define MAX_LINE_NUM 1000

typedef struct {
    char *text;
    int line_num;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
    FILE *fp;
} File;

File *open_file(const char *filename) {
    File *file = malloc(sizeof(File));
    file->lines = NULL;
    file->num_lines = 0;
    file->fp = fopen(filename, "r");
    if (file->fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    return file;
}

void close_file(File *file) {
    fclose(file->fp);
    free(file);
}

void add_line(File *file, const char *text, int line_num) {
    Line *line = malloc(sizeof(Line));
    line->text = strdup(text);
    line->line_num = line_num;
    file->lines = realloc(file->lines, sizeof(Line) * (file->num_lines + 1));
    file->lines[file->num_lines++] = *line;
    free(line);
}

void print_file(File *file) {
    for (int i = 0; i < file->num_lines; i++) {
        printf("%d: %s\n", file->lines[i].line_num, file->lines[i].text);
    }
}

int is_number(const char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    File *file = open_file("example.txt");
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, file->fp)!= NULL) {
        int line_num = file->num_lines;
        char *text = strdup(line);
        char *token = strtok(text, " ");
        while (token!= NULL) {
            if (is_number(token)) {
                int num = atoi(token);
                if (num > 0) {
                    add_line(file, text, line_num);
                }
            }
            token = strtok(NULL, " ");
        }
        free(text);
    }
    print_file(file);
    close_file(file);
    return 0;
}