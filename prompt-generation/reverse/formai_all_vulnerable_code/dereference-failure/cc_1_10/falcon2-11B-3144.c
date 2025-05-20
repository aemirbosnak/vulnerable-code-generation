//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PHONEBOOK_SIZE 100

typedef struct {
    char name[50];
    char number[20];
} PhoneBookEntry;

typedef struct {
    int capacity;
    int size;
    PhoneBookEntry *phonebook;
} PhoneBook;

void addPhoneBookEntry(PhoneBook *phonebook, const char *name, const char *number) {
    if (phonebook->size >= phonebook->capacity) {
        phonebook->capacity *= 2;
        phonebook->phonebook = realloc(phonebook->phonebook, phonebook->capacity * sizeof(PhoneBookEntry));
    }
    strcpy(phonebook->phonebook[phonebook->size].name, name);
    strcpy(phonebook->phonebook[phonebook->size].number, number);
    phonebook->size++;
}

PhoneBook *createPhoneBook() {
    PhoneBook *phonebook = (PhoneBook *)malloc(sizeof(PhoneBook));
    phonebook->capacity = MAX_PHONEBOOK_SIZE;
    phonebook->size = 0;
    phonebook->phonebook = (PhoneBookEntry *)malloc(phonebook->capacity * sizeof(PhoneBookEntry));
    return phonebook;
}

void printPhoneBook(PhoneBook *phonebook) {
    int i;
    for (i = 0; i < phonebook->size; i++) {
        printf("%s: %s\n", phonebook->phonebook[i].name, phonebook->phonebook[i].number);
    }
}

void freePhoneBook(PhoneBook *phonebook) {
    free(phonebook->phonebook);
    free(phonebook);
}

int main() {
    PhoneBook *phonebook = createPhoneBook();
    addPhoneBookEntry(phonebook, "John", "1234567890");
    addPhoneBookEntry(phonebook, "Jane", "0987654321");
    printPhoneBook(phonebook);
    freePhoneBook(phonebook);
    return 0;
}