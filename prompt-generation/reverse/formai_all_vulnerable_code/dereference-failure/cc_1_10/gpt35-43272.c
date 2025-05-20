//FormAI DATASET v1.0 Category: Database Indexing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to hold the information about a book
typedef struct Book {
    char title[50];
    char author[50];
    int year;
} Book;

// Data structure to hold a node of the index tree
typedef struct IndexNode {
    char letter;
    struct IndexNode *left;
    struct IndexNode *right;
    Book **books;
} IndexNode;

// Function to create a new index node
IndexNode *createIndexNode(char letter) {
    IndexNode *newNode = malloc(sizeof(IndexNode));
    newNode->letter = letter;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->books = NULL;
    return newNode;
}

// Function to insert a book into the index tree
void insertBook(IndexNode **root, Book *book) {
    // Check if root is null
    if (*root == NULL) {
        *root = createIndexNode(book->title[0]);
    }
    // Compare first letter to determine which subtree to insert
    if (book->title[0] < (*root)->letter) {
        insertBook(&((*root)->left), book);
    } else if (book->title[0] > (*root)->letter) {
        insertBook(&((*root)->right), book);
    } 
    // If first letters match, add book to the array of books stored in the node
    else {
        if ((*root)->books == NULL) {
            (*root)->books = malloc(sizeof(Book *) * 10);
            (*root)->books[0] = book;
        } else {
            int i = 0;
            while ((*root)->books[i] != NULL) {
                i++;
            }
            (*root)->books[i] = book; 
        }
    }
}

// Function to print out the books in the index tree
void printBooks(IndexNode *root) {
    if (root == NULL) {
        return;
    }
    printBooks(root->left);
    printf("%c\n", root->letter);
    if (root->books != NULL) {
        int i = 0;
        while (root->books[i] != NULL) {
            printf("- %s by %s (%d)\n", root->books[i]->title, root->books[i]->author, root->books[i]->year);
            i++;
        }
    }
    printBooks(root->right);
}

int main() {
    // Create root node
    IndexNode *root = NULL;

    // Create some example books
    Book *book1 = malloc(sizeof(Book));
    strcpy(book1->title, "The Lord of the Rings");
    strcpy(book1->author, "J.R.R. Tolkien");
    book1->year = 1954;

    Book *book2 = malloc(sizeof(Book));
    strcpy(book2->title, "A Game of Thrones");
    strcpy(book2->author, "George R.R. Martin");
    book2->year = 1996;

    Book *book3 = malloc(sizeof(Book));
    strcpy(book3->title, "The Hobbit");
    strcpy(book3->author, "J.R.R. Tolkien");
    book3->year = 1937;

    // Insert books into index tree
    insertBook(&root, book1);
    insertBook(&root, book2);
    insertBook(&root, book3);

    // Print out books in index tree
    printBooks(root);

    return 0;
}