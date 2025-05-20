//Gemma-7B DATASET v1.0 Category: Password management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 255

typedef struct Password {
    char *name;
    char *password;
    struct Password *next;
} Password;

Password *createPassword(char *name, char *password)
{
    Password *new_password = malloc(sizeof(Password));
    new_password->name = strdup(name);
    new_password->password = strdup(password);
    new_password->next = NULL;

    return new_password;
}

int main()
{
    Password *passwords = NULL;
    char name[255];
    char password[255];

    // Create a new password
    printf("Enter a username: ");
    scanf("%s", name);

    printf("Enter a password: ");
    scanf("%s", password);

    passwords = createPassword(name, password);

    // Add the new password to the list
    if (passwords)
    {
        passwords->next = passwords;
    }

    // Print the list of passwords
    Password *current_password = passwords;
    while (current_password)
    {
        printf("Username: %s\n", current_password->name);
        printf("Password: %s\n", current_password->password);
        printf("\n");
        current_password = current_password->next;
    }

    return 0;
}