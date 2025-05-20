//FormAI DATASET v1.0 Category: Ebook reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* bookTitle;
    char* author;
    int numPages;
    double price;
} Book;

// function to read a book from file
Book readBookFromFile(char* filename) {
    FILE* fp = fopen(filename, "r");

    // read book details from file
    char* title = calloc(256, sizeof(char));
    char* author = calloc(256, sizeof(char));
    int numPages;
    double price;
    fscanf(fp, "%s %s %d %lf", title, author, &numPages, &price);

    fclose(fp);

    // create book instance
    Book book;
    book.bookTitle = title;
    book.author = author;
    book.numPages = numPages;
    book.price = price;

    return book;
}

// function to display book details
void displayBookDetails(Book book) {
    printf("Book Title: %s\n", book.bookTitle);
    printf("Author: %s\n", book.author);
    printf("Number of Pages: %d\n", book.numPages);
    printf("Price: $%.2lf\n\n", book.price);
}

int main() {
    // read books from files and create book arrays
    Book* harryPotterBooks = calloc(7, sizeof(Book));
    Book* lotrBooks = calloc(3, sizeof(Book));
    harryPotterBooks[0] = readBookFromFile("HP1.txt");
    harryPotterBooks[1] = readBookFromFile("HP2.txt");
    harryPotterBooks[2] = readBookFromFile("HP3.txt");
    harryPotterBooks[3] = readBookFromFile("HP4.txt");
    harryPotterBooks[4] = readBookFromFile("HP5.txt");
    harryPotterBooks[5] = readBookFromFile("HP6.txt");
    harryPotterBooks[6] = readBookFromFile("HP7.txt");
    lotrBooks[0] = readBookFromFile("FOTR.txt");
    lotrBooks[1] = readBookFromFile("TTT.txt");
    lotrBooks[2] = readBookFromFile("ROTK.txt");

    // display book details
    printf("Harry Potter Books:\n");
    for (int i = 0; i < 7; i++) {
        displayBookDetails(harryPotterBooks[i]);
    }
    printf("Lord of the Rings Books:\n");
    for (int i = 0; i < 3; i++) {
        displayBookDetails(lotrBooks[i]);
    }

    // free memory
    for (int i = 0; i < 7; i++) {
        free(harryPotterBooks[i].bookTitle);
        free(harryPotterBooks[i].author);
    }
    for (int i = 0; i < 3; i++) {
        free(lotrBooks[i].bookTitle);
        free(lotrBooks[i].author);
    }
    free(harryPotterBooks);
    free(lotrBooks);

    return 0;
}