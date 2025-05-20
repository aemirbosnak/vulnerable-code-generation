//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MIN_LENGTH 8

//generates a random character
char randomChar() {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const size_t charset_len = sizeof(charset) / sizeof(char) - 1;
    return charset[rand() % charset_len];
}

//generates a random password with given length
char* generatePassword(int length) {
    char* password = malloc((length + 1) * sizeof(char));
    for (int i = 0; i < length; i++) {
        password[i] = randomChar();
    }
    password[length] = '\0';
    return password;
}

//checks if password has at least one lowercase character
bool hasLowercase(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            return true;
        }
    }
    return false;
}

//checks if password has at least one uppercase character
bool hasUppercase(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            return true;
        }
    }
    return false;
}

//checks if password has at least one digit
bool hasDigit(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            return true;
        }
    }
    return false;
}

//checks if password has at least one special character
bool hasSpecial(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            return true;
        }
    }
    return false;
}

//checks if password meets minimum length requirement
bool meetsLengthRequirement(char* password) {
    return strlen(password) >= MIN_LENGTH;
}

//checks password strength and outputs corresponding message
void checkPassword(char* password) {
    bool hasLower = hasLowercase(password);
    bool hasUpper = hasUppercase(password);
    bool hasDig = hasDigit(password);
    bool hasSpec = hasSpecial(password);
    bool meetsLen = meetsLengthRequirement(password);
    if (hasLower && hasUpper && hasDig && hasSpec && meetsLen) {
        printf("Password strength: Strong\n");
    } else if ((hasLower || hasUpper) && hasDig && meetsLen) {
        printf("Password strength: Medium\n");
    } else {
        printf("Password strength: Weak\n");
    }
}

//main function
int main() {
    srand(time(NULL)); //initialize random generator

    //generate and check 5 random passwords
    for (int i = 0; i < 5; i++) {
        char* password = generatePassword(rand() % 10 + MIN_LENGTH); //generate random password
        printf("Password: %s\n", password);
        checkPassword(password); //check password strength
        printf("\n");
        free(password); //free memory
    }

    return 0;
}