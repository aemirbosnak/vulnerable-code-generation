//FormAI DATASET v1.0 Category: System administration ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayMenu() {
    printf("Choose an option:\n");
    printf("1. Add new user\n");
    printf("2. Remove user\n");
    printf("3. Display all users\n");
    printf("4. Exit\n");
}

void addUser(char **users, int *numUsers) {
    char *newUser = (char *)malloc(50 * sizeof(char));
    printf("Enter username to add: ");
    scanf("%s", newUser);
    users[*numUsers] = newUser;
    *numUsers += 1;
    printf("User %s added.\n", newUser);
}

void removeUser(char **users, int *numUsers) {
    char *userToRemove = (char *)malloc(50 * sizeof(char));
    int found = 0;
    printf("Enter username to remove: ");
    scanf("%s", userToRemove);
    for (int i = 0; i <*numUsers; i++) {
        if (strcmp(users[i], userToRemove) == 0) {
            free(users[i]);
            users[i] = NULL;
            found = 1;
            break;
        }
    }
    if (found) {
        *numUsers -= 1;
        printf("User %s removed.\n", userToRemove);
    } else {
        printf("User not found.\n");
    }
}

void displayUsers(char **users, int numUsers) {
    printf("All users:\n");
    for (int i = 0; i < numUsers; i++) {
        if (users[i] != NULL) {
            printf("- %s\n", users[i]);
        }
    }
}

int main() {
    char **users = (char **)malloc(100 * sizeof(char *));
    int numUsers = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addUser(users, &numUsers);
                break;
            case 2:
                removeUser(users, &numUsers);
                break;
            case 3:
                displayUsers(users, numUsers);
                break;
            case 4:
                printf("Exiting.\n");
                for (int i = 0; i < numUsers; i++) {
                    free(users[i]);
                }
                free(users);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}