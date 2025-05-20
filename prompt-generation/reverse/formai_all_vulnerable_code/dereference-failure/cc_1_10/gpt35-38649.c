//FormAI DATASET v1.0 Category: Ebook reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    char title[50];
    char author[20];
    double price;
    int pages;
    char language[20];
    char* path;
} Ebook;

void print_ebook_info(Ebook book) {
    printf("----EBOOK INFO----\n");
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Price: $%0.2lf\n", book.price);
    printf("Pages: %d\n", book.pages);
    printf("Language: %s\n", book.language);
    printf("Path: %s\n", book.path);
}

void read_ebook(Ebook book) {
    FILE* fp;
    char ch;
    fp = fopen(book.path,"r");
    if(fp == NULL) {
        printf("Error opening book!\n");
        return;
    }
    printf("----%s----\n\n", book.title);
    while((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
    fclose(fp);
}

int main() {
    Ebook books[MAX_BOOKS];
    int num_books = 0;
    int choice;
    char filename[20];

    printf("Welcome to Ebook Reader!\n");
    while(1) {
        printf("\nEnter a choice:\n");
        printf("1. Add an Ebook\n");
        printf("2. View Ebook Info\n");
        printf("3. Read an Ebook\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_books >= MAX_BOOKS) {
                    printf("Maximum number of books reached!\n");
                    break;
                }
                printf("Enter title: ");
                scanf("%s", books[num_books].title);
                printf("Enter author: ");
                scanf("%s", books[num_books].author);
                printf("Enter price: $");
                scanf("%lf", &books[num_books].price);
                printf("Enter pages: ");
                scanf("%d", &books[num_books].pages);
                printf("Enter language: ");
                scanf("%s", books[num_books].language);
                printf("Enter filename (max 20 chars): ");
                scanf("%s", filename);
                books[num_books].path = (char*) malloc(20*sizeof(char));
                strcpy(books[num_books].path, filename);
                num_books++;
                printf("Ebook added!\n");
                break;
            case 2:
                if(num_books == 0) {
                    printf("No books added yet!\n");
                    break;
                }
                for(int i=0; i<num_books; i++) {
                    printf("%d. %s by %s\n", i+1, books[i].title, books[i].author);
                }
                printf("Enter a book number: ");
                int book_num;
                scanf("%d", &book_num);
                if(book_num < 1 || book_num > num_books) {
                    printf("Invalid book number!\n");
                    break;
                }
                print_ebook_info(books[book_num-1]);
                break;
            case 3:
                if(num_books == 0) {
                    printf("No books added yet!\n");
                    break;
                }
                for(int i=0; i<num_books; i++) {
                    printf("%d. %s by %s\n", i+1, books[i].title, books[i].author);
                }
                printf("Enter a book number: ");
                scanf("%d", &book_num);
                if(book_num < 1 || book_num > num_books) {
                    printf("Invalid book number!\n");
                    break;
                }
                read_ebook(books[book_num-1]);
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}