//Gemma-7B DATASET v1.0 Category: Password management ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PASSWORDS 10
#define MAX_LENGTH 255

typedef struct Password {
    char *name;
    char *password;
    struct Password *next;
} Password;

int main() {
    Password *head = NULL;
    int i = 0;

    // Allocate memory for the passwords
    head = (Password *)malloc(MAX_PASSWORDS * sizeof(Password));
    for (i = 0; i < MAX_PASSWORDS; i++) {
        head[i].name = (char *)malloc(MAX_LENGTH * sizeof(char));
        head[i].password = (char *)malloc(MAX_LENGTH * sizeof(char));
    }

    // Prompt the user to enter their passwords
    printf("Enter the name of the password: ");
    scanf("%s", head[i].name);

    printf("Enter the password: ");
    scanf("%s", head[i].password);

    // Add the password to the list
    head[i].next = head;
    head = head[i].next;

    // Print the passwords
    printf("Here are your passwords:\n");
    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (head[i].name) {
            printf("%s: %s\n", head[i].name, head[i].password);
        }
    }

    // Free the memory
    for (i = 0; i < MAX_PASSWORDS; i++) {
        free(head[i].name);
        free(head[i].password);
    }
    free(head);

    return 0;
}