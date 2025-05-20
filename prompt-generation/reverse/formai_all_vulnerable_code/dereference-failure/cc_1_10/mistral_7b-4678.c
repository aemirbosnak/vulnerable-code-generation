//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char* title;
    char* author;
    char* content;
    size_t size;
} Book;

typedef struct {
    Book* books;
    size_t capacity;
    size_t count;
} Library;

Library* library_new(size_t capacity) {
    Library* lib = malloc(sizeof(Library));
    lib->books = calloc(capacity, sizeof(Book));
    lib->capacity = capacity;
    lib->count = 0;
    return lib;
}

void library_add_book(Library* lib, const char* title, const char* author, const char* content, size_t size) {
    if (lib->count == lib->capacity) {
        fprintf(stderr, "Library is full\n");
        return;
    }

    Book* book = &lib->books[lib->count];
    size_t title_len = strlen(title) + 1;
    size_t author_len = strlen(author) + 1;

    book->title = malloc(title_len);
    strcpy(book->title, title);

    book->author = malloc(author_len);
    strcpy(book->author, author);

    book->content = malloc(size);
    strcpy(book->content, content);

    book->size = size;
    lib->count++;
}

void library_print(Library* lib) {
    for (size_t i = 0; i < lib->count; i++) {
        printf("%d. %s by %s (%ld bytes)\n", i + 1, lib->books[i].title, lib->books[i].author, lib->books[i].size);
    }
}

int main() {
    Library* lib = library_new(3);

    library_add_book(lib, "The C Programming Language", "Kernighan & Pike", "/* ... */", 1024);
    library_add_book(lib, "C: A Reference Manual", "Harbison & Steele", "/* ... */", 2048);
    library_add_book(lib, "The Art of Computer Programming", "Donald Knuth", "/* ... */", 4096);

    library_print(lib);

    return 0;
}