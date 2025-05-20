//Falcon-180B DATASET v1.0 Category: Password management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 32

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

Password *generatePassword(int length) {
    Password *password = malloc(sizeof(Password));
    password->length = length;
    for (int i = 0; i < length; i++) {
        password->password[i] = 'a' + rand() % 26;
    }
    password->password[length] = '\0';
    return password;
}

void printPassword(Password *password) {
    printf("%s\n", password->password);
}

int main() {
    int numPasswords;
    printf("Enter the number of passwords to generate: ");
    scanf("%d", &numPasswords);

    if (numPasswords > MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords is %d.\n", MAX_PASSWORDS);
        return 1;
    }

    Password **passwords = malloc(numPasswords * sizeof(Password *));
    for (int i = 0; i < numPasswords; i++) {
        int length;
        printf("Enter the length of password %d: ", i+1);
        scanf("%d", &length);
        if (length > MAX_PASSWORD_LENGTH) {
            printf("Error: Maximum password length is %d characters.\n", MAX_PASSWORD_LENGTH);
            return 1;
        }
        passwords[i] = generatePassword(length);
        printPassword(passwords[i]);
    }

    return 0;
}