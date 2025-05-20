//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

struct book {
    char *title;
    char *author;
    int num_pages;
    char **pages;
};

struct ebook_reader {
    struct book *book;
    int current_page;
};

struct ebook_reader *new_ebook_reader(struct book *book) {
    struct ebook_reader *reader = malloc(sizeof(struct ebook_reader));
    reader->book = book;
    reader->current_page = 0;
    return reader;
}

void free_ebook_reader(struct ebook_reader *reader) {
    free(reader->book->title);
    free(reader->book->author);
    for (int i = 0; i < reader->book->num_pages; i++) {
        free(reader->book->pages[i]);
    }
    free(reader->book->pages);
    free(reader->book);
    free(reader);
}

void turn_page(struct ebook_reader *reader, int page) {
    if (page < 0 || page >= reader->book->num_pages) {
        printf("Invalid page number\n");
    } else {
        reader->current_page = page;
    }
}

void print_page(struct ebook_reader *reader) {
    printf("%s\n", reader->book->pages[reader->current_page]);
}

int main() {
    // Create a new book
    struct book *book = malloc(sizeof(struct book));
    book->title = strdup("The Catcher in the Rye");
    book->author = strdup("J.D. Salinger");
    book->num_pages = 277;
    book->pages = malloc(sizeof(char *) * book->num_pages);
    for (int i = 0; i < book->num_pages; i++) {
        char *page = malloc(BUFFER_SIZE);
        snprintf(page, BUFFER_SIZE, "Page %d of %d", i + 1, book->num_pages);
        book->pages[i] = page;
    }

    // Create a new ebook reader
    struct ebook_reader *reader = new_ebook_reader(book);

    // Turn to the first page
    turn_page(reader, 0);

    // Print the first page
    print_page(reader);

    // Turn to the next page
    turn_page(reader, 1);

    // Print the next page
    print_page(reader);

    // Free the ebook reader
    free_ebook_reader(reader);

    return 0;
}