//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Medicine
{
    char name[20];
    char dosage[20];
    int quantity;
    float price;
} Medicine;

void insertMedicine(Medicine **medicines, int *size)
{
    *medicines = (Medicine *)realloc(*medicines, (*size) * sizeof(Medicine));
    (*medicines)[*size].name[0] = '\0';
    (*medicines)[*size].dosage[0] = '\0';
    (*medicines)[*size].quantity = 0;
    (*medicines)[*size].price = 0.0f;
    *size++;
}

void searchMedicine(Medicine **medicines, int size, char *name)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp((*medicines)[i].name, name) == 0)
        {
            printf("Name: %s\n", (*medicines)[i].name);
            printf("Dosage: %s\n", (*medicines)[i].dosage);
            printf("Quantity: %d\n", (*medicines)[i].quantity);
            printf("Price: %.2f\n", (*medicines)[i].price);
            return;
        }
    }

    printf("Medicine not found.\n");
}

int main()
{
    Medicine *medicines = NULL;
    int size = 0;

    insertMedicine(&medicines, &size);
    insertMedicine(&medicines, &size);
    insertMedicine(&medicines, &size);

    searchMedicine(medicines, size, "Medicine 1");

    return 0;
}