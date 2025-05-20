//FormAI DATASET v1.0 Category: Ebook reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct page {
    char content[50];
    struct page *next;
};

typedef struct page Page;

Page* read_ebook(FILE *fp, Page *curr_page) {
    char c;
    int i = 0;
    while ((c = fgetc(fp)) != EOF) {
        if (i == 0) {
            Page *new_page = malloc(sizeof(Page));
            new_page->next = curr_page;
            curr_page = new_page;
        }
        curr_page->content[i++] = c;
        if (i == 50) {
            i = 0;
        }
    }
    return curr_page;
}

void print_page(Page *page) {
    printf("%s\n", page->content);
}

void recursive_ebook_reader(Page *curr_page) {
    char command;
    print_page(curr_page);
    printf("Enter N for next page, P for previous page, Q to quit: ");
    scanf(" %c", &command);
    if (command == 'N' || command == 'n') {
        recursive_ebook_reader(curr_page->next);
    } else if (command == 'P' || command == 'p') {
        recursive_ebook_reader(curr_page);
    } else if (command == 'Q' || command == 'q') {
        printf("Exiting...\n");
        return;
    }
}

int main() {
    FILE *fp = fopen("ebook.txt", "r");
    if (!fp) {
        printf("Error: could not open ebook.txt!\n");
        return 1;
    }
    Page *last_page = NULL;
    Page *first_page = read_ebook(fp, last_page);
    recursive_ebook_reader(first_page);
    return 0;
}