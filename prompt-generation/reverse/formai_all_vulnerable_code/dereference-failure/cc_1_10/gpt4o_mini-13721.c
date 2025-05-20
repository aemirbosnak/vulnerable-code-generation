//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a book
typedef struct Book {
    char title[100];
    char author[100];
    float price;
    struct Book* next;
} Book;

// Function prototypes
Book* createBook(char* title, char* author, float price);
void addBook(Book** head, char* title, char* author, float price);
void removeBook(Book** head, char* title);
void displayInventory(Book* head);
Book* searchBook(Book* head, char* title);
void freeInventory(Book* head);

int main() {
    Book* inventory = NULL;
    int choice;
    char title[100], author[100];
    float price;

    while (1) {
        printf("\nBookstore Inventory Management System\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Display Inventory\n");
        printf("4. Search for a Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character after choice input

        switch (choice) {
            case 1:
                printf("Enter book title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove the newline character

                printf("Enter author name: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = '\0'; // Remove the newline character

                printf("Enter price: ");
                scanf("%f", &price);

                addBook(&inventory, title, author, price);
                printf("Book added successfully!\n");
                break;

            case 2:
                printf("Enter book title to remove: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove the newline character

                removeBook(&inventory, title);
                break;

            case 3:
                displayInventory(inventory);
                break;

            case 4:
                printf("Enter book title to search: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove the newline character

                Book* found = searchBook(inventory, title);
                if (found) {
                    printf("Book found: \nTitle: %s\nAuthor: %s\nPrice: %.2f\n", found->title, found->author, found->price);
                } else {
                    printf("Book not found!\n");
                }
                break;

            case 5:
                freeInventory(inventory);
                printf("Exiting. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to create a new book node
Book* createBook(char* title, char* author, float price) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->price = price;
    newBook->next = NULL;
    return newBook;
}

// Function to add a book to the inventory
void addBook(Book** head, char* title, char* author, float price) {
    Book* newBook = createBook(title, author, price);
    newBook->next = *head;
    *head = newBook;
}

// Function to remove a book from the inventory
void removeBook(Book** head, char* title) {
    Book* current = *head;
    Book* previous = NULL;

    while (current != NULL && strcmp(current->title, title) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Book not found in inventory.\n");
        return;
    }

    if (previous == NULL) {
        *head = current->next; // Book to be removed is the first book
    } else {
        previous->next = current->next; // Bypass the current book
    }

    free(current);
    printf("Book removed successfully!\n");
}

// Function to display the inventory
void displayInventory(Book* head) {
    if (head == NULL) {
        printf("No books in inventory.\n");
        return;
    }

    printf("Current Inventory:\n");
    Book* current = head;
    while (current != NULL) {
        printf("Title: %s\nAuthor: %s\nPrice: %.2f\n", current->title, current->author, current->price);
        current = current->next;
    }
}

// Function to search for a book by title
Book* searchBook(Book* head, char* title) {
    Book* current = head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            return current; // Book found
        }
        current = current->next;
    }
    return NULL; // Book not found
}

// Function to free the inventory
void freeInventory(Book* head) {
    Book* current = head;
    while (current != NULL) {
        Book* next = current->next;
        free(current);
        current = next;
    }
}