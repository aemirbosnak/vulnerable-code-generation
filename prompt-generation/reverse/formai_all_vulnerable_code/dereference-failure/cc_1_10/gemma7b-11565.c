//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Medicine
{
    char name[20];
    int quantity;
    float price;
    struct Medicine *next;
} Medicine;

void insert(Medicine **head, char *name, int quantity, float price)
{
    Medicine *new_node = (Medicine *)malloc(sizeof(Medicine));
    strcpy(new_node->name, name);
    new_node->quantity = quantity;
    new_node->price = price;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        (*head)->next = new_node;
    }
}

void search(Medicine *head, char *name)
{
    while (head)
    {
        if (strcmp(head->name, name) == 0)
        {
            printf("Name: %s\n", head->name);
            printf("Quantity: %d\n", head->quantity);
            printf("Price: %.2f\n", head->price);
            return;
        }
        head = head->next;
    }

    printf("No medicine found.\n");
}

int main()
{
    Medicine *head = NULL;

    insert(&head, "Acetaminophen", 100, 2.0);
    insert(&head, "Ibuprofen", 50, 2.5);
    insert(&head, "Tylenol", 75, 3.0);

    search(head, "Tylenol");

    return 0;
}