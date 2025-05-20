//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_PHONE_NUMBER 10

typedef struct PhoneBookEntry {
    char name[20];
    int phone_number[MAX_PHONE_NUMBER];
    struct PhoneBookEntry* next;
} PhoneBookEntry;

PhoneBookEntry* insert_phone_book_entry(PhoneBookEntry* head, char* name, int phone_number) {
    PhoneBookEntry* new_entry = malloc(sizeof(PhoneBookEntry));
    strcpy(new_entry->name, name);
    for(int i = 0; i < MAX_PHONE_NUMBER; i++) {
        new_entry->phone_number[i] = phone_number;
    }
    new_entry->next = NULL;

    if(head == NULL) {
        head = new_entry;
    } else {
        head->next = new_entry;
    }

    return head;
}

int search_phone_book(PhoneBookEntry* head, char* name) {
    while(head) {
        if(strcmp(head->name, name) == 0) {
            return 1;
        } else {
            head = head->next;
        }
    }

    return 0;
}

int main() {
    PhoneBookEntry* phone_book = NULL;

    insert_phone_book_entry(phone_book, "John Doe", 12345);
    insert_phone_book_entry(phone_book, "Jane Doe", 45678);
    insert_phone_book_entry(phone_book, "Bill Smith", 98412);

    if(search_phone_book(phone_book, "John Doe") == 1) {
        printf("John Doe's phone number is: ");
        for(int i = 0; i < MAX_PHONE_NUMBER; i++) {
            printf("%d ", phone_book->phone_number[i]);
        }
        printf("\n");
    }

    return 0;
}