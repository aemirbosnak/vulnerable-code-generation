//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Book data structure
typedef struct {
    char *title;
    char *author;
    char *text;
    int num_pages;
    int current_page;
} Book;

// Function to create a new book
Book *create_book(char *title, char *author, char *text, int num_pages) {
    Book *book = malloc(sizeof(Book));
    book->title = title;
    book->author = author;
    book->text = text;
    book->num_pages = num_pages;
    book->current_page = 1;
    return book;
}

// Function to free a book
void free_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book->text);
    free(book);
}

// Function to print a book
void print_book(Book *book) {
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Number of pages: %d\n", book->num_pages);
    printf("Current page: %d\n", book->current_page);
    printf("\n");
    printf("%s\n", book->text);
}

// Function to turn a page
void turn_page(Book *book) {
    if (book->current_page < book->num_pages) {
        book->current_page++;
    } else {
        printf("You are already on the last page.\n");
    }
}

// Function to go to a specific page
void go_to_page(Book *book, int page) {
    if (page > 0 && page <= book->num_pages) {
        book->current_page = page;
    } else {
        printf("Invalid page number.\n");
    }
}

// Function to search for a word in a book
int search_word(Book *book, char *word) {
    char *ptr = strstr(book->text, word);
    if (ptr != NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Main function
int main() {
    // Create a new book
    Book *book = create_book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams",
    "Far out in the uncharted backwaters of the unfashionable end of the western spiral arm of the Galaxy lies a small, unassuming planet called Earth.\n\nThis planet is home to a wide variety of biological life forms, including the human race, who are known for their intelligence and their love of tea.", 100);

    // Print the book
    print_book(book);

    // Turn a page
    turn_page(book);

    // Go to a specific page
    go_to_page(book, 10);

    // Search for a word in the book
    int found = search_word(book, "tea");
    if (found) {
        printf("The word \"tea\" was found in the book.\n");
    } else {
        printf("The word \"tea\" was not found in the book.\n");
    }

    // Free the book
    free_book(book);

    return 0;
}