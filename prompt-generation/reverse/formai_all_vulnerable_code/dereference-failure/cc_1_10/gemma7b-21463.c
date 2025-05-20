//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a medicine
typedef struct Medicine
{
    char name[20];
    int quantity;
    double price;
} Medicine;

// Define a function to add a medicine to the store
void addMedicine(Medicine *medicineList, int *numMedics)
{
    // Allocate memory for a new medicine
    medicineList = (Medicine *)realloc(medicineList, (*numMedics + 1) * sizeof(Medicine));

    // Get the medicine name, quantity, and price
    printf("Enter the medicine name: ");
    scanf("%s", medicineList[*numMedics].name);

    printf("Enter the medicine quantity: ");
    scanf("%d", &medicineList[*numMedics].quantity);

    printf("Enter the medicine price: ");
    scanf("%lf", &medicineList[*numMedics].price);

    // Increment the number of medicines
    (*numMedics)++;
}

// Define a function to list all medicines in the store
void listMedicines(Medicine *medicineList, int numMedics)
{
    // Print the list of medicines
    for (int i = 0; i < numMedics; i++)
    {
        printf("%s - %d - %.2lf\n", medicineList[i].name, medicineList[i].quantity, medicineList[i].price);
    }
}

// Define a function to search for a medicine in the store
void searchMedicine(Medicine *medicineList, int numMedics)
{
    // Get the medicine name
    char searchName[20];
    printf("Enter the medicine name: ");
    scanf("%s", searchName);

    // Search for the medicine
    for (int i = 0; i < numMedics; i++)
    {
        if (strcmp(medicineList[i].name, searchName) == 0)
        {
            printf("%s - %d - %.2lf\n", medicineList[i].name, medicineList[i].quantity, medicineList[i].price);
        }
    }
}

int main()
{
    // Define an array of medicines
    Medicine *medicineList = NULL;

    // Define the number of medicines
    int numMedics = 0;

    // Add some medicines to the store
    addMedicine(medicineList, &numMedics);
    addMedicine(medicineList, &numMedics);
    addMedicine(medicineList, &numMedics);

    // List all medicines in the store
    listMedicines(medicineList, numMedics);

    // Search for a medicine in the store
    searchMedicine(medicineList, numMedics);

    return 0;
}