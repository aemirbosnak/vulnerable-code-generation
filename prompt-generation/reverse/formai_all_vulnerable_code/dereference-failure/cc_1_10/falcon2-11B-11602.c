//Falcon2-11B DATASET v1.0 Category: Password management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_USER_NAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define MAX_PASSWORD_TOTAL_LENGTH 1000

typedef struct {
    char username[MAX_USER_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char password_total[MAX_PASSWORD_TOTAL_LENGTH];
    int password_length;
} Password;

int compare_passwords(const void* a, const void* b) {
    return strcmp(((const Password*)a)->password_total, ((const Password*)b)->password_total);
}

void generate_password(char* password, int length) {
    for (int i = 0; i < length; i++) {
        password[i] = 'A' + rand() % 26;
    }
}

int main() {
    Password* password_table = NULL;
    int num_passwords = 0;

    password_table = (Password*)malloc(sizeof(Password));
    if (!password_table) {
        printf("Error allocating memory for password table\n");
        return 1;
    }

    password_table->username[0] = 'a';
    password_table->password[0] = 'a';
    password_table->password_total[0] = 'a';
    password_table->password_length = 1;

    num_passwords = 1;

    while (1) {
        Password* new_password = (Password*)malloc(sizeof(Password));
        if (!new_password) {
            printf("Error allocating memory for new password\n");
            return 1;
        }

        printf("Enter username: ");
        fgets(new_password->username, MAX_USER_NAME_LENGTH, stdin);
        new_password->username[strcspn(new_password->username, "\n")] = '\0';

        printf("Enter password: ");
        fgets(new_password->password, MAX_PASSWORD_LENGTH, stdin);
        new_password->password[strcspn(new_password->password, "\n")] = '\0';

        generate_password(new_password->password_total, MAX_PASSWORD_LENGTH);

        qsort(password_table, num_passwords, sizeof(Password), compare_passwords);

        if (strcmp(new_password->password_total, password_table[0].password_total) == 0) {
            printf("Password already exists\n");
            continue;
        }

        new_password->password_length = MAX_PASSWORD_LENGTH;

        if (num_passwords == MAX_PASSWORD_TOTAL_LENGTH) {
            printf("Password table is full\n");
            return 1;
        }

        printf("Enter password: ");
        fgets(new_password->password_total, MAX_PASSWORD_TOTAL_LENGTH, stdin);
        new_password->password_total[strcspn(new_password->password_total, "\n")] = '\0';

        password_table[num_passwords++] = *new_password;
        qsort(password_table, num_passwords, sizeof(Password), compare_passwords);

        printf("Password added successfully\n");
    }

    return 0;
}