//FormAI DATASET v1.0 Category: HTML beautifier ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

void beautify(char *filename);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];

    beautify(filename);

    printf("HTML beautification complete!\n");

    return 0;
}

void beautify(char *filename) {
    FILE *fp = fopen(filename, "r");

    if (!fp) {
        printf("Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    FILE *fpout = fopen("output.html", "w");

    if (!fpout) {
        printf("Error creating output file\n");
        exit(EXIT_FAILURE);
    }

    char c, prev = '\n';
    int indent = 0;

    while ((c = fgetc(fp)) != EOF) {
        if (c == '<') {
            if (prev == '\n') {
                for (int i = 0; i < indent; i++) {
                    fputc('\t', fpout);
                }
            }
            fputc(c, fpout);
            if (prev != '\n') {
                fputc('\n', fpout);
            }
            indent++;
        } else if (c == '>') {
            fputc(c, fpout);
            fputc('\n', fpout);
            indent--;
            for (int i = 0; i < indent; i++) {
                fputc('\t', fpout);
            }
        } else {
            fputc(c, fpout);
        }
        prev = c;
    }

    fclose(fp);
    fclose(fpout);

    remove(filename);
    rename("output.html", filename);
}