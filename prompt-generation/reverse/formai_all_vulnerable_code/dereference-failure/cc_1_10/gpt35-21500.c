//FormAI DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the structure for a medieval character
struct medievalCharacter
{
    char name[20];
    int age;
    char profession[20];
    struct medievalCharacter *next;
};

// Create a global head pointer to the first node of the linked list
struct medievalCharacter *head = NULL;

// Function to create a new medieval character node
struct medievalCharacter *createNewCharacter(char name[], int age, char profession[])
{
    struct medievalCharacter *newCharacter = (struct medievalCharacter *)malloc(sizeof(struct medievalCharacter));

    // Copy the input values into the new character node
    strcpy(newCharacter->name, name);
    newCharacter->age = age;
    strcpy(newCharacter->profession, profession);

    // Set the next pointer of the new character node to NULL
    newCharacter->next = NULL;

    return newCharacter;
}

// Function to add a new medieval character to the linked list
void addCharacter(char name[], int age, char profession[])
{
    struct medievalCharacter *newCharacter = createNewCharacter(name, age, profession);

    // If the head is null, point it to the new character
    if (head == NULL)
    {
        head = newCharacter;
    }
    else
    {
        // Otherwise, iterate through the linked list to find the end
        struct medievalCharacter *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }

        // Set the next pointer of the last node to the new character node
        current->next = newCharacter;
    }

    printf("%s added to the kingdom!\n", name);
}

// Function to display all medieval characters in the linked list
void displayCharacters()
{
    printf("Characters in the kingdom:\n");

    // Iterate through the linked list and print each character
    struct medievalCharacter *current = head;
    while (current != NULL)
    {
        printf("Name: %s\tAge: %d\tProfession: %s\n", current->name, current->age, current->profession);
        current = current->next;
    }
}

// Function to remove a medieval character from the linked list
void removeCharacter(char name[])
{
    // If the head node is the one to be removed
    if (strcmp(head->name, name) == 0)
    {
        // Set the head pointer to the next node
        struct medievalCharacter *temp = head;
        head = head->next;
        free(temp);
        printf("%s has been removed from the kingdom!\n", name);
    }
    else
    {
        // Otherwise, iterate through the linked list to find the node to remove
        struct medievalCharacter *current = head;
        struct medievalCharacter *previous = NULL;
        while (strcmp(current->name, name) != 0 && current != NULL)
        {
            previous = current;
            current = current->next;
        }

        // If the character is not found
        if (current == NULL)
        {
            printf("%s is not in the kingdom!\n", name);
        }
        else
        {
            // Remove the node by setting the previous node's next pointer to the next node
            previous->next = current->next;
            free(current);
            printf("%s has been removed from the kingdom!\n", name);
        }
    }
}

int main()
{
    printf("Welcome to the medieval character kingdom!\n");

    // Add some initial characters to the kingdom
    addCharacter("Arthur", 35, "King");
    addCharacter("Lancelot", 29, "Knight");
    addCharacter("Guinevere", 32, "Queen");
    addCharacter("Merlin", 56, "Wizard");

    // Display the characters in the kingdom
    displayCharacters();

    // Remove a character from the kingdom
    removeCharacter("Lancelot");

    // Display the updated characters in the kingdom
    displayCharacters();

    return 0;
}