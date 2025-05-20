//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Item
{
    char name[20];
    int quantity;
    float price;
    struct Item* next;
};

struct Warehouse
{
    struct Item* head;
    struct Item* tail;
    int items_count;
    float total_value;
};

void insert_item(struct Warehouse* warehouse, char* name, int quantity, float price)
{
    struct Item* new_item = (struct Item*)malloc(sizeof(struct Item));
    strcpy(new_item->name, name);
    new_item->quantity = quantity;
    new_item->price = price;
    new_item->next = NULL;

    if (warehouse->head == NULL)
    {
        warehouse->head = new_item;
        warehouse->tail = new_item;
    }
    else
    {
        warehouse->tail->next = new_item;
        warehouse->tail = new_item;
    }

    warehouse->items_count++;
    warehouse->total_value += new_item->quantity * new_item->price;
}

void update_item_quantity(struct Warehouse* warehouse, char* name, int new_quantity)
{
    struct Item* item = warehouse->head;

    while (item)
    {
        if (strcmp(item->name, name) == 0)
        {
            item->quantity = new_quantity;
            warehouse->total_value = warehouse->total_value - (item->quantity * item->price) + (new_quantity * item->price);
            break;
        }
        item = item->next;
    }

    if (item == NULL)
    {
        printf("Item not found.\n");
    }
}

void delete_item(struct Warehouse* warehouse, char* name)
{
    struct Item* item = warehouse->head;
    struct Item* previous_item = NULL;

    while (item)
    {
        if (strcmp(item->name, name) == 0)
        {
            if (previous_item)
            {
                previous_item->next = item->next;
                warehouse->tail = previous_item;
            }
            else
            {
                warehouse->head = item->next;
                warehouse->tail = warehouse->head;
            }

            warehouse->items_count--;
            warehouse->total_value -= item->quantity * item->price;
            free(item);
            break;
        }
        previous_item = item;
        item = item->next;
    }

    if (item == NULL)
    {
        printf("Item not found.\n");
    }
}

int main()
{
    struct Warehouse warehouse;
    warehouse.head = NULL;
    warehouse.tail = NULL;
    warehouse.items_count = 0;
    warehouse.total_value = 0.0f;

    insert_item(&warehouse, "Apple", 10, 1.20f);
    insert_item(&warehouse, "Banana", 20, 0.80f);
    insert_item(&warehouse, "Orange", 30, 0.90f);

    update_item_quantity(&warehouse, "Banana", 30);

    delete_item(&warehouse, "Orange");

    printf("Items in the warehouse:");
    struct Item* item = warehouse.head;
    while (item)
    {
        printf(" %s (%d) - $%.2f", item->name, item->quantity, item->price);
        item = item->next;
    }

    printf("\nTotal value of items: $%.2f", warehouse.total_value);

    return 0;
}