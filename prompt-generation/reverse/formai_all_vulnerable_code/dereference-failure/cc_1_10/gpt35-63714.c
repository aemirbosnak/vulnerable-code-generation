//FormAI DATASET v1.0 Category: Ebook reader ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book {
    char title[50];
    char author[50];
    char publisher[50];
    char isbn[13];
    int pages;
    int year;
    char filetype[5];
    char *content;
} Book;

void readBook(Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Publisher: %s\n", book.publisher);
    printf("ISBN: %s\n", book.isbn);
    printf("Number of pages: %d\n", book.pages);
    printf("Year of publication: %d\n", book.year);
}

void displayContents(Book book) {
    printf("%s", book.content);
}

int main() {
    Book myBook;
    strcpy(myBook.title, "My Unique Ebook Reader Program");
    strcpy(myBook.author, "Ephemeral Chatbot");
    strcpy(myBook.publisher, "Ephemeral Publishers");
    strcpy(myBook.isbn, "1234567890123");
    myBook.pages = 50;
    myBook.year = 2021;
    strcpy(myBook.filetype, "txt");

    FILE *fp;
    fp = fopen("book.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    char *str;
    int size, count;
    fseek(fp, 0L, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    str = (char*)calloc(size, sizeof(char));

    if (str == NULL) {
        printf("Memory allocation failed.");
        exit(1);
    }

    count = fread(str, sizeof(char), size, fp);
    fclose(fp);

    myBook.content = str;

    readBook(myBook);
    displayContents(myBook);

    free(myBook.content);

    return 0;
}