//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

typedef struct csv_reader_s {
    FILE *fp;
    char buf[BUF_SIZE];
    char *ptr;
    int len;
} csv_reader_t;

csv_reader_t *csv_reader_new(FILE *fp)
{
    csv_reader_t *reader = malloc(sizeof(csv_reader_t));
    if (!reader) {
        return NULL;
    }

    reader->fp = fp;
    reader->ptr = reader->buf;
    reader->len = 0;

    return reader;
}

void csv_reader_free(csv_reader_t *reader)
{
    if (reader) {
        fclose(reader->fp);
        free(reader);
    }
}

int csv_reader_next(csv_reader_t *reader, char **fields, int *num_fields)
{
    int i = 0;
    char *p, *q;

    if (reader->len == 0) {
        reader->len = fread(reader->buf, 1, BUF_SIZE, reader->fp);
        if (reader->len == 0) {
            return 0;
        }
        reader->ptr = reader->buf;
    }

    p = reader->ptr;
    while (i < *num_fields) {
        while (*p == ' ' || *p == '\t') {
            p++;
        }
        if (*p == '\n' || *p == '\0') {
            break;
        }
        q = p;
        while (*q != ',' && *q != '\n' && *q != '\0') {
            q++;
        }
        *fields[i++] = p;
        *q = '\0';
        p = q + 1;
    }

    reader->ptr = p;
    reader->len -= (p - reader->buf);

    *num_fields = i;

    return 1;
}

int main(int argc, char **argv)
{
    FILE *fp;
    csv_reader_t *reader;
    char *fields[10];
    int num_fields;
    int i;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <csv file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    reader = csv_reader_new(fp);
    if (!reader) {
        fprintf(stderr, "csv_reader_new\n");
        return EXIT_FAILURE;
    }

    num_fields = sizeof(fields) / sizeof(fields[0]);

    while (csv_reader_next(reader, fields, &num_fields)) {
        for (i = 0; i < num_fields; i++) {
            printf("%s ", fields[i]);
        }
        printf("\n");
    }

    csv_reader_free(reader);

    return EXIT_SUCCESS;
}