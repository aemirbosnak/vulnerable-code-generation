//Gemma-7B DATASET v1.0 Category: Password management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10

typedef struct Password
{
    char *name;
    char *password;
    struct Password *next;
} Password;

void addPassword(Password **head)
{
    Password *newPass = (Password *)malloc(sizeof(Password));
    newPass->name = strdup("Test");
    newPass->password = strdup("Secret");
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

void printPasswords(Password *head)
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
    addPassword(&passwords);
    addPassword(&passwords);
    addPassword(&passwords);

    printPasswords(passwords);

    return 0;
}