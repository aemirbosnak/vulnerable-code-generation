//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define PAGE_SIZE 50

typedef struct Page {
    int start_line;
    int end_line;
    char title[100];
} Page;

Page pages[MAX_LINES];
int current_page = 0;
int lines_on_page = 0;

void display_page(int page_num) {
    int start_line = pages[page_num].start_line;
    int end_line = pages[page_num].start_line + lines_on_page - 1;

    printf("\nPage %d:\n", page_num + 1);
    for (int i = start_line; i <= end_line; i++) {
        printf("%d: %s", i, pages[page_num].title + i - start_line);
    }
}

void load_file(char *filename) {
    FILE *file = fopen(filename, "r");
    int line_num = 0;
    char line[100];

    while (fgets(line, sizeof(line), file)) {
        int page_num = current_page;
        if (lines_on_page + (int)(strlen(line) / 30) > PAGE_SIZE) {
            pages[page_num + 1].start_line = line_num + 1;
            strcpy(pages[page_num + 1].title, pages[page_num].title);
            pages[page_num + 1].end_line = 0;
            current_page++;
            lines_on_page = 0;
        }
        strncpy(pages[page_num].title + lines_on_page * 30, line, 30);
        lines_on_page++;
        line_num++;
    }

    if (lines_on_page > 0) {
        pages[current_page].start_line = line_num + 1;
        pages[current_page].end_line = 0;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    load_file(filename);

    while (1) {
        display_page(current_page);
        int choice;
        scanf("%d", &choice);

        if (choice == 0) {
            current_page--;
            if (current_page < 0) {
                current_page = 0;
            }
            lines_on_page = pages[current_page].end_line - pages[current_page].start_line + 1;
        } else if (choice == 1) {
            current_page++;
            if (current_page >= MAX_LINES) {
                current_page = MAX_LINES - 1;
            }
            lines_on_page = 0;
            if (pages[current_page].start_line > 0) {
                lines_on_page = pages[current_page].end_line - pages[current_page].start_line + 1;
            }
        } else {
            break;
        }
    }

    return 0;
}