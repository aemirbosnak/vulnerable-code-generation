//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define PHONE_BOOK_SIZE 1024
#define NAME_MAX_LEN 256
#define PHONE_MAX_LEN 64

typedef struct phone_book {
    char *names[PHONE_BOOK_SIZE];
    char *phones[PHONE_BOOK_SIZE];
} phone_book;

phone_book *create_phone_book() {
    phone_book *pb = (phone_book *)calloc(1, sizeof(phone_book));
    return pb;
}

void add_contact(phone_book *pb, const char *name, const char *phone) {
    if (pb->names[0] == NULL) {
        pb->names[0] = strdup(name);
        pb->phones[0] = strdup(phone);
    } else {
        int i = 0;
        while (i < PHONE_BOOK_SIZE && pb->names[i] != NULL) i++;
        if (i < PHONE_BOOK_SIZE) {
            pb->names[i] = strdup(name);
            pb->phones[i] = strdup(phone);
        } else {
            printf("Phone book is full, cannot add more contacts\n");
        }
    }
}

void print_contacts(phone_book *pb) {
    int i = 0;
    while (i < PHONE_BOOK_SIZE && pb->names[i] != NULL) {
        printf("%s %s\n", pb->names[i], pb->phones[i]);
        i++;
    }
}

int main() {
    phone_book *pb = create_phone_book();

    add_contact(pb, "John Doe", "555-1234");
    add_contact(pb, "Jane Doe", "555-5678");
    add_contact(pb, "Bob Smith", "555-9012");

    print_contacts(pb);

    return 0;
}