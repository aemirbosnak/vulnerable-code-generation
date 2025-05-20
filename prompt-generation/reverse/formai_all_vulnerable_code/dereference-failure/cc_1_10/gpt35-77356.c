//FormAI DATASET v1.0 Category: Ebook reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char author[50];
    int release_year;
    int num_pages;
    char format[10];
    char language[20];
} Book;

typedef struct {
    Book* books;
    int num_books;
    int max_books;
} EBookReader;

int add_book(EBookReader* reader, Book* book) {
    if (reader->num_books >= reader->max_books) {
        return 0;
    }
    
    reader->books[reader->num_books] = *book;
    reader->num_books++;
    
    return 1;
}

void print_book(Book book) {
    printf("Title: %s\nAuthor: %s\nRelease Year: %d\nNumber of Pages: %d\nFormat: %s\nLanguage: %s\n\n", book.title, book.author, book.release_year, book.num_pages, book.format, book.language);
}

void print_library(EBookReader reader) {
    for (int i = 0; i < reader.num_books; i++) {
        printf("Book %d:\n", i+1);
        print_book(reader.books[i]);
    }
}

int main() {
    EBookReader library;
    library.num_books = 0;
    library.max_books = 10;
    library.books = malloc(sizeof(Book) * library.max_books);
    
    Book book1 = {"The Catcher in the Rye", "J.D. Salinger", 1951, 224, "PDF", "English"};
    Book book2 = {"Pride and Prejudice", "Jane Austen", 1813, 279, "EPUB", "English"};
    Book book3 = {"1984", "George Orwell", 1949, 328, "MOBI", "English"};
    Book book4 = {"The Great Gatsby", "F. Scott Fitzgerald", 1925, 180, "PDF", "English"};
    
    add_book(&library, &book1);
    add_book(&library, &book2);
    add_book(&library, &book3);
    add_book(&library, &book4);
    
    printf("Library:\n");
    print_library(library);
    
    free(library.books);
    
    return 0;
}