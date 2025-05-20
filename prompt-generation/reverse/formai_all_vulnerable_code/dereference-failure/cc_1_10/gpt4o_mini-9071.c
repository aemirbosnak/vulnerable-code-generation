//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    struct Book *left;
    struct Book *right;
};

struct Book *createBook(int id, const char *title) {
    struct Book *newBook = (struct Book *)malloc(sizeof(struct Book));
    newBook->id = id;
    strcpy(newBook->title, title);
    newBook->left = NULL;
    newBook->right = NULL;
    return newBook;
}

struct Book *insertBook(struct Book *node, int id, const char *title) {
    if (node == NULL) {
        return createBook(id, title);
    }

    if (id < node->id) {
        node->left = insertBook(node->left, id, title);
    } else if (id > node->id) {
        node->right = insertBook(node->right, id, title);
    } else {
        printf("Book with ID %d already exists. Skipping...\n", id);
    }

    return node;
}

struct Book *searchBook(struct Book *node, int id) {
    if (node == NULL || node->id == id) {
        return node;
    }

    if (id < node->id) {
        return searchBook(node->left, id);
    } else {
        return searchBook(node->right, id);
    }
}

void inOrderTraversal(struct Book *node) {
    if (node == NULL) {
        return;
    }
    
    inOrderTraversal(node->left);
    printf("Book ID: %d, Title: %s\n", node->id, node->title);
    inOrderTraversal(node->right);
}

int main() {
    struct Book *root = NULL;
    int choice, id;
    char title[100];

    while (1) {
        printf("\n--- Library Management System ---\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Display Books\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &id);
                printf("Enter Book Title: ");
                getchar(); // consume newline
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // remove newline
                root = insertBook(root, id, title);
                break;
            case 2:
                printf("Enter Book ID to search: ");
                scanf("%d", &id);
                struct Book *foundBook = searchBook(root, id);
                if (foundBook) {
                    printf("Book found: ID: %d, Title: %s\n", foundBook->id, foundBook->title);
                } else {
                    printf("Book with ID %d not found.\n", id);
                }
                break;
            case 3:
                printf("Displaying all books in the library:\n");
                inOrderTraversal(root);
                break;
            case 4:
                printf("Exiting the library system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}