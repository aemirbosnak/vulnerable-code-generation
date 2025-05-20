//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Medicine
{
    char name[20];
    int quantity;
    float price;
} Medicine;

void insertMedicine(Medicine **medList, int *size)
{
    *medList = (Medicine *)malloc((*size) * sizeof(Medicine));
    (*size)++;
}

void searchMedicine(Medicine **medList, int size, char *name)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp((*medList)[i].name, name) == 0)
        {
            printf("Name: %s\n", (*medList)[i].name);
            printf("Quantity: %d\n", (*medList)[i].quantity);
            printf("Price: %.2f\n", (*medList)[i].price);
            return;
        }
    }

    printf("Medicine not found.\n");
}

void updateMedicine(Medicine **medList, int size, char *name, int quantity, float price)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp((*medList)[i].name, name) == 0)
        {
            (*medList)[i].quantity = quantity;
            (*medList)[i].price = price;
            return;
        }
    }

    printf("Medicine not found.\n");
}

int main()
{
    Medicine *medList = NULL;
    int size = 0;

    insertMedicine(&medList, &size);
    insertMedicine(&medList, &size);
    insertMedicine(&medList, &size);

    searchMedicine(&medList, size, "Medicine 1");
    updateMedicine(&medList, size, "Medicine 1", 10, 20.0);

    searchMedicine(&medList, size, "Medicine 1");

    return 0;
}