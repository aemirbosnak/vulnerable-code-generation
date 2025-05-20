//FormAI DATASET v1.0 Category: System administration ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    // Check if user is an administrator
    if(getuid() != 0) {
        printf("You must have root privileges to run this program.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize variables
    char choice;
    FILE *fp;
    char *filename = "users.txt";
    char username[20], password[20];

    // Display menu options
    printf("Welcome to User Management System\n");
    printf("---------------------------------\n\n");
    printf("1. Add new user\n");
    printf("2. Remove existing user\n");
    printf("3. List all users\n");
    printf("4. Exit\n\n");

    // Prompt user for choice
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    switch(choice) {

        case '1':
            // Prompt user for username and password
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);

            // Append user to file
            fp = fopen(filename, "a");
            fprintf(fp, "%s:%s\n", username, password);
            fclose(fp);

            printf("User added successfully.\n");
            break;

        case '2':
            // Prompt user for username to remove
            printf("Enter username to remove: ");
            scanf("%s", username);

            // Open file for reading
            fp = fopen(filename, "r");

            // Create temporary file for writing
            FILE *temp = fopen("temp.txt", "w");

            char line[50];
            while(fgets(line, sizeof(line), fp)) {
                char *name = strtok(line, ":");
                if(strcmp(name, username) != 0) {
                    fputs(line, temp);
                }
            }

            // Close both files
            fclose(fp);
            fclose(temp);

            // Remove original file and rename temporary file
            remove(filename);
            rename("temp.txt", filename);

            printf("User removed successfully.\n");
            break;

        case '3':
            // Open file for reading
            fp = fopen(filename, "r");

            // Read file line by line and print usernames
            printf("List of users:\n");
            char line2[50];
            while(fgets(line2, sizeof(line2), fp)) {
                char *name = strtok(line2, ":");
                printf("%s\n", name);
            }

            // Close file
            fclose(fp);
            break;

        case '4':
            // Exit program
            printf("Exiting program...\n");
            exit(EXIT_SUCCESS);
            break;

        default:
            // Invalid choice
            printf("Invalid choice. Please select a valid option.\n");
            break;
    }

    return 0;
}