//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

// Define the two families
struct family
{
    char name[MAX_NAME_LENGTH];
    int members;
    struct family* next;
};

// Create a linked list of families
struct family* family_head = NULL;

// Function to add a family to the list
void add_family(char* name, int members)
{
    struct family* new_family = malloc(sizeof(struct family));

    strcpy(new_family->name, name);
    new_family->members = members;
    new_family->next = NULL;

    if (family_head == NULL)
    {
        family_head = new_family;
    }
    else
    {
        family_head->next = new_family;
        family_head = new_family;
    }
}

// Function to print family information
void print_family(struct family* family)
{
    printf("Family name: %s\n", family->name);
    printf("Number of members: %d\n", family->members);
    printf("\n");
}

int main()
{
    // Create the two families
    add_family("Montague", 5);
    add_family("Capulet", 6);

    // Print family information
    print_family(family_head);

    return 0;
}