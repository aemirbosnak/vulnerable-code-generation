//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <grp.h>

#define MAX_PASSWORDS 10
#define MAX_GROUPS 5

// Structure to store password and group information
typedef struct {
    char *password;
    char *group;
} password_info;

// Function to read passwords and groups from file
void read_passwords(password_info *passwords, int max_passwords, char *file_name) {
    FILE *file = fopen(file_name, "r");
    char line[1024];
    int i = 0;

    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    while (fgets(line, 1024, file) != NULL) {
        // Ignore empty lines and comments
        if (line[0] == '\0' || strncmp(line, "#", 2) == 0) {
            continue;
        }

        // Parse password and group information
        char *password = strtok(line, ":");
        char *group = strtok(NULL, ":");

        // Check for invalid input
        if (password == NULL || group == NULL) {
            perror("Invalid input");
            exit(1);
        }

        // Add password and group to list
        passwords[i].password = password;
        passwords[i].group = group;
        i++;

        if (i >= max_passwords) {
            break;
        }
    }

    fclose(file);
}

// Function to check if password is in the list
int check_password(password_info passwords[], int num_passwords, char *password) {
    int i;

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].password, password) == 0) {
            return 1;
        }
    }

    return 0;
}

// Function to display the list of passwords and their corresponding groups
void display_passwords(password_info passwords[], int num_passwords) {
    int i;

    for (i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].password, passwords[i].group);
    }
}

int main() {
    // Read passwords and groups from file
    password_info passwords[MAX_PASSWORDS];
    read_passwords(passwords, MAX_PASSWORDS, "passwords.txt");

    // Check if the user's input password is in the list
    char *password = "my_secret_password";
    if (check_password(passwords, MAX_PASSWORDS, password)) {
        printf("Password found\n");
    } else {
        printf("Password not found\n");
    }

    // Display the list of passwords and their corresponding groups
    display_passwords(passwords, MAX_PASSWORDS);

    return 0;
}