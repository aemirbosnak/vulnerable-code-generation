//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_PHONE_LEN 20

// Structure to store a person's name and phone number
typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
} person_t;

// Function to insert a person into the phone book
void insert_person(person_t *phone_book, const char *name, const char *phone) {
    // Check if the name and phone number are not null
    if (name == NULL || phone == NULL) {
        return;
    }

    // Find an empty slot in the phone book
    int i = 0;
    while (phone_book[i].name != NULL) {
        i++;
    }

    // Insert the person into the phone book
    strcpy(phone_book[i].name, name);
    strcpy(phone_book[i].phone, phone);
}

// Function to search for a person in the phone book
person_t *search_person(const char *name, person_t *phone_book) {
    int i = 0;
    while (phone_book[i].name != NULL) {
        if (strcmp(name, phone_book[i].name) == 0) {
            return &phone_book[i];
        }
        i++;
    }
    return NULL;
}

int main() {
    // Create an empty phone book
    person_t *phone_book = malloc(sizeof(person_t) * 10);
    memset(phone_book, 0, sizeof(person_t) * 10);

    // Insert some people into the phone book
    insert_person(phone_book, "John Doe", "555-1234");
    insert_person(phone_book, "Jane Doe", "555-5678");
    insert_person(phone_book, "Bob Smith", "555-9012");

    // Search for a person in the phone book
    person_t *jane = search_person("Jane Doe", phone_book);
    if (jane != NULL) {
        printf("Found Jane Doe with phone number 555-5678\n");
    } else {
        printf("Did not find Jane Doe in the phone book\n");
    }

    // Free the memory allocated for the phone book
    free(phone_book);
    return 0;
}