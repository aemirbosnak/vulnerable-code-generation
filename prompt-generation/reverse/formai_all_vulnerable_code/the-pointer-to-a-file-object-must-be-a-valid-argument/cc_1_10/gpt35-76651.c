//FormAI DATASET v1.0 Category: System administration ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Define necessary variables
    char username[30];
    char password[30];
    char confirm[30];
    int password_match = 0;
    
    // Prompt user to create new username and password
    printf("Welcome to the System Administration Program!\n");
    printf("Please enter a new username: ");
    fgets(username, 30, stdin);
    username[strcspn(username, "\n")] = 0; // Remove newline character
    
    while (!password_match) {
        printf("Please enter a new password: ");
        fgets(password, 30, stdin);
        password[strcspn(password, "\n")] = 0; // Remove newline character
        
        printf("Please confirm your password: ");
        fgets(confirm, 30, stdin);
        confirm[strcspn(confirm, "\n")] = 0; // Remove newline character
        
        if (strcmp(password, confirm) == 0) {
            printf("Password confirmation successful.\n");
            password_match = 1;
        } else {
            printf("Passwords do not match. Please try again.\n");
        }
    }
    
    // Create new user account
    FILE *fp;
    fp = fopen("user_accounts.txt", "a");
    fprintf(fp, "%s:%s\n", username, password);
    fclose(fp);
    
    printf("User account %s created successfully!\n", username);
    
    // Display list of user accounts
    fp = fopen("user_accounts.txt", "r");
    char buf[1024];
    printf("\nList of user accounts:\n");
    while (fgets(buf, 1024, fp)) {
        printf("%s", buf);
    }
    fclose(fp);
    
    return 0;
}