//Gemma-7B DATASET v1.0 Category: Password management ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 5
#define MAX_CHAR 20

typedef struct Password
{
    char *name;
    char *password;
    struct Password *next;
} Password;

void create_password(Password **head)
{
    *head = malloc(sizeof(Password));
    (*head)->name = malloc(MAX_CHAR);
    (*head)->password = malloc(MAX_CHAR);
    (*head)->next = NULL;
}

void add_password(Password **head, char *name, char *password)
{
    Password *new_password = malloc(sizeof(Password));
    new_password->name = malloc(MAX_CHAR);
    new_password->password = malloc(MAX_CHAR);
    new_password->next = NULL;

    strcpy(new_password->name, name);
    strcpy(new_password->password, password);

    if (*head == NULL)
    {
        *head = new_password;
    }
    else
    {
        (*head)->next = new_password;
    }
}

void search_password(Password *head, char *name)
{
    while (head)
    {
        if (strcmp(head->name, name) == 0)
        {
            printf("Password: %s\n", head->password);
            return;
        }
        head = head->next;
    }

    printf("Password not found.\n");
}

int main()
{
    Password *head = NULL;

    create_password(&head);
    add_password(&head, "John Doe", "Secret123!");
    add_password(&head, "Jane Doe", "StrongPaswd!");
    add_password(&head, "Mr. Smith", "Password123!");

    search_password(head, "John Doe");
    search_password(head, "Jane Doe");
    search_password(head, "Mr. Smith");

    return 0;
}