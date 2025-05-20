//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PHONE_NUMBERS 10

typedef struct PhoneNumber
{
    char name[50];
    char number[20];
    struct PhoneNumber* next;
} PhoneNumber;

PhoneNumber* insertPhoneNumber(PhoneNumber* head, char* name, char* number)
{
    PhoneNumber* newPhone = (PhoneNumber*)malloc(sizeof(PhoneNumber));
    strcpy(newPhone->name, name);
    strcpy(newPhone->number, number);
    newPhone->next = NULL;

    if (head == NULL)
    {
        return newPhone;
    }

    head->next = newPhone;
    return head;
}

void printPhoneNumbers(PhoneNumber* head)
{
    while (head)
    {
        printf("%s: %s\n", head->name, head->number);
        head = head->next;
    }
}

int main()
{
    PhoneNumber* phoneBook = NULL;

    insertPhoneNumber(&phoneBook, "John Doe", "555-123-4567");
    insertPhoneNumber(&phoneBook, "Jane Doe", "555-234-5678");
    insertPhoneNumber(&phoneBook, "Bob Smith", "555-345-6789");

    printPhoneNumbers(phoneBook);

    return 0;
}