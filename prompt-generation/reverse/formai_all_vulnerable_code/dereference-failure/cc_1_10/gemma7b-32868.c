//Gemma-7B DATASET v1.0 Category: Password management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORDS 10

typedef struct Password
{
    char *name;
    char *password;
    struct Password *next;
} Password;

Password *createPassword(char *name, char *password)
{
    Password *newPass = malloc(sizeof(Password));

    newPass->name = strdup(name);
    newPass->password = strdup(password);
    newPass->next = NULL;

    return newPass;
}

void addPassword(Password *head, char *name, char *password)
{
    Password *newPass = createPassword(name, password);

    if (head == NULL)
    {
        head = newPass;
    }
    else
    {
        head->next = newPass;
    }
}

void printPasswords(Password *head)
{
    Password *currPass = head;

    while (currPass)
    {
        printf("Name: %s, Password: %s\n", currPass->name, currPass->password);
        currPass = currPass->next;
    }
}

int main()
{
    Password *passwords = NULL;

    addPassword(passwords, "John Doe", "Secret1");
    addPassword(passwords, "Jane Doe", "Secret2");
    addPassword(passwords, "Bob Smith", "Secret3");

    printPasswords(passwords);

    return 0;
}