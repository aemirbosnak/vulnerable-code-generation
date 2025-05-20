//FormAI DATASET v1.0 Category: Password management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 50 // Maximum length of password
#define MAX_GEN_PASSWORDS 5 // Maximum number of random passwords that can be generated at a time

// Function to generate a random password
char* generatePassword(int length) {
    char* password = (char*)malloc((length+1)*sizeof(char));
    static const char alphabets[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    srand(time(NULL)); // Setting random number generator seed

    for(int i=0;i<length;i++) {
        password[i] = alphabets[rand()%62];
    }

    password[length] = '\0'; // Adding null terminator to password

    return password;
}

int main() {
    int choice, password_count=0, password_length;
    char passwords[MAX_GEN_PASSWORDS][MAX_LENGTH];

    printf("Welcome to Password Management System!\n");

    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Generate a new password\n");
        printf("2. View saved passwords\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        if(choice == 1) {
            printf("\nHow long would you like your password to be?(Maximum length is %d)\n", MAX_LENGTH);
            scanf("%d", &password_length);

            if(password_length > MAX_LENGTH) {
                printf("Password length exceeds maximum length of %d characters. Try again.\n", MAX_LENGTH);
                continue;
            }

            char* password = generatePassword(password_length);

            if(password_count < MAX_GEN_PASSWORDS) {
                strcpy(passwords[password_count], password);
                printf("\nYour password is: %s\n", passwords[password_count]);
                password_count++;
            }
            else {
                printf("\nYou have reached the maximum limit of %d generated passwords. The new password will be discarded.\n", MAX_GEN_PASSWORDS);
            }

            free(password); // Free allocated memory for password
        }
        else if(choice == 2) {
            if(password_count == 0) {
                printf("\nNo passwords have been generated yet.\n");
            }
            else {
                printf("\nList of generated passwords:\n");
                for(int i=0;i<password_count;i++) {
                    printf("%d. %s\n", i+1, passwords[i]);
                }
            }
        } 
        else if(choice == 3) {
            printf("\nThank you for using Password Management System.\n");
            break;
        }
        else {
            printf("\nInvalid choice. Try again.\n");
        }
    }

    return 0;
}