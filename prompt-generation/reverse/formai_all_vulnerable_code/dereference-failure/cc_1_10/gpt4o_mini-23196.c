//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
    char *content; // Pointer to store file content
} Book;

void clearScreen() {
    // Attempting to clear the screen, let's hope it does not blow your monitor!
    printf("\033[H\033[J");
}

void pause() {
    printf("Press Enter to continue...");
    while (getchar() != '\n');
}

void welcomeBanner() {
    clearScreen();
    printf("===================================\n");
    printf("         C E-Book Reader          \n");
    printf("===================================\n");
    printf("Join us on this literary adventure!\n");
    pause();
}

void addBook(Book books[], int *totalBooks) {
    if (*totalBooks >= MAX_BOOKS) {
        printf("Whoa there! We can only hold so many stories!\n");
        return;
    }

    Book newBook;

    printf("Enter the title of the book: ");
    getchar(); // Cleaning up the newline
    fgets(newBook.title, MAX_TITLE_LENGTH, stdin);
    strtok(newBook.title, "\n"); // Removing the newline

    printf("Who wrote this masterpiece? ");
    fgets(newBook.author, MAX_AUTHOR_LENGTH, stdin);
    strtok(newBook.author, "\n");

    printf("How many pages does it have? ");
    scanf("%d", &newBook.pages);
    
    // Read the content from the book file
    newBook.content = malloc(newBook.pages * 100); // Assume each page can have 100 characters
    if (newBook.content == NULL) {
        printf("Memory allocation failed! Better luck next time.\n");
        return;
    }

    printf("Enter the content of the book (end with a blank line):\n");
    getchar(); // Clean up the newline from pages
    for (int i = 0; i < newBook.pages; i++) {
        fgets(newBook.content + (i * 100), 100, stdin);
        if (strcmp(newBook.content + (i * 100), "\n") == 0) {
            break;
        }
    }

    books[*totalBooks] = newBook;
    (*totalBooks)++;

    printf("Book added successfully! Remember to keep some bookmarks handy!\n");
    pause();
}

void displayBooks(Book books[], int totalBooks) {
    clearScreen();
    printf("List of Books:\n");
    for (int i = 0; i < totalBooks; i++) {
        printf("%d: \"%s\" by %s (%d pages)\n", 
            i + 1, books[i].title, books[i].author, books[i].pages);
    }
    pause();
}

void readBook(Book books[], int totalBooks) {
    int choice;
    displayBooks(books, totalBooks);
    
    printf("Which book would you like to read? (1-%d): ", totalBooks);
    scanf("%d", &choice);
    
    if (choice < 1 || choice > totalBooks) {
        printf("That's not a valid choice! Books don’t bite—most of the time.\n");
        pause();
        return;
    }

    Book selectedBook = books[choice - 1];
    clearScreen();
    printf("Now reading: \"%s\"\n", selectedBook.title);
    printf("Written by: %s\n\n", selectedBook.author);
    printf("Pages:\n");

    for (int i = 0; i < selectedBook.pages; i++) {
        printf("%s", selectedBook.content + (i * 100));
    }
    pause();
}

void freeBooks(Book books[], int totalBooks) {
    for (int i = 0; i < totalBooks; i++) {
        free(books[i].content);
    }
}

int main() {
    Book books[MAX_BOOKS];
    int totalBooks = 0;
    int option;

    welcomeBanner();

    while (1) {
        clearScreen();
        printf("Choose an option:\n");
        printf("1. Add a new book\n");
        printf("2. Read a book\n");
        printf("3. Show book list\n");
        printf("4. Exit the C E-Book Reader (we'll miss you!)\n");
        printf("Your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addBook(books, &totalBooks);
                break;
            case 2:
                readBook(books, totalBooks);
                break;
            case 3:
                displayBooks(books, totalBooks);
                break;
            case 4:
                freeBooks(books, totalBooks);
                printf("Thanks for reading! Now go conquer the world!\n");
                exit(0);
            default:
                printf("Oops! That's not a valid option! Try again...\n");
                pause();
        }
    }

    return 0;
}