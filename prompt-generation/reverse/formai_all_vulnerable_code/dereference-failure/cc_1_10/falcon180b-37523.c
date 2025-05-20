//Falcon-180B DATASET v1.0 Category: Error handling ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    int linenum = 0;
    int errors = 0;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return 1;
    }

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        linenum++;
        if (line[strlen(line) - 1]!= '\n') {
            fprintf(stderr, "Line %d is too long\n", linenum);
            errors++;
        }
    }

    if (ferror(fp)) {
        fprintf(stderr, "Error reading file\n");
        errors++;
    }

    if (fclose(fp)!= 0) {
        fprintf(stderr, "Error closing file\n");
        errors++;
    }

    if (errors == 0) {
        printf("No errors found in file\n");
    } else {
        printf("Found %d errors in file\n", errors);
    }

    return 0;
}