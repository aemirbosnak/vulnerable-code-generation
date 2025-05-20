//Falcon-180B DATASET v1.0 Category: Password management ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

struct password {
    char *username;
    char *password;
};

void generate_password(char *password, int length) {
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_-=+[{]}\\|;:'\",<.>/?`~";
    int i;

    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }

    password[length] = '\0';
}

int main() {
    int i, j, num_passwords;
    char *passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];
    char *username;
    char *password;

    printf("Enter the number of passwords to generate: ");
    scanf("%d", &num_passwords);

    for (i = 0; i < num_passwords; i++) {
        printf("Enter the username for password #%d: ", i + 1);
        scanf("%s", username);

        printf("Enter the desired length of the password for %s: ", username);
        scanf("%d", &j);

        if (j > MAX_PASSWORD_LENGTH) {
            printf("Password length cannot exceed %d characters.\n", MAX_PASSWORD_LENGTH);
            continue;
        }

        password = (char *)malloc(j + 1);
        generate_password(password, j);

        strcpy(passwords[i], password);
        printf("Password for %s: %s\n", username, password);
    }

    return 0;
}