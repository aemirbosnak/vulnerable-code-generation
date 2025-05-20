//FormAI DATASET v1.0 Category: Ebook reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// struct to represent an ebook
typedef struct ebook {
    char title[50];
    char author[30];
    int numPages;
    char* content; // dynamically allocated array to hold book content
} Ebook;

// struct to represent an ebook reader
typedef struct ebookReader {
    Ebook* currentBook; // currently open book
    int currentPage; // current page number in current book
} EbookReader;

int main() {
    // create an ebook and fill it with sample content
    Ebook* myEbook = (Ebook*) malloc(sizeof(Ebook));
    strncpy(myEbook->title, "My Happy Ebook", 50);
    strncpy(myEbook->author, "Happy Author", 30);
    myEbook->numPages = 20;
    myEbook->content = (char*) calloc(5000, sizeof(char));
    strncpy(myEbook->content, "Once upon a time, there was a happy ebook...\n", 5000);

    // create an ebook reader and open the ebook
    EbookReader myReader;
    myReader.currentBook = myEbook;
    myReader.currentPage = 1;

    // display the ebook title and author
    printf("Welcome to the Ebook reader!\n");
    printf("\n");
    printf("Title: %s\n", myEbook->title);
    printf("Author: %s\n", myEbook->author);
    printf("\n");

    // read the ebook, page by page
    int numPages = myEbook->numPages;
    char* content = myEbook->content;
    int currentPage = myReader.currentPage;
    int i;
    for (i = currentPage; i <= numPages; i++) {
        // print the current page's content
        printf("Page %d:\n", i);
        int startIndex = (i - 1) * 250;
        int endIndex = startIndex + 250;
        printf("%.*s\n", endIndex - startIndex, content + startIndex);

        // prompt the user to continue reading or close the book
        printf("Press \'C\' to continue reading or \'X\' to exit the book...\n");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'X') {
            printf("Thanks for reading! Goodbye!\n");
            exit(0);
        }
    }

    // if we reach here, the user has finished the ebook
    printf("Congratulations! You've reached the end of the book!\n");
    printf("Thanks for reading! Goodbye!\n");
    return 0;
}