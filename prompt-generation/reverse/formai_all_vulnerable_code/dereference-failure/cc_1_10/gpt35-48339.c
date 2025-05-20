//FormAI DATASET v1.0 Category: Ebook reader ; Style: decentralized
// Decentralized C Ebook Reader Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of books and book title length
#define MAX_BOOKS 100
#define MAX_TITLE_LEN 50

// Define book struct
typedef struct {
    char title[MAX_TITLE_LEN];
    char* content;
} Book;

// Define array of books
Book* books[MAX_BOOKS];

// Define function to add a book
void add_book(char* title, char* content) {
    // Find available index in books array
    int index = 0;
    while (index < MAX_BOOKS && books[index] != NULL) {
        index++;
    }
    // If there is available index, add a book
    if (index < MAX_BOOKS) {
        books[index] = malloc(sizeof(Book));
        strncpy(books[index]->title, title, MAX_TITLE_LEN);
        books[index]->content = malloc(strlen(content)+1);
        strcpy(books[index]->content, content);
        printf("Book '%s' added with content: %s\n", books[index]->title, books[index]->content);
    } else {
        printf("Cannot add book as maximum number of books reached.\n");
    }
}

// Define function to find a book by title
Book* find_book(char* title) {
    int index = 0;
    while (index < MAX_BOOKS && books[index] != NULL) {
        if (strcmp(books[index]->title, title) == 0) {
            return books[index];
        }
        index++;
    }
    return NULL;
}

// Define function to delete a book by title
void delete_book(char* title) {
    int index = 0;
    while (index < MAX_BOOKS && books[index] != NULL) {
        if (strcmp(books[index]->title, title) == 0) {
            free(books[index]->content);
            free(books[index]);
            books[index] = NULL;
            printf("Book '%s' deleted.\n", title);
            return;
        }
        index++;
    }
    printf("Book '%s' not found.\n", title);
}

// Define function to read a book by title
void read_book(char* title) {
    Book* book = find_book(title);
    if (book != NULL) {
        printf("Reading book '%s':\n%s\n", book->title, book->content);
    } else {
        printf("Book '%s' not found.\n", title);
    }
}

int main() {
    // Add some example books
    add_book("The Catcher in the Rye", "All the kids kept trying to grab for the gold ring, and so was old Phoebe, and I was sort of afraid she\\'d fall off the goddam horse, but I didn\\'t say anything or do anything. The thing with kids is, if they want to grab for the gold ring, you have to let them do it, and not say anything. If they fall off, they fall off, but it\\'s bad if you say anything to them.");
    add_book("1984", "He thought of the telescreen with its never-sleeping ear. They could spy upon you night and day, but if you kept your head you could still outwit them. With all their cleverness they had never mastered the secret of finding out what another human being was thinking. Perhaps that was less true when you were actually in their hands. One did not know what happened inside the Ministry of Love, but it was possible to guess: tortures, drugs, delicate instruments that registered your nervous reactions, gradual wearing-down by sleeplessness and solitude and persistent questioning.");
    add_book("To Kill a Mockingbird", "\"Atticus, he was real nice. . .\" \n\"Most people are, Scout, when you finally see them.\"");

    // Read some books
    read_book("1984");
    read_book("The Catcher in the Rye");
    read_book("To Kill a Mockingbird");

    // Delete a book and try to read it again
    delete_book("The Catcher in the Rye");
    read_book("The Catcher in the Rye");

    return 0;
}