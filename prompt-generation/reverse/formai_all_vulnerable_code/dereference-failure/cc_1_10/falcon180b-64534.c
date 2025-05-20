//Falcon-180B DATASET v1.0 Category: File handling ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *filename;
    FILE *file;
    int line_number;
} FileContext;

void open_file(FileContext *ctx, const char *filename) {
    ctx->filename = strdup(filename);
    ctx->file = fopen(filename, "r");
    if (ctx->file == NULL) {
        printf("Error opening file '%s'\n", filename);
        exit(1);
    }
    ctx->line_number = 1;
}

char *read_line(FileContext *ctx) {
    char *line = NULL;
    size_t capacity = 0;
    int c;

    ctx->line_number++;

    line = malloc(MAX_LINE_LENGTH);
    if (line == NULL) {
        printf("Error allocating memory for line\n");
        exit(1);
    }

    capacity = MAX_LINE_LENGTH;
    while ((c = fgetc(ctx->file))!= EOF && capacity > 0) {
        if (c == '\n') {
            line[--capacity] = '\0';
            break;
        } else {
            line[capacity - 1] = c;
            capacity--;
        }
    }

    if (ferror(ctx->file)) {
        printf("Error reading line from file\n");
        exit(1);
    }

    return line;
}

void close_file(FileContext *ctx) {
    if (ctx->file!= NULL) {
        fclose(ctx->file);
        ctx->file = NULL;
    }
    free(ctx->filename);
    ctx->filename = NULL;
}

int main() {
    FileContext ctx;
    char *line;

    open_file(&ctx, "example.txt");

    while ((line = read_line(&ctx))!= NULL) {
        printf("Line %d: %s\n", ctx.line_number, line);
    }

    close_file(&ctx);

    return 0;
}