//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define PASSWORD_LENGTH 12

char *generate_password() {
    char *password = malloc(PASSWORD_LENGTH + 1);
    int i, random_number;

    // Seed the random number generator with current time
    srand(time(0));

    // Generate password consisting of random upper case, lower case, and digit characters
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        random_number = rand() % 62; // 26 upper case, 26 lower case, 10 digits = 62
        if (random_number < 26) {
            password[i] = 'A' + random_number; // Upper case
        } else if (random_number < 52) {
            password[i] = 'a' + (random_number - 26); // Lower case
        } else {
            password[i] = '0' + (random_number - 52); // Digits
        }
    }

    password[PASSWORD_LENGTH] = '\0'; // Null terminate the string

    return password;
}

int is_valid_password(char *password) {
    int i, has_upper = 0, has_lower = 0, has_digit = 0;

    // Check if password has at least one upper case, one lower case, and one digit character
    for (i = 0; password[i]; i++) {
        if (isupper(password[i])) {
            has_upper = 1;
        } else if (islower(password[i])) {
            has_lower = 1;
        } else if (isdigit(password[i])) {
            has_digit = 1;
        }
    }

    return has_upper && has_lower && has_digit;
}

int main() {
    char *password;

    do {
        password = generate_password();
    } while (!is_valid_password(password)); // Keep generating passwords until a valid one is found

    printf("Your password is: %s\n", password);

    free(password); // Free the memory allocated for the password

    return 0;
}