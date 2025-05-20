//Falcon-180B DATASET v1.0 Category: Password management ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

void generatePassword(Password *password) {
    int i;
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    for (i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        password->password[i] = charset[rand() % strlen(charset)];
        if (i == MAX_PASSWORD_LENGTH - 1) {
            password->password[i] = '\0';
        }
    }
    password->length = rand() % MAX_PASSWORD_LENGTH + 8;
}

int comparePasswords(Password *password1, Password *password2) {
    return strcmp(password1->password, password2->password);
}

void sortPasswords(Password passwords[], int numPasswords) {
    qsort(passwords, numPasswords, sizeof(Password), comparePasswords);
}

int main() {
    int numPasswords;
    scanf("%d", &numPasswords);
    if (numPasswords > MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords is %d.\n", MAX_PASSWORDS);
        return 1;
    }
    Password passwords[numPasswords];
    int i;
    for (i = 0; i < numPasswords; i++) {
        generatePassword(&passwords[i]);
    }
    sortPasswords(passwords, numPasswords);
    printf("Generated passwords:\n");
    for (i = 0; i < numPasswords; i++) {
        printf("%d. %s\n", i + 1, passwords[i].password);
    }
    return 0;
}