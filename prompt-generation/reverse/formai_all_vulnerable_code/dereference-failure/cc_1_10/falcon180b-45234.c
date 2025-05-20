//Falcon-180B DATASET v1.0 Category: Password management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 32

struct password {
    char *name;
    char *password;
    time_t created_at;
    time_t last_modified;
};

struct password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void generate_password(char *password, int length) {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-+={}[]\\|;:'\"<>,.?/";
    int i = 0;
    while (i < length) {
        password[i] = chars[rand() % strlen(chars)];
        i++;
    }
    password[length] = '\0';
}

int main() {
    char *name;
    int choice, length;
    time_t now = time(NULL);

    printf("Welcome to the Password Manager!\n");
    printf("Enter your name: ");
    scanf("%s", name);

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Generate a new password\n");
        printf("2. Save a password\n");
        printf("3. View saved passwords\n");
        printf("4. Search for a password\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter password length (1-32): ");
                scanf("%d", &length);
                generate_password(passwords[num_passwords].password, length);
                printf("Generated password: %s\n", passwords[num_passwords].password);
                break;
            case 2:
                printf("Enter name for password: ");
                scanf("%s", passwords[num_passwords].name);
                strcpy(passwords[num_passwords].password, "");
                passwords[num_passwords].created_at = now;
                passwords[num_passwords].last_modified = now;
                num_passwords++;
                break;
            case 3:
                printf("\nSaved Passwords:\n");
                for (int i = 0; i < num_passwords; i++) {
                    printf("%s - %s\n", passwords[i].name, passwords[i].password);
                }
                break;
            case 4:
                printf("Enter search query: ");
                scanf("%s", name);
                for (int i = 0; i < num_passwords; i++) {
                    if (strstr(passwords[i].name, name)!= NULL || strstr(passwords[i].password, name)!= NULL) {
                        printf("%s - %s\n", passwords[i].name, passwords[i].password);
                    }
                }
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}