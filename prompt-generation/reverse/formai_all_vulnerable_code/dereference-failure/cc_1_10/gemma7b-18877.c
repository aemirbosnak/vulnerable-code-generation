//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure to store book information
typedef struct Book {
    char title[50];
    char author[50];
    char genre[50];
    int quantity;
    float price;
} Book;

// Define a function to add a book to the library
void addBook(Book *bookList, int *numBooks) {
    // Allocate memory for a new book
    bookList = (Book *)realloc(bookList, (*numBooks + 1) * sizeof(Book));

    // Get book information from the user
    printf("Enter book title: ");
    scanf("%s", bookList[*numBooks].title);

    printf("Enter book author: ");
    scanf("%s", bookList[*numBooks].author);

    printf("Enter book genre: ");
    scanf("%s", bookList[*numBooks].genre);

    printf("Enter book quantity: ");
    scanf("%d", &bookList[*numBooks].quantity);

    printf("Enter book price: ");
    scanf("%f", &bookList[*numBooks].price);

    // Increment the number of books
    *numBooks++;
}

// Define a function to search for a book in the library
Book *searchBook(Book *bookList, int numBooks, char *title) {
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(bookList[i].title, title) == 0) {
            return &bookList[i];
        }
    }

    return NULL;
}

// Define a function to update book quantity
void updateBookQuantity(Book *bookList, int numBooks, char *title, int quantity) {
    Book *book = searchBook(bookList, numBooks, title);

    if (book) {
        book->quantity = quantity;
    }
}

// Define a function to delete a book from the library
void deleteBook(Book *bookList, int *numBooks, char *title) {
    Book *book = searchBook(bookList, numBooks, title);

    if (book) {
        for (int i = book - bookList; i < numBooks - 1; i++) {
            bookList[i] = bookList[i + 1];
        }

        *numBooks--;
    }
}

int main() {
    // Define an array of books
    Book *bookList = NULL;

    // Define the number of books
    int numBooks = 0;

    // Add some books to the library
    addBook(bookList, &numBooks);
    addBook(bookList, &numBooks);
    addBook(bookList, &numBooks);

    // Search for a book
    Book *book = searchBook(bookList, numBooks, "Book 2");

    // Update book quantity
    updateBookQuantity(bookList, numBooks, "Book 2", 10);

    // Delete a book
    deleteBook(bookList, &numBooks, "Book 1");

    // Print the updated book list
    for (int i = 0; i < numBooks; i++) {
        printf("%s by %s (%.2f)\n", bookList[i].title, bookList[i].author, bookList[i].price);
    }

    return 0;
}