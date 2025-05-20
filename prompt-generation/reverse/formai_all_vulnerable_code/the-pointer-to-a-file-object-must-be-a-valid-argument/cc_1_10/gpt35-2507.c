//FormAI DATASET v1.0 Category: System administration ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to check if a given user exists on the system 
int doesUserExist(char *username) {
    int flag = 0;
    char command[100];
    sprintf(command, "grep -c \"%s\" /etc/passwd", username);
    FILE *output = popen(command, "r");
    char line[10];
    fgets(line, 10, output);
    if (atoi(line) > 0) {
        printf("User '%s' exists\n", username);
        flag = 1;
    } else {
        printf("User '%s' does not exist\n", username);
    }
    pclose(output);
    return flag;
}

// Function to add a new user to the system 
void addUser(char *username, char *password) {
    if (doesUserExist(username)) {
        printf("Cannot add user '%s'. User already exists\n", username);
        return;
    }
    char command[100];
    sprintf(command, "useradd -m -p $(openssl passwd -1 %s) %s", password, username);
    system(command);
    printf("User '%s' added to the system\n", username);
}

// Function to delete a user from the system 
void deleteUser(char *username) {
    if (!doesUserExist(username)) {
        printf("Cannot delete user '%s'. User does not exist\n", username);
        return;
    }
    char command[100];
    sprintf(command, "userdel -rf %s", username);
    system(command);
    printf("User '%s' deleted from the system\n", username);
}

int main() {
    int option;
    char username[20], password[20];
    printf("Welcome to the System Administration Program\n");
    do {
        printf("\nSelect an option:\n");
        printf("1. Check if a user exists on the system\n");
        printf("2. Add a new user to the system\n");
        printf("3. Delete a user from the system\n");
        printf("4. Exit\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                doesUserExist(username);
                break;
            case 2:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                addUser(username, password);
                break;
            case 3:
                printf("Enter username: ");
                scanf("%s", username);
                deleteUser(username);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option. Please select again.\n");
        }
    } while (option != 4);
    return 0;
}