//FormAI DATASET v1.0 Category: Ebook reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE 50
#define MAX_AUTHOR 30
#define MAX_PAGES 10000

typedef struct {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int num_pages;
    char* content;
} Book;

Book library[MAX_BOOKS];
int num_books = 0;

void add_book() {
    if (num_books == MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }

    Book new_book;

    printf("Title: ");
    fgets(new_book.title, MAX_TITLE, stdin);
    new_book.title[strcspn(new_book.title, "\n")] = 0;

    printf("Author: ");
    fgets(new_book.author, MAX_AUTHOR, stdin);
    new_book.author[strcspn(new_book.author, "\n")] = 0;

    printf("Number of pages: ");
    scanf("%d", &new_book.num_pages);
    getchar();

    new_book.content = (char*) malloc(sizeof(char) * (new_book.num_pages * MAX_PAGES));

    printf("Enter book content:\n");
    fgets(new_book.content, (new_book.num_pages * MAX_PAGES), stdin);
    new_book.content[strcspn(new_book.content, "\n")] = 0;

    library[num_books++] = new_book;

    printf("Book added successfully!\n");
}

void view_library() {
    if (num_books == 0) {
        printf("Library is empty.\n");
        return;
    }

    printf("--------------Library--------------\n");
    for (int i = 0; i < num_books; i++) {
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Number of pages: %d\n", library[i].num_pages);
        printf("Content:\n%s\n", library[i].content);
        printf("-----------------------------------\n");
    }
}

int main() {
    int choice;

    printf("Ebook Reader\n\n");

    while (1) {
        printf("1. Add Book\n");
        printf("2. View Library\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                add_book();
                break;

            case 2:
                view_library();
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}