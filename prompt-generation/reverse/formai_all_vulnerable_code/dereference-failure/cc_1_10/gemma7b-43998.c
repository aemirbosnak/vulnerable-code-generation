//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

struct Medicine
{
    char name[20];
    int quantity;
    float price;
    struct Medicine* next;
};

struct Medicine* insert(struct Medicine* head, char* name, int quantity, float price)
{
    struct Medicine* newNode = (struct Medicine*)malloc(sizeof(struct Medicine));
    strcpy(newNode->name, name);
    newNode->quantity = quantity;
    newNode->price = price;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Medicine* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

void display(struct Medicine* head)
{
    struct Medicine* temp = head;
    while (temp)
    {
        printf("%s - %d - %.2f\n", temp->name, temp->quantity, temp->price);
        temp = temp->next;
    }
}

int main()
{
    struct Medicine* head = NULL;

    insert(head, "Acetaminophen", 10, 5.0);
    insert(head, "Ibuprofen", 15, 6.0);
    insert(head, "Aspirin", 20, 7.0);

    display(head);

    return 0;
}