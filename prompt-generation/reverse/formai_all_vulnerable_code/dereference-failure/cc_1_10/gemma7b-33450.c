//Gemma-7B DATASET v1.0 Category: Password management ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define PASSWORD_LENGTH 20

typedef struct Password
{
    char *name;
    char *password;
} Password;

int main()
{
    Password passwords[MAX_PASSWORDS];

    // Create and initialize passwords
    for (int i = 0; i < MAX_PASSWORDS; i++)
    {
        passwords[i].name = malloc(PASSWORD_LENGTH);
        passwords[i].password = malloc(PASSWORD_LENGTH);
    }

    // Get the password for a particular user
    printf("Enter the name of the user: ");
    scanf("%s", passwords[0].name);

    printf("Enter the password for %s: ", passwords[0].name);
    scanf("%s", passwords[0].password);

    // Check if the password is valid
    if (strcmp(passwords[0].password, "secret") == 0)
    {
        printf("Welcome, %s!", passwords[0].name);
    }
    else
    {
        printf("Invalid password.");
    }

    // Free memory
    for (int i = 0; i < MAX_PASSWORDS; i++)
    {
        free(passwords[i].name);
        free(passwords[i].password);
    }

    return 0;
}