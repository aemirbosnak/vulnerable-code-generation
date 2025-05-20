//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 16

// Function to generate a random character
char generate_random_character() {
    int random_number = rand() % 94 + 33;
    return (char)random_number;
}

// Function to generate a random password
char *generate_random_password(int password_length) {
    char *password = malloc(sizeof(char) * (password_length + 1));
    for (int i = 0; i < password_length; i++) {
        password[i] = generate_random_character();
    }
    password[password_length] = '\0';
    return password;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the password length from the user
    int password_length;
    printf("Enter the desired password length (between 8 and 16): ");
    scanf("%d", &password_length);

    // Validate the password length
    if (password_length < MIN_PASSWORD_LENGTH || password_length > MAX_PASSWORD_LENGTH) {
        printf("Invalid password length. Please enter a value between 8 and 16.\n");
        return 1;
    }

    // Generate a random password
    char *password = generate_random_password(password_length);

    // Print the generated password
    printf("Your randomly generated password is: %s\n", password);

    // Free the allocated memory
    free(password);

    return 0;
}