//FormAI DATASET v1.0 Category: HTML beautifier ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void handle_error(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

void beautify_html(const char *filename) {
    FILE *file_ptr = fopen(filename, "r");
    if (!file_ptr) handle_error("Error: Could not open file.");

    char line[MAX_LINE_LENGTH];
    int depth = 0;
    while (fgets(line, MAX_LINE_LENGTH, file_ptr)) {
        int len = strlen(line);
        if (len && line[len - 1] == '\n') line[len - 1] = '\0'; // remove newline character

        // remove leading and trailing whitespaces
        char *begin = line;
        while (*begin == ' ' || *begin == '\t') begin++;
        char *end = line + strlen(begin) - 1;
        while (*end == ' ' || *end == '\t') end--;
        *(end + 1) = '\0';

        if (*begin == '<') { // if this line is an opening or closing tag
            if (*end == '>') { // if this is a single line tag
                for (int i = 0; i < depth; i++) printf("\t");
                printf("%s\n", begin);
            } else if (*(end - 1) == '/') { // if this is a closing tag
                for (int i = 0; i < depth; i++) printf("\t");
                printf("%s\n", begin);
            } else { // if this is an opening tag
                for (int i = 0; i < depth; i++) printf("\t");
                printf("%s\n", begin);
                depth++;
            }
        } else if (*begin == '/') { // if this line is a closing tag
            depth--;
            for (int i = 0; i < depth; i++) printf("\t");
            printf("%s\n", begin);
        } else { // if this line contains content
            for (int i = 0; i < depth; i++) printf("\t");
            printf("%s\n", begin);
        }
    }
    fclose(file_ptr);
}

int main(int argc, char *argv[]) {
    if (argc != 2) handle_error("Usage: beautify_html <filename>");

    beautify_html(argv[1]);

    return 0;
}