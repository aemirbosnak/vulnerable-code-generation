//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 50
#define MAX_PHONE_NUM_LEN 20
#define MAX_ADDRESS_LEN 100

// Structure to hold a phone book entry
typedef struct {
    char name[MAX_NAME_LEN];
    char phone_num[MAX_PHONE_NUM_LEN];
    char address[MAX_ADDRESS_LEN];
} phone_book_entry;

// Function to generate a random phone book entry
phone_book_entry generate_entry(void) {
    char name[MAX_NAME_LEN];
    char phone_num[MAX_PHONE_NUM_LEN];
    char address[MAX_ADDRESS_LEN];

    // Generate a random name
    srand(time(NULL));
    for (int i = 0; i < MAX_NAME_LEN; i++) {
        name[i] = 'A' + (rand() % 26);
    }

    // Generate a random phone number
    for (int i = 0; i < MAX_PHONE_NUM_LEN; i++) {
        phone_num[i] = '0' + (rand() % 10);
    }

    // Generate a random address
    for (int i = 0; i < MAX_ADDRESS_LEN; i++) {
        address[i] = 'A' + (rand() % 26);
    }

    return (phone_book_entry) {
        .name = name,
        .phone_num = phone_num,
        .address = address
    };
}

int main(void) {
    // Create an empty phone book
    phone_book_entry *phone_book = calloc(1, sizeof(phone_book_entry));

    // Add some entries to the phone book
    for (int i = 0; i < 10; i++) {
        phone_book[i] = generate_entry();
    }

    // Print the phone book
    for (int i = 0; i < 10; i++) {
        printf("%d. %s %s %s\n", i + 1, phone_book[i].name, phone_book[i].phone_num, phone_book[i].address);
    }

    return 0;
}