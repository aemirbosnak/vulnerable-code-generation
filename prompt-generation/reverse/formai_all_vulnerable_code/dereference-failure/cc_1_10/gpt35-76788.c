//FormAI DATASET v1.0 Category: Ebook reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_STR_LEN 256

typedef struct {
    char title[MAX_STR_LEN];
    char author[MAX_STR_LEN];
    char format[MAX_STR_LEN];
    int year_published;
    double file_size_in_mb;
} Ebook;

void clear_input_buffer(void) {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void read_string(char *str, int max_len) {
    fgets(str, max_len, stdin);
    str[strcspn(str, "\n")] = '\0';
}

Ebook *create_book(char *title, char *author, char *format, int year_published, double file_size_in_mb) {
    Ebook *book = malloc(sizeof(Ebook));
    strcpy(book->title, title);
    strcpy(book->author, author);
    strcpy(book->format, format);
    book->year_published = year_published;
    book->file_size_in_mb = file_size_in_mb;
    return book;
}

void display_book(Ebook *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Format: %s\n", book->format);
    printf("Year Published: %d\n", book->year_published);
    printf("File Size: %.2lf MB\n\n", book->file_size_in_mb);
}

int main(void) {
    Ebook *books[MAX_BOOKS];
    int num_books = 0;

    printf("Ebook Reader Program\n\n");

    while (1) {
        printf("Choose an option:\n");
        printf("1. Add a book\n");
        printf("2. Display all books\n");
        printf("3. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter book details:\n");

                char title[MAX_STR_LEN];
                printf("Title: ");
                read_string(title, MAX_STR_LEN);

                char author[MAX_STR_LEN];
                printf("Author: ");
                read_string(author, MAX_STR_LEN);

                char format[MAX_STR_LEN];
                printf("Format: ");
                read_string(format, MAX_STR_LEN);

                int year_published;
                printf("Year Published: ");
                scanf("%d", &year_published);
                clear_input_buffer();

                double file_size_in_mb;
                printf("File Size (in MB): ");
                scanf("%lf", &file_size_in_mb);
                clear_input_buffer();

                if (num_books == MAX_BOOKS) {
                    printf("\nMaximum number of books reached. Cannot add more books.\n\n");
                } else {
                    Ebook *book = create_book(title, author, format, year_published, file_size_in_mb);
                    books[num_books++] = book;
                    printf("\nBook added successfully.\n\n");
                }
                break;

            case 2:
                if (num_books == 0) {
                    printf("\nThere are no books to display.\n\n");
                } else {
                    printf("\nList of all books:\n");
                    for (int i = 0; i < num_books; i++) {
                        display_book(books[i]);
                    }
                }
                break;

            case 3:
                printf("\nExiting program.\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice. Please enter a valid choice.\n\n");
        }
    }

    return 0;
}