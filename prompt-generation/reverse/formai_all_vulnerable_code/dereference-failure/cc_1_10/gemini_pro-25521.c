//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the character sets for password generation
char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char digits[] = "0123456789";
char special[] = "!@#$%^&*()-_=+";

// Get the length of the password from the user
int get_password_length() {
    int length;
    printf("Enter the desired length of the password: ");
    scanf("%d", &length);
    return length;
}

// Generate a random character from a given character set
char generate_random_character(char *character_set) {
    int index = rand() % strlen(character_set);
    return character_set[index];
}

// Generate a secure password
char *generate_secure_password(int length) {
    // Create a buffer to store the password
    char *password = malloc(length + 1);

    // Initialize the password with a random lowercase letter
    password[0] = generate_random_character(lowercase);

    // Generate the remaining characters of the password
    for (int i = 1; i < length; i++) {
        // Choose a random character set based on the iteration number
        char *character_set;
        if (i % 4 == 0) {
            character_set = special;
        } else if (i % 3 == 0) {
            character_set = digits;
        } else if (i % 2 == 0) {
            character_set = uppercase;
        } else {
            character_set = lowercase;
        }

        // Generate a random character from the chosen character set
        password[i] = generate_random_character(character_set);
    }

    // Terminate the password string with a null character
    password[length] = '\0';

    // Return the generated password
    return password;
}

// Display the generated password to the user
void display_password(char *password) {
    printf("Your secure password is: %s\n", password);
}

// Free the memory allocated for the password
void free_password(char *password) {
    free(password);
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Get the password length from the user
    int length = get_password_length();

    // Generate a secure password
    char *password = generate_secure_password(length);

    // Display the generated password to the user
    display_password(password);

    // Free the memory allocated for the password
    free_password(password);

    return 0;
}