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

// Create a function to add a medicine to the store
void addMedicine(Medicine *store, int *num)
{
    // Allocate memory for a new medicine
    store = (Medicine *)malloc(sizeof(Medicine));

    // Get the medicine name, quantity, and price
    printf("Enter the medicine name: ");
    scanf("%s", store->name);

    printf("Enter the medicine quantity: ");
    scanf("%d", &store->quantity);

    printf("Enter the medicine price: ");
    scanf("%f", &store->price);

    // Increment the number of medicines in the store
    (*num)++;

    // Add the medicine to the store
    store = store;
}

// Create a function to display the medicines in the store
void displayMedicines(Medicine *store, int num)
{
    // Print the medicines in the store
    for (int i = 0; i < num; i++)
    {
        printf("%s - %d - %.2f\n", store[i].name, store[i].quantity, store[i].price);
    }
}

// Create a function to search for a medicine in the store
void searchMedicine(Medicine *store, int num)
{
    // Get the medicine name
    char name[20];
    printf("Enter the medicine name: ");
    scanf("%s", name);

    // Search for the medicine in the store
    for (int i = 0; i < num; i++)
    {
        if (strcmp(store[i].name, name) == 0)
        {
            printf("%s - %d - %.2f\n", store[i].name, store[i].quantity, store[i].price);
        }
    }
}

int main()
{
    // Create an array of medicines in the store
    Medicine *store = NULL;

    // Initialize the number of medicines in the store
    int num = 0;

    // Add some medicines to the store
    addMedicine(store, &num);
    addMedicine(store, &num);
    addMedicine(store, &num);

    // Display the medicines in the store
    displayMedicines(store, num);

    // Search for a medicine in the store
    searchMedicine(store, num);

    return 0;
}