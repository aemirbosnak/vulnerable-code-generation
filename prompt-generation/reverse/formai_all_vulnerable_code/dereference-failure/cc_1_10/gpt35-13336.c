//FormAI DATASET v1.0 Category: Password management ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the maximum length of the password
#define MAX_PASSWORD_LENGTH 20

// Password structure
typedef struct password {
    char username[50];
    char website[100];
    char password[MAX_PASSWORD_LENGTH + 1];
} Password;

void encrypt(char *password) {
    // A simple encryption function using ASCII values
    for (int i = 0; i < strlen(password); i++) {
        password[i] = password[i] + 3;
    }
}

void decrypt(char *password) {
    // A simple decryption function using ASCII values
    for (int i = 0; i < strlen(password); i++) {
        password[i] = password[i] - 3;
    }
}

void save_password(Password *p) {
    FILE *fp;
    fp = fopen("passwords.txt", "a");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    // Encrypt the password before saving
    encrypt(p->password);
    fprintf(fp, "%s,%s,%s\n", p->username, p->website, p->password);
    fclose(fp);
    printf("Password saved successfully!\n");
}

void search_passwords(char *keyword) {
    FILE *fp;
    fp = fopen("passwords.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    char line[200];
    printf("Results for keyword '%s':\n", keyword);
    while (fgets(line, sizeof(line), fp)) {
        char *username = strtok(line, ",");
        char *website = strtok(NULL, ",");
        char *encrypted_password = strtok(NULL, ",");
        char password[MAX_PASSWORD_LENGTH + 1];
        // Decrypt the password before printing
        decrypt(encrypted_password);
        strncpy(password, encrypted_password, MAX_PASSWORD_LENGTH);
        password[MAX_PASSWORD_LENGTH] = '\0';
        if (strstr(username, keyword) || strstr(website, keyword)) {
            printf("Username: %s\nWebsite: %s\nPassword: %s\n", username, website, password);
        }
    }
    fclose(fp);
}

int main() {
    int choice;
    do {
        printf("Menu:\n1. Save password\n2. Search passwords\n3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter username: ");
                char username[50];
                scanf("%s", username);
                printf("Enter website name: ");
                char website[100];
                scanf("%s", website);
                printf("Enter password (max length %d): ", MAX_PASSWORD_LENGTH);
                char password[MAX_PASSWORD_LENGTH + 1];
                scanf("%s", password);
                // Create a new password record
                Password p;
                strncpy(p.username, username, 50);
                strncpy(p.website, website, 100);
                strncpy(p.password, password, MAX_PASSWORD_LENGTH);
                p.password[MAX_PASSWORD_LENGTH] = '\0';
                // Save the password
                save_password(&p);
                break;
            case 2:
                printf("Enter search keyword: ");
                char keyword[50];
                scanf("%s", keyword);
                search_passwords(keyword);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 3);
    return 0;
}