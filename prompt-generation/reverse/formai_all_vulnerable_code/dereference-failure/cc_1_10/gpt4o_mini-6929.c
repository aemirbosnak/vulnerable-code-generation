//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char title[100];
    char author[100];
    char isbn[20];
    struct Book *left;
    struct Book *right;
} Book;

// Function to create a new book
Book* createBook(char *title, char *author, char *isbn) {
    Book *newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    strcpy(newBook->isbn, isbn);
    newBook->left = newBook->right = NULL;
    return newBook;
}

// Function to insert a book into the BST
Book* insertBook(Book *root, Book *newBook) {
    if (root == NULL) {
        return newBook;
    }
    if (strcmp(newBook->isbn, root->isbn) < 0) {
        root->left = insertBook(root->left, newBook);
    } else if (strcmp(newBook->isbn, root->isbn) > 0) {
        root->right = insertBook(root->right, newBook);
    }
    return root;
}

// Function to search for a book by ISBN
Book* searchBook(Book *root, char *isbn) {
    if (root == NULL || strcmp(root->isbn, isbn) == 0) {
        return root;
    }
    if (strcmp(isbn, root->isbn) < 0) {
        return searchBook(root->left, isbn);
    }
    return searchBook(root->right, isbn);
}

// Function to find the minimum book in the BST
Book* findMin(Book *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a book from the BST
Book* deleteBook(Book *root, char *isbn) {
    if (root == NULL) {
        return root;
    }
    if (strcmp(isbn, root->isbn) < 0) {
        root->left = deleteBook(root->left, isbn);
    } else if (strcmp(isbn, root->isbn) > 0) {
        root->right = deleteBook(root->right, isbn);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Book *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Book *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor
        Book *temp = findMin(root->right);
        strcpy(root->isbn, temp->isbn);
        strcpy(root->title, temp->title);
        strcpy(root->author, temp->author);
        root->right = deleteBook(root->right, temp->isbn);
    }
    return root;
}

// Function to display books in order
void inorderDisplay(Book *root) {
    if (root != NULL) {
        inorderDisplay(root->left);
        printf("Title: %s, Author: %s, ISBN: %s\n", root->title, root->author, root->isbn);
        inorderDisplay(root->right);
    }
}

int main() {
    Book *root = NULL;
    int choice;
    char title[100], author[100], isbn[20];

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Search Book by ISBN\n");
        printf("3. Delete Book by ISBN\n");
        printf("4. Display All Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter book title: ");
                getchar(); // consume newline after choice
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // remove newline character
                printf("Enter book author: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = 0; // remove newline character
                printf("Enter book ISBN: ");
                fgets(isbn, sizeof(isbn), stdin);
                isbn[strcspn(isbn, "\n")] = 0; // remove newline character
                root = insertBook(root, createBook(title, author, isbn));
                printf("Book added successfully!\n");
                break;

            case 2:
                printf("Enter ISBN to search: ");
                getchar(); // consume newline after choice
                fgets(isbn, sizeof(isbn), stdin);
                isbn[strcspn(isbn, "\n")] = 0; // remove newline character
                Book *foundBook = searchBook(root, isbn);
                if (foundBook != NULL) {
                    printf("Book found: Title: %s, Author: %s, ISBN: %s\n", foundBook->title, foundBook->author, foundBook->isbn);
                } else {
                    printf("Book not found.\n");
                }
                break;

            case 3:
                printf("Enter ISBN to delete: ");
                getchar(); // consume newline after choice
                fgets(isbn, sizeof(isbn), stdin);
                isbn[strcspn(isbn, "\n")] = 0; // remove newline character
                root = deleteBook(root, isbn);
                printf("Book deleted successfully!\n");
                break;

            case 4:
                printf("All Books in Library:\n");
                inorderDisplay(root);
                break;

            case 5:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}