//FormAI DATASET v1.0 Category: HTML beautifier ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Change the following path to the path where your HTML file is located
#define FILE_PATH "C:/example.html"
#define OUTPUT_PATH "C:/beautified.html"

void beautify() {
    FILE *fp_in, *fp_out;

    char *buffer = NULL;
    size_t len = 0;
    ssize_t read;

    fp_in = fopen(FILE_PATH, "r");
    if (fp_in == NULL) {
        printf("Cannot open input file.");
        exit(EXIT_FAILURE);
    }

    fp_out = fopen(OUTPUT_PATH, "w");
    if (fp_out == NULL) {
        printf("Cannot open output file.");
        exit(EXIT_FAILURE);
    }

    int indent_level = 0;
    int in_tag = 0;

    while ((read = getline(&buffer, &len, fp_in)) != -1) {
        if (buffer[0] == '<' && buffer[1] != '/') {
            if (in_tag) {
                fprintf(fp_out, "\n");
                in_tag = 0;
            }
            for (int i = 0; i < indent_level; i++) {
                fprintf(fp_out, "\t");
            }
            fprintf(fp_out, "%s", buffer);
            indent_level++;
            in_tag = 1;
        } else if (buffer[0] == '<' && buffer[1] == '/') {
            if (in_tag) {
                fprintf(fp_out, "\n");
                in_tag = 0;
            }
            indent_level--;
            for (int i = 0; i < indent_level; i++) {
                fprintf(fp_out, "\t");
            }
            fprintf(fp_out, "%s", buffer);
        } else {
            if (in_tag) {
                fprintf(fp_out, "\n");
                in_tag = 0;
            }
            for (int i = 0; i < indent_level; i++) {
                fprintf(fp_out, "\t");
            }
            fprintf(fp_out, "%s", buffer);
        }
    }

    fclose(fp_in);
    fclose(fp_out);
    if (buffer) {
        free(buffer);
    }

    printf("File beautified successfully.");
}

int main() {
    beautify();
    return 0;
}