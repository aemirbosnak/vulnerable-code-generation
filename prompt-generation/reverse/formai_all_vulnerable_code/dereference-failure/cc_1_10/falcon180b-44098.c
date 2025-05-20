//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_PASSWORD_LENGTH 32

// Function to generate a random password
void generate_password(char *password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}\\|;':\",./<>?";
    const int charset_size = strlen(charset);

    // Initialize the password with random characters from the charset
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % charset_size];
    }

    // Add some complexity to the password
    for (int i = 0; i < length - 1; i++) {
        int j = rand() % length;
        char tmp = password[i];
        password[i] = password[j];
        password[j] = tmp;
    }
}

// Function to check if a password meets the complexity requirements
int check_password_complexity(const char *password) {
    // Check length
    if (strlen(password) < 8) {
        return 0;
    }

    // Check for uppercase letters
    if (!isupper(password[0])) {
        return 0;
    }

    // Check for lowercase letters
    if (!islower(password[1])) {
        return 0;
    }

    // Check for numbers
    if (!isdigit(password[2])) {
        return 0;
    }

    // Check for special characters
    if (!isalnum(password[3])) {
        return 0;
    }

    // Password meets complexity requirements
    return 1;
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Initialize the password with random characters
    char password[MAX_PASSWORD_LENGTH];
    generate_password(password, MAX_PASSWORD_LENGTH);

    // Check if the password meets the complexity requirements
    int complexity = check_password_complexity(password);

    // Output the generated password
    if (complexity) {
        printf("Generated password: %s\n", password);
    } else {
        printf("Password does not meet complexity requirements.\n");
    }

    return 0;
}