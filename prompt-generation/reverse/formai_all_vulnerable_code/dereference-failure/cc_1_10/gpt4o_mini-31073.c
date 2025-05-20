//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a Book
typedef struct Book {
    char title[100];
    char author[100];
    int isAvailable; // 1 if available, 0 if borrowed
    struct Book* next; // Pointer to the next book
} Book;

// Function prototypes
Book* createBook(const char* title, const char* author);
void addBook(Book** head, const char* title, const char* author);
void borrowBook(Book* head, const char* title);
void returnBook(Book* head, const char* title);
void listBooks(Book* head);
void freeLibrary(Book* head);

int main() {
    Book* library = NULL;
    int choice;
    char title[100];
    char author[100];

    do {
        printf("\nLibrary Management System:\n");
        printf("1. Add Book\n");
        printf("2. Borrow Book\n");
        printf("3. Return Book\n");
        printf("4. List Available Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter book title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                
                printf("Enter book author: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = 0; // Remove newline
                
                addBook(&library, title, author);
                break;
            case 2:
                printf("Enter book title to borrow: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline
                
                borrowBook(library, title);
                break;
            case 3:
                printf("Enter book title to return: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline

                returnBook(library, title);
                break;
            case 4:
                listBooks(library);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    
    freeLibrary(library);
    return 0;
}

// Function to create a new book
Book* createBook(const char* title, const char* author) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->isAvailable = 1; // New book is available
    newBook->next = NULL;
    return newBook;
}

// Function to add a book to the library
void addBook(Book** head, const char* title, const char* author) {
    Book* newBook = createBook(title, author);
    newBook->next = *head; // Insert at the beginning
    *head = newBook;
    printf("Book '%s' by '%s' added to the library.\n", title, author);
}

// Function to borrow a book
void borrowBook(Book* head, const char* title) {
    while (head != NULL) {
        if (strcmp(head->title, title) == 0) {
            if (head->isAvailable) {
                head->isAvailable = 0; // Mark as borrowed
                printf("You have borrowed the book '%s'.\n", title);
                return;
            } else {
                printf("The book '%s' is currently not available.\n", title);
                return;
            }
        }
        head = head->next;
    }
    printf("Book '%s' not found in the library.\n", title);
}

// Function to return a book
void returnBook(Book* head, const char* title) {
    while (head != NULL) {
        if (strcmp(head->title, title) == 0) {
            if (!head->isAvailable) {
                head->isAvailable = 1; // Mark as available
                printf("You have returned the book '%s'.\n", title);
                return;
            } else {
                printf("The book '%s' was not borrowed.\n", title);
                return;
            }
        }
        head = head->next;
    }
    printf("Book '%s' not found in the library.\n", title);
}

// Function to list available books
void listBooks(Book* head) {
    printf("\nAvailable Books in the Library:\n");
    while (head != NULL) {
        if (head->isAvailable) {
            printf("Title: %s, Author: %s\n", head->title, head->author);
        }
        head = head->next;
    }
}

// Function to free memory allocated for the library
void freeLibrary(Book* head) {
    Book* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}