//Gemma-7B DATASET v1.0 Category: Password management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define PASSWORD_LENGTH 20

char **passwords;

void initialize_passwords()
{
    passwords = malloc(MAX_PASSWORDS * sizeof(char *));
    for (int i = 0; i < MAX_PASSWORDS; i++)
    {
        passwords[i] = malloc(PASSWORD_LENGTH * sizeof(char));
    }
}

void store_password(char *password)
{
    int i = 0;
    for (char *p = passwords[i]; *p = password[i]; i++)
    {
        if (*p == '\0')
        {
            passwords[i] = realloc(passwords[i], PASSWORD_LENGTH * sizeof(char));
            break;
        }
    }

    strcpy(passwords[i], password);
}

char *retrieve_password(char *username)
{
    for (int i = 0; i < MAX_PASSWORDS; i++)
    {
        if (strcmp(passwords[i], username) == 0)
        {
            return passwords[i];
        }
    }

    return NULL;
}

int main()
{
    initialize_passwords();

    store_password("Secret123");
    store_password("MySecret");

    char *password = retrieve_password("Secret123");

    if (password)
    {
        printf("Your password is: %s\n", password);
    }

    return 0;
}