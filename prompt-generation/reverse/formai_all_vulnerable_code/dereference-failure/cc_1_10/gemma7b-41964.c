//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: secure
#include <stdio.h>
#include <string.h>

#define MAX_PHONE_NUMBER_LENGTH 20

typedef struct PhoneNumber
{
    char *number;
    struct PhoneNumber *next;
} PhoneNumber;

PhoneNumber *phoneNumberCreate(char *number)
{
    PhoneNumber *phoneNumber = malloc(sizeof(PhoneNumber));

    phoneNumber->number = strdup(number);
    phoneNumber->next = NULL;

    return phoneNumber;
}

void phoneNumberInsert(PhoneNumber *phoneNumber, char *number)
{
    PhoneNumber *newPhoneNumber = phoneNumberCreate(number);

    if (phoneNumber)
    {
        phoneNumber->next = newPhoneNumber;
    }
    else
    {
        phoneNumber = newPhoneNumber;
    }
}

void phoneNumberPrint(PhoneNumber *phoneNumber)
{
    while (phoneNumber)
    {
        printf("%s\n", phoneNumber->number);
        phoneNumber = phoneNumber->next;
    }
}

int main()
{
    PhoneNumber *phoneNumberList = NULL;

    phoneNumberInsert(phoneNumberList, "123-456-7890");
    phoneNumberInsert(phoneNumberList, "555-123-4567");
    phoneNumberInsert(phoneNumberList, "987-654-2134");

    phoneNumberPrint(phoneNumberList);

    return 0;
}