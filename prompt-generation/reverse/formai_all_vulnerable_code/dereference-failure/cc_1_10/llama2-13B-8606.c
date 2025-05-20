//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PHONE_BOOK_SIZE 100
#define PHONE_NUMBER_LENGTH 10

typedef struct phone_book {
    char name[50];
    char phone_number[PHONE_NUMBER_LENGTH];
} phone_book;

phone_book phone_book_array[PHONE_BOOK_SIZE];
int current_size = 0;

void add_phone(char *name, char *phone_number) {
    if (current_size == PHONE_BOOK_SIZE) {
        printf("OH NO! The phone book is full! I can't add any more numbers! \n");
        return;
    }

    strcpy(phone_book_array[current_size].name, name);
    strcpy(phone_book_array[current_size].phone_number, phone_number);
    current_size++;
}

void print_phone_book() {
    printf("Here is the phone book:\n");
    for (int i = 0; i < current_size; i++) {
        printf("%d: %s %s\n", i, phone_book_array[i].name, phone_book_array[i].phone_number);
    }
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        char name[50];
        char phone_number[PHONE_NUMBER_LENGTH];
        int num;

        // Generate a random name and phone number
        sprintf(name, "Person %d", i);
        for (num = 0; num < PHONE_NUMBER_LENGTH; num++) {
            phone_number[num] = '0' + (rand() % 10);
        }

        add_phone(name, phone_number);
    }

    print_phone_book();

    return 0;
}