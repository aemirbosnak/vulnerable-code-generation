//Gemma-7B DATASET v1.0 Category: Password management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_PASSWORD_LEN 255

typedef struct Password {
    char *name;
    char *password;
    struct Password *next;
} Password;

int main() {
    Password *head = NULL;
    Password *curr = NULL;
    char input[MAX_PASSWORD_LEN] = "";
    int option = 0;

    // Menu options
    printf("1. Add Password\n");
    printf("2. List Passwords\n");
    printf("3. Search Passwords\n");
    printf("4. Exit\n");

    // Get user input
    printf("Enter an option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            // Allocate memory for new password
            curr = malloc(sizeof(Password));
            curr->name = malloc(MAX_PASSWORD_LEN);
            curr->password = malloc(MAX_PASSWORD_LEN);

            // Get password details
            printf("Enter password name: ");
            scanf("%s", curr->name);

            printf("Enter password: ");
            scanf("%s", curr->password);

            // Add password to list
            if (head == NULL) {
                head = curr;
            } else {
                curr->next = head;
                head = curr;
            }

            break;
        case 2:
            // List all passwords
            curr = head;
            while (curr) {
                printf("Name: %s, Password: %s\n", curr->name, curr->password);
                curr = curr->next;
            }

            break;
        case 3:
            // Search for password
            printf("Enter password name: ");
            scanf("%s", input);

            curr = head;
            while (curr) {
                if (strcmp(curr->name, input) == 0) {
                    printf("Password: %s\n", curr->password);
                    break;
                }
                curr = curr->next;
            }

            if (curr == NULL) {
                printf("Password not found.\n");
            }

            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid option.\n");
    }

    return 0;
}