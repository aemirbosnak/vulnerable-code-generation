//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function prototypes
void generatePassword(int length);
void generateRandomString(char *str, int length);
int isPasswordSecure(char *password);

int main() {
    int length;

    printf("Enter the desired length of the password: ");
    scanf("%d", &length);

    // Generate the password
    generatePassword(length);

    return 0;
}

void generatePassword(int length) {
    char password[length + 1];
    int i, j;

    srand(time(NULL));

    // Generate a random string of the desired length
    generateRandomString(password, length);

    // Check if the generated password is secure
    while (!isPasswordSecure(password)) {
        // If not, generate a new random string
        generateRandomString(password, length);
    }

    printf("Generated password: %s\n", password);
}

void generateRandomString(char *str, int length) {
    int i, j;

    for (i = 0; i < length; i++) {
        str[i] = (char)rand() % 26 + 'a';
    }

    // Add a random special character
    str[length] = (char)rand() % 10 + '0';
}

int isPasswordSecure(char *password) {
    // Check if the password contains at least one uppercase letter, one lowercase letter, one number, and one special character
    int hasUppercase = 0, hasLowercase = 0, hasNumber = 0, hasSpecialChar = 0;

    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            hasUppercase = 1;
        } else if (islower(password[i])) {
            hasLowercase = 1;
        } else if (isdigit(password[i])) {
            hasNumber = 1;
        } else if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '&' || password[i] == '*' || password[i] == '?') {
            hasSpecialChar = 1;
        }
    }

    if (hasUppercase && hasLowercase && hasNumber && hasSpecialChar) {
        return 1;
    } else {
        return 0;
    }
}