//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Medicine
{
    char name[50];
    char dosage[50];
    int quantity;
    float price;
} Medicine;

void addMedicine(Medicine **medList, int *medListSize)
{
    *medList = (Medicine *)realloc(*medList, (*medListSize) * sizeof(Medicine) + 1);
    (*medListSize)++;
    (*medList)->name[0] = '\0';
    (*medList)->dosage[0] = '\0';
    (*medList)->quantity = 0;
    (*medList)->price = 0.0f;
}

void displayMedicine(Medicine *medList, int medListSize)
{
    for (int i = 0; i < medListSize; i++)
    {
        printf("%s - %s, %d, %.2f\n", medList[i].name, medList[i].dosage, medList[i].quantity, medList[i].price);
    }
}

void searchMedicine(Medicine *medList, int medListSize, char *searchName)
{
    for (int i = 0; i < medListSize; i++)
    {
        if (strcmp(medList[i].name, searchName) == 0)
        {
            printf("%s - %s, %d, %.2f\n", medList[i].name, medList[i].dosage, medList[i].quantity, medList[i].price);
        }
    }
}

int main()
{
    Medicine *medList = NULL;
    int medListSize = 0;

    addMedicine(&medList, &medListSize);
    addMedicine(&medList, &medListSize);
    addMedicine(&medList, &medListSize);

    displayMedicine(medList, medListSize);

    searchMedicine(medList, medListSize, "Medicine A");

    return 0;
}