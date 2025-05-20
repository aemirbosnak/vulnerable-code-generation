//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

struct Warehouse
{
    char name[100];
    int items[100];
    int capacity;
    int current_items;
};

struct Warehouse* create_warehouse(char name[], int capacity)
{
    struct Warehouse* w = (struct Warehouse*)malloc(sizeof(struct Warehouse));
    strcpy(w->name, name);
    w->capacity = capacity;
    w->current_items = 0;
    return w;
}

void add_item(struct Warehouse* w, int item_id)
{
    if (w->current_items < w->capacity)
    {
        w->items[w->current_items] = item_id;
        w->current_items++;
    }
    else
    {
        printf("Warehouse is full, cannot add more items.\n");
    }
}

int remove_item(struct Warehouse* w, int item_id)
{
    int found = 0;
    for (int i = 0; i < w->current_items; i++)
    {
        if (w->items[i] == item_id)
        {
            w->items[i] = 0;
            w->current_items--;
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Item not found in warehouse.\n");
    }
    return found;
}

void display_warehouse(struct Warehouse* w)
{
    printf("Warehouse: %s\n", w->name);
    printf("Capacity: %d\n", w->capacity);
    printf("Current items: %d\n", w->current_items);
    for (int i = 0; i < w->current_items; i++)
    {
        printf("Item %d: %d\n", i+1, w->items[i]);
    }
}

int main()
{
    struct Warehouse* w1 = create_warehouse("Warehouse 1", 10);
    add_item(w1, 1);
    add_item(w1, 2);
    add_item(w1, 3);
    display_warehouse(w1);

    remove_item(w1, 2);
    display_warehouse(w1);

    remove_item(w1, 3);
    display_warehouse(w1);

    remove_item(w1, 1);
    display_warehouse(w1);

    return 0;
}