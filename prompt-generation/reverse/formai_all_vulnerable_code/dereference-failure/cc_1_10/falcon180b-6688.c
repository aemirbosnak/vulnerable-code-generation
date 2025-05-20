//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 64
#define MAX_BOOK_SIZE 1000

// Structure to hold book information
typedef struct {
    char title[MAX_BOOK_SIZE];
    char author[MAX_BOOK_SIZE];
    char genre[MAX_BOOK_SIZE];
    int pages;
    int chapters;
} Book;

// Function to read a line from the file
char* readLine(FILE* file) {
    char line[MAX_LINE_SIZE];
    char* result = fgets(line, MAX_LINE_SIZE, file);
    if (result!= NULL) {
        int length = strlen(result);
        if (length > 0 && result[length - 1] == '\n') {
            result[--length] = '\0';
        }
    }
    return result;
}

// Function to read a word from the line
char* readWord(char* line) {
    char* result = strtok(line, " \t\n\r\f\v");
    while (result!= NULL && strlen(result) == 0) {
        result = strtok(NULL, " \t\n\r\f\v");
    }
    return result;
}

// Function to read a book from the file
Book readBook(FILE* file) {
    Book book;
    char* line = readLine(file);
    while (line!= NULL && strcmp(line, "BOOK")!= 0) {
        char* word = readWord(line);
        if (strcmp(word, "TITLE") == 0) {
            strcpy(book.title, readWord(NULL));
        } else if (strcmp(word, "AUTHOR") == 0) {
            strcpy(book.author, readWord(NULL));
        } else if (strcmp(word, "GENRE") == 0) {
            strcpy(book.genre, readWord(NULL));
        } else if (strcmp(word, "PAGES") == 0) {
            book.pages = atoi(readWord(NULL));
        } else if (strcmp(word, "CHAPTERS") == 0) {
            book.chapters = atoi(readWord(NULL));
        }
        line = readLine(file);
    }
    return book;
}

// Function to print a book
void printBook(Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Genre: %s\n", book.genre);
    printf("Pages: %d\n", book.pages);
    printf("Chapters: %d\n", book.chapters);
    printf("\n");
}

// Function to read a list of books from the file
void readBooks(FILE* file) {
    char* line = readLine(file);
    while (line!= NULL && strcmp(line, "END")!= 0) {
        Book book = readBook(file);
        printBook(book);
        line = readLine(file);
    }
}

int main() {
    FILE* file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    readBooks(file);
    fclose(file);
    return 0;
}