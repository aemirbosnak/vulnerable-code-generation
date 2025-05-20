//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char author[50];
    char year[10];
    char publisher[50];
    char pages[10];
} Book;

Book* getBook(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file '%s'\n", filename);
        exit(1);
    }

    char buffer[100];
    fgets(buffer, 100, file); // Read the title line
    fgets(buffer, 100, file); // Read the author line
    fgets(buffer, 100, file); // Read the year line
    fgets(buffer, 100, file); // Read the publisher line
    fgets(buffer, 100, file); // Read the pages line

    fclose(file);

    Book* book = malloc(sizeof(Book));
    strcpy(book->title, buffer);
    strcpy(book->author, buffer);
    strcpy(book->year, buffer);
    strcpy(book->publisher, buffer);
    strcpy(book->pages, buffer);

    return book;
}

int main() {
    Book* book = getBook("ebook.txt");

    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Year: %s\n", book->year);
    printf("Publisher: %s\n", book->publisher);
    printf("Pages: %s\n", book->pages);

    free(book);

    return 0;
}