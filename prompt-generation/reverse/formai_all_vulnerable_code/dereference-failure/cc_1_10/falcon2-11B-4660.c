//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct {
    char *name;
    char *value;
} Line;

int read_line(FILE *fp, Line *line) {
    char *buffer = NULL;
    int nread;
    char *ptr;

    nread = fread(buffer, sizeof(char), 1024, fp);
    if (nread < 0) {
        fprintf(stderr, "Error reading line: %s\n", strerror(errno));
        exit(1);
    }

    ptr = strchr(buffer, '\n');
    if (ptr == NULL) {
        fprintf(stderr, "No newline found\n");
        exit(1);
    }

    *ptr = '\0';
    line->name = strtok(buffer, ",");
    line->value = strtok(NULL, ",");

    return 0;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    Line line;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(1);
    }

    while (read_line(fp, &line) == 0) {
        printf("%s,%s\n", line.name, line.value);
    }

    fclose(fp);
    return 0;
}