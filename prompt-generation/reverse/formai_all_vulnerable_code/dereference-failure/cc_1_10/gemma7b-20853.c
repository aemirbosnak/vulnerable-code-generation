//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Medicine
{
    char name[20];
    int quantity;
    float price;
} Medicine;

void add_medicine(Medicine *medicines, int *num_medicines);
void display_medicines(Medicine *medicines, int num_medicines);
void update_medicine(Medicine *medicines, int num_medicines);

int main()
{
    int num_medicines = 0;
    Medicine *medicines = NULL;

    char choice;

    while (1)
    {
        printf("\nWelcome to the Medical Store Management System!\n");
        printf("Please select an option:\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Update Medicine\n");
        printf("4. Exit\n");

        scanf(" %c", &choice);

        switch (choice)
        {
            case '1':
                add_medicine(medicines, &num_medicines);
                break;
            case '2':
                display_medicines(medicines, num_medicines);
                break;
            case '3':
                update_medicine(medicines, num_medicines);
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}

void add_medicine(Medicine *medicines, int *num_medicines)
{
    Medicine new_medicine;

    printf("Enter the name of the medicine: ");
    scanf("%s", new_medicine.name);

    printf("Enter the quantity of the medicine: ");
    scanf("%d", &new_medicine.quantity);

    printf("Enter the price of the medicine: ");
    scanf("%f", &new_medicine.price);

    medicines = (Medicine *)realloc(medicines, (*num_medicines + 1) * sizeof(Medicine));
    medicines[*num_medicines] = new_medicine;
    *num_medicines++;
}

void display_medicines(Medicine *medicines, int num_medicines)
{
    for (int i = 0; i < num_medicines; i++)
    {
        printf("Name: %s\n", medicines[i].name);
        printf("Quantity: %d\n", medicines[i].quantity);
        printf("Price: %.2f\n", medicines[i].price);
        printf("\n");
    }
}

void update_medicine(Medicine *medicines, int num_medicines)
{
    char name[20];

    printf("Enter the name of the medicine you want to update: ");
    scanf("%s", name);

    for (int i = 0; i < num_medicines; i++)
    {
        if (strcmp(medicines[i].name, name) == 0)
        {
            printf("Enter the new quantity of the medicine: ");
            scanf("%d", &medicines[i].quantity);

            printf("Enter the new price of the medicine: ");
            scanf("%f", &medicines[i].price);

            printf("Medicine updated successfully!\n");
            return;
        }
    }

    printf("Medicine not found.\n");
}