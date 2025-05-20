//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

struct book {
    char title[50];
    char author[50];
    int year;
};

int num_books = 0;
struct book *books;

void add_book(const char *title, const char *author, int year) {
    if (num_books >= 10) {
        fprintf(stderr, "Database is full.\n");
        return;
    }

    struct book *new_book = (struct book *)malloc(sizeof(struct book));
    if (!new_book) {
        fprintf(stderr, "Out of memory.\n");
        return;
    }

    strcpy(new_book->title, title);
    strcpy(new_book->author, author);
    new_book->year = year;

    books[num_books] = *new_book;
    num_books++;
}

void display_books() {
    printf("Books:\n");
    for (int i = 0; i < num_books; i++) {
        printf("%s by %s (%d)\n", books[i].title, books[i].author, books[i].year);
    }
}

int main() {
    books = (struct book *)malloc(10 * sizeof(struct book));
    if (!books) {
        fprintf(stderr, "Out of memory.\n");
        return 1;
    }

    while (1) {
        int choice;
        printf("Choose an option:\n");
        printf("1. Add book\n");
        printf("2. Display books\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter title:\n");
                scanf("%s", books[num_books].title);
                printf("Enter author:\n");
                scanf("%s", books[num_books].author);
                printf("Enter year:\n");
                scanf("%d", &books[num_books].year);
                add_book(books[num_books].title, books[num_books].author, books[num_books].year);
                break;
            case 2:
                display_books();
                break;
            case 3:
                return 0;
            default:
                fprintf(stderr, "Invalid choice.\n");
        }
    }

    return 0;
}