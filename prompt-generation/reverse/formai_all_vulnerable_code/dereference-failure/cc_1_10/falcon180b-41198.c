//Falcon-180B DATASET v1.0 Category: Password management ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100
#define HASH_LENGTH 20

typedef struct {
    char* username;
    char* password;
    int length;
} Password;

Password passwords[MAX_PASSWORDS];

void generatePassword(char* password, int length) {
    int i;
    for (i = 0; i < length; i++) {
        int randChar = rand() % 62;
        if (randChar < 26) {
            password[i] = 'a' + randChar;
        } else if (randChar < 52) {
            password[i] = 'A' + (randChar - 26);
        } else {
            password[i] = '0' + (randChar - 52);
        }
    }
    password[i] = '\0';
}

int hashPassword(char* password) {
    int hash = 0;
    int i;
    for (i = 0; i < strlen(password); i++) {
        hash += password[i];
    }
    return hash % HASH_LENGTH;
}

int comparePasswords(char* password1, char* password2) {
    int i;
    for (i = 0; i < strlen(password1); i++) {
        if (password1[i]!= password2[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].username = (char*) malloc(MAX_PASSWORD_LENGTH * sizeof(char));
        passwords[i].password = (char*) malloc(HASH_LENGTH * sizeof(char));
        generatePassword(passwords[i].password, HASH_LENGTH);
        strcpy(passwords[i].username, "User");
        passwords[i].length = HASH_LENGTH;
    }

    char* username = (char*) malloc(MAX_PASSWORD_LENGTH * sizeof(char));
    char* password = (char*) malloc(HASH_LENGTH * sizeof(char));

    printf("Enter username: ");
    scanf("%s", username);

    int index = hashPassword(username) % MAX_PASSWORDS;
    strcpy(password, passwords[index].password);

    if (comparePasswords(password, passwords[index].password)) {
        printf("Login successful!\n");
    } else {
        printf("Login failed.\n");
    }

    return 0;
}