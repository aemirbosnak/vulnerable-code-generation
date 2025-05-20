//FormAI DATASET v1.0 Category: Password management ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORDS 10
#define MAX_LEN 50

struct Password {
    char service[MAX_LEN];
    char username[MAX_LEN];
    char password[MAX_LEN];
};

int menu();
void flush();
void add_password(struct Password passwords[], int *num_passwords);
void view_passwords(struct Password passwords[], int num_passwords);
void search_password(struct Password passwords[], int num_passwords);
void generate_password(char password[]);
void encrypt_password(struct Password *password);
void decrypt_password(struct Password *password);

int main() {
    struct Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;
    char key[MAX_LEN];

    printf("Enter encryption key: ");
    fgets(key, MAX_LEN, stdin);
    key[strcspn(key, "\n")] = 0; // remove new line character

    int choice;
    do {
        choice = menu();
        switch (choice) {
            case 1:
                add_password(passwords, &num_passwords);
                break;
            case 2:
                view_passwords(passwords, num_passwords);
                break;
            case 3:
                search_password(passwords, num_passwords);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}

int menu() {
    int choice;
    printf("\nPassword Management System\n");
    printf("--------------------------\n");
    printf("1. Add new password\n");
    printf("2. View all passwords\n");
    printf("3. Search password\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
    scanf("%d", &choice);
    flush(); // clear input buffer
    return choice;
}

void flush() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void add_password(struct Password passwords[], int *num_passwords) {
    if (*num_passwords == MAX_PASSWORDS) {
        printf("Maximum number of passwords exceeded!\n");
        return;
    }

    struct Password new_password;

    printf("Enter name of service: ");
    fgets(new_password.service, MAX_LEN, stdin);
    new_password.service[strcspn(new_password.service, "\n")] = 0; // remove new line character

    printf("Enter username: ");
    fgets(new_password.username, MAX_LEN, stdin);
    new_password.username[strcspn(new_password.username, "\n")] = 0; // remove new line character

    generate_password(new_password.password);

    encrypt_password(&new_password);

    passwords[*num_passwords] = new_password;
    (*num_passwords)++;

    printf("Password added successfully!\n");
}

void generate_password(char password[]) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=?<>,./;:'[]{}|\\";
    const int len_charset = sizeof(charset) - 1;

    printf("Do you want to generate a password? (y/n): ");
    char response = getchar();
    flush();

    if (response == 'n') {
        printf("Enter password: ");
        fgets(password, MAX_LEN, stdin);
        password[strcspn(password, "\n")] = 0; // remove new line character
    } else {
        printf("Enter length of password: ");
        int len;
        scanf("%d", &len);
        flush();

        for (int i = 0; i < len; i++) {
            int index = rand() % len_charset;
            password[i] = charset[index];
        }
        password[len] = '\0';

        printf("Generated password: %s\n", password);
    }
}

void view_passwords(struct Password passwords[], int num_passwords) {
    if (num_passwords == 0) {
        printf("No passwords to display!\n");
        return;
    }

    printf("%-20s %-20s %-20s\n", "Service", "Username", "Password");
    printf("--------------------------------------------\n");

    for (int i = 0; i < num_passwords; i++) {
        struct Password password = passwords[i];

        decrypt_password(&password);

        printf("%-20s %-20s %-20s\n", password.service, password.username, password.password);

        encrypt_password(&password);

        passwords[i] = password;
    }
}

void search_password(struct Password passwords[], int num_passwords) {
    if (num_passwords == 0) {
        printf("No passwords to search!\n");
        return;
    }

    char service[MAX_LEN];
    printf("Enter name of service to search: ");
    fgets(service, MAX_LEN, stdin);
    service[strcspn(service, "\n")] = 0; // remove new line character

    bool found = false;

    for (int i = 0; i < num_passwords; i++) {
        struct Password password = passwords[i];

        decrypt_password(&password);

        if (strcmp(password.service, service) == 0) {
            printf("%-20s %-20s %-20s\n", "Service", "Username", "Password");
            printf("--------------------------------------------\n");
            printf("%-20s %-20s %-20s\n", password.service, password.username, password.password);
            found = true;
        }

        encrypt_password(&password);

        passwords[i] = password;
    }

    if (!found) {
        printf("Service not found!\n");
    }
}

void encrypt_password(struct Password *password) {
    char key[MAX_LEN];
    memcpy(key, password->service, MAX_LEN); // use service name as key
    int len_key = strlen(key);

    for (int i = 0; i < MAX_LEN; i++) {
        password->password[i] = password->password[i] ^ key[i % len_key];
    }
}

void decrypt_password(struct Password *password) {
    char key[MAX_LEN];
    memcpy(key, password->service, MAX_LEN); // use service name as key
    int len_key = strlen(key);

    for (int i = 0; i < MAX_LEN; i++) {
        password->password[i] = password->password[i] ^ key[i % len_key];
    }
}