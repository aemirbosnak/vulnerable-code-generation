//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Stock
{
    char name[20];
    int price;
    int quantity;
    struct Stock* next;
} Stock;

Stock* InsertStock(Stock* head, char* name, int price, int quantity)
{
    Stock* newStock = (Stock*)malloc(sizeof(Stock));
    strcpy(newStock->name, name);
    newStock->price = price;
    newStock->quantity = quantity;
    newStock->next = NULL;

    if (head == NULL)
    {
        head = newStock;
    }
    else
    {
        head->next = newStock;
    }

    return head;
}

void PrintStock(Stock* head)
{
    while (head)
    {
        printf("%s - %d - %d\n", head->name, head->price, head->quantity);
        head = head->next;
    }
}

int main()
{
    Stock* head = NULL;

    InsertStock(head, "AAPL", 150, 100);
    InsertStock(head, "TSLA", 200, 50);
    InsertStock(head, "FB", 120, 75);

    PrintStock(head);

    return 0;
}