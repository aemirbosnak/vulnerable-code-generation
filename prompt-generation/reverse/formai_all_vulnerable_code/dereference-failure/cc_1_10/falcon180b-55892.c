//Falcon-180B DATASET v1.0 Category: Password management ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 1000
#define MAX_PASSWORD_LENGTH 256

struct password_entry {
    char *username;
    char *password;
};

void generate_password(char *password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>/?";
    int i;

    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }

    password[length] = '\0';
}

int compare_passwords(const void *a, const void *b) {
    const char *password_a = *(const char **)a;
    const char *password_b = *(const char **)b;

    return strcmp(password_a, password_b);
}

int main() {
    srand(time(NULL));

    char *passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    while (num_passwords < MAX_PASSWORDS) {
        printf("Enter a website or service: ");
        char *website = malloc(MAX_PASSWORD_LENGTH);
        fgets(website, MAX_PASSWORD_LENGTH, stdin);
        website[strcspn(website, "\n")] = '\0';

        printf("Enter a username: ");
        char *username = malloc(MAX_PASSWORD_LENGTH);
        fgets(username, MAX_PASSWORD_LENGTH, stdin);
        username[strcspn(username, "\n")] = '\0';

        generate_password(passwords[num_passwords], 16);
        strcpy(passwords[num_passwords + 1], passwords[num_passwords]);

        struct password_entry entry = {
           .username = username,
           .password = passwords[num_passwords]
        };

        passwords[num_passwords] = malloc(MAX_PASSWORD_LENGTH);
        strcpy(passwords[num_passwords], passwords[num_passwords + 1]);

        qsort(passwords, num_passwords + 2, sizeof(char *), compare_passwords);
        num_passwords++;

        free(website);
        free(username);
    }

    printf("Saved %d passwords.\n", num_passwords);

    return 0;
}