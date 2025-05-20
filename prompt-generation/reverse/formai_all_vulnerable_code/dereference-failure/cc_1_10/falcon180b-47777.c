//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a struct for our book
typedef struct {
    char* title;
    char* author;
    int num_pages;
    char* content;
} Book;

// Function to print a book's info
void print_book(Book* b) {
    printf("Title: %s\n", b->title);
    printf("Author: %s\n", b->author);
    printf("Number of pages: %d\n", b->num_pages);
    printf("Content:\n%s\n", b->content);
}

// Function to read a book from a file
Book* read_book_from_file(FILE* fp) {
    Book* b = malloc(sizeof(Book));
    fscanf(fp, "Title: %[^\n]\n", b->title);
    fscanf(fp, "Author: %[^\n]\n", b->author);
    fscanf(fp, "Number of pages: %d\n", &b->num_pages);
    fscanf(fp, "Content:\n%[^\n]\n", b->content);
    return b;
}

// Function to write a book to a file
void write_book_to_file(Book* b, FILE* fp) {
    fprintf(fp, "Title: %s\n", b->title);
    fprintf(fp, "Author: %s\n", b->author);
    fprintf(fp, "Number of pages: %d\n", b->num_pages);
    fprintf(fp, "Content:\n%s\n", b->content);
}

// Function to save changes to a book
void save_book(Book* b) {
    FILE* fp = fopen("book.txt", "w");
    write_book_to_file(b, fp);
    fclose(fp);
}

// Function to display the main menu
void display_menu() {
    printf("=== Ebook Reader ===\n");
    printf("1. Read a book\n");
    printf("2. Save changes to book\n");
    printf("3. Exit\n");
}

// Main function
int main() {
    Book* book = NULL;
    int choice;

    do {
        display_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Read a book from a file
                book = read_book_from_file(fopen("book.txt", "r"));
                print_book(book);
                break;
            case 2:
                // Save changes to the book
                save_book(book);
                printf("Changes saved!\n");
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 3);

    return 0;
}