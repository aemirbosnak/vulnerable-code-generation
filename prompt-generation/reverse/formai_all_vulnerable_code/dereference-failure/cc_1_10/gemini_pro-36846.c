//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a page in the book
typedef struct page {
    char *text;
    struct page *next;
    struct page *prev;
} page;

// Define a struct to represent the book
typedef struct book {
    page *first_page;
    page *last_page;
    int num_pages;
} book;

// Function to create a new page
page *create_page(char *text) {
    page *new_page = (page *)malloc(sizeof(page));
    new_page->text = text;
    new_page->next = NULL;
    new_page->prev = NULL;
    return new_page;
}

// Function to add a page to the end of the book
void add_page(book *book, page *new_page) {
    if (book->first_page == NULL) {
        book->first_page = new_page;
        book->last_page = new_page;
    } else {
        book->last_page->next = new_page;
        new_page->prev = book->last_page;
        book->last_page = new_page;
    }
    book->num_pages++;
}

// Function to remove a page from the book
void remove_page(book *book, page *page_to_remove) {
    if (page_to_remove == book->first_page) {
        book->first_page = page_to_remove->next;
        if (book->first_page != NULL) {
            book->first_page->prev = NULL;
        }
    } else if (page_to_remove == book->last_page) {
        book->last_page = page_to_remove->prev;
        if (book->last_page != NULL) {
            book->last_page->next = NULL;
        }
    } else {
        page_to_remove->prev->next = page_to_remove->next;
        page_to_remove->next->prev = page_to_remove->prev;
    }
    book->num_pages--;
    free(page_to_remove);
}

// Function to print the book
void print_book(book *book) {
    page *current_page = book->first_page;
    while (current_page != NULL) {
        printf("%s\n", current_page->text);
        current_page = current_page->next;
    }
}

// Function to free the memory allocated for the book
void free_book(book *book) {
    page *current_page = book->first_page;
    while (current_page != NULL) {
        page *next_page = current_page->next;
        free(current_page->text);
        free(current_page);
        current_page = next_page;
    }
    free(book);
}

int main() {
    // Create a new book
    book *my_book = (book *)malloc(sizeof(book));
    my_book->first_page = NULL;
    my_book->last_page = NULL;
    my_book->num_pages = 0;

    // Add some pages to the book
    add_page(my_book, create_page("Page 1"));
    add_page(my_book, create_page("Page 2"));
    add_page(my_book, create_page("Page 3"));

    // Print the book
    print_book(my_book);

    // Remove a page from the book
    remove_page(my_book, my_book->first_page);

    // Print the book again
    print_book(my_book);

    // Free the memory allocated for the book
    free_book(my_book);

    return 0;
}