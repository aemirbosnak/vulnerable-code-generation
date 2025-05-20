//Gemma-7B DATASET v1.0 Category: Password management ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10

typedef struct Password
{
    char *name;
    char *password;
    struct Password *next;
} Password;

void insertPassword(Password **head, char *name, char *password)
{
    Password *newPass = malloc(sizeof(Password));
    newPass->name = strdup(name);
    newPass->password = strdup(password);
    newPass->next = NULL;

    if (*head == NULL)
    {
        *head = newPass;
    }
    else
    {
        (*head)->next = newPass;
    }
}

void displayPasswords(Password *head)
{
    while (head)
    {
        printf("%s - %s\n", head->name, head->password);
        head = head->next;
    }
}

int main()
{
    Password *passwords = NULL;

    insertPassword(&passwords, "John Doe", "secret1");
    insertPassword(&passwords, "Jane Doe", "secret2");
    insertPassword(&passwords, "Bob Smith", "secret3");

    displayPasswords(passwords);

    return 0;
}