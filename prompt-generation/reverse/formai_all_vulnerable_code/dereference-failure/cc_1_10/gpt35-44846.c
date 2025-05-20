//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: invasive
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 20
#define MIN_PASSWORD_LENGTH 8

char * generate_password();

int main() {
    printf("Welcome to the Secure Password Generator!\n");

    char *password = generate_password();

    printf("Your secure password is: %s\n", password);

    free(password);

    return 0;
}

char * generate_password() {
    char *password = (char *) malloc(sizeof(char) * (MAX_PASSWORD_LENGTH + 1));
    int password_length = rand() % (MAX_PASSWORD_LENGTH - MIN_PASSWORD_LENGTH + 1) + MIN_PASSWORD_LENGTH;
    bool has_uppercase = false;
    bool has_lowercase = false;
    bool has_digit = false;
    bool has_special_character = false;

    srand(time(NULL));

    for (int i = 0; i < password_length; i++) {
        int character_type = rand() % 4;

        switch (character_type) {
            case 0:
                password[i] = rand() % 26 + 'a';  // lowercase letter
                has_lowercase = true;
                break;
            case 1:
                password[i] = rand() % 26 + 'A';  // uppercase letter
                has_uppercase = true;
                break;
            case 2:
                password[i] = rand() % 10 + '0';  // digit
                has_digit = true;
                break;
            case 3:
                password[i] = rand() % 15 + 33;   // special character
                has_special_character = true;
                break;
        }

        if (i == password_length - 1 && !has_lowercase) {
            // If this is the last character and there is no lowercase letter, add one
            password[i] = rand() % 26 + 'a';
        }
    }

    if (!has_uppercase || !has_digit || !has_special_character) {
        // If at least one of the character types is not present, generate a new password
        free(password);
        password = generate_password();
    }

    return password;
}