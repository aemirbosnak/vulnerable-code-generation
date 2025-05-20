//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Medical store structure
typedef struct
{
    char name[100];
    int quantity;
    float price;
} Medicine;

// Function declarations
void addMedicine();
void viewMedicines();
void searchMedicine();
void deleteMedicine();

// Global variables
Medicine* medicines[100];
int numMedicines = 0;

int main()
{
    // Welcome message
    printf("Welcome to Happy Medical Store Management System!\n\n");

    // Display menu
    printf("1. Add new medicine\n");
    printf("2. View all medicines\n");
    printf("3. Search for a medicine\n");
    printf("4. Delete a medicine\n");
    printf("5. Exit\n\n");

    // Prompt user for input
    int choice = 0;
    printf("Please enter your choice: ");
    scanf("%d", &choice);

    // Loop through menu until user chooses to exit
    while(choice != 5)
    {
        switch(choice)
        {
            case 1:
                addMedicine();
                break;
            case 2:
                viewMedicines();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                deleteMedicine();
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        // Display menu and prompt user for input
        printf("\n1. Add new medicine\n");
        printf("2. View all medicines\n");
        printf("3. Search for a medicine\n");
        printf("4. Delete a medicine\n");
        printf("5. Exit\n\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
    }

    // Exit message
    printf("\nThank you for using Happy Medical Store Management System!\n");

    return 0;
}

// Function to add a new medicine
void addMedicine()
{
    // Prompt user for input
    printf("Please enter the name of the medicine: ");
    char name[100];
    scanf("%s", name);

    int quantity;
    printf("Please enter the quantity of the medicine: ");
    scanf("%d", &quantity);

    float price;
    printf("Please enter the price of the medicine: ");
    scanf("%f", &price);

    // Allocate memory for new medicine
    Medicine* medicine = (Medicine*) malloc(sizeof(Medicine));

    // Copy data to the medicine structure
    strcpy(medicine->name, name);
    medicine->quantity = quantity;
    medicine->price = price;

    // Add medicine to the array of medicines
    medicines[numMedicines++] = medicine;

    // Success message
    printf("\nMedicine added!\n");
}

// Function to view all medicines
void viewMedicines()
{
    // Check if there are any medicines
    if(numMedicines == 0)
    {
        printf("\nNo medicines found!\n");
        return;
    }

    // Display header
    printf("\n%-20s %-10s %-10s\n", "Name", "Quantity", "Price");

    // Loop through all medicines and display data
    for(int i = 0; i < numMedicines; i++)
    {
        printf("%-20s %-10d $%-10.2f\n", medicines[i]->name, medicines[i]->quantity, medicines[i]->price);
    }
}

// Function to search for a medicine
void searchMedicine()
{
    // Prompt user for input
    printf("Please enter the name of the medicine to search for: ");
    char name[100];
    scanf("%s", name);

    // Loop through all medicines and search for the given name
    int found = 0;
    for(int i = 0; i < numMedicines; i++)
    {
        if(strcmp(medicines[i]->name, name) == 0)
        {
            // Found the medicine, display data and set found flag
            printf("\n%-20s %-10s %-10s\n", "Name", "Quantity", "Price");
            printf("%-20s %-10d $%-10.2f\n", medicines[i]->name, medicines[i]->quantity, medicines[i]->price);
            found = 1;
            break;
        }
    }

    // Check if medicine was not found
    if(!found)
    {
        printf("\nMedicine not found!\n");
    }
}

// Function to delete a medicine
void deleteMedicine()
{
    // Check if there are any medicines
    if(numMedicines == 0)
    {
        printf("\nNo medicines found!\n");
        return;
    }

    // Prompt user for input
    printf("Please enter the name of the medicine to delete: ");
    char name[100];
    scanf("%s", name);

    int found = 0;

    // Loop through all medicines and search for the given name
    for(int i = 0; i < numMedicines; i++)
    {
        if(strcmp(medicines[i]->name, name) == 0)
        {
            // Found the medicine, delete it and set found flag
            free(medicines[i]);
            medicines[i] = NULL;
            found = 1;
            numMedicines--;
            break;
        }
    }

    // Check if medicine was not found
    if(!found)
    {
        printf("\nMedicine not found!\n");
    }
    else
    {
        // Success message
        printf("\nMedicine deleted!\n");
    }
}