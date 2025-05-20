//FormAI DATASET v1.0 Category: Ebook reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

struct ebook {
    char title[50];
    char author[50];
    int year;
    int pages;
};

typedef struct ebook eBook;

void print_book_info(eBook book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Year: %d\n", book.year);
    printf("Pages: %d\n", book.pages);
}

void read_ebook_file(FILE *fp, eBook library[], int *number_of_books) {
    char line[100];
    char *token;

    while (fgets(line, 100, fp)) {
        eBook book;
        token = strtok(line, ",");
        strcpy(book.title, token);
        token = strtok(NULL, ",");
        strcpy(book.author, token);
        token = strtok(NULL, ",");
        book.year = atoi(token);
        token = strtok(NULL, ",");
        book.pages = atoi(token);
        library[*number_of_books] = book;
        (*number_of_books)++;
    }

    fclose(fp);
}

void view_library(eBook library[], int number_of_books) {
    for (int i = 0; i < number_of_books; i++) {
        printf("Book #%d\n", i+1);
        print_book_info(library[i]);
        printf("\n");
    }
}

void view_book(eBook library[], int number_of_books) {
    int book_number;
    printf("Enter book number: ");
    scanf("%d", &book_number);

    if (book_number <= 0 || book_number > number_of_books) {
        printf("Invalid input\n");
        return;
    }

    printf("\n");
    print_book_info(library[book_number-1]);
    printf("\n");
}

int main() {
    eBook library[50];
    int number_of_books = 0;
    FILE *fp = fopen("books.csv", "r");
    
    if (fp == NULL) {
        printf("Error: File does not exist\n");
        return 1;
    }
    
    read_ebook_file(fp, library, &number_of_books);
    fclose(fp);
    
    int choice;
    do {
        printf("1. View library\n");
        printf("2. View book\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                view_library(library, number_of_books);
                break;
            case 2:
                view_book(library, number_of_books);
                break;
            case 3:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid input\n");
        }
        
        printf("\n");
    } while (choice != 3);

    return 0;
}