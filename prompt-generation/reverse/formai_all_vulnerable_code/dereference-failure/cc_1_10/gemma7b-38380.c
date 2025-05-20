//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Define a struct to store information about a post-apocalyptic city
typedef struct City
{
    char name[50];
    int population;
    float resources;
    struct City* next;
} City;

// Create a linked list of post-apocalyptic cities
City* head = NULL;

// Function to add a new city to the linked list
void addCity(char* name, int population, float resources)
{
    City* newCity = malloc(sizeof(City));
    strcpy(newCity->name, name);
    newCity->population = population;
    newCity->resources = resources;
    newCity->next = NULL;

    if (head == NULL)
    {
        head = newCity;
    }
    else
    {
        City* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newCity;
    }
}

// Function to print information about a city
void printCity(City* city)
{
    printf("Name: %s\n", city->name);
    printf("Population: %d\n", city->population);
    printf("Resources: %.2f\n", city->resources);
}

int main()
{
    // Add some cities to the linked list
    addCity("The Last City", 10000, 10.0);
    addCity("The Scrapyard", 5000, 5.0);
    addCity("The Dust Bowl", 2000, 2.0);

    // Print information about the cities
    printCity(head);

    return 0;
}