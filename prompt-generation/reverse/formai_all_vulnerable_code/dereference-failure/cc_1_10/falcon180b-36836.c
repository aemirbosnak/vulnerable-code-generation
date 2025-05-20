//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_PAGE_SIZE 4096
#define MAX_BOOK_SIZE 1000000
#define MAX_BOOKS 100

typedef struct {
    char* name;
    int num_pages;
    char* content;
} Book;

typedef struct {
    Book* books;
    int num_books;
} Library;

void init_library(Library* library) {
    library->books = (Book*) malloc(MAX_BOOKS * sizeof(Book));
    library->num_books = 0;
}

void add_book(Library* library, char* name, int num_pages, char* content) {
    if (library->num_books >= MAX_BOOKS) {
        printf("Error: Library is full.\n");
        return;
    }

    Book* book = &library->books[library->num_books];
    book->name = strdup(name);
    book->num_pages = num_pages;
    book->content = (char*) malloc(num_pages * MAX_PAGE_SIZE);
    memcpy(book->content, content, num_pages * MAX_PAGE_SIZE);

    library->num_books++;
}

void print_books(Library* library) {
    printf("Library contains the following books:\n");
    for (int i = 0; i < library->num_books; i++) {
        printf("%d. %s (%d pages)\n", i+1, library->books[i].name, library->books[i].num_pages);
    }
}

void read_book(Library* library, int book_index, int page_index) {
    if (book_index >= library->num_books || book_index < 0) {
        printf("Invalid book index.\n");
        return;
    }

    if (page_index >= library->books[book_index].num_pages || page_index < 0) {
        printf("Invalid page index.\n");
        return;
    }

    printf("Reading page %d of %s:\n%s\n", page_index+1, library->books[book_index].name, library->books[book_index].content + (page_index * MAX_PAGE_SIZE));
}

int main() {
    Library library;
    init_library(&library);

    add_book(&library, "The Great Gatsby", 180, "In my younger and more vulnerable years my father gave me some advice...");
    add_book(&library, "To Kill a Mockingbird", 281, "When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow.");

    print_books(&library);

    read_book(&library, 0, 0);
    read_book(&library, 1, 1);

    return 0;
}