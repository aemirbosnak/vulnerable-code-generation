//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_PAGES 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int pages;
} Book;

int main() {
    int num_books;
    printf("Enter the number of books: ");
    scanf("%d", &num_books);

    Book books[num_books];
    for (int i = 0; i < num_books; i++) {
        printf("Enter the title of book %d: ", i+1);
        scanf("%s", books[i].title);
        printf("Enter the author of book %d: ", i+1);
        scanf("%s", books[i].author);
        printf("Enter the number of pages of book %d: ", i+1);
        scanf("%d", &books[i].pages);
    }

    int choice;
    do {
        printf("\n1. Display all books\n2. Search for a book by title\n3. Search for a book by author\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (int i = 0; i < num_books; i++) {
                    printf("Book %d:\nTitle: %s\nAuthor: %s\nPages: %d\n\n", i+1, books[i].title, books[i].author, books[i].pages);
                }
                break;
            case 2:
                printf("Enter the title to search: ");
                char search_title[MAX_TITLE_LENGTH];
                scanf("%s", search_title);
                for (int i = 0; i < num_books; i++) {
                    if (strcmp(books[i].title, search_title) == 0) {
                        printf("Book %d:\nTitle: %s\nAuthor: %s\nPages: %d\n\n", i+1, books[i].title, books[i].author, books[i].pages);
                    }
                }
                break;
            case 3:
                printf("Enter the author to search: ");
                char search_author[MAX_AUTHOR_LENGTH];
                scanf("%s", search_author);
                for (int i = 0; i < num_books; i++) {
                    if (strcmp(books[i].author, search_author) == 0) {
                        printf("Book %d:\nTitle: %s\nAuthor: %s\nPages: %d\n\n", i+1, books[i].title, books[i].author, books[i].pages);
                    }
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 4);

    return 0;
}