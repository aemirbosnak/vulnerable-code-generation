//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char **phoneBook = NULL;
    int size = 0;

    // Decentralized phone book operations
    while (1)
    {
        char name[256];
        char number[256];

        printf("Enter name: ");
        scanf("%s", name);

        printf("Enter number: ");
        scanf("%s", number);

        // Allocate memory for new entry
        if (size == 0)
        {
            phoneBook = malloc(sizeof(char *) * 10);
            size = 10;
        }
        else if (size == phoneBook[0])
        {
            phoneBook = realloc(phoneBook, sizeof(char *) * size * 2);
            size *= 2;
        }

        phoneBook[size - 1] = malloc(sizeof(char) * 256);
        strcpy(phoneBook[size - 1], name);
        strcpy(phoneBook[size - 1] + 256, number);

        printf("Entry added.\n");

        // Option to continue or quit
        char choice;
        printf("Enter 'c' to continue or 'q' to quit: ");
        scanf("%c", &choice);

        if (choice == 'q')
            break;
    }

    // Print phone book contents
    printf("Phone book:\n");
    for (int i = 0; i < size; i++)
    {
        if (phoneBook[i] != NULL)
        {
            printf("%s - %s\n", phoneBook[i], phoneBook[i] + 256);
        }
    }

    // Free memory
    for (int i = 0; i < size; i++)
    {
        if (phoneBook[i] != NULL)
        {
            free(phoneBook[i]);
        }
    }
    free(phoneBook);

    return 0;
}