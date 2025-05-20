//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

struct Medicine
{
    char name[50];
    int quantity;
    float price;
    struct Medicine* next;
};

void insert(struct Medicine** head, char* name, int quantity, float price)
{
    struct Medicine* new_node = (struct Medicine*)malloc(sizeof(struct Medicine));
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

void search(struct Medicine* head, char* name)
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
    struct Medicine* head = NULL;

    insert(&head, "Paracetamol", 100, 2.0);
    insert(&head, "Ibuprofen", 50, 3.5);
    insert(&head, "Acetaminophen", 75, 1.75);

    search(head, "Ibuprofen");

    return 0;
}