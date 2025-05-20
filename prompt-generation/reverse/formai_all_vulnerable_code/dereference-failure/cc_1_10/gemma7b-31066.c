//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: innovative
#include <stdio.h>
#include <string.h>

#define MAX_PHONE_NUMBER_LENGTH 10

typedef struct PhoneNumber
{
    char *number;
    struct PhoneNumber *next;
} PhoneNumber;

PhoneNumber *phoneNumber_create(char *number)
{
    PhoneNumber *phone_number = malloc(sizeof(PhoneNumber));
    phone_number->number = strdup(number);
    phone_number->next = NULL;

    return phone_number;
}

void phoneNumber_add(PhoneNumber *head, char *number)
{
    PhoneNumber *new_phone_number = phoneNumber_create(number);

    if (head == NULL)
    {
        head = new_phone_number;
    }
    else
    {
        PhoneNumber *current_phone_number = head;
        while (current_phone_number->next)
        {
            current_phone_number = current_phone_number->next;
        }
        current_phone_number->next = new_phone_number;
    }
}

void phoneNumber_print(PhoneNumber *head)
{
    PhoneNumber *current_phone_number = head;
    while (current_phone_number)
    {
        printf("%s\n", current_phone_number->number);
        current_phone_number = current_phone_number->next;
    }
}

int main()
{
    PhoneNumber *phone_book = NULL;

    phoneNumber_add(phone_book, "123-456-7890");
    phoneNumber_add(phone_book, "412-567-8342");
    phoneNumber_add(phone_book, "555-623-9121");

    phoneNumber_print(phone_book);

    return 0;
}