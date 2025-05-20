//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define PASSWORD_LEN 12 // The length of generated password
#define MIN_ASCII 33 // The minimum ASCII value for printable characters
#define MAX_ASCII 126 // The maximum ASCII value for printable characters

/* Function declarations */
char *generatePassword(int len);
int checkPassword(char *password);

/* Main function */
int main() {
    char *password;
    srand(time(NULL)); // Seed the random number generator with the current time

    do {
        password = generatePassword(PASSWORD_LEN);
    } while (!checkPassword(password));
    printf("Your secure password: %s\n", password);

    free(password); // Free memory allocated by generatePassword function
    return 0;
}

/**
 * Generate a random password of specified length
 * @param len: Length of generated password
 * @return: Pointer to the generated password
 */
char *generatePassword(int len) {
    char *password = malloc((len + 1) * sizeof(char)); // Allocate memory for password
    int i;

    for (i = 0; i < len; i++) {
        password[i] = rand() % (MAX_ASCII - MIN_ASCII + 1) + MIN_ASCII; // Generate random character
    }
    password[len] = '\0'; // Null terminate the string
    return password;
}

/**
 * Check if the generated password meets the security requirements
 * @param password: The password to check
 * @return: 1 if the password is secure, 0 otherwise
 */
int checkPassword(char *password) {
    int i, hasLower = 0, hasUpper = 0, hasNumber = 0, hasSymbol = 0;

    for (i = 0; password[i] != '\0'; i++) {
        if (islower(password[i])) {
            hasLower = 1;
        } else if (isupper(password[i])) {
            hasUpper = 1;
        } else if (isdigit(password[i])) {
            hasNumber = 1;
        } else {
            hasSymbol = 1;
        }
    }

    // Check if the password contains at least one lowercase letter, one uppercase letter,
    // one digit and one symbol
    if (hasLower && hasUpper && hasNumber && hasSymbol) {
        return 1;
    } else {
        return 0;
    }
}