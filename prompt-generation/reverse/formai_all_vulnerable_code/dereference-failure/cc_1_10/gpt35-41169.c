//FormAI DATASET v1.0 Category: Password management ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// define the maximum number of passwords the user can store
#define MAX_PASSWORDS 100

// define the maximum length of each password
#define MAX_PASSWORD_LENGTH 50

// declare a struct to store the password and its corresponding username
struct password_info {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

// declare a global array to store the user's passwords
struct password_info passwords[MAX_PASSWORDS];

// declare a function to generate a random string of characters of a specified length
char* generate_random_string(int length) {
    char* result = malloc(length + 1);
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < length; i++) {
        result[i] = charset[rand() % strlen(charset)];
    }
    result[length] = '\0';
    return result;
}

int main() {
    // seed the random number generator with the current system time
    srand(time(NULL));
    
    printf("Welcome to the password manager.\n");
    printf("Please choose from the following options:\n");
    printf("1. Add a new password.\n");
    printf("2. View an existing password.\n");
    printf("3. Exit.\n");
    
    int choice;
    scanf("%d", &choice);
    
    while (choice != 3) {
        if (choice == 1) {
            // add a new password
            printf("Please enter the username for the new password:\n");
            scanf("%s", passwords[MAX_PASSWORDS].username);
            
            printf("Please choose a password length:\n");
            int length;
            scanf("%d", &length);
            
            printf("Please wait while we generate a password for you...\n");
            char* password = generate_random_string(length);
            
            printf("Your new password is: %s\n", password);
            strcpy(passwords[MAX_PASSWORDS].password, password);
            free(password);
        } else if (choice == 2) {
            // view an existing password
            printf("Please enter the number of the password you wish to view:\n");
            int index;
            scanf("%d", &index);
            
            if (index >= 0 && index < MAX_PASSWORDS) {
                printf("Username: %s\n", passwords[index].username);
                printf("Password: %s\n", passwords[index].password);
            } else {
                printf("Invalid password number.\n");
            }
        } else {
            printf("Invalid choice.\n");
        }
        
        printf("Please choose from the following options:\n");
        printf("1. Add a new password.\n");
        printf("2. View an existing password.\n");
        printf("3. Exit.\n");
        scanf("%d", &choice);
    }
    
    printf("Thank you for using the password manager.\n");
    
    return 0;
}