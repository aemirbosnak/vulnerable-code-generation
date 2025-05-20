//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine
{
    char name[50];
    int quantity;
    float price;
};

struct node
{
    struct medicine med;
    struct node *next;
};

struct node *head = NULL;

void add_medicine(char *name, int quantity, float price)
{
    struct node *new_node = malloc(sizeof(struct node));
    strcpy(new_node->med.name, name);
    new_node->med.quantity = quantity;
    new_node->med.price = price;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void display_medicines()
{
    struct node *current = head;
    while (current != NULL)
    {
        printf("%s %d %.2f\n", current->med.name, current->med.quantity, current->med.price);
        current = current->next;
    }
}

void search_medicine(char *name)
{
    struct node *current = head;
    while (current != NULL)
    {
        if (strcmp(current->med.name, name) == 0)
        {
            printf("%s %d %.2f\n", current->med.name, current->med.quantity, current->med.price);
            return;
        }
        current = current->next;
    }
    printf("Medicine not found\n");
}

void update_quantity(char *name, int quantity)
{
    struct node *current = head;
    while (current != NULL)
    {
        if (strcmp(current->med.name, name) == 0)
        {
            current->med.quantity = quantity;
            return;
        }
        current = current->next;
    }
    printf("Medicine not found\n");
}

void delete_medicine(char *name)
{
    struct node *current = head;
    struct node *previous = NULL;
    while (current != NULL)
    {
        if (strcmp(current->med.name, name) == 0)
        {
            if (previous == NULL)
            {
                head = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Medicine not found\n");
}

int main()
{
    add_medicine("Paracetamol", 100, 10.0);
    add_medicine("Ibuprofen", 50, 15.0);
    add_medicine("Aspirin", 25, 5.0);

    display_medicines();

    printf("\nSearching for Paracetamol\n");
    search_medicine("Paracetamol");

    printf("\nUpdating quantity of Ibuprofen to 75\n");
    update_quantity("Ibuprofen", 75);

    printf("\nDisplaying medicines after update\n");
    display_medicines();

    printf("\nDeleting Aspirin\n");
    delete_medicine("Aspirin");

    printf("\nDisplaying medicines after delete\n");
    display_medicines();

    return 0;
}