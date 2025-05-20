//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PHONE_NUMBER_LENGTH 20

typedef struct PhoneNumber
{
    char *number;
    struct PhoneNumber *next;
} PhoneNumber;

PhoneNumber *phoneNumberList = NULL;

void addPhoneNumber(char *number)
{
    PhoneNumber *newPhoneNumber = malloc(sizeof(PhoneNumber));
    newPhoneNumber->number = malloc(MAX_PHONE_NUMBER_LENGTH);
    strcpy(newPhoneNumber->number, number);

    if (phoneNumberList == NULL)
    {
        phoneNumberList = newPhoneNumber;
    }
    else
    {
        phoneNumberList->next = newPhoneNumber;
        phoneNumberList = newPhoneNumber;
    }
}

void searchPhoneNumber(char *number)
{
    PhoneNumber *phoneNumber = phoneNumberList;

    while (phoneNumber)
    {
        if (strcmp(phoneNumber->number, number) == 0)
        {
            printf("Phone number: %s\n", phoneNumber->number);
            return;
        }
        phoneNumber = phoneNumber->next;
    }

    printf("Phone number not found.\n");
}

int main()
{
    addPhoneNumber("555-123-4567");
    addPhoneNumber("555-234-5678");
    addPhoneNumber("555-345-6789");

    searchPhoneNumber("555-123-4567");
    searchPhoneNumber("555-234-5678");
    searchPhoneNumber("555-345-6789");
    searchPhoneNumber("555-456-7890");

    return 0;
}