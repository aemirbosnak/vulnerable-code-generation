//Gemma-7B DATASET v1.0 Category: Password management ; Style: high level of detail
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORDS 10

typedef struct Password
{
    char *name;
    char *password;
    struct Password *next;
} Password;

Password *insert_password(Password *head, char *name, char *password)
{
    Password *new_password = malloc(sizeof(Password));
    new_password->name = strdup(name);
    new_password->password = strdup(password);
    new_password->next = NULL;

    if (head == NULL)
    {
        head = new_password;
    }
    else
    {
        head->next = new_password;
    }

    return head;
}

void print_passwords(Password *head)
{
    Password *current = head;

    while (current)
    {
        printf("%s: %s\n", current->name, current->password);
        current = current->next;
    }
}

int main()
{
    Password *head = NULL;

    insert_password(head, "John Doe", "secret1");
    insert_password(head, "Jane Doe", "secret2");
    insert_password(head, "Bill Smith", "secret3");

    print_passwords(head);

    return 0;
}