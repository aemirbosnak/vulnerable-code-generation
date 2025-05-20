//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_NUM_PAGES 100

typedef struct {
    int page_number;
    char line[MAX_LINE_LENGTH];
} Page;

void read_line(FILE *file, int page_number, Page *pages) {
    char line[MAX_LINE_LENGTH];
    int length = 0;
    int ch;

    pages[page_number].page_number = page_number + 1;

    while (length < MAX_LINE_LENGTH - 1 && (ch = fgetc(file)) != EOF && ch != '\n') {
        line[length++] = ch;
    }

    if (ch == '\n') {
        line[length++] = ch;
        line[length++] = '\0';

        printf("Page %d:\n%s\n", pages[page_number].page_number, line);

        if (page_number < MAX_NUM_PAGES - 1) {
            read_line(file, page_number + 1, pages);
        }
    } else {
        fputc(ch, stderr);
        fprintf(stderr, "Error: invalid character '%c' at line %d\n", ch, page_number + 1);
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error: could not open file");
        exit(1);
    }

    Page pages[MAX_NUM_PAGES];
    read_line(file, 0, pages);

    fclose(file);

    return 0;
}