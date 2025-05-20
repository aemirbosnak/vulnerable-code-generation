//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: paranoid
#include <stdio.h>
#include <string.h>

#define MAX_PHONE_NUMBERS 10

typedef struct PhoneNumber
{
    char name[20];
    char number[20];
    struct PhoneNumber* next;
} PhoneNumber;

PhoneNumber* createPhoneNumber(char* name, char* number)
{
    PhoneNumber* newPhone = malloc(sizeof(PhoneNumber));
    strcpy(newPhone->name, name);
    strcpy(newPhone->number, number);
    newPhone->next = NULL;
    return newPhone;
}

void addToPhoneBook(PhoneNumber* phoneBook, char* name, char* number)
{
    PhoneNumber* newPhone = createPhoneNumber(name, number);

    if (phoneBook == NULL)
    {
        phoneBook = newPhone;
    }
    else
    {
        PhoneNumber* currentPhone = phoneBook;

        while (currentPhone->next)
        {
            currentPhone = currentPhone->next;
        }

        currentPhone->next = newPhone;
    }
}

void searchPhoneBook(PhoneNumber* phoneBook, char* name)
{
    PhoneNumber* currentPhone = phoneBook;

    while (currentPhone)
    {
        if (strcmp(currentPhone->name, name) == 0)
        {
            printf("Name: %s\n", currentPhone->name);
            printf("Number: %s\n", currentPhone->number);
            return;
        }

        currentPhone = currentPhone->next;
    }

    printf("Name not found.\n");
}

int main()
{
    PhoneNumber* phoneBook = NULL;

    addToPhoneBook(phoneBook, "John Doe", "555-123-4567");
    addToPhoneBook(phoneBook, "Jane Doe", "555-456-7890");
    addToPhoneBook(phoneBook, "Bob Smith", "555-341-9628");

    searchPhoneBook(phoneBook, "John Doe");
    searchPhoneBook(phoneBook, "Jane Doe");
    searchPhoneBook(phoneBook, "Bob Smith");
    searchPhoneBook(phoneBook, "Bill Jones");

    return 0;
}