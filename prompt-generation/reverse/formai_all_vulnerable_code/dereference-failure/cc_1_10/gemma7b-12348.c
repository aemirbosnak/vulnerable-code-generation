//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

typedef struct Customer
{
    char name[20];
    int age;
    struct Customer* next;
} Customer;

int main()
{
    Customer* head = NULL;
    Customer* tail = NULL;

    // Allocate memory for the first customer
    head = (Customer*)malloc(sizeof(Customer));
    tail = head;

    // Get the customer's name and age
    printf("Enter the customer's name: ");
    scanf("%s", head->name);

    printf("Enter the customer's age: ");
    scanf("%d", &head->age);

    // Link the first customer to the tail
    tail->next = NULL;

    // Add more customers to the list
    while (1)
    {
        // Allocate memory for a new customer
        Customer* newCustomer = (Customer*)malloc(sizeof(Customer));

        // Get the customer's name and age
        printf("Enter the customer's name: ");
        scanf("%s", newCustomer->name);

        printf("Enter the customer's age: ");
        scanf("%d", &newCustomer->age);

        // Link the new customer to the tail
        tail->next = newCustomer;
        tail = newCustomer;

        // Ask if the customer wants to add more customers
        char answer;
        printf("Do you want to add more customers? (Y/N): ");
        scanf("%c", &answer);

        // If the customer does not want to add more customers, break out of the loop
        if (answer == 'N')
        {
            break;
        }
    }

    // Print the list of customers
    printf("Here is the list of customers:\n");
    Customer* currentCustomer = head;
    while (currentCustomer)
    {
        printf("Name: %s, Age: %d\n", currentCustomer->name, currentCustomer->age);
        currentCustomer = currentCustomer->next;
    }

    return 0;
}