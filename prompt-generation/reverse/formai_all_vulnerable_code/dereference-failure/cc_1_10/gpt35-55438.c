//FormAI DATASET v1.0 Category: Database querying ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[50];
    char author[50];
    int pages;
    float price;
};

void insertBook(struct Book **library, int index);
void displayBooks(struct Book **library, int numBooks);
void searchBook(struct Book **library, int numBooks, char query[]);
void deleteBook(struct Book **library, int *numBooks, char title[]);

int main() {
    int choice, numBooks = 0;

    struct Book **library = (struct Book **) malloc(sizeof(struct Book *));
    *library = NULL;

    printf("Welcome to your library!\n");

    do {
        printf("\nChoose an option:\n");
        printf("1. Add a book to the library\n");
        printf("2. Display all books in the library\n");
        printf("3. Search for a book by title\n");
        printf("4. Delete a book from the library\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                insertBook(library, numBooks);
                numBooks++;
                break;
            case 2:
                displayBooks(library, numBooks);
                break;
            case 3:
                printf("Enter the title of the book to search for: ");
                char query[50];
                scanf(" %[^\n]s", query);
                searchBook(library, numBooks, query);
                break;
            case 4:
                printf("Enter the title of the book to delete: ");
                char title[50];
                scanf(" %[^\n]s", title);
                deleteBook(library, &numBooks, title);
                break;
            case 5:
                printf("Thank you for using your library!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    free(*library);
    free(library);

    return 0;
}

void insertBook(struct Book **library, int index) {
    struct Book newBook;

    printf("Enter the title of the book: ");
    scanf(" %[^\n]s", newBook.title);

    printf("Enter the name of the author: ");
    scanf(" %[^\n]s", newBook.author);

    printf("Enter the number of pages: ");
    scanf("%d", &newBook.pages);

    printf("Enter the price of the book: ");
    scanf("%f", &newBook.price);

    *(library + index) = (struct Book *) malloc(sizeof(struct Book));
    **(library + index) = newBook;
}

void displayBooks(struct Book **library, int numBooks) {
    if (numBooks == 0) {
        printf("There are no books in the library.\n");
    } else {
        printf("The following books are in the library:\n");
        for (int i = 0; i < numBooks; i++) {
            printf("%d. %s by %s\n", i+1, (*(library + i))->title, (*(library + i))->author);
        }
    }
}

void searchBook(struct Book **library, int numBooks, char query[]) {
    for (int i = 0; i < numBooks; i++) {
        if (strcmp((*(library + i))->title, query) == 0) {
            printf("Found: %s by %s\n", (*(library + i))->title, (*(library + i))->author);
            return;
        }
    }

    printf("No book found with that title.\n");
}

void deleteBook(struct Book **library, int *numBooks, char title[]) {
    int indexToDelete = -1;
    for (int i = 0; i < *numBooks; i++) {
        if (strcmp((*(library + i))->title, title) == 0) {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete == -1) {
        printf("No book found with that title.\n");
    } else {
        free(*(library + indexToDelete));

        for (int i = indexToDelete; i < (*numBooks) - 1; i++) {
            *(library + i) = *(library + i + 1);
        }

        *(library + (*numBooks) - 1) = NULL;
        (*numBooks)--;
        printf("Book deleted.\n");
    }
}