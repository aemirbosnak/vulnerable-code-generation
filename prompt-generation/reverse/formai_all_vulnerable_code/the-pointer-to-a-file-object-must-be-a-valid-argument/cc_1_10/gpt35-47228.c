//FormAI DATASET v1.0 Category: System administration ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// declare function prototypes
void displayUsers();
void addUser();
void removeUser();
void displaySystemLogs();

int main() {
    int choice;
    printf("Welcome to the Future System Administrator Program!\n");
    
    // keep running the program until the user chooses to exit
    while(1) {
        printf("\nPlease choose an operation:\n");
        printf("1. Display all users\n");
        printf("2. Add a new user\n");
        printf("3. Remove a user\n");
        printf("4. Display system logs\n");
        printf("5. Exit program\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displayUsers();
                break;
            case 2:
                addUser();
                break;
            case 3:
                removeUser();
                break;
            case 4:
                displaySystemLogs();
                break;
            case 5:
                printf("Thank you for using the Future System Administrator Program!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void displayUsers() {
    FILE *fp = fopen("userlist.txt", "r");
    char line[1000];
    while(fgets(line, 1000, fp) != NULL) {
        printf("%s", line);
    }
    fclose(fp);
}

void addUser() {
    char username[20], password[20], confirm_password[20];
    printf("Enter a username: ");
    scanf("%s", username);
    
    // check if the username already exists
    FILE *fp = fopen("userlist.txt", "r");
    char line[1000];
    while(fgets(line, 1000, fp) != NULL) {
        char *token = strtok(line, " ");
        if (strcmp(token, username) == 0) {
            printf("Error: username already exists.\n");
            fclose(fp);
            return;
        }
    }
    fclose(fp);

    printf("Enter a password: ");
    scanf("%s", password);
    printf("Confirm password: ");
    scanf("%s", confirm_password);

    // check if the passwords match
    if (strcmp(password, confirm_password) != 0) {
        printf("Error: passwords do not match.\n");
        return;
    }

    // add the new user to the userlist.txt file
    fp = fopen("userlist.txt", "a");
    fprintf(fp, "%s %s\n", username, password);
    printf("User added successfully.\n");
    fclose(fp);
}

void removeUser() {
    char username[20];
    printf("Enter the username of the user to remove: ");
    scanf("%s", username);

    // remove the user from the userlist.txt file
    FILE *fp1 = fopen("userlist.txt", "r");
    FILE *fp2 = fopen("temp.txt", "w");
    char line[1000];
    int found = 0;
    while(fgets(line, 1000, fp1) != NULL) {
        char *token = strtok(line, " ");
        if (strcmp(token, username) != 0) {
            fprintf(fp2, "%s", line);
        } else {
            found = 1;
        }
    }
    fclose(fp1);
    fclose(fp2);

    // check if the user was found and removed
    if (found) {
        remove("userlist.txt");
        rename("temp.txt", "userlist.txt");
        printf("User removed successfully.\n");
    } else {
        printf("Error: user not found.\n");
        remove("temp.txt");
    }
}

void displaySystemLogs() {
    printf("Displaying system logs...\n");
    srand(time(0));
    int num_logs = rand() % 20 + 1; // get a random number of logs to generate
    for (int i = 0; i < num_logs; i++) {
        int code = rand() % 3 + 1; // randomly choose a log code
        char *description;
        switch(code) {
            case 1:
                description = "system boot";
                break;
            case 2:
                description = "user login";
                break;
            case 3:
                description = "system update";
                break;
        }
        printf("[%d] %s\n", code, description);
    }
}