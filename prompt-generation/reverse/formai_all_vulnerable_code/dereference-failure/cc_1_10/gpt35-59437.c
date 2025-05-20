//FormAI DATASET v1.0 Category: Password management ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

char *encrypt(char *password);
char *decrypt(char *encrypted_password);
void clear_buffer();
void change_password(char *encrypted_password);

int main()
{
    int option;
    char original_password[MAX_LENGTH], *encrypted_password;

    printf("Welcome to the paranoid password manager!\n");

    // Prompt the user to enter their original password
    printf("Please enter your original password: ");
    fgets(original_password, MAX_LENGTH, stdin);

    // Encrypt the password and print the encrypted version
    encrypted_password = encrypt(original_password);
    printf("Your encrypted password is: %s\n", encrypted_password);

    // Clear the original password from memory
    clear_buffer(original_password, MAX_LENGTH);

    // Prompt the user to choose an option
    printf("\nWhat would you like to do?\n");
    printf("1. Decrypt password\n");
    printf("2. Change password\n");
    printf("3. Exit\n");
    printf("Enter option number: ");
    scanf("%d", &option);

    switch(option)
    {
        case 1:
        {
            // Decrypt the password and print the original version
            char *decrypted_password = decrypt(encrypted_password);
            printf("Your original password is: %s\n", decrypted_password);

            // Clear the decrypted password from memory
            clear_buffer(decrypted_password, MAX_LENGTH);
            break;
        }
        case 2:
        {
            // Change the password
            change_password(encrypted_password);
            break;
        }
        case 3:
        {
            // Exit the program
            printf("Goodbye!\n");
            exit(0);
        }
        default:
        {
            printf("Invalid option. Please try again.\n");
            break;
        }
    }

    // Clear the encrypted password from memory
    clear_buffer(encrypted_password, MAX_LENGTH);

    return 0;
}

// Encrypt a password using a simple substitution cipher
char *encrypt(char *password)
{
    char *encrypted_password = malloc(MAX_LENGTH * sizeof(char));

    for(int i = 0; i < strlen(password); i++)
    {
        if(password[i] >= 'A' && password[i] <= 'Z')
        {
            encrypted_password[i] = 'A' + (password[i] - 'A' + 3) % 26;
        }
        else if(password[i] >= 'a' && password[i] <= 'z')
        {
            encrypted_password[i] = 'a' + (password[i] - 'a' + 3) % 26;
        }
        else
        {
            encrypted_password[i] = password[i];
        }
    }

    return encrypted_password;
}

// Decrypt an encrypted password using the inverse cipher
char *decrypt(char *encrypted_password)
{
    char *decrypted_password = malloc(MAX_LENGTH * sizeof(char));

    for(int i = 0; i < strlen(encrypted_password); i++)
    {
        if(encrypted_password[i] >= 'A' && encrypted_password[i] <= 'Z')
        {
            decrypted_password[i] = 'A' + (encrypted_password[i] - 'A' + 23) % 26;
        }
        else if(encrypted_password[i] >= 'a' && encrypted_password[i] <= 'z')
        {
            decrypted_password[i] = 'a' + (encrypted_password[i] - 'a' + 23) % 26;
        }
        else
        {
            decrypted_password[i] = encrypted_password[i];
        }
    }

    return decrypted_password;
}

// Clear a buffer of a specified length
void clear_buffer(char *buffer, int length)
{
    for(int i = 0; i < length; i++)
    {
        buffer[i] = '\0';
    }
}

// Change the original password
void change_password(char *encrypted_password)
{
    char new_password[MAX_LENGTH], *new_encrypted_password;

    // Prompt the user to enter a new password
    printf("Please enter a new password: ");
    fgets(new_password, MAX_LENGTH, stdin);

    // Encrypt the new password and print the encrypted version
    new_encrypted_password = encrypt(new_password);
    printf("Your new encrypted password is: %s\n", new_encrypted_password);

    // Clear the new password from memory
    clear_buffer(new_password, MAX_LENGTH);

    // Replace the old encrypted password with the new one
    strcpy(encrypted_password, new_encrypted_password);

    // Clear the new encrypted password from memory
    clear_buffer(new_encrypted_password, MAX_LENGTH);
}