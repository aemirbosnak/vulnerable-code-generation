//FormAI DATASET v1.0 Category: HTML beautifier ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

int main(int argc, char *argv[]) {
    FILE *in, *out;
    char line[MAXLINE];
    int i, spaces;
    int indent_level = 0;
    int indent_width = 2;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s input-file output-file\n", argv[0]);
        exit(1);
    }

    if ((in = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open %s for reading.\n", argv[1]);
        exit(1);
    }

    if ((out = fopen(argv[2], "w")) == NULL) {
        fprintf(stderr, "Can't open %s for writing.\n", argv[2]);
        exit(1);
    }

    while (fgets(line, MAXLINE, in) != NULL) {
        i = 0;
        spaces = 0;

        while (line[i] == ' ') {
            i++;
            spaces++;
        }

        if (line[i] == '<') {
            if (line[i+1] == '/') {
                indent_level--;
            }
            else {
                for (int j = 0; j < indent_level * indent_width; j++) {
                    fputc(' ', out);
                }
                indent_level++;
            }
        }

        for (int j = 0; j < spaces; j++) {
            fputc(' ', out);
        }

        fputs(line, out);
    }

    fclose(in);
    fclose(out);

    return 0;
}