//FormAI DATASET v1.0 Category: Ebook reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char title[50];
    char author[50];
    char publisher[50];
    int releaseYear;
    float price;
    char isbn[14];
} Book;

typedef struct{
    Book *books;
    int numBooks;
} EbookLibrary;

void addBook(EbookLibrary *library){
    int numNewBooks;
    printf("How many new books do you want to add? ");
    scanf("%d", &numNewBooks);

    for(int i = 0; i < numNewBooks; i++){
        Book newBook;

        fflush(stdin);
        printf("Enter the book title: ");
        gets(newBook.title);

        fflush(stdin);
        printf("Enter the book author: ");
        gets(newBook.author);

        fflush(stdin);
        printf("Enter the book publisher: ");
        gets(newBook.publisher);

        printf("Enter the book release year: ");
        scanf("%d", &newBook.releaseYear);

        printf("Enter the book price: ");
        scanf("%f", &newBook.price);

        fflush(stdin);
        printf("Enter the book ISBN: ");
        gets(newBook.isbn);

        library->books = (Book*)realloc(library->books, (library->numBooks+1)*sizeof(Book));
        library->books[library->numBooks] = newBook;

        printf("\nBook added successfully!\n\n");
        library->numBooks++;
    }

    return;
}

void viewLibrary(EbookLibrary *library){
    if(library->numBooks == 0){
        printf("\nNo books found in the library.\n\n");
        return;
    }

    printf("\n%-4s| %-35s| %-20s| %-13s\n", "No.", "Title", "Author", "ISBN");
    printf("--------------------------------------------------------\n");
    for(int i = 0; i < library->numBooks; i++){
        printf("%-4d| %-35s| %-20s| %-13s\n", i+1, library->books[i].title, library->books[i].author, library->books[i].isbn);
    }

    printf("\n");
    return;
}

int main(){
    EbookLibrary library;
    library.books = NULL;
    library.numBooks = 0;

    int choice = 0;

    while(choice != 3){
        printf("Welcome to the Ebook Library.\n");
        printf("1. Add a new book.\n");
        printf("2. View the library.\n");
        printf("3. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addBook(&library);
                break;
            case 2:
                viewLibrary(&library);
                break;
            case 3:
                printf("Thank you for using Ebook Library. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }

    free(library.books);

    return 0;
}