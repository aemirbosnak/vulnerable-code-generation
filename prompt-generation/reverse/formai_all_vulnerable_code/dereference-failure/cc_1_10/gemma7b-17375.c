//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Define a structure to store book information
    struct book {
        char title[20];
        char author[20];
        int pages;
    };

    // Create an array of books
    struct book books[3] = {
        {"The Lord of the Flies", "William Golding", 248},
        {"The Great Gatsby", "F. Scott Fitzgerald", 180},
        {"To Kill a Mockingbird", "Harper Lee", 282}
    };

    // Print book information
    for (int i = 0; i < 3; i++) {
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Pages: %d\n", books[i].pages);
        printf("\n");
    }

    // Get the user's book choice
    char choice;
    printf("Enter the title of your book: ");
    scanf("%c", &choice);

    // Find the book by title
    struct book *book = NULL;
    for (int i = 0; i < 3; i++) {
        if (strcmp(books[i].title, choice) == 0) {
            book = &books[i];
            break;
        }
    }

    // Print book information
    if (book) {
        printf("Title: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Pages: %d\n", book->pages);
    } else {
        printf("Book not found.\n");
    }

    return 0;
}