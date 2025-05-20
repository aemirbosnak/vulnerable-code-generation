//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define some constants and types
#define MAX_STRING_LENGTH 1024
#define MAX_ARRAY_SIZE 100

typedef struct {
    char *name;
    int age;
} person_t;

typedef struct {
    char *book_title;
    int page_count;
} book_t;

// Function to allocate memory for a person struct
person_t *create_person(char *name, int age) {
    person_t *ptr = (person_t *)malloc(sizeof(person_t));
    ptr->name = name;
    ptr->age = age;
    return ptr;
}

// Function to allocate memory for a book struct
book_t *create_book(char *book_title, int page_count) {
    book_t *ptr = (book_t *)malloc(sizeof(book_t));
    ptr->book_title = book_title;
    ptr->page_count = page_count;
    return ptr;
}

// Function to print a person's details
void print_person(person_t *ptr) {
    printf("Name: %s, Age: %d\n", ptr->name, ptr->age);
}

// Function to print a book's details
void print_book(book_t *ptr) {
    printf("Book Title: %s, Page Count: %d\n", ptr->book_title, ptr->page_count);
}

// Main function
int main() {
    // Allocate memory for a person struct
    person_t *john = create_person("John Doe", 35);

    // Allocate memory for a book struct
    book_t *harry_potter = create_book("Harry Potter and the Philosopher's Stone", 300);

    // Print the person's details
    print_person(john);

    // Print the book's details
    print_book(harry_potter);

    // Free the memory for the person struct
    free(john);

    // Free the memory for the book struct
    free(harry_potter);

    return 0;
}