//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ Stocks 10

typedef struct Stock
{
    char name[20];
    double price;
    int quantity;
    struct Stock* next;
} Stock;

void insertStock(Stock** head, char* name, double price, int quantity)
{
    Stock* newStock = (Stock*)malloc(sizeof(Stock));
    strcpy(newStock->name, name);
    newStock->price = price;
    newStock->quantity = quantity;
    newStock->next = NULL;

    if (*head == NULL)
    {
        *head = newStock;
    }
    else
    {
        (*head)->next = newStock;
    }
}

void printStocks(Stock* head)
{
    while (head)
    {
        printf("%s: %.2lf, %d\n", head->name, head->price, head->quantity);
        head = head->next;
    }
}

int main()
{
    Stock* head = NULL;

    insertStock(&head, "Apple", 100.0, 100);
    insertStock(&head, "Microsoft", 200.0, 50);
    insertStock(&head, "Google", 150.0, 75);
    insertStock(&head, "Amazon", 250.0, 20);

    printStocks(head);

    return 0;
}