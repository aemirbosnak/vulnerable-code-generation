//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PHONE_NUMBER 100

typedef struct PhoneNumber {
    char name[50];
    char phone_number[20];
} PhoneNumber;

void create_phone_book(PhoneNumber **phone_book) {
    *phone_book = (PhoneNumber *)malloc(MAX_PHONE_NUMBER * sizeof(PhoneNumber));
    for (int i = 0; i < MAX_PHONE_NUMBER; i++) {
        (*phone_book)[i].name[0] = '\0';
        (*phone_book)[i].phone_number[0] = '\0';
    }
}

void add_phone_number(PhoneNumber **phone_book, char *name, char *phone_number) {
    for (int i = 0; i < MAX_PHONE_NUMBER; i++) {
        if ((*phone_book)[i].name[0] == '\0') {
            strcpy((*phone_book)[i].name, name);
            strcpy((*phone_book)[i].phone_number, phone_number);
            return;
        }
    }

    printf("Error: Phone book is full.\n");
}

int search_phone_number(PhoneNumber **phone_book, char *name) {
    for (int i = 0; i < MAX_PHONE_NUMBER; i++) {
        if (strcmp((*phone_book)[i].name, name) == 0) {
            printf("Phone number: %s\n", (*phone_book)[i].phone_number);
            return 1;
        }
    }

    printf("Name not found.\n");
    return 0;
}

int main() {
    PhoneNumber *phone_book = NULL;
    create_phone_book(&phone_book);

    add_phone_number(&phone_book, "John Doe", "555-123-4567");
    add_phone_number(&phone_book, "Jane Doe", "555-234-5678");
    add_phone_number(&phone_book, "Bill Smith", "555-345-6789");

    search_phone_number(&phone_book, "John Doe");
    search_phone_number(&phone_book, "Jane Doe");
    search_phone_number(&phone_book, "Bob Smith");

    return 0;
}