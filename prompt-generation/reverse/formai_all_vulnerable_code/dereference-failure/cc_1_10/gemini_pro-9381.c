//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

typedef struct _book_page {
    char *text;
    int length;
} book_page;

typedef struct _book {
    char *title;
    int num_pages;
    book_page *pages;
} book;

book *create_book(char *title, int num_pages) {
    book *b = malloc(sizeof(book));
    b->title = title;
    b->num_pages = num_pages;
    b->pages = malloc(sizeof(book_page) * num_pages);
    return b;
}

void destroy_book(book *b) {
    free(b->title);
    for (int i = 0; i < b->num_pages; i++) {
        free(b->pages[i].text);
    }
    free(b->pages);
    free(b);
}

int main() {
    book *b = create_book("The Hitchhiker's Guide to the Galaxy", 42);

    // Load the book's text from a file.
    FILE *f = fopen("hitchhikers.txt", "r");
    if (f == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    char *line = NULL;
    size_t len = 0;
    int page_num = 0;
    while (getline(&line, &len, f) != -1) {
        b->pages[page_num].text = line;
        b->pages[page_num].length = len;
        page_num++;
    }
    fclose(f);

    // Print the book's title and text.
    printf("Title: %s\n", b->title);
    for (int i = 0; i < b->num_pages; i++) {
        printf("Page %d:\n", i + 1);
        printf("%s", b->pages[i].text);
    }

    // Destroy the book.
    destroy_book(b);

    return EXIT_SUCCESS;
}