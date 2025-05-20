//Falcon-180B DATASET v1.0 Category: File handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *filename;
    FILE *file;
    int line_count;
    char *line;
} FileContext;

void init_file_context(FileContext *ctx, const char *filename) {
    ctx->filename = strdup(filename);
    ctx->file = fopen(filename, "r");
    ctx->line_count = 0;
    ctx->line = malloc(MAX_LINE_SIZE);
}

void close_file_context(FileContext *ctx) {
    fclose(ctx->file);
    free(ctx->filename);
    free(ctx->line);
    free(ctx);
}

int read_line(FileContext *ctx) {
    char ch;
    int count = 0;

    while ((ch = fgetc(ctx->file))!= EOF) {
        if (count == MAX_LINE_SIZE - 1) {
            ctx->line = realloc(ctx->line, MAX_LINE_SIZE * 2);
        }
        ctx->line[count++] = ch;
    }

    ctx->line[count] = '\0';
    ctx->line_count++;

    return count;
}

int main() {
    FileContext ctx;

    init_file_context(&ctx, "example.txt");

    int line_count = 0;
    while (read_line(&ctx) > 0) {
        printf("Line %d: %s\n", line_count++, ctx.line);
    }

    close_file_context(&ctx);

    return 0;
}