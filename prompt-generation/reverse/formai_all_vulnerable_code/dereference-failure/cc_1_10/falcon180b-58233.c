//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
} book;

book* create_book(char* title, char* author, char* description) {
    book* new_book = (book*) malloc(sizeof(book));
    strcpy(new_book->title, title);
    strcpy(new_book->author, author);
    strcpy(new_book->description, description);
    return new_book;
}

void add_book(book** books, int num_books, book* new_book) {
    (*books)[num_books] = *new_book;
    num_books++;
}

void display_books(book* books, int num_books) {
    for (int i = 0; i < num_books; i++) {
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Description: %s\n\n", books[i].description);
    }
}

int main() {
    book* books[MAX_BOOKS];
    int num_books = 0;

    books[num_books] = create_book("The Catcher in the Rye", "J.D. Salinger", "A story about a teenager's struggle with identity and belonging.");
    num_books++;

    books[num_books] = create_book("To Kill a Mockingbird", "Harper Lee", "A classic novel about racial injustice and the loss of innocence.");
    num_books++;

    books[num_books] = create_book("1984", "George Orwell", "A dystopian novel about a totalitarian society and the power of language.");
    num_books++;

    display_books(books, num_books);

    return 0;
}