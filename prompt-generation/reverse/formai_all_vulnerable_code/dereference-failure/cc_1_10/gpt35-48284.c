//FormAI DATASET v1.0 Category: Ebook reader ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct EBook {
    char title[100];
    char author[100];
    char format[20];
    int length;
    float version;
    char* content;
} EBook;

void loadEBook(EBook** book, char* path) {
    FILE *fp;
    fp = fopen(path, "r");

    if(fp == NULL) {
        printf("Error reading file.");
        return;
    }

    EBook* newBook = (EBook*) malloc(sizeof(EBook));
    strcpy(newBook->title, path);
    strcpy(newBook->format, "txt");

    int i;
    char line[256];
    for (i = 0; fgets(line, sizeof(line), fp); i++) {
        newBook->content = (char*) realloc(newBook->content, (i + 1) * sizeof(char) * 256);
        strcpy(&newBook->content[i * 256], line);
    }
    newBook->length = i;
    *book = newBook;

    fclose(fp);
}

void printEBook(EBook* book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Format: %s\n", book->format);
    printf("Length: %d\n", book->length);
    printf("Version: %.1f\n\n", book->version);
}

void displayEBook(EBook* book, int start, int end) {
    int i;
    for(i = start; i < end && i < book->length; i++) {
        printf("%s", &book->content[i * 256]);
    }
}

int main() {
    EBook* book;
    loadEBook(&book, "MyEBook.txt");

    strcpy(book->author, "John Doe");
    book->version = 1.0;

    printEBook(book);
    displayEBook(book, 0, 10);

    return 0;
}