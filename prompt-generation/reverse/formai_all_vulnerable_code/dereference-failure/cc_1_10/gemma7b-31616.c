//Gemma-7B DATASET v1.0 Category: Password management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **passwords = NULL;
    int num_passwords = 0;

    // Allocate memory for the passwords list
    passwords = malloc(sizeof(char *) * 10);
    if (passwords == NULL)
    {
        return EXIT_FAILURE;
    }

    // Get the number of passwords from the user
    printf("How many passwords do you want to manage? ");
    scanf("%d", &num_passwords);

    // Allocate memory for each password
    for (int i = 0; i < num_passwords; i++)
    {
        passwords[i] = malloc(sizeof(char) * 20);
        if (passwords[i] == NULL)
        {
            return EXIT_FAILURE;
        }
    }

    // Get the passwords from the user
    for (int i = 0; i < num_passwords; i++)
    {
        printf("Enter password %d: ", i + 1);
        scanf("%s", passwords[i]);
    }

    // Print the passwords
    for (int i = 0; i < num_passwords; i++)
    {
        printf("Password %d: %s\n", i + 1, passwords[i]);
    }

    // Free the memory allocated for the passwords
    for (int i = 0; i < num_passwords; i++)
    {
        free(passwords[i]);
    }

    free(passwords);

    return EXIT_SUCCESS;
}