//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30
#define MAX_ISBN_LENGTH 13

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char isbn[MAX_ISBN_LENGTH];
} Book;

Book books[MAX_BOOKS];
int num_books = 0;

void create_book(const char *title, const char *author, const char *isbn) {
    char *new_title = malloc(strlen(title) + 1);
    strcpy(new_title, title);
    char *new_author = malloc(strlen(author) + 1);
    strcpy(new_author, author);
    char *new_isbn = malloc(strlen(isbn) + 1);
    strcpy(new_isbn, isbn);

    Book new_book = {new_title, new_author, new_isbn};

    if (num_books >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        free(new_title);
        free(new_author);
        free(new_isbn);
        return;
    }

    books[num_books] = new_book;
    num_books++;
    printf("Book added successfully.\n");

    free(new_title);
    free(new_author);
    free(new_isbn);
}

void print_books() {
    for (int i = 0; i < num_books; i++) {
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("ISBN: %s\n", books[i].isbn);
        printf("\n");
    }
}

void search_book(const char *title) {
    for (int i = 0; i < num_books; i++) {
        if (strcmp(books[i].title, title) == 0) {
            printf("Book found!\n");
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("ISBN: %s\n", books[i].isbn);
            printf("\n");
            return;
        }
    }
    printf("Book not found.\n");
}

void remove_book(int index) {
    if (index >= 0 && index < num_books) {
        free(books[index].title);
        free(books[index].author);
        free(books[index].isbn);

        for (int i = index; i < num_books - 1; i++) {
            books[i] = books[i + 1];
        }

        num_books--;
        printf("Book removed successfully.\n");
    } else {
        printf("Invalid book index.\n");
    }
}

void exit_program() {
    for (int i = 0; i < num_books; i++) {
        free(books[i].title);
        free(books[i].author);
        free(books[i].isbn);
    }
    free(books);
}

int main() {
    while (true) {
        printf("1. Add a new book\n2. List all books\n3. Search for a book\n4. Remove a book\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter title, author, and ISBN:\n");
                char title[MAX_TITLE_LENGTH];
                char author[MAX_AUTHOR_LENGTH];
                char isbn[MAX_ISBN_LENGTH];
                scanf("%s%s%s", title, author, isbn);
                create_book(title, author, isbn);
                break;
            case 2:
                print_books();
                break;
            case 3:
                printf("Enter book title to search for:\n");
                char title_search[MAX_TITLE_LENGTH];
                scanf("%s", title_search);
                search_book(title_search);
                break;
            case 4:
                printf("Enter book index to remove (1-based):\n");
                int index;
                scanf("%d", &index);
                remove_book(index - 1);
                break;
            case 5:
                exit_program();
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}