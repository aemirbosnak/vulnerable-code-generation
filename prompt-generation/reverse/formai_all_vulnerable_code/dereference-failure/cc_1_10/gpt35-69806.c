//FormAI DATASET v1.0 Category: Ebook reader ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 50
#define MAX_AUTHOR_LEN 50
#define MAX_FILENAME_LEN 50

typedef struct {
    char title[MAX_TITLE_LEN + 1];
    char author[MAX_AUTHOR_LEN + 1];
    char filename[MAX_FILENAME_LEN + 1];
    int page_count;
} Book;

void print_book(Book book) {
    printf("%s by %s\n", book.title, book.author);
    printf("Pages: %d\n", book.page_count);
}

int main(int argc, char *argv[]) {
    // Check number of arguments
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open file in binary mode
    FILE *file = fopen(argv[1], "rb");

    if (file == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    // Read book count from file
    int book_count;
    fread(&book_count, sizeof(int), 1, file);

    // Allocate memory for books
    Book *books = malloc(book_count * sizeof(Book));

    // Read books from file
    fread(books, sizeof(Book), book_count, file);

    // Loop through books and print information
    for (int i = 0; i < book_count; i++) {
        print_book(books[i]);
    }

    // Free memory and close file
    free(books);
    fclose(file);

    return 0;
}