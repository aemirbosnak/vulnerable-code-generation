//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LEN 256

typedef struct {
    char *filename;
    FILE *fp;
    int linenumber;
} Ebook;

void ebook_init(Ebook *ebook) {
    ebook->filename = NULL;
    ebook->fp = NULL;
    ebook->linenumber = 0;
}

void ebook_open(Ebook *ebook, char *filename) {
    ebook->filename = filename;
    ebook->fp = fopen(filename, "r");
    if (ebook->fp == NULL) {
        printf("Error opening ebook file: %s\n", filename);
        exit(1);
    }
}

void ebook_close(Ebook *ebook) {
    if (ebook->fp!= NULL) {
        fclose(ebook->fp);
        ebook->fp = NULL;
    }
}

int ebook_linenumber(Ebook *ebook) {
    return ebook->linenumber;
}

char *ebook_readline(Ebook *ebook) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (ebook->fp == NULL) {
        return NULL;
    }

    if (ebook->linenumber == 0) {
        char *header = NULL;
        ssize_t header_len = getline(&header, &len, ebook->fp);
        if (header_len <= 0) {
            ebook->linenumber = 0;
            free(header);
            return NULL;
        }
        ebook->linenumber++;
        free(header);
    }

    line = malloc(MAX_LINE_LEN);
    if (line == NULL) {
        printf("Error allocating memory for ebook line\n");
        exit(1);
    }

    read = getline(line, &len, ebook->fp);
    if (read <= 0) {
        ebook->linenumber = 0;
        free(line);
        return NULL;
    }

    ebook->linenumber++;
    line[read - 1] = '\0';

    return line;
}

int main(int argc, char *argv[]) {
    Ebook ebook;
    char *filename;
    char *line;

    if (argc!= 2) {
        printf("Usage: %s <ebook_file>\n", argv[0]);
        return 1;
    }

    filename = argv[1];
    ebook_init(&ebook);
    ebook_open(&ebook, filename);

    while ((line = ebook_readline(&ebook))!= NULL) {
        printf("%d: %s", ebook_linenumber(&ebook), line);
        free(line);
    }

    ebook_close(&ebook);
    return 0;
}