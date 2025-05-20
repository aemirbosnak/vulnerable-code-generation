//MISTRAL-7B DATASET v1.0 Category: HTML beautifier ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LINE_LENGTH 1024

void print_html(const char *line) {
    int len = strlen(line);
    int i;

    // Remove comments and C-style comments from the line
    for (i = 0; i < len; i++) {
        if (line[i] == '/' && (line[i + 1] == '*' || line[i + 1] == '/')) {
            int comment_length = 0;
            if (line[i] == '/' && line[i + 1] == '*') {
                i++; // Skip '*'
                while (line[i] != '*' && line[i] != '\0') {
                    i++;
                    comment_length++;
                }
                if (line[i] == '\0') {
                    fprintf(stderr, "Error: Malformed HTML comment\n");
                    exit(1);
                }
                i++; // Skip '*'
            }
            memmove(&line[i - comment_length], &line[i], len - i);
            len -= comment_length;
            i -= comment_length;
        }
    }

    // Print the line with proper indentation and formatting
    if (strstr(line, "<") != NULL) {
        printf("%s\n", line);
    } else {
        printf("%s\n", line);
    }
}

void print_c(const char *line) {
    int len = strlen(line);
    int i;

    // Remove comments from the line
    for (i = 0; i < len; i++) {
        if (line[i] == '/' && line[i + 1] == '/') {
            int comment_length = 2;
            i += 2;
            while (line[i] != '\n' && line[i] != '\0') {
                i++;
                comment_length++;
            }
            memmove(&line[i - comment_length], &line[i], len - i);
            len -= comment_length;
            i -= comment_length;
        }
    }

    // Print the line with proper indentation
    for (i = 0; i < len && isspace(line[i]); i++) {
        putchar(' ');
    }
    printf("%s\n", &line[i]);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int i;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        if (strrchr(argv[1], '.') != NULL && strrchr(argv[1], '.')[1] == 'c') {
            print_c(line);
        } else {
            print_html(line);
        }
    }

    fclose(file);
    return 0;
}