//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    int id;
    char title[100];
    char author[100];
    struct Book* next;
} Book;

Book* head = NULL;
int bookCount = 0;

void addBook() {
    Book* newBook = (Book*)malloc(sizeof(Book));
    newBook->id = ++bookCount; // Assign a unique ID
    printf("Enter book title: ");
    getchar(); // clear the newline left by previous scanf
    fgets(newBook->title, sizeof(newBook->title), stdin);
    newBook->title[strcspn(newBook->title, "\n")] = 0; // Remove newline

    printf("Enter author name: ");
    fgets(newBook->author, sizeof(newBook->author), stdin);
    newBook->author[strcspn(newBook->author, "\n")] = 0; // Remove newline

    newBook->next = head;
    head = newBook;
    printf("Book '%s' by '%s' added with ID %d.\n", newBook->title, newBook->author, newBook->id);
}

void displayBooks() {
    if (head == NULL) {
        printf("No books available.\n");
        return;
    }
    printf("List of Books:\n");
    Book* current = head;
    while (current != NULL) {
        printf("ID: %d, Title: '%s', Author: '%s'\n", current->id, current->title, current->author);
        current = current->next;
    }
}

void deleteBook() {
    if (head == NULL) {
        printf("No books to delete.\n");
        return;
    }
    
    int id;
    printf("Enter the ID of the book to delete: ");
    scanf("%d", &id);
    
    Book* current = head;
    Book* previous = NULL;

    while (current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Book with ID %d not found.\n", id);
        return;
    }
    
    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }
    
    free(current);
    printf("Book with ID %d deleted.\n", id);
}

void displayMenu() {
    printf("\nLibrary Database Simulator\n");
    printf("1. Add Book\n");
    printf("2. Display Books\n");
    printf("3. Delete Book\n");
    printf("4. Exit\n");
    printf("Choose an option (1-4): ");
}

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                deleteBook();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 4);
    
    // Free the allocated memory
    Book* current = head;
    while (current != NULL) {
        Book* temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}