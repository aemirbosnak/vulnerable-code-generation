//FormAI DATASET v1.0 Category: HTML beautifier ; Style: calm
#include <stdio.h>
#include <stdlib.h>

void beautify(char* filename);

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char* filename = (char*) malloc(sizeof(char) * (strlen(argv[1]) + 1));
    strcpy(filename, argv[1]);
    beautify(filename);
    printf("File %s has been beautified successfully.\n", filename);
    free(filename);
    return 0;
}

void beautify(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Cannot open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }
    int open_tags = 0;
    char ch, prev_ch = '\0';
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '<') {
            if (prev_ch == '/') {
                open_tags--; // closing tag
            }
            for (int i = 0; i < open_tags; ++i) {
                printf("  ");
            }
            printf("%c", ch);
            open_tags++; // opening tag
        } else if (ch == '>') {
            printf("%c\n", ch);
        } else if (ch == '\n') {
            continue; // ignore newline character
        } else {
            printf("%c", ch);
        }
        prev_ch = ch;
    }
    fclose(fp);
    if (open_tags != 0) {
        fprintf(stderr, "Error: Invalid HTML file.\n");
        exit(EXIT_FAILURE);
    }
}