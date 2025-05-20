//Gemma-7B DATASET v1.0 Category: Password management ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10
#define PASSWORD_LENGTH 16

typedef struct Password
{
    char *name;
    char *password;
} Password;

void create_passwords(Password *passwords)
{
    passwords = malloc(MAX_PASSWORDS * sizeof(Password));
    for (int i = 0; i < MAX_PASSWORDS; i++)
    {
        passwords[i].name = malloc(PASSWORD_LENGTH);
        passwords[i].password = malloc(PASSWORD_LENGTH);
    }
}

void store_passwords(Password *passwords, char *name, char *password)
{
    for (int i = 0; i < MAX_PASSWORDS; i++)
    {
        if (passwords[i].name == NULL)
        {
            passwords[i].name = strdup(name);
            passwords[i].password = strdup(password);
            return;
        }
    }

    printf("Error: No more passwords can be stored.\n");
}

char *retrieve_password(Password *passwords, char *name)
{
    for (int i = 0; i < MAX_PASSWORDS; i++)
    {
        if (passwords[i].name && strcmp(passwords[i].name, name) == 0)
        {
            return passwords[i].password;
        }
    }

    return NULL;
}

int main()
{
    Password *passwords = NULL;
    create_passwords(passwords);

    store_passwords(passwords, "John Doe", "Secret123!");
    store_passwords(passwords, "Jane Doe", "Secret456!");

    char *password = retrieve_password(passwords, "John Doe");
    if (password)
    {
        printf("Password for John Doe: %s\n", password);
    } else
    {
        printf("Error: Password not found.\n");
    }

    return 0;
}