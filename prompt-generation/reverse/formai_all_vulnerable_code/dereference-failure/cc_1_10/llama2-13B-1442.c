//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define PHONE_BOOK_SIZE 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 20

typedef struct phone_book {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
} phone_book;

phone_book phone_book_array[PHONE_BOOK_SIZE];
int current_size = 0;

void add_phone_book(char *name, char *phone_number) {
    if (current_size == PHONE_BOOK_SIZE) {
        printf("Phone book is full, cannot add more entries\n");
        return;
    }
    strcpy(phone_book_array[current_size].name, name);
    strcpy(phone_book_array[current_size].phone_number, phone_number);
    current_size++;
}

void search_phone_book(char *name) {
    int i;
    for (i = 0; i < current_size; i++) {
        if (strcmp(name, phone_book_array[i].name) == 0) {
            printf("Found: %s\n", phone_book_array[i].phone_number);
            return;
        }
    }
    printf("Not found\n");
}

void print_phone_book() {
    int i;
    for (i = 0; i < current_size; i++) {
        printf("%d. %s\n", i, phone_book_array[i].name);
    }
}

int main() {
    srand(time(NULL));
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
    int i;

    for (i = 0; i < 10; i++) {
        // Generate a random name and phone number
        sprintf(name, "Person %d", i);
        sprintf(phone_number, "%d-%d-%d", rand() % 1000, rand() % 1000, rand() % 1000);

        add_phone_book(name, phone_number);
    }

    search_phone_book("John Doe");
    search_phone_book("Jane Doe");
    print_phone_book();

    return 0;
}