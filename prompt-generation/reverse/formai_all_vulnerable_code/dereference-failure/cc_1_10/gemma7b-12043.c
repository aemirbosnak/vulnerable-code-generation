//Gemma-7B DATASET v1.0 Category: Password management ; Style: complete
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <openssl/sha.h>

#define MAX_PASSWORD_LENGTH 255

typedef struct Password {
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

void printPassword(Password *pass)
{
    while (pass)
    {
        printf("Name: %s\n", pass->name);
        printf("Password: %s\n", pass->password);
        printf("\n");
        pass = pass->next;
    }
}

int main()
{
    Password *head = NULL;

    // Create a few passwords
    Password *pass1 = createPassword("John Doe", "Secret123");
    Password *pass2 = createPassword("Jane Doe", "StrongPaswd");
    Password *pass3 = createPassword("Bob Smith", "SimplePass");

    // Link the passwords together
    head = pass1;
    pass1->next = pass2;
    pass2->next = pass3;

    // Print the passwords
    printPassword(head);

    return 0;
}