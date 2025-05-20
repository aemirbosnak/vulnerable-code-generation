//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char *name;
    char *email;
    char *phone;
};

struct contact_book {
    struct contact *contacts;
    int num_contacts;
};

struct contact_book *create_contact_book() {
    struct contact_book *book = malloc(sizeof(struct contact_book));
    if (book == NULL) {
        return NULL;
    }

    book->contacts = NULL;
    book->num_contacts = 0;

    return book;
}

void free_contact_book(struct contact_book *book) {
    if (book == NULL) {
        return;
    }

    for (int i = 0; i < book->num_contacts; i++) {
        free(book->contacts[i].name);
        free(book->contacts[i].email);
        free(book->contacts[i].phone);
    }

    free(book->contacts);
    free(book);
}

int add_contact(struct contact_book *book, char *name, char *email, char *phone) {
    if (book == NULL) {
        return -1;
    }

    struct contact *new_contact = malloc(sizeof(struct contact));
    if (new_contact == NULL) {
        return -1;
    }

    new_contact->name = strdup(name);
    new_contact->email = strdup(email);
    new_contact->phone = strdup(phone);

    book->contacts = realloc(book->contacts, (book->num_contacts + 1) * sizeof(struct contact));
    if (book->contacts == NULL) {
        free(new_contact);
        return -1;
    }

    book->contacts[book->num_contacts] = *new_contact;
    book->num_contacts++;

    free(new_contact);

    return 0;
}

struct contact *find_contact(struct contact_book *book, char *name) {
    if (book == NULL) {
        return NULL;
    }

    for (int i = 0; i < book->num_contacts; i++) {
        if (strcmp(book->contacts[i].name, name) == 0) {
            return &book->contacts[i];
        }
    }

    return NULL;
}

int delete_contact(struct contact_book *book, char *name) {
    if (book == NULL) {
        return -1;
    }

    for (int i = 0; i < book->num_contacts; i++) {
        if (strcmp(book->contacts[i].name, name) == 0) {
            for (int j = i + 1; j < book->num_contacts; j++) {
                book->contacts[j - 1] = book->contacts[j];
            }

            book->num_contacts--;

            return 0;
        }
    }

    return -1;
}

void print_contact_book(struct contact_book *book) {
    if (book == NULL) {
        return;
    }

    for (int i = 0; i < book->num_contacts; i++) {
        printf("%s %s %s\n", book->contacts[i].name, book->contacts[i].email, book->contacts[i].phone);
    }
}

int main() {
    struct contact_book *book = create_contact_book();

    add_contact(book, "Romeo Montague", "romeo@montague.com", "555-1212");
    add_contact(book, "Juliet Capulet", "juliet@capulet.com", "555-1313");
    add_contact(book, "Tybalt Capulet", "tybalt@capulet.com", "555-1414");

    printf("Contacts:\n");
    print_contact_book(book);

    struct contact *romeo = find_contact(book, "Romeo Montague");
    printf("Romeo's email: %s\n", romeo->email);

    delete_contact(book, "Tybalt Capulet");

    printf("Contacts after deleting Tybalt:\n");
    print_contact_book(book);

    free_contact_book(book);

    return 0;
}