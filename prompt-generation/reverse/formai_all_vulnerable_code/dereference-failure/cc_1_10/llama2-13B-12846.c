//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: satisfied
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
        printf("Phone book is full! Please delete some entries before adding more.\n");
        return;
    }

    strcpy(phone_book_array[current_size].name, name);
    strcpy(phone_book_array[current_size].phone_number, phone_number);
    current_size++;
}

void delete_phone(int index) {
    if (index < 0 || index >= current_size) {
        printf("Invalid index\n");
        return;
    }

    for (int i = index; i < current_size - 1; i++) {
        strcpy(phone_book_array[i].name, phone_book_array[i + 1].name);
        strcpy(phone_book_array[i].phone_number, phone_book_array[i + 1].phone_number);
    }

    current_size--;
}

void search_phone(char *name) {
    for (int i = 0; i < current_size; i++) {
        if (strcmp(phone_book_array[i].name, name) == 0) {
            printf("Found phone number: %s\n", phone_book_array[i].phone_number);
            return;
        }
    }

    printf("Phone not found\n");
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        char name[50];
        char phone_number[PHONE_NUMBER_LENGTH];
        sprintf(name, "Name %d", i);
        sprintf(phone_number, "Phone number %d", i);
        add_phone(name, phone_number);
    }

    char search_name[50];
    printf("Enter name to search: ");
    scanf("%49s", search_name);

    search_phone(search_name);

    return 0;
}