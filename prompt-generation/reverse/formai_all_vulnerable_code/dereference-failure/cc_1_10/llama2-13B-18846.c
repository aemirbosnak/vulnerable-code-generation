//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PHONE_BOOK_SIZE 100
#define NAME_LENGTH 20
#define PHONE_NUMBER_LENGTH 10

struct phone_book {
    char name[NAME_LENGTH];
    char phone_number[PHONE_NUMBER_LENGTH];
};

// Function to initialize the phone book
void init_phone_book(struct phone_book *phone_book) {
    int i;
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        phone_book[i].name[0] = '\0';
        phone_book[i].phone_number[0] = '\0';
    }
}

// Function to add a new entry to the phone book
void add_entry(struct phone_book *phone_book, char *name, char *phone_number) {
    int i;
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            // Entry already exists, update the phone number
            strcpy(phone_book[i].phone_number, phone_number);
            return;
        }
    }
    // Entry does not exist, add a new one
    strcpy(phone_book[i].name, name);
    strcpy(phone_book[i].phone_number, phone_number);
    i++;
}

// Function to search for a phone number in the phone book
int search_phone_number(struct phone_book *phone_book, char *phone_number) {
    int i;
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (strcmp(phone_book[i].phone_number, phone_number) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to display the phone book
void display_phone_book(struct phone_book *phone_book) {
    int i;
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        printf("%d: %s %s\n", i, phone_book[i].name, phone_book[i].phone_number);
    }
}

int main() {
    struct phone_book phone_book;
    char name[NAME_LENGTH];
    char phone_number[PHONE_NUMBER_LENGTH];
    int choice;

    // Initialize the phone book
    init_phone_book(&phone_book);

    do {
        printf("Enter a name: ");
        fgets(name, NAME_LENGTH, stdin);
        printf("Enter a phone number: ");
        fgets(phone_number, PHONE_NUMBER_LENGTH, stdin);

        // Add a new entry to the phone book
        add_entry(&phone_book, name, phone_number);

        // Display the phone book
        display_phone_book(&phone_book);

        // Ask the user to search for a phone number
        printf("Do you want to search for a phone number? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y') {
            // Search for a phone number
            int found = search_phone_number(&phone_book, phone_number);
            if (found != -1) {
                printf("Found %s at index %d\n", phone_number, found);
            } else {
                printf("Not found\n");
            }
        }
    } while (1);

    return 0;
}