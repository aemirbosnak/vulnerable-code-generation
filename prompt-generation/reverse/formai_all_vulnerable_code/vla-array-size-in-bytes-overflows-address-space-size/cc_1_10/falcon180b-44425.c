//Falcon-180B DATASET v1.0 Category: Password management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100
#define MAX_PASSWORDS 100

typedef struct {
    char* username;
    char* password;
} Password;

void generatePassword(char* password, int length) {
    const char* characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    for (int i = 0; i < length; i++) {
        password[i] = characters[rand() % strlen(characters)];
    }
    password[length] = '\0';
}

int main() {
    int numPasswords;
    printf("How many passwords would you like to generate? ");
    scanf("%d", &numPasswords);

    if (numPasswords > MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords is %d.\n", MAX_PASSWORDS);
        return 1;
    }

    Password passwords[numPasswords];

    for (int i = 0; i < numPasswords; i++) {
        char username[MAX_PASSWORD_LENGTH];
        printf("Enter username for password %d: ", i+1);
        scanf("%s", username);

        char password[MAX_PASSWORD_LENGTH];
        generatePassword(password, rand() % (MAX_PASSWORD_LENGTH - 8) + 8);

        strcpy(passwords[i].username, username);
        strcpy(passwords[i].password, password);
    }

    FILE* file = fopen("passwords.txt", "w");
    if (file == NULL) {
        printf("Error: Could not create file.\n");
        return 1;
    }

    for (int i = 0; i < numPasswords; i++) {
        fprintf(file, "Username: %s\nPassword: %s\n\n", passwords[i].username, passwords[i].password);
    }

    fclose(file);
    printf("Passwords saved to file.\n");

    return 0;
}