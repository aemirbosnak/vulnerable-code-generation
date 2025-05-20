//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PHONE_BOOK_MAX_NAME_LEN 50
#define PHONE_BOOK_MAX_NUMBER_LEN 20

typedef struct phone_book_entry {
    char name[PHONE_BOOK_MAX_NAME_LEN];
    char number[PHONE_BOOK_MAX_NUMBER_LEN];
} phone_book_entry_t;

typedef struct phone_book {
    int size;
    phone_book_entry_t** entries;
} phone_book_t;

int main() {
    phone_book_t* phone_book = calloc(1, sizeof(phone_book_t));
    phone_book->size = 0;

    // Add some entries to the phone book
    phone_book_entry_t* entry1 = calloc(1, sizeof(phone_book_entry_t));
    strcpy(entry1->name, "John Doe");
    strcpy(entry1->number, "555-1234");
    phone_book->entries[0] = entry1;

    phone_book_entry_t* entry2 = calloc(1, sizeof(phone_book_entry_t));
    strcpy(entry2->name, "Jane Doe");
    strcpy(entry2->number, "555-5678");
    phone_book->entries[1] = entry2;

    phone_book_entry_t* entry3 = calloc(1, sizeof(phone_book_entry_t));
    strcpy(entry3->name, "Bob Smith");
    strcpy(entry3->number, "555-9012");
    phone_book->entries[2] = entry3;

    // Search for an entry
    char search_name[] = "John Doe";
    int i;
    for (i = 0; i < phone_book->size; i++) {
        if (strcmp(phone_book->entries[i]->name, search_name) == 0) {
            break;
        }
    }

    if (i == phone_book->size) {
        printf("Name not found\n");
    } else {
        printf("Name found: %s\n", search_name);
        printf("Number: %s\n", phone_book->entries[i]->number);
    }

    // Remove an entry
    int remove_index = 0;
    if (phone_book->size > 0) {
        remove_index = phone_book->size - 1;
        phone_book->size--;
        memmove(phone_book->entries, phone_book->entries + remove_index,
            (phone_book->size - remove_index) * sizeof(phone_book_entry_t*));
        free(phone_book->entries[remove_index]);
    }

    // Print the phone book
    for (i = 0; i < phone_book->size; i++) {
        printf("%d: %s %s\n", i, phone_book->entries[i]->name,
            phone_book->entries[i]->number);
    }

    return 0;
}