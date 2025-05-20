//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_PHONE_NUMBER 10

typedef struct PhoneNumber
{
    char name[50];
    int number[MAX_PHONE_NUMBER];
    struct PhoneNumber* next;
} PhoneNumber;

PhoneNumber* insertPhoneNumber(PhoneNumber* head, char* name, int number)
{
    PhoneNumber* new_node = (PhoneNumber*)malloc(sizeof(PhoneNumber));
    strcpy(new_node->name, name);
    for (int i = 0; i < MAX_PHONE_NUMBER; i++)
    {
        new_node->number[i] = number;
    }
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        head->next = new_node;
    }

    return head;
}

void printPhoneNumbers(PhoneNumber* head)
{
    while (head)
    {
        printf("%s: ", head->name);
        for (int i = 0; i < MAX_PHONE_NUMBER; i++)
        {
            printf("%d ", head->number[i]);
        }
        printf("\n");
        head = head->next;
    }
}

int main()
{
    PhoneNumber* head = NULL;

    insertPhoneNumber(head, "John Doe", 123456);
    insertPhoneNumber(head, "Jane Doe", 543214);
    insertPhoneNumber(head, "Bill Smith", 654321);

    printPhoneNumbers(head);

    return 0;
}