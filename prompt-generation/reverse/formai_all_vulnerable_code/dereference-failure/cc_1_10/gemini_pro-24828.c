//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the details of a medicine
typedef struct Medicine
{
	char name[50];
	char company[50];
	float price;
	int quantity;
} Medicine;

// Function to add a new medicine to the inventory
void addMedicine(Medicine **inventory, int *count)
{
	// Allocate memory for the new medicine
	Medicine *newMedicine = (Medicine *)malloc(sizeof(Medicine));

	// Get the details of the new medicine from the user
	printf("Enter the name of the medicine: ");
	scanf(" %s", newMedicine->name);

	printf("Enter the name of the company: ");
	scanf(" %s", newMedicine->company);

	printf("Enter the price of the medicine: ");
	scanf(" %f", &newMedicine->price);

	printf("Enter the quantity of the medicine: ");
	scanf(" %d", &newMedicine->quantity);

	// Add the new medicine to the inventory
	inventory[*count] = newMedicine;

	// Increment the count of medicines in the inventory
	(*count)++;
}

// Function to display the inventory of medicines
void displayInventory(Medicine **inventory, int count)
{
	printf("Inventory of Medicines:\n");
	printf("------------------------------------------------------------------------------------\n");
	printf("| %-20s | %-20s | %-10s | %-10s |\n", "Name", "Company", "Price", "Quantity");
	printf("------------------------------------------------------------------------------------\n");

	for (int i = 0; i < count; i++)
	{
		printf("| %-20s | %-20s | %-10.2f | %-10d |\n", inventory[i]->name, inventory[i]->company, inventory[i]->price, inventory[i]->quantity);
	}

	printf("------------------------------------------------------------------------------------\n");
}

// Function to search for a medicine in the inventory
int searchMedicine(Medicine **inventory, int count, char *name)
{
	for (int i = 0; i < count; i++)
	{
		if (strcmp(inventory[i]->name, name) == 0)
		{
			return i;
		}
	}

	return -1;
}

// Function to update the details of a medicine in the inventory
void updateMedicine(Medicine **inventory, int count)
{
	char name[50];
	int index;

	// Get the name of the medicine to be updated
	printf("Enter the name of the medicine to be updated: ");
	scanf(" %s", name);

	// Search for the medicine in the inventory
	index = searchMedicine(inventory, count, name);

	if (index == -1)
	{
		printf("Medicine not found.\n");
	}
	else
	{
		// Get the updated details of the medicine from the user
		printf("Enter the new name of the medicine: ");
		scanf(" %s", inventory[index]->name);

		printf("Enter the new name of the company: ");
		scanf(" %s", inventory[index]->company);

		printf("Enter the new price of the medicine: ");
		scanf(" %f", &inventory[index]->price);

		printf("Enter the new quantity of the medicine: ");
		scanf(" %d", &inventory[index]->quantity);
	}
}

// Function to delete a medicine from the inventory
void deleteMedicine(Medicine **inventory, int *count)
{
	char name[50];
	int index;

	// Get the name of the medicine to be deleted
	printf("Enter the name of the medicine to be deleted: ");
	scanf(" %s", name);

	// Search for the medicine in the inventory
	index = searchMedicine(inventory, *count, name);

	if (index == -1)
	{
		printf("Medicine not found.\n");
	}
	else
	{
		// Delete the medicine from the inventory
		free(inventory[index]);

		// Shift the remaining medicines down one position
		for (int i = index; i < *count - 1; i++)
		{
			inventory[i] = inventory[i + 1];
		}

		// Decrement the count of medicines in the inventory
		(*count)--;
	}
}

// Main function
int main()
{
	// Declare an array of pointers to medicines
	Medicine **inventory;

	// Allocate memory for the array of pointers
	inventory = (Medicine **)malloc(100 * sizeof(Medicine *));

	// Initialize the count of medicines to 0
	int count = 0;

	// Add some sample medicines to the inventory
	addMedicine(&inventory, &count);
	addMedicine(&inventory, &count);
	addMedicine(&inventory, &count);

	// Display the inventory of medicines
	displayInventory(inventory, count);

	// Search for a medicine in the inventory
	char name[50];
	printf("Enter the name of the medicine to be searched: ");
	scanf(" %s", name);

	int index = searchMedicine(inventory, count, name);

	if (index == -1)
	{
		printf("Medicine not found.\n");
	}
	else
	{
		printf("Medicine found:\n");
		printf("------------------------------------------------------------------------------------\n");
		printf("| %-20s | %-20s | %-10s | %-10s |\n", "Name", "Company", "Price", "Quantity");
		printf("------------------------------------------------------------------------------------\n");
		printf("| %-20s | %-20s | %-10.2f | %-10d |\n", inventory[index]->name, inventory[index]->company, inventory[index]->price, inventory[index]->quantity);
		printf("------------------------------------------------------------------------------------\n");
	}

	// Update the details of a medicine in the inventory
	updateMedicine(inventory, count);

	// Delete a medicine from the inventory
	deleteMedicine(inventory, &count);

	// Display the updated inventory of medicines
	displayInventory(inventory, count);

	// Free the allocated memory
	for (int i = 0; i < count; i++)
	{
		free(inventory[i]);
	}

	free(inventory);

	return 0;
}