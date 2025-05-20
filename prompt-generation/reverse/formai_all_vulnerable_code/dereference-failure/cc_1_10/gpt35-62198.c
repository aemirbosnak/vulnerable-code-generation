//FormAI DATASET v1.0 Category: Ebook reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>

struct Book {
    char title[50];
    char author[50];
    int ISBN;
};

struct Node {
    struct Book book;
    struct Node* next;
};

struct Library {
    struct Node* head;
};

//function for adding a book to the library
void add_book(struct Library* lib, char title[], char author[], int ISBN) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    strcpy(new_node->book.title, title);
    strcpy(new_node->book.author, author);
    new_node->book.ISBN = ISBN;
    new_node->next = NULL;

    if (lib->head == NULL) {
        lib->head = new_node;
        return;
    }

    struct Node* current = lib->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

//function for removing a book from the library
void remove_book(struct Library* lib, char title[], char author[], int ISBN) {
    struct Node* prev = NULL;
    struct Node* current = lib->head;

    while (current != NULL) {
        if (strcmp(current->book.title, title) == 0 && strcmp(current->book.author, author) == 0 && current->book.ISBN == ISBN) {
            if (prev == NULL) {
                lib->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

//function for displaying all the books in the library
void display_books(struct Library* lib) {
    struct Node* current = lib->head;
    while (current != NULL) {
        printf("Title: %s\n", current->book.title);
        printf("Author: %s\n", current->book.author);
        printf("ISBN: %d\n", current->book.ISBN);
        printf("\n");
        current = current->next;
    }
}

int main() {
    struct Library lib;
    lib.head = NULL;

    //adding books to the library
    add_book(&lib, "The C Programming Language", "Dennis Ritchie and Brian Kernighan", 9780131103627);
    add_book(&lib, "C Primer Plus", "Steven Prata", 9780134191630);
    add_book(&lib, "Head First C", "David Griffiths and Dawn Griffiths", 9780596006309);
    add_book(&lib, "Effective C: An Introduction to Professional C Programming", "Robert C. Seacord", 9780321958310);

    //displaying all the books in the library
    printf("All Books in the Library:\n\n");
    display_books(&lib);

    //removing a book from the library
    remove_book(&lib, "The C Programming Language", "Dennis Ritchie and Brian Kernighan", 9780131103627);

    //displaying all the books in the library after removal
    printf("All Books in the Library after removal:\n\n");
    display_books(&lib);

    return 0;
}