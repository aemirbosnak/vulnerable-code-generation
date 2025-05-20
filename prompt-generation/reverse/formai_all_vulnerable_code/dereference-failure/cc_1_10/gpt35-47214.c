//FormAI DATASET v1.0 Category: Ebook reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book {
    char title[100];
    char author[50];
    char publisher[50];
    char year_published[10];
    int num_of_pages;
} Book;

typedef struct node {
    Book book;
    struct node* next;
} Node;

Node* head = NULL;

void insert_book(Book book) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->book = book;
    new_node->next = head;
    head = new_node;
}

void print_all_books() {
    Node* current_node = head;
    while (current_node != NULL) {
        printf("Title: %s\n", current_node->book.title);
        printf("Author: %s\n", current_node->book.author);
        printf("Publisher: %s\n", current_node->book.publisher);
        printf("Year Published: %s\n", current_node->book.year_published);
        printf("Number of Pages: %d\n\n", current_node->book.num_of_pages);
        current_node = current_node->next;
    }
}

void delete_book(char* title) {
    Node* current_node = head;
    Node* previous_node = NULL;
    while (current_node != NULL && strcmp(current_node->book.title, title) != 0) {
        previous_node = current_node;
        current_node = current_node->next;
    }
    if (current_node == NULL) {
        printf("Book not found.\n");
        return;
    }
    if (previous_node == NULL) {
        head = current_node->next;
    } else {
        previous_node->next = current_node->next;
    }
    free(current_node);
}

int main() {
    // Sample book data
    Book book1 = { .title = "The C Programming Language", .author = "Brian W. Kernighan and Dennis M. Ritchie", .publisher = "Prentice Hall Professional Technical Reference", .year_published = "1978", .num_of_pages = 272 };
    Book book2 = { .title = "C: A Reference Manual", .author = "Harbison, Samuel; Steele Jr., Guy L.", .publisher = "Prentice Hall", .year_published = "2002", .num_of_pages = 576 };
    Book book3 = { .title = "Expert C Programming", .author = "Peter van der Linden", .publisher = "Prentice Hall", .year_published = "1994", .num_of_pages = 300 };

    // Insert books into the linked list
    insert_book(book1);
    insert_book(book2);
    insert_book(book3);

    // Print all books
    printf("All books in list:\n");
    print_all_books();

    // Delete book with title "Expert C Programming"
    printf("Deleting book with title 'Expert C Programming':\n");
    delete_book("Expert C Programming");

    // Print updated list of books
    printf("All books in list after deletion:\n");
    print_all_books();

    return 0;
}