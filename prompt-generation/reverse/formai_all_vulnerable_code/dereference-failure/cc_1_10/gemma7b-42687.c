//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of books in the library
#define MAX_BOOKS 100

// Define the book structure
typedef struct Book {
    char title[20];
    char author[20];
    int quantity;
    struct Book* next;
} Book;

// Function to insert a book into the library
void insertBook(Book** head) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    printf("Enter book title: ");
    scanf("%s", newBook->title);
    printf("Enter book author: ");
    scanf("%s", newBook->author);
    printf("Enter book quantity: ");
    scanf("%d", &newBook->quantity);

    newBook->next = NULL;

    if (*head == NULL) {
        *head = newBook;
    } else {
        (*head)->next = newBook;
    }
}

// Function to search for a book in the library
Book* searchBook(Book* head, char* title) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

// Function to update the quantity of a book in the library
void updateBookQuantity(Book* head, char* title, int quantity) {
    Book* book = searchBook(head, title);

    if (book) {
        book->quantity = quantity;
    }
}

// Function to delete a book from the library
void deleteBook(Book* head, char* title) {
    Book* book = searchBook(head, title);

    if (book) {
        Book* prevBook = NULL;

        while (book->next) {
            prevBook = book;
            book = book->next;
        }

        if (prevBook) {
            prevBook->next = book->next;
        } else {
            head = book->next;
        }

        free(book);
    }
}

int main() {
    Book* head = NULL;

    // Insert some books into the library
    insertBook(&head);
    insertBook(&head);
    insertBook(&head);

    // Search for a book in the library
    Book* book = searchBook(head, "Book 2");
    if (book) {
        printf("Book title: %s\n", book->title);
        printf("Book author: %s\n", book->author);
        printf("Book quantity: %d\n", book->quantity);
    }

    // Update the quantity of a book in the library
    updateBookQuantity(head, "Book 2", 10);

    // Search for the updated book
    book = searchBook(head, "Book 2");
    if (book) {
        printf("Book title: %s\n", book->title);
        printf("Book author: %s\n", book->author);
        printf("Book quantity: %d\n", book->quantity);
    }

    // Delete a book from the library
    deleteBook(head, "Book 2");

    // Search for the deleted book
    book = searchBook(head, "Book 2");
    if (book) {
        printf("Error: Book not found.\n");
    } else {
        printf("Book title: %s\n", book->title);
        printf("Book author: %s\n", book->author);
        printf("Book quantity: %d\n", book->quantity);
    }

    return 0;
}