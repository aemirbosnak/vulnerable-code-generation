//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define PASSWORD_LENGTH 10

int main() {
    // Initialize arrays with possible characters for password generation
    char lowercase_letters[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase_letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char special_chars[] = "!@#$%^&*_-+=";

    // Concatenate arrays for password generation
    char possible_chars[] = "";
    strcat(possible_chars, lowercase_letters);
    strcat(possible_chars, uppercase_letters);
    strcat(possible_chars, numbers);
    strcat(possible_chars, special_chars);

    // Initialize seed for random number generation
    srand(time(NULL));

    // Generate password
    char password[PASSWORD_LENGTH+1] = "";
    int i;
    for (i=0; i<PASSWORD_LENGTH; i++) {
        int random_index = rand() % (strlen(possible_chars));
        password[i] = possible_chars[random_index];
    }
    password[PASSWORD_LENGTH] = '\0';

    // Ensure password contains at least one lowercase letter, uppercase letter, number, and special character
    int has_lowercase = 0;
    int has_uppercase = 0;
    int has_number = 0;
    int has_special = 0;
    for (i=0; i<PASSWORD_LENGTH; i++) {
        if (islower(password[i])) {
            has_lowercase = 1;
        } else if (isupper(password[i])) {
            has_uppercase = 1;
        } else if (isdigit(password[i])) {
            has_number = 1;
        } else {
            has_special = 1;
        }
    }
    if (!has_lowercase || !has_uppercase || !has_number || !has_special) {
        // If password does not contain all required characters, randomly replace one character
        int random_index = rand() % (PASSWORD_LENGTH);
        password[random_index] = possible_chars[rand() % (strlen(possible_chars))];
    }

    printf("Generated password: %s\n", password);
    return 0;
}