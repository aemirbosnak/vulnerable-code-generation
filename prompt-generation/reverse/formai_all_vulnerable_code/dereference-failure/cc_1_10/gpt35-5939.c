//FormAI DATASET v1.0 Category: Password management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct password{
    char *site;
    char *username;
    char *password;
};

void add_password(struct password passwords[], int *count) {
    printf("Enter website name: ");
    char site[50];
    fgets(site, 50, stdin);
    site[strcspn(site, "\n")] = '\0';
    for (int i = 0; i < *count; i++) {
        if (strcmp(passwords[i].site, site) == 0) {
            printf("Website already exists in record.\n");
            return;
        }
    }
    printf("Enter username: ");
    char username[50];
    fgets(username, 50, stdin);
    username[strcspn(username, "\n")] = '\0';
    printf("Enter password: ");
    char password[50];
    fgets(password, 50, stdin);
    password[strcspn(password, "\n")] = '\0';
    passwords[*count].site = strdup(site);
    passwords[*count].username = strdup(username);
    passwords[*count].password = strdup(password);
    *count += 1;
}

void display_passwords(struct password passwords[], int count) {
    if (count == 0) {
        printf("No passwords saved.\n");
        return;
    }
    printf("Website\t\t\tUsername\tPassword\n");
    for (int i = 0; i < count; i++) {
        printf("%-24s%-16s%s\n", passwords[i].site, passwords[i].username, passwords[i].password);
    }
}

void search_passwords(struct password passwords[], int count) {
    if (count == 0) {
        printf("No passwords saved.\n");
        return;
    }
    printf("Enter website name: ");
    char site[50];
    fgets(site, 50, stdin);
    site[strcspn(site, "\n")] = '\0';
    for (int i = 0; i < count; i++) {
        if (strcmp(passwords[i].site, site) == 0) {
            printf("Website\t\t\tUsername\tPassword\n");
            printf("%-24s%-16s%s\n", passwords[i].site, passwords[i].username, passwords[i].password);
            return;
        }
    }
    printf("Website not found.\n");
}

void change_password(struct password passwords[], int count) {
    if (count == 0) {
        printf("No passwords saved.\n");
        return;
    }
    printf("Enter website name: ");
    char site[50];
    fgets(site, 50, stdin);
    site[strcspn(site, "\n")] = '\0';
    for (int i = 0; i < count; i++) {
        if (strcmp(passwords[i].site, site) == 0) {
            printf("Enter new password: ");
            char password[50];
            fgets(password, 50, stdin);
            password[strcspn(password, "\n")] = '\0';
            free(passwords[i].password);
            passwords[i].password = strdup(password);
            printf("Password for %s has been changed.\n", site);
            return;
        }
    }
    printf("Website not found.\n");
}

void delete_password(struct password passwords[], int *count) {
    if (*count == 0) {
        printf("No passwords saved.\n");
        return;
    }
    printf("Enter website name to delete: ");
    char site[50];
    fgets(site, 50, stdin);
    site[strcspn(site, "\n")] = '\0';
    for (int i = 0; i < *count; i++) {
        if (strcmp(passwords[i].site, site) == 0) {
            free(passwords[i].site);
            free(passwords[i].username);
            free(passwords[i].password);
            for (int j = i; j < *count - 1; j++) {
                passwords[j] = passwords[j+1];
            }
            *count -= 1;
            printf("Password for %s has been deleted.\n", site);
            return;
        }
    }
    printf("Website not found.\n");
}

int main() {
    struct password passwords[100];
    int count = 0;
    int choice = 0;
    while (choice != 6) {
        printf("\nPassword Management System\n");
        printf("1. Add Passwords\n");
        printf("2. Display Passwords\n");
        printf("3. Search Passwords\n");
        printf("4. Change Passwords\n");
        printf("5. Delete Passwords\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        char input[10];
        fgets(input, 10, stdin);
        choice = atoi(input);
        switch (choice) {
            case 1:
                add_password(passwords, &count);
                break;
            case 2:
                display_passwords(passwords, count);
                break;
            case 3:
                search_passwords(passwords, count);
                break;
            case 4:
                change_password(passwords, count);
                break;
            case 5:
                delete_password(passwords, &count);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
                break;
        }
    }
    return 0;
}