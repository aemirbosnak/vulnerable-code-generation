//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random uppercase letter
char random_uppercase_letter() {
    return (char)(rand() % 26 + 65);
}

// Function to generate a random lowercase letter
char random_lowercase_letter() {
    return (char)(rand() % 26 + 97);
}

// Function to generate a random digit
char random_digit() {
    return (char)(rand() % 10 + 48);
}

// Function to generate a random special character
char random_special_character() {
    char special_characters[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '{', '}', '[', ']', '|', '\\', ':', ';', '"', '<', '>', ',', '.', '?', '/'};
    return special_characters[rand() % 30];
}

// Function to shuffle the characters in the password
void shuffle_characters(char *password, int length) {
    for (int i = 0; i < length; i++) {
        int random_index = rand() % length;
        char temp = password[random_index];
        password[random_index] = password[i];
        password[i] = temp;
    }
}

int main() {
    srand(time(NULL)); // Initialize random seed with current time

    int length; // Length of password
    printf("Enter the length of the password: ");
    scanf("%d", &length);
    
    char *password = (char*)malloc(sizeof(char) * length + 1); // Allocate memory for password including null terminator
    
    // Generate random characters for the password
    for (int i = 0; i < length; i++) {
        int random_number = rand() % 4; // Randomly select a type of character
        if (random_number == 0) {
            password[i] = random_uppercase_letter();
        } else if (random_number == 1) {
            password[i] = random_lowercase_letter();
        } else if (random_number == 2) {
            password[i] = random_digit();
        } else if (random_number == 3) {
            password[i] = random_special_character();
        }
    }

    password[length] = '\0'; // Add null terminator to password string
    shuffle_characters(password, length); // Shuffle characters in password

    printf("Your secure password is: %s\n", password);

    free(password); // Free memory allocated for password

    return 0;
}