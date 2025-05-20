//FormAI DATASET v1.0 Category: Syntax parsing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 1024

// Custom Struct
typedef struct {
    int id;
    char name[MAX_BUF];
    float price;
} Book;

int main() {
    // Declare variables
    int num_books, i;
    char line[MAX_BUF];
    Book *books;

    // Prompt user for number of books
    printf("How many books do you want to enter? ");
    fgets(line, MAX_BUF, stdin);
    num_books = atoi(line);

    // Allocate memory for book array
    books = (Book*) malloc(num_books * sizeof(Book));

    // Prompt user for book information
    for (i = 0; i < num_books; i++) {
        printf("Enter book ID: ");
        fgets(line, MAX_BUF, stdin);
        books[i].id = atoi(line);

        printf("Enter book name: ");
        fgets(line, MAX_BUF, stdin);
        line[strcspn(line, "\n")] = 0; // remove newline character
        strcpy(books[i].name, line);

        printf("Enter book price: ");
        fgets(line, MAX_BUF, stdin);
        books[i].price = atof(line);
    }

    // Print entered book information
    printf("Entered book information:\n");
    for (i = 0; i < num_books; i++) {
        printf("ID: %d\n", books[i].id);
        printf("Name: %s\n", books[i].name);
        printf("Price: $%.2f\n", books[i].price);
    }

    // Free dynamically allocated memory
    free(books);

    return 0;
}