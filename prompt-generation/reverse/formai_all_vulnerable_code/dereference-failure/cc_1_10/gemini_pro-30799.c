//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char *title;
    char *author;
    int pages;
    char *genre;
};

struct library {
    struct book *books;
    int num_books;
};

struct library *create_library() {
    struct library *library = malloc(sizeof(struct library));
    library->books = NULL;
    library->num_books = 0;
    return library;
}

void add_book_to_library(struct library *library, struct book *book) {
    library->books = realloc(library->books, (library->num_books + 1) * sizeof(struct book));
    library->books[library->num_books] = *book;
    library->num_books++;
}

void print_library(struct library *library) {
    for (int i = 0; i < library->num_books; i++) {
        printf("%s by %s (%d pages, %s)\n", library->books[i].title, library->books[i].author, library->books[i].pages, library->books[i].genre);
    }
}

void free_library(struct library *library) {
    for (int i = 0; i < library->num_books; i++) {
        free(library->books[i].title);
        free(library->books[i].author);
        free(library->books[i].genre);
    }
    free(library->books);
    free(library);
}

int main() {
    struct library *library = create_library();

    struct book book1 = {"The Catcher in the Rye", "J.D. Salinger", 277, "Fiction"};
    add_book_to_library(library, &book1);

    struct book book2 = {"The Great Gatsby", "F. Scott Fitzgerald", 180, "Fiction"};
    add_book_to_library(library, &book2);

    struct book book3 = {"1984", "George Orwell", 328, "Fiction"};
    add_book_to_library(library, &book3);

    print_library(library);

    free_library(library);

    return 0;
}