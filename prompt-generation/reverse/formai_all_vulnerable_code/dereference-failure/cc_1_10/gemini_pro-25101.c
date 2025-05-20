//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 16

// A function to generate a random password
char *generate_password(int length) {
    // Get a random seed from the system clock
    srand(time(NULL));

    // Create an array of characters to store the password
    char *password = malloc(length + 1);

    // Loop through the array and generate a random character for each position
    for (int i = 0; i < length; i++) {
        // Generate a random number between 33 and 126 (ASCII codes for printable characters)
        int randomNumber = rand() % (126 - 33 + 1) + 33;

        // Convert the random number to a character and store it in the array
        password[i] = (char) randomNumber;
    }

    // Terminate the string with a null character
    password[length] = '\0';

    // Return the password
    return password;
}

// A function to display a password
void display_password(char *password) {
    // Print the password
    printf("Your password is: %s\n", password);
}

// A function to get the length of a password from the user
int get_password_length() {
    // Get the password length from the user
    int length;
    printf("Enter the desired password length: ");
    scanf("%d", &length);

    // Validate the password length
    while (length < 8 || length > 32) {
        printf("Password length must be between 8 and 32 characters. Please enter a valid length: ");
        scanf("%d", &length);
    }

    // Return the password length
    return length;
}

// A function to get the number of passwords to generate from the user
int get_number_of_passwords() {
    // Get the number of passwords from the user
    int number;
    printf("Enter the number of passwords to generate: ");
    scanf("%d", &number);

    // Validate the number of passwords
    while (number < 1 || number > 10) {
        printf("Number of passwords must be between 1 and 10. Please enter a valid number: ");
        scanf("%d", &number);
    }

    // Return the number of passwords
    return number;
}

// A function to generate and display multiple passwords
void generate_and_display_passwords(int number, int length) {
    // Generate and display the passwords
    for (int i = 0; i < number; i++) {
        char *password = generate_password(length);
        display_password(password);
        free(password);
    }
}

// A function to get the user's choice
int get_user_choice() {
    // Get the user's choice
    int choice;
    printf("Enter your choice (1 to generate passwords, 2 to exit): ");
    scanf("%d", &choice);

    // Validate the user's choice
    while (choice < 1 || choice > 2) {
        printf("Invalid choice. Please enter a valid choice (1 to generate passwords, 2 to exit): ");
        scanf("%d", &choice);
    }

    // Return the user's choice
    return choice;
}

// The main function
int main() {
    // Get the user's choice
    int choice = get_user_choice();

    // Loop until the user chooses to exit
    while (choice != 2) {
        // Get the password length and the number of passwords to generate
        int length = get_password_length();
        int number = get_number_of_passwords();

        // Generate and display the passwords
        generate_and_display_passwords(number, length);

        // Get the user's choice
        choice = get_user_choice();
    }

    // Return 0 to indicate successful execution
    return 0;
}