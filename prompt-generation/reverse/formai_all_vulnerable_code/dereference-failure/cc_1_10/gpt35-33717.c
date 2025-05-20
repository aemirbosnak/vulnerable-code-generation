//FormAI DATASET v1.0 Category: Ebook reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

struct Book {
    char title[100];
    char author[50];
    char genre[20];
    float price;
    int pages;
};

struct Node {
    struct Book book;
    struct Node* next;
};

typedef struct Node* node_ptr;

node_ptr add_book(node_ptr head, struct Book new_book) {
    node_ptr new_node;

    new_node = (node_ptr)malloc(sizeof(struct Node));
    new_node->book = new_book;
    new_node->next = head;
    head = new_node;

    return head;
}

void display_library(node_ptr head) {
    node_ptr temp;

    printf("\nCURRENTLY AVAILABLE BOOKS:\n");

    for (temp = head; temp != NULL; temp = temp->next) {
        printf("Title: %s\n", temp->book.title);
        printf("Author: %s\n", temp->book.author);
        printf("Genre: %s\n", temp->book.genre);
        printf("Price: $%.2f\n", temp->book.price);
        printf("Number of pages: %d\n\n", temp->book.pages);
    }
}

void display_book(node_ptr head, char title[]) {
    node_ptr temp;
    int flag = 0;

    for (temp = head; temp != NULL; temp = temp->next) {
        if (strcmp(title, temp->book.title) == 0) {
            flag = 1;
            printf("\nTitle: %s\n", temp->book.title);
            printf("Author: %s\n", temp->book.author);
            printf("Genre: %s\n", temp->book.genre);
            printf("Price: $%.2f\n", temp->book.price);
            printf("Number of pages: %d\n\n", temp->book.pages);
            break;
        }
    }

    if (flag == 0) {
        printf("\nThe book \"%s\" was not found in the library.\n\n", title);
    }
}

int main() {
    node_ptr head = NULL;
    int user_choice;
    char title[100];

    // Adding some initial books to the library
    struct Book book1 = {"Harry Potter and the Philosopher's Stone", "J.K. Rowling", "Fantasy", 20.99, 223};
    struct Book book2 = {"The Alchemist", "Paulo Coelho", "Fiction", 15.00, 208};
    struct Book book3 = {"The Da Vinci Code", "Dan Brown", "Mystery", 12.99, 689};
    head = add_book(head, book1);
    head = add_book(head, book2);
    head = add_book(head, book3);

    do {
        printf("\nMENU:\n");
        printf("1. View all books in the library\n");
        printf("2. Search for a specific book\n");
        printf("3. Exit\n");
        printf("What would you like to do? ");
        scanf("%d", &user_choice);

        switch (user_choice) {
            case 1:
                display_library(head);
                break;
            case 2:
                printf("\nEnter the title of the book you're looking for: ");
                scanf("\n");
                fgets(title, 100, stdin); // This is to read the entire user input, including any spaces
                title[strcspn(title, "\n")] = 0; // This removes the newline character from the end of the user input
                display_book(head, title);
                break;
            case 3:
                printf("\nThank you for using the Ebook Reader! Goodbye!\n\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n\n");
        }
    } while (user_choice != 3);

    return 0;
}