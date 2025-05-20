//FormAI DATASET v1.0 Category: Phone Book ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INIT_CAP 10
#define CAP_INCREMENT 5

typedef struct {
    char name[50];
    char email[50];
    char phone[15];
} contact_t;

typedef struct {
    contact_t *contacts;
    int size;
    int capacity;
} phone_book_t;

phone_book_t* create_phone_book() {
    phone_book_t *book = (phone_book_t*) malloc(sizeof(phone_book_t));
    book->size = 0;
    book->capacity = INIT_CAP;
    book->contacts = (contact_t*) malloc(INIT_CAP * sizeof(contact_t));
    return book;
}

void destroy_phone_book(phone_book_t *book) {
    free(book->contacts);
    free(book);
}

void add_contact(phone_book_t *book, const char *name, const char *email, const char *phone) {
    if(book->size == book->capacity) {
        book->capacity += CAP_INCREMENT;
        book->contacts = (contact_t*) realloc(book->contacts, book->capacity * sizeof(contact_t));
    }
    contact_t *new_contact = &(book->contacts[book->size]);
    strcpy(new_contact->name, name);
    strcpy(new_contact->email, email);
    strcpy(new_contact->phone, phone);
    book->size++;
}

int find_contact_index(const phone_book_t *book, const char *name) {
    for(int i = 0; i < book->size; i++) {
        if(strcmp(book->contacts[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void remove_contact(phone_book_t *book, const char *name) {
    int index = find_contact_index(book, name);
    if(index != -1) {
        memmove(&(book->contacts[index]), &(book->contacts[index+1]), (book->size - index - 1) * sizeof(contact_t));
        book->size--;
    }
}

void print_phone_book(const phone_book_t *book) {
    printf("NAME\t\t\tEMAIL\t\t\tPHONE\n");
    printf("----------------------------------------------------\n");
    for(int i = 0; i < book->size; i++) {
        printf("%-20s\t%-20s\t%-15s\n", book->contacts[i].name, book->contacts[i].email, book->contacts[i].phone);
    }
}

int main() {
    phone_book_t *book = create_phone_book();

    add_contact(book, "John Smith", "john.smith@gmail.com", "555-1234");
    add_contact(book, "Jane Doe", "jane.doe@hotmail.com", "555-5678");
    add_contact(book, "Bob Johnson", "bob.johnson@yahoo.com", "555-2468");
    add_contact(book, "Mary Brown", "mary.brown@gmail.com", "555-3698");

    printf("Initial phone book:\n");
    print_phone_book(book);

    remove_contact(book, "Bob Johnson");

    printf("\nPhone book after removing Bob Johnson:\n");
    print_phone_book(book);

    destroy_phone_book(book);
    return 0;
}