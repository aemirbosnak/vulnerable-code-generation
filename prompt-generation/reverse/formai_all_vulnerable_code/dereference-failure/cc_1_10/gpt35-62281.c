//FormAI DATASET v1.0 Category: Ebook reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>

struct Book {
    char title[50];
    char author[50];
    int pages;
    float price;
};

struct Node {
    struct Book data;
    struct Node *next;
};

void addBook(struct Node **head_ref, struct Book new_book) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_book;
    new_node->next  = (*head_ref);
    (*head_ref) = new_node;
}

void displayBooks(struct Node *node) {
    while (node != NULL) {
        printf("| %-4d | %-20s | %-20s | %-6d | $%.2f |\n", 
                node->data.pages,
                node->data.title,
                node->data.author,
                node->data.pages,
                node->data.price
        );
        node = node->next;
    }
}

void searchBooks(struct Node *node, char* title) {
    int found = 0;
    while (node != NULL) {
        if (strcmp(node->data.title, title) == 0) {
            printf("| %-4d | %-20s | %-20s | %-6d | $%.2f |\n", 
                    node->data.pages,
                    node->data.title,
                    node->data.author,
                    node->data.pages,
                    node->data.price
            );
            found = 1;
        }
        node = node->next;
    }
    if (!found) printf("Book not found.\n");
}

int main() {
    struct Node* head = NULL;

    addBook(&head, (struct Book){ "The C Programming Language", "Dennis Ritchie", 272, 50.00 });
    addBook(&head, (struct Book){ "C Programming Absolute Beginner's Guide", "Greg Perry", 352, 24.99 });
    addBook(&head, (struct Book){ "C Programming for the Absolute Beginner", "Michael Vine", 327, 29.99 });
    addBook(&head, (struct Book){ "Head First C", "David Griffiths and Dawn Griffiths", 626, 59.99 });
    addBook(&head, (struct Book){ "C Programming: A Modern Approach", "K. N. King", 830, 69.99 });

    printf("| Pages | Title                | Author               | Price  |\n");
    printf("----------------------------------------------------------\n");
    displayBooks(head);

    printf("\n\nSearch: ");
    char query[50];
    scanf("%[^\n]%*c", query);
    printf("\n| Pages | Title                | Author               | Price  |\n");
    printf("----------------------------------------------------------\n");
    searchBooks(head, query);

    return 0;
}