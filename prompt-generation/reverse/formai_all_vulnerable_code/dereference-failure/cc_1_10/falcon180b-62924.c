//Falcon-180B DATASET v1.0 Category: Error handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_NUM_LINES 100

struct line {
    char *text;
    int length;
};

struct line *lines = NULL;
int num_lines = 0;

void print_lines() {
    int i;
    for (i = 0; i < num_lines; i++) {
        printf("%s\n", lines[i].text);
    }
}

void free_lines() {
    int i;
    for (i = 0; i < num_lines; i++) {
        free(lines[i].text);
    }
    free(lines);
    lines = NULL;
    num_lines = 0;
}

int read_file(const char *filename) {
    FILE *fp;
    char line[MAX_LINE_LEN];
    int line_len;
    int ret = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        ret = 1;
        goto cleanup;
    }

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        line_len = strlen(line);
        if (line_len >= MAX_LINE_LEN) {
            printf("Error: line too long in file %s\n", filename);
            ret = 1;
            goto cleanup;
        }
        if (num_lines >= MAX_NUM_LINES) {
            printf("Error: too many lines in file %s\n", filename);
            ret = 1;
            goto cleanup;
        }
        lines = realloc(lines, sizeof(struct line) * (num_lines + 1));
        if (lines == NULL) {
            printf("Error: out of memory\n");
            ret = 1;
            goto cleanup;
        }
        lines[num_lines].text = strdup(line);
        if (lines[num_lines].text == NULL) {
            printf("Error: out of memory\n");
            ret = 1;
            goto cleanup;
        }
        lines[num_lines].length = line_len;
        num_lines++;
    }

    ret = 0;

cleanup:
    if (fp!= NULL) {
        fclose(fp);
    }
    if (ret!= 0) {
        free_lines();
    }
    return ret;
}

int main(int argc, char *argv[]) {
    int i;

    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    for (i = 1; i < argc; i++) {
        int ret = read_file(argv[i]);
        if (ret!= 0) {
            return ret;
        }
    }

    print_lines();

    return 0;
}