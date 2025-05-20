//Gemma-7B DATASET v1.0 Category: Password management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 255

typedef struct Password
{
    char *name;
    char *password;
} Password;

Password passwords[MAX_PASSWORDS];

void create_password(char *name, char *password)
{
    int i = 0;

    for (i = 0; i < MAX_PASSWORDS; i++)
    {
        if (passwords[i].name == NULL)
        {
            passwords[i].name = strdup(name);
            passwords[i].password = strdup(password);
            return;
        }
    }

    printf("Error: No more passwords can be created.\n");
}

void print_passwords()
{
    int i = 0;

    for (i = 0; i < MAX_PASSWORDS; i++)
    {
        if (passwords[i].name)
        {
            printf("Name: %s, Password: %s\n", passwords[i].name, passwords[i].password);
        }
    }
}

int main()
{
    create_password("John Doe", "Secret12!");
    create_password("Jane Doe", "Secret23!");
    print_passwords();

    return 0;
}