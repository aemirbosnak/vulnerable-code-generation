//Falcon-180B DATASET v1.0 Category: File handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *filename;
    FILE *file;
    int line_number;
    char line[MAX_LINE_LENGTH];
} FileContext;

int read_line(FileContext *context) {
    return fgets(context->line, MAX_LINE_LENGTH, context->file);
}

char *get_filename(FileContext *context) {
    return context->filename;
}

int get_line_number(FileContext *context) {
    return context->line_number;
}

char *get_line(FileContext *context) {
    return context->line;
}

void close_file(FileContext *context) {
    if (context->file!= NULL) {
        fclose(context->file);
        context->file = NULL;
    }
}

FileContext *open_file(char *filename) {
    FileContext *context = (FileContext *) malloc(sizeof(FileContext));
    context->filename = filename;
    context->file = fopen(filename, "r");
    if (context->file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }
    context->line_number = 1;
    return context;
}

void print_line(FileContext *context) {
    printf("%s:%d: %s", get_filename(context), get_line_number(context), get_line(context));
}

int main() {
    FileContext *context = open_file("example.txt");
    while (read_line(context)!= NULL) {
        print_line(context);
    }
    close_file(context);
    free(context);
    return 0;
}