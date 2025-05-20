//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: futuristic
#include <stdio.h>
#include <string.h>

#define MAX_PHONE_NUMBER_LENGTH 20

typedef struct PhoneNumber
{
    char number[MAX_PHONE_NUMBER_LENGTH];
    char name[MAX_PHONE_NUMBER_LENGTH];
    struct PhoneNumber* next;
} PhoneNumber;

PhoneNumber* InsertPhoneNumber(PhoneNumber* head, char* name, char* number)
{
    PhoneNumber* newPhoneNumber = (PhoneNumber*)malloc(sizeof(PhoneNumber));
    strcpy(newPhoneNumber->name, name);
    strcpy(newPhoneNumber->number, number);
    newPhoneNumber->next = NULL;

    if (head == NULL)
    {
        head = newPhoneNumber;
    }
    else
    {
        PhoneNumber* currentPhoneNumber = head;
        while (currentPhoneNumber->next != NULL)
        {
            currentPhoneNumber = currentPhoneNumber->next;
        }
        currentPhoneNumber->next = newPhoneNumber;
    }

    return head;
}

void PrintPhoneNumber(PhoneNumber* head)
{
    PhoneNumber* currentPhoneNumber = head;
    while (currentPhoneNumber)
    {
        printf("%s - %s\n", currentPhoneNumber->name, currentPhoneNumber->number);
        currentPhoneNumber = currentPhoneNumber->next;
    }
}

int main()
{
    PhoneNumber* head = NULL;

    InsertPhoneNumber(head, "Alice", "123-45-678");
    InsertPhoneNumber(head, "Bob", "456-78-901");
    InsertPhoneNumber(head, "Charlie", "555-90-123");

    PrintPhoneNumber(head);

    return 0;
}