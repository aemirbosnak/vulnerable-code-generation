//FormAI DATASET v1.0 Category: Password management ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate a random password of length len
char* generate_password(int len) {
    char* password = malloc(len + 1); // Allocate memory for password

    // Set of characters to choose from while generating password
    char* charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+=-{}[]:;?<>,./|\\`~";

    int i;
    for(i = 0; i < len; i++) {
        password[i] = charset[rand() % strlen(charset)]; // Pick a random character from the set
    }

    password[len] = '\0'; // Null-terminate the password string
    return password;
}

// Function to encrypt and save password in file
void save_password(char* password, char* file_name) {
    FILE* fp = fopen(file_name, "w"); // Open file in write mode

    if(fp == NULL) {
        printf("Error: Unable to open file for writing!\n");
        return;
    }

    // Encrypt password by shifting each character by 3 positions
    int i;
    for(i = 0; i < strlen(password); i++) {
        fputc(password[i] + 3, fp); // Write encrypted character to file
    }

    fclose(fp); // Close file
    printf("Password saved successfully!\n");
}

// Function to decrypt and display password from file
void display_password(char* file_name) {
    FILE* fp = fopen(file_name, "r"); // Open file in read mode

    if(fp == NULL) {
        printf("Error: Unable to open file for reading!\n");
        return;
    }

    printf("Password: ");

    int c;
    while((c = fgetc(fp)) != EOF) {
        printf("%c", c - 3); // Decrypt and display character from file
    }

    fclose(fp); // Close file
    printf("\n");
}

int main() {
    char choice;
    do {
        printf("-----------------\n");
        printf("  PASSWORD MANAGER\n");
        printf("-----------------\n");
        printf("1. Generate Password\n");
        printf("2. Save Password\n");
        printf("3. Display Password\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        char* password;
        char file_name[100];

        switch(choice) {
            case '1':
                printf("Enter password length: ");
                int len;
                scanf("%d", &len);
                password = generate_password(len);
                printf("Generated password: %s\n", password);
                free(password); // Free the allocated memory
                break;

            case '2':
                printf("Enter password to be saved:\n");
                scanf(" %[^\n]s", password);
                printf("Enter file name: ");
                scanf(" %s", file_name);
                save_password(password, file_name);
                break;

            case '3':
                printf("Enter file name: ");
                scanf(" %s", file_name);
                display_password(file_name);
                break;

            case '4':
                printf("Thank you for using Password Manager!\n");
                break;

            default:
                printf("Invalid choice, please try again!\n");
        }

    } while(choice != '4');

    return 0;
}