//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CSV_COLUMNS 1024
#define MAX_CSV_LINE_LENGTH 4096

char *csv_file;
char **columns;
int num_columns;

void die(const char *msg) {
    perror(msg);
    exit(1);
}

void consume_whitespace(FILE *fp) {
    int c;
    while ((c = fgetc(fp)) != EOF) {
        if (!isspace(c)) break;
    }
}

void eat_newline(FILE *fp) {
    int c;
    do {
        c = fgetc(fp);
    } while (c != '\n' && c != EOF);

    if (c == EOF) die("Premature end of file");
}

void parse_csv_line(FILE *fp) {
    int i, len, cap, alloc;
    char *token = NULL;
    char **tokens = NULL;

    consume_whitespace(fp);

    if (feof(fp)) {
        num_columns = 0;
        free(columns);
        return;
    }

    if ((token = malloc(sizeof(char) * 2)) == NULL) die("Out of memory");

    len = 0;
    cap = 1;
    alloc = 1;

    while (1) {
        tokens = realloc(tokens, sizeof(char *) * (alloc + 1));
        if (tokens == NULL) die("Out of memory");

        tokens[alloc] = token;

        token[len++] = fgetc(fp);

        if (token[len] == ',') {
            if (len > 0) token[len++] = '\0';
            eat_newline(fp);
            consume_whitespace(fp);

            if (len > cap) {
                cap *= 2;
                token = realloc(token, len + cap + 1);
                if (token == NULL) die("Out of memory");
            }

            alloc++;

            if (len > MAX_CSV_LINE_LENGTH) die("Line too long");

            continue;
        }

        if (token[len] == '\0' || feof(fp)) {
            if (len > cap) {
                cap *= 2;
                token = realloc(token, len + cap + 1);
                if (token == NULL) die("Out of memory");
            }

            token[len] = '\0';
            eat_newline(fp);
            consume_whitespace(fp);

            if (num_columns > MAX_CSV_COLUMNS) die("Too many columns");

            columns = realloc(columns, sizeof(char *) * (num_columns + 1));
            if (columns == NULL) die("Out of memory");

            columns[num_columns++] = tokens[0];

            for (i = 1; i <= alloc; i++) free(tokens[i]);
            free(tokens);

            if (len > MAX_CSV_LINE_LENGTH) die("Line too long");

            break;
        }
    }
}

int main(int argc, char **argv) {
    FILE *fp;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv file>\n", argv[0]);
        exit(1);
    }

    csv_file = argv[1];

    if ((fp = fopen(csv_file, "r")) == NULL) die("Could not open file");

    parse_csv_line(fp);

    for (int i = 0; i < num_columns; i++) printf("%s,", columns[i]);
    printf("\b\n");

    for (int i = 0; i < num_columns; i++) free(columns[i]);
    free(columns);

    fclose(fp);

    return 0;
}