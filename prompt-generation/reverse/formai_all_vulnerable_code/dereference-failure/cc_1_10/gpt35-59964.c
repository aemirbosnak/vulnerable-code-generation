//FormAI DATASET v1.0 Category: Ebook reader ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct eBook {   // structure to hold ebook information
    char title[50];
    char author[50];
    char publisher[50];
    double price;
    int numPages;
} eBook;

void displayMenu();   // function to display menu
void addBook(eBook *, int *);   // function to add new book to library
void viewBooks(eBook *, int);   // function to display all books in library
void searchBook(eBook *, int);   // function to search for a specific book by title

int main() {
    eBook *library = NULL;
    int numBooks = 0;
    int choice;
    
    do {   // loop to display menu until user chooses to exit
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addBook(library, &numBooks);
                break;
            case 2:
                viewBooks(library, numBooks);
                break;
            case 3:
                searchBook(library, numBooks);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
    } while (choice != 4);
    
    free(library);   // free memory allocated for library
    
    return 0;
}

void displayMenu() {
    printf("\nEBOOK LIBRARY\n");
    printf("1. Add new book\n");
    printf("2. View all books\n");
    printf("3. Search for book\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void addBook(eBook *library, int *numBooks) {
    eBook newBook;
    
    printf("\nEnter book title: ");
    scanf("%s", &newBook.title);
    printf("Enter book author: ");
    scanf("%s", &newBook.author);
    printf("Enter book publisher: ");
    scanf("%s", &newBook.publisher);
    printf("Enter book price: ");
    scanf("%lf", &newBook.price);
    printf("Enter number of pages: ");
    scanf("%d", &newBook.numPages);
    
    *numBooks += 1;
    library = (eBook *)realloc(library, (*numBooks)*sizeof(eBook));   // dynamically allocate memory for new book
    
    if (library == NULL) {   // check if memory allocation was successful
        printf("Memory allocation failed. Please try again.");
        return;
    }
    
    library[*numBooks-1] = newBook;   // add new book to library
    
    printf("\nBook successfully added!\n");
}

void viewBooks(eBook *library, int numBooks) {
    if (numBooks == 0) {
        printf("\nNo books found.\n");
        return;
    }
    
    printf("\nBOOKS IN LIBRARY\n");
    for (int i = 0; i < numBooks; i++) {
        printf("Book %d\n", i+1);
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Publisher: %s\n", library[i].publisher);
        printf("Price: %.2lf\n", library[i].price);
        printf("Number of pages: %d\n", library[i].numPages);
        printf("\n");
    }
}

void searchBook(eBook *library, int numBooks) {
    if (numBooks == 0) {
        printf("\nNo books found.\n");
        return;
    }
    
    char searchTitle[50];
    printf("\nEnter title of book to search for: ");
    scanf("%s", searchTitle);
    
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {  // check if book title matches search term
            printf("\nBook found!\n");
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Publisher: %s\n", library[i].publisher);
            printf("Price: %.2lf\n", library[i].price);
            printf("Number of pages: %d\n", library[i].numPages);
            return;
        }
    }
    
    printf("\nBook not found.\n");
}