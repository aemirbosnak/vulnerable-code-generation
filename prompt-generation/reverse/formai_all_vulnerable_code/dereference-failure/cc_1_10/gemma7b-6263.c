//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char item_name[20];
    int quantity;
    struct Node* next;
};

struct Warehouse {
    struct Node* head;
    int total_items;
};

void insert_item(struct Warehouse* warehouse, char item_name, int quantity)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(new_node->item_name, item_name);
    new_node->quantity = quantity;
    new_node->next = NULL;

    if (warehouse->head == NULL)
    {
        warehouse->head = new_node;
    }
    else
    {
        struct Node* temp = warehouse->head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    warehouse->total_items++;
}

void search_item(struct Warehouse* warehouse, char item_name)
{
    struct Node* current_node = warehouse->head;

    while (current_node)
    {
        if (strcmp(current_node->item_name, item_name) == 0)
        {
            printf("Item name: %s\n", current_node->item_name);
            printf("Quantity: %d\n", current_node->quantity);
            return;
        }

        current_node = current_node->next;
    }

    printf("Item not found.\n");
}

int main()
{
    struct Warehouse warehouse;
    warehouse.head = NULL;
    warehouse.total_items = 0;

    insert_item(&warehouse, "Apple", 10);
    insert_item(&warehouse, "Banana", 20);
    insert_item(&warehouse, "Orange", 30);

    search_item(&warehouse, "Apple");
    search_item(&warehouse, "Banana");
    search_item(&warehouse, "Orange");

    return 0;
}