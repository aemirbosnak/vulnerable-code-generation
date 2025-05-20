//Falcon-180B DATASET v1.0 Category: Password management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 20

typedef struct {
    char password[PASSWORD_LENGTH];
    int is_used;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void generate_password(Password *pw) {
    int i;
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        pw->password[i] = 'a' + rand() % 26;
    }
    pw->is_used = 0;
}

int find_unused_password(Password *pw) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (!passwords[i].is_used) {
            strcpy(pw->password, passwords[i].password);
            pw->is_used = 1;
            return i;
        }
    }
    return -1;
}

void print_passwords(void) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("Password %d: %s\n", i, passwords[i].password);
    }
}

int main(void) {
    int choice, password_index;
    char input[100];

    srand(time(NULL));

    while (1) {
        printf("1. Generate new password\n"
              "2. Use existing password\n"
              "3. Print passwords\n"
              "4. Exit\n"
              "Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the index of the new password: ");
            scanf("%d", &password_index);
            generate_password(&passwords[password_index]);
            num_passwords++;
            printf("New password generated successfully.\n");
            break;

        case 2:
            printf("Enter the index of the password to use: ");
            scanf("%d", &password_index);
            if (find_unused_password(&passwords[password_index]) == -1) {
                printf("All passwords are already in use.\n");
            }
            break;

        case 3:
            print_passwords();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}