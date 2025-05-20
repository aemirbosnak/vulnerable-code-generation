//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int item_id;
    char item_name[20];
    int quantity;
    struct Node* next;
};

struct Node* insert_at_tail(struct Node* head, int item_id, char item_name[], int quantity)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->item_id = item_id;
    strcpy(newNode->item_name, item_name);
    newNode->quantity = quantity;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node* temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

void search_item(struct Node* head, int item_id)
{
    struct Node* temp = head;
    while (temp)
    {
        if (temp->item_id == item_id)
        {
            printf("Item Name: %s\n", temp->item_name);
            printf("Quantity: %d\n", temp->quantity);
            break;
        }
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Item not found.\n");
    }
}

int main()
{
    struct Node* head = NULL;

    insert_at_tail(head, 1, "Apple", 10);
    insert_at_tail(head, 2, "Banana", 20);
    insert_at_tail(head, 3, "Orange", 30);

    search_item(head, 2);

    return 0;
}