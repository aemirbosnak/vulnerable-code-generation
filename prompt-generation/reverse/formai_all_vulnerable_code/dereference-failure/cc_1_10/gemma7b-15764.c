//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 10
#define MAX_PAGES 100

typedef struct Book
{
    char title[50];
    int pages;
    struct Book* next;
} Book;

void readBook(Book* book)
{
    printf("You are reading: %s\n", book->title);
    printf("Number of pages: %d\n", book->pages);
    printf("Please turn to a page: ");
    int page = atoi(stdin);
    printf("Content of page %d: %s\n", page, book->pages * page);
}

int main()
{
    Book* books = NULL;
    Book* currentPage = NULL;

    // Create a few books
    for (int i = 0; i < MAX_BOOKS; i++)
    {
        Book* newBook = (Book*)malloc(sizeof(Book));
        strcpy(newBook->title, "Book #");
        newBook->pages = rand() % MAX_PAGES + 1;
        newBook->next = NULL;

        if (books == NULL)
        {
            books = newBook;
            currentPage = newBook;
        }
        else
        {
            currentPage->next = newBook;
            currentPage = newBook;
        }
    }

    // Read a book
    readBook(currentPage);

    return 0;
}