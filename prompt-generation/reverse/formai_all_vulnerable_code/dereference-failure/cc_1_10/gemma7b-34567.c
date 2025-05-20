//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a medicine
typedef struct Medicine
{
    char name[20];
    int quantity;
    float price;
} Medicine;

// Define a function to add a medicine to the store
void addMedicine(Medicine *store, int *num)
{
    store = (Medicine *)realloc(store, (*num) * sizeof(Medicine));
    (*num)++;
    store[*num - 1].name[0] = '\0';
    scanf("Enter the name of the medicine: ", store[*num - 1].name);
    scanf("Enter the quantity of the medicine: ", &store[*num - 1].quantity);
    scanf("Enter the price of the medicine: ", &store[*num - 1].price);
}

// Define a function to search for a medicine
void searchMedicine(Medicine *store, int num)
{
    char searchName[20];
    printf("Enter the name of the medicine: ");
    scanf("Enter the name of the medicine: ", searchName);

    int found = 0;
    for (int i = 0; i < num; i++)
    {
        if (strcmp(store[i].name, searchName) == 0)
        {
            found = 1;
            printf("Name: %s\n", store[i].name);
            printf("Quantity: %d\n", store[i].quantity);
            printf("Price: %.2f\n", store[i].price);
        }
    }

    if (!found)
    {
        printf("Medicine not found.\n");
    }
}

// Define a function to update the quantity of a medicine
void updateQuantity(Medicine *store, int num)
{
    char searchName[20];
    printf("Enter the name of the medicine: ");
    scanf("Enter the name of the medicine: ", searchName);

    int found = 0;
    for (int i = 0; i < num; i++)
    {
        if (strcmp(store[i].name, searchName) == 0)
        {
            found = 1;
            printf("Enter the new quantity of the medicine: ");
            scanf("%d", &store[i].quantity);
        }
    }

    if (!found)
    {
        printf("Medicine not found.\n");
    }
}

// Define a function to delete a medicine from the store
void deleteMedicine(Medicine *store, int *num)
{
    char searchName[20];
    printf("Enter the name of the medicine: ");
    scanf("Enter the name of the medicine: ", searchName);

    int found = 0;
    for (int i = 0; i < *num; i++)
    {
        if (strcmp(store[i].name, searchName) == 0)
        {
            found = 1;
            (*num)--;
            store[i] = store[*num];
        }
    }

    if (!found)
    {
        printf("Medicine not found.\n");
    }
}

int main()
{
    // Create a medicine store
    Medicine *store = NULL;
    int num = 0;

    // Add some medicines to the store
    addMedicine(store, &num);
    addMedicine(store, &num);
    addMedicine(store, &num);

    // Search for a medicine
    searchMedicine(store, num);

    // Update the quantity of a medicine
    updateQuantity(store, num);

    // Delete a medicine from the store
    deleteMedicine(store, &num);

    return 0;
}