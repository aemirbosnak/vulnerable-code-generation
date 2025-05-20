//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of books in the library
#define MAX_BOOKS 100

// Define the book structure
struct book {
    char title[50];
    char author[50];
    int quantity;
    struct book* next;
};

// Function to insert a book into the library
void insertBook(struct book** head) {
    // Allocate memory for the new book
    struct book* newBook = (struct book*)malloc(sizeof(struct book));

    // Get the book's title and author
    printf("Enter book title: ");
    scanf("%s", newBook->title);

    printf("Enter book author: ");
    scanf("%s", newBook->author);

    // Get the book's quantity
    printf("Enter book quantity: ");
    scanf("%d", &newBook->quantity);

    // Insert the new book into the library
    if (*head == NULL) {
        *head = newBook;
    } else {
        (*head)->next = newBook;
    }
}

// Function to search for a book in the library
void searchBook(struct book* head) {
    // Get the book's title
    char title[50];
    printf("Enter book title: ");
    scanf("%s", title);

    // Search for the book
    struct book* currentBook = head;
    while (currentBook) {
        if (strcmp(currentBook->title, title) == 0) {
            // Display the book's information
            printf("Book title: %s\n", currentBook->title);
            printf("Book author: %s\n", currentBook->author);
            printf("Book quantity: %d\n", currentBook->quantity);
            break;
        }
        currentBook = currentBook->next;
    }

    // If the book is not found, display an error message
    if (currentBook == NULL) {
        printf("Book not found.\n");
    }
}

int main() {
    // Create the library head
    struct book* head = NULL;

    // Insert some books into the library
    insertBook(&head);
    insertBook(&head);
    insertBook(&head);

    // Search for a book in the library
    searchBook(head);

    return 0;
}