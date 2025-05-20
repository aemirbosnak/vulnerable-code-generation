//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stock
{
    char name[20];
    int price;
    int quantity;
} Stock;

void updateStock(Stock **arr, int *size, char *name, int price, int quantity)
{
    int i = 0;
    for (i = 0; i < *size; i++)
    {
        if (strcmp((*arr)[i].name, name) == 0)
        {
            ((*arr)[i].price = price);
            ((*arr)[i].quantity = quantity);
            return;
        }
    }

    *size++ = *size + 1;
    (*arr) = realloc(*arr, *size * sizeof(Stock));

    Stock newStock;
    strcpy(newStock.name, name);
    newStock.price = price;
    newStock.quantity = quantity;

    (*arr)[*size - 1] = newStock;
}

int main()
{
    int size = 0;
    Stock *arr = NULL;

    updateStock(&arr, &size, "ABC", 100, 10);
    updateStock(&arr, &size, "XYZ", 200, 20);

    for (int i = 0; i < size; i++)
    {
        printf("%s: %d, %d\n", arr[i].name, arr[i].price, arr[i].quantity);
    }

    return 0;
}