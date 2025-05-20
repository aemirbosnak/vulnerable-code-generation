//Gemma-7B DATASET v1.0 Category: Password management ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inv_pw_mgmt(void)
{
    char **passwords = NULL;
    int i = 0, max_passwords = 0;

    // Allocate memory for the passwords array
    passwords = malloc(sizeof(char *) * max_passwords);

    // Get the current password from the user
    printf("Enter your current password: ");
    char current_pw[20];
    scanf("%s", current_pw);

    // Check if the password is valid
    for (i = 0; passwords[i] != NULL; i++)
    {
        if (strcmp(passwords[i], current_pw) == 0)
        {
            printf("Your password is valid.\n");
            break;
        }
    }

    // If the password is not valid, prompt the user to enter a new password
    if (passwords[i] == NULL)
    {
        printf("Your password is not valid. Please enter a new password: ");
        char new_pw[20];
        scanf("%s", new_pw);

        // Add the new password to the passwords array
        passwords[max_passwords++] = malloc(sizeof(char) * 20);
        strcpy(passwords[max_passwords - 1], new_pw);

        // Print a confirmation message
        printf("Your new password has been set.\n");
    }

    // Free the memory allocated for the passwords array
    for (i = 0; passwords[i] != NULL; i++)
    {
        free(passwords[i]);
    }
    free(passwords);
}

int main()
{
    inv_pw_mgmt();

    return 0;
}