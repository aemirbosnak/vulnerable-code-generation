//FormAI DATASET v1.0 Category: Ebook reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 50
#define MAX_PUB_YEAR_LEN 10
#define MAX_PAGES_LEN 5

typedef struct {
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    char pub_year[MAX_PUB_YEAR_LEN];
    char pages[MAX_PAGES_LEN];
    char* content;
} Book;

void add_book(Book* book, FILE* fp) {
    printf("Enter book title: ");
    fgets(book->title, MAX_TITLE_LEN, stdin);
    printf("Enter author: ");
    fgets(book->author, MAX_AUTHOR_LEN, stdin);
    printf("Enter publication year: ");
    fgets(book->pub_year, MAX_PUB_YEAR_LEN, stdin);
    printf("Enter number of pages: ");
    fgets(book->pages, MAX_PAGES_LEN, stdin);
    book->content = (char*) malloc(sizeof(char) * MAX_BOOKS);
    printf("Enter book content: ");
    fgets(book->content, MAX_BOOKS, stdin);

    fprintf(fp, "%s,%s,%s,%s,%s", book->title, book->author, book->pub_year, book->pages, book->content);
}

void print_book(Book book) {
    printf("\nTitle: %sAuthor: %sPublication year: %sNumber of pages: %s\n", book.title, book.author, book.pub_year, book.pages);
}

void search_book(char search_query[], Book books[], int num_books) {
    int found = 0;
    for (int i = 0; i < num_books; i++) {
        if (strstr(books[i].title, search_query) != NULL) {
            print_book(books[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No books found.\n");
    }
}

int main() {
    Book books[MAX_BOOKS];
    int num_books = 0;

    FILE* fp = fopen("books.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char line[MAX_BOOKS];
    while (fgets(line, MAX_BOOKS, fp) != NULL) {
        char* token = strtok(line, ",");
        strcpy(books[num_books].title, token);
        token = strtok(NULL, ",");
        strcpy(books[num_books].author, token);
        token = strtok(NULL, ",");
        strcpy(books[num_books].pub_year, token);
        token = strtok(NULL, ",");
        strcpy(books[num_books].pages, token);
        token = strtok(NULL, ",");
        books[num_books].content = strdup(token);
        num_books++;
    }

    int option;
    char search_query[MAX_TITLE_LEN];

    do {
        printf("1. Add book\n");
        printf("2. Search for book\n");
        printf("3. Exit\n");
        scanf("%d", &option);
        getchar();

        switch(option) {
            case 1:
                if (num_books < MAX_BOOKS) {
                    add_book(&books[num_books], fp);
                    num_books++;
                } else {
                    printf("Cannot add more books. Maximum limit reached.\n");
                }
                break;
            case 2:
                printf("Enter search query: ");
                fgets(search_query, MAX_TITLE_LEN, stdin);
                search_book(search_query, books, num_books);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    } while(option != 3);

    fclose(fp);
    return 0;
}