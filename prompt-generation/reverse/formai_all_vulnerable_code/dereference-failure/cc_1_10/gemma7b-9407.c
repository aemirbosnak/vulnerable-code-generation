//Gemma-7B DATASET v1.0 Category: System administration ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define a variable to store the number of users
    int numUsers = 0;

    // Loop to get the number of users
    while (1)
    {
        printf("Enter the number of users: ");
        scanf("%d", &numUsers);

        // Check if the input is valid
        if (numUsers < 1)
        {
            printf("Invalid input. Please try again.\n");
        }
        else
        {
            break;
        }
    }

    // Allocate memory for the users
    char **users = (char **)malloc(numUsers * sizeof(char *));

    // Loop to get the users' names
    for (int i = 0; i < numUsers; i++)
    {
        printf("Enter the name of user %d: ", i + 1);
        users[i] = (char *)malloc(20 * sizeof(char));
        scanf("%s", users[i]);
    }

    // Print the users' names
    for (int i = 0; i < numUsers; i++)
    {
        printf("User %d: %s\n", i + 1, users[i]);
    }

    // Free the memory allocated for the users
    for (int i = 0; i < numUsers; i++)
    {
        free(users[i]);
    }

    // Free the memory allocated for the users array
    free(users);

    return 0;
}