//Gemma-7B DATASET v1.0 Category: Password management ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10

typedef struct Password {
    char *name;
    char *password;
    struct Password *next;
} Password;

int main() {
    Password *passwords = NULL;
    int i = 0;

    // Allocate memory for the first password
    passwords = malloc(sizeof(Password));
    passwords->name = malloc(20);
    passwords->password = malloc(20);
    passwords->next = NULL;

    // Get the password from the user
    printf("Enter a password: ");
    scanf("%s", passwords->name);

    // Store the password
    printf("Enter your desired password: ");
    scanf("%s", passwords->password);

    // Insert the password into the list
    passwords->next = malloc(sizeof(Password));
    passwords->next->name = malloc(20);
    passwords->next->password = malloc(20);
    passwords->next->next = NULL;

    // Get the second password from the user
    printf("Enter a password: ");
    scanf("%s", passwords->next->name);

    // Store the password
    printf("Enter your desired password: ");
    scanf("%s", passwords->next->password);

    // Insert the password into the list
    passwords->next->next = malloc(sizeof(Password));
    passwords->next->next->name = malloc(20);
    passwords->next->next->password = malloc(20);
    passwords->next->next->next = NULL;

    // Print the passwords
    for (i = 0; i < MAX_PASSWORDS; i++) {
        printf("%s: %s\n", passwords->name[i], passwords->password[i]);
    }

    return 0;
}