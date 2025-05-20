//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: cheerful
#include <stdio.h>

int main()
{
    int i, n, choice, found = 0;
    char name[20], search[20];

    printf("Welcome to the C Phone Book!\n");
    printf("Please enter the number of entries: ");
    scanf("%d", &n);

    // Create an array of structures to store phone book entries
    struct phoneBookEntry
    {
        char name[20];
        int number;
    } phoneBook[n];

    // Populate the phone book
    for (i = 0; i < n; i++)
    {
        printf("Enter the name of the person: ");
        scanf("%s", phoneBook[i].name);

        printf("Enter their phone number: ");
        scanf("%d", &phoneBook[i].number);
    }

    // Search for a name in the phone book
    printf("Enter the name of the person you want to find: ");
    scanf("%s", search);

    // Iterate over the phone book to find the entry
    for (i = 0; i < n; i++)
    {
        if (strcmp(phoneBook[i].name, search) == 0)
        {
            found = 1;
            printf("Name: %s\n", phoneBook[i].name);
            printf("Phone number: %d\n", phoneBook[i].number);
        }
    }

    // If the name was not found, print an error message
    if (!found)
    {
        printf("Sorry, the name was not found.\n");
    }

    return 0;
}