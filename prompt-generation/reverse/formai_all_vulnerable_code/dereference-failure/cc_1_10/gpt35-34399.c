//FormAI DATASET v1.0 Category: Ebook reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 50
#define MAX_AUTHOR_LEN 30
#define MAX_PAGES 500

struct Book{
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int num_pages;
    char *contents;
};

typedef struct Book Book; // Renaming struct Book to Book

void read_book(Book *book){
    printf("Enter the title: ");
    scanf("%[^\n]%*c", book->title);

    printf("Enter the author's name: ");
    scanf("%[^\n]%*c", book->author);

    printf("Enter the number of pages: ");
    scanf("%d", &book->num_pages);

    book->contents = (char*)malloc(MAX_PAGES * sizeof(char)); // allocating memory for contents

    printf("Enter the contents of the book: \n");
    scanf("%[^\n]%*c", book->contents);
}

void display_book(Book book){
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Number of pages: %d\n", book.num_pages);
    printf("Contents: %s\n", book.contents);
}

int main(){
    Book my_book;

    printf("Welcome to the Ebook Reader\n");

    printf("\nEnter the details of the book: \n");
    read_book(&my_book);

    printf("\nBook Details: \n");
    display_book(my_book);

    return 0;
}