//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct csv_reader {
    FILE *fp;
    char *line;
    size_t line_len;
    size_t line_num;
    char *delim;
};

struct csv_reader *csv_reader_new(FILE *fp, char *delim) {
    struct csv_reader *reader = malloc(sizeof(struct csv_reader));
    reader->fp = fp;
    reader->line = NULL;
    reader->line_len = 0;
    reader->line_num = 0;
    reader->delim = delim;
    return reader;
}

void csv_reader_free(struct csv_reader *reader) {
    free(reader->line);
    free(reader);
}

int csv_reader_next(struct csv_reader *reader) {
    if (reader->line) {
        free(reader->line);
        reader->line = NULL;
        reader->line_len = 0;
    }

    size_t len = 0;
    ssize_t res = getline(&reader->line, &len, reader->fp);
    if (res == -1) {
        return 0;
    }

    reader->line_len = res;
    reader->line_num++;
    return 1;
}

char *csv_reader_get(struct csv_reader *reader, int i) {
    char *start = reader->line;
    while (i--) {
        start = strchr(start, reader->delim[0]);
        if (!start) {
            return NULL;
        }
        start++;
    }
    char *end = strchr(start, reader->delim[0]);
    if (!end) {
        end = start + strlen(start);
    }
    char *ret = malloc(end - start + 1);
    strncpy(ret, start, end - start);
    ret[end - start] = '\0';
    return ret;
}

int main() {
    FILE *fp = fopen("data.csv", "r");
    if (!fp) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    struct csv_reader *reader = csv_reader_new(fp, ",");

    while (csv_reader_next(reader)) {
        for (int i = 0; ; i++) {
            char *field = csv_reader_get(reader, i);
            if (!field) {
                break;
            }
            printf("%s ", field);
            free(field);
        }
        printf("\n");
    }

    csv_reader_free(reader);
    fclose(fp);

    return EXIT_SUCCESS;
}