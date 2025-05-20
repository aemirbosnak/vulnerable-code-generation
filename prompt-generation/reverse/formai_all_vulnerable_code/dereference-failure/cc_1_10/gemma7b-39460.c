//Gemma-7B DATASET v1.0 Category: Password management ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10

typedef struct _Password
{
    char *name;
    char *password;
    struct _Password *next;
} Password;

Password *passwords = NULL;

void addPassword(char *name, char *password)
{
    Password *new_password = malloc(sizeof(Password));
    new_password->name = strdup(name);
    new_password->password = strdup(password);
    new_password->next = NULL;

    if (passwords == NULL)
    {
        passwords = new_password;
    }
    else
    {
        passwords->next = new_password;
        passwords = new_password;
    }
}

void listPasswords()
{
    Password *current_password = passwords;

    while (current_password)
    {
        printf("%s: %s\n", current_password->name, current_password->password);
        current_password = current_password->next;
    }
}

int main()
{
    addPassword("alice", "secret");
    addPassword("bob", "strong");
    addPassword("charlie", "123");

    listPasswords();

    return 0;
}