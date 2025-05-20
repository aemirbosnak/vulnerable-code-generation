//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the character sets for the password
char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char digits[] = "0123456789";
char symbols[] = "!@#$%^&*()_+";

// Generate a random number between min and max
int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Generate a random character from a given character set
char get_random_character(char *charset) {
    int index = get_random_number(0, strlen(charset) - 1);
    return charset[index];
}

// Generate a random password of a given length
char *generate_password(int length) {
    // Allocate memory for the password
    char *password = malloc(length + 1);

    // Initialize the password with random characters
    for (int i = 0; i < length; i++) {
        char charset[] = {lowercase, uppercase, digits, symbols};
        char *random_charset = charset[get_random_number(0, 3)];
        password[i] = get_random_character(random_charset);
    }

    // Terminate the password with a null character
    password[length] = '\0';

    return password;
}

// Print the generated password
void print_password(char *password) {
    printf("Your password is: %s\n", password);
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Get the desired password length from the user
    int length;
    printf("Enter the desired password length: ");
    scanf("%d", &length);

    // Generate the password
    char *password = generate_password(length);

    // Print the generated password
    print_password(password);

    // Free the allocated memory
    free(password);

    return 0;
}