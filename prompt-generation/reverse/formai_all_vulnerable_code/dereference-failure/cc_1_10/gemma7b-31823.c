//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: light-weight
#include <stdio.h>
#include <string.h>

#define MAX_PHONE_NUMBER_LENGTH 20

typedef struct PhoneNumber
{
    char *number;
    struct PhoneNumber *next;
} PhoneNumber;

PhoneNumber *insertPhoneNumber(PhoneNumber *head, char *number)
{
    PhoneNumber *new_node = malloc(sizeof(PhoneNumber));
    new_node->number = strdup(number);
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        head->next = insertPhoneNumber(head->next, number);
    }

    return head;
}

void printPhoneNumber(PhoneNumber *head)
{
    PhoneNumber *current = head;

    while (current)
    {
        printf("%s\n", current->number);
        current = current->next;
    }
}

int main()
{
    PhoneNumber *phone_book = NULL;

    phone_book = insertPhoneNumber(phone_book, "123-456-7890");
    phone_book = insertPhoneNumber(phone_book, "412-567-8234");
    phone_book = insertPhoneNumber(phone_book, "555-123-4567");

    printPhoneNumber(phone_book);

    return 0;
}