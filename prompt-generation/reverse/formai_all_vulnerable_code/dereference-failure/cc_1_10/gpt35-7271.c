//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the total cost of items in the warehouse
float calculateTotalCost(int numItems, float *unitPrice, int *quantity)
{
    float totalCost = 0;
    for(int i = 0; i < numItems; i++)
    {
        totalCost += unitPrice[i] * quantity[i];
    }
    return totalCost;
}

// Function to display the list of items in the warehouse
void displayItems(int numItems, char **itemName, float *unitPrice, int *quantity)
{
    printf("Warehouse Inventory:\n");
    printf("Item Name\tUnit Price\tQuantity\n");
    for(int i = 0; i < numItems; i++)
    {
        printf("%s\t\t$%.2f\t\t%d\n", itemName[i], unitPrice[i], quantity[i]);
    }
}

// Function to add a new item to the warehouse
void addItem(int *numItems, char ***itemName, float **unitPrice, int **quantity)
{
    (*numItems)++;
    *itemName = realloc(*itemName, *numItems * sizeof(char*));
    printf("Enter item name: ");
    (*itemName)[*numItems-1] = malloc(50 * sizeof(char));
    scanf("%s", (*itemName)[*numItems-1]);
    *unitPrice = realloc(*unitPrice, *numItems * sizeof(float));
    printf("Enter unit price: ");
    scanf("%f", &((*unitPrice)[*numItems-1]));
    *quantity = realloc(*quantity, *numItems * sizeof(int));
    printf("Enter quantity: ");
    scanf("%d", &((*quantity)[*numItems-1]));
    printf("Item added successfully!\n");
}

// Main function to run the program
int main()
{
    int numItems = 5;
    char *itemNames[] = {"Item 1", "Item 2", "Item 3", "Item 4", "Item 5"};
    float unitPrices[] = {2.50, 5.99, 3.25, 1.85, 4.99};
    int quantities[] = {10, 5, 7, 12, 3};
    char **itemName = malloc(numItems * sizeof(char*));
    float *unitPrice = malloc(numItems * sizeof(float));
    int *quantity = malloc(numItems * sizeof(int));

    // Copy the default item information into dynamically allocated arrays
    for(int i = 0; i < numItems; i++)
    {
        itemName[i] = malloc(50 * sizeof(char));
        strcpy(itemName[i], itemNames[i]);
        unitPrice[i] = unitPrices[i];
        quantity[i] = quantities[i];
    }

    // Main menu loop
    int choice = 0;
    while(choice != 4)
    {
        printf("\nWarehouse Management System\n");
        printf("1. Show items\n");
        printf("2. Add item\n");
        printf("3. Calculate total cost\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                displayItems(numItems, itemName, unitPrice, quantity);
                break;
            case 2:
                addItem(&numItems, &itemName, &unitPrice, &quantity);
                break;
            case 3:
                printf("Total cost: $%.2f\n", calculateTotalCost(numItems, unitPrice, quantity));
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    // Free dynamically allocated memory
    for(int i = 0; i < numItems; i++)
    {
        free(itemName[i]);
    }
    free(itemName);
    free(unitPrice);
    free(quantity);

    return 0;
}