//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct phonebook {
    char name[20];
    char number[20];
} PhoneBook;

PhoneBook* createPhoneBook(char name[], char number[]) {
    PhoneBook* newBook = (PhoneBook*)malloc(sizeof(PhoneBook));
    strcpy(newBook->name, name);
    strcpy(newBook->number, number);
    return newBook;
}

void addPhoneBook(PhoneBook* books[], char name[], char number[]) {
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        if (strcmp(books[i]->name, name) == 0) {
            break;
        }
    }
    if (i < MAX_SIZE) {
        strcpy(books[i]->name, name);
        strcpy(books[i]->number, number);
    } else {
        PhoneBook* newBook = createPhoneBook(name, number);
        books[i] = newBook;
    }
}

void displayPhoneBook(PhoneBook* books[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("Name: %s, Number: %s\n", books[i]->name, books[i]->number);
    }
}

int main() {
    PhoneBook* books[MAX_SIZE];
    char name[20], number[20];
    int i, size;

    printf("Enter the size of the phone book: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++) {
        printf("Enter name: ");
        fgets(name, sizeof(name), stdin);
        printf("Enter number: ");
        fgets(number, sizeof(number), stdin);
        addPhoneBook(books, name, number);
    }

    displayPhoneBook(books, size);

    free(books[0]);
    for (i = 1; i < size; i++) {
        free(books[i]);
    }

    return 0;
}