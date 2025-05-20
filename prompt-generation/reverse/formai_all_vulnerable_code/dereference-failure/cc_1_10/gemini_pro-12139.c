//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_TOKENS 10

struct csv_reader {
    FILE *fp;
    char *line;
    size_t line_len;
    char *tokens[MAX_TOKENS];
    int num_tokens;
};

struct csv_reader *csv_reader_init(FILE *fp) {
    struct csv_reader *reader = malloc(sizeof(struct csv_reader));
    if (reader == NULL) {
        return NULL;
    }

    reader->fp = fp;
    reader->line = NULL;
    reader->line_len = 0;
    reader->num_tokens = 0;

    return reader;
}

void csv_reader_free(struct csv_reader *reader) {
    if (reader->line != NULL) {
        free(reader->line);
    }
    free(reader);
}

int csv_reader_next_line(struct csv_reader *reader) {
    if (reader->line != NULL) {
        free(reader->line);
    }

    reader->line = NULL;
    reader->line_len = 0;
    reader->num_tokens = 0;

    char *line = NULL;
    size_t line_len = 0;
    ssize_t nread = getline(&line, &line_len, reader->fp);
    if (nread == -1) {
        return -1;
    }

    reader->line = line;
    reader->line_len = line_len;

    return 0;
}

int csv_reader_tokenize_line(struct csv_reader *reader) {
    reader->num_tokens = 0;

    char *token = strtok(reader->line, ",");
    while (token != NULL) {
        reader->tokens[reader->num_tokens++] = token;
        token = strtok(NULL, ",");
    }

    return 0;
}

char *csv_reader_get_token(struct csv_reader *reader, int index) {
    if (index < 0 || index >= reader->num_tokens) {
        return NULL;
    }

    return reader->tokens[index];
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    struct csv_reader *reader = csv_reader_init(fp);
    if (reader == NULL) {
        fprintf(stderr, "csv_reader_init failed\n");
        return EXIT_FAILURE;
    }

    while (csv_reader_next_line(reader) == 0) {
        csv_reader_tokenize_line(reader);

        for (int i = 0; i < reader->num_tokens; i++) {
            printf("%s", csv_reader_get_token(reader, i));
            if (i < reader->num_tokens - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }

    csv_reader_free(reader);
    fclose(fp);

    return EXIT_SUCCESS;
}