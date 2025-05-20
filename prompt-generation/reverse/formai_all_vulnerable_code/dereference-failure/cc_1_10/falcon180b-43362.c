//Falcon-180B DATASET v1.0 Category: File handling ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *filename;
    FILE *file;
    int line_num;
} FileContext;

void open_file(FileContext *ctx, const char *filename) {
    ctx->filename = strdup(filename);
    ctx->file = fopen(filename, "r");
    if (ctx->file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    ctx->line_num = 1;
}

int read_line(FileContext *ctx, char *buffer, int max_length) {
    char ch;
    int i = 0;
    while ((ch = fgetc(ctx->file))!= EOF && i < max_length - 1) {
        if (ch == '\n') {
            ctx->line_num++;
        }
        buffer[i++] = ch;
    }
    buffer[i] = '\0';
    return i;
}

void close_file(FileContext *ctx) {
    fclose(ctx->file);
    free(ctx->filename);
    free(ctx);
}

int main() {
    FileContext ctx;
    char buffer[MAX_LINE_LENGTH];
    int max_length = MAX_LINE_LENGTH;

    open_file(&ctx, "example.txt");

    while ((read_line(&ctx, buffer, max_length)) > 0) {
        printf("%d: %s", ctx.line_num, buffer);
    }

    close_file(&ctx);

    return 0;
}