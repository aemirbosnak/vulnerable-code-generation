//FormAI DATASET v1.0 Category: Password management ; Style: rigorous
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORDS 100

char *encrypt(const char *password) {
    char *encrypted = malloc(sizeof(char) * strlen(password));
    for (size_t i = 0; i < strlen(password); i++) {
        encrypted[i] = password[i] + 1; // Simple encryption algorithm
    }
    return encrypted;
}

char *decrypt(const char *encrypted_password) {
    char *decrypted = malloc(sizeof(char) * strlen(encrypted_password));
    for (size_t i = 0; i < strlen(encrypted_password); i++) {
        decrypted[i] = encrypted_password[i] - 1; // Inverse of encryption algorithm
    }
    return decrypted;
}

struct Password {
    char *service_name;
    char *encrypted_password;
};

void create_password(struct Password *passwords, int *num_passwords) {
    char *service_name = malloc(sizeof(char) * 50);
    printf("Enter service name: ");
    scanf("%s", service_name);

    char *password = malloc(sizeof(char) * 50);
    printf("Enter password: ");
    scanf("%s", password);

    char *encrypted_password = encrypt(password);

    struct Password new_password = { service_name, encrypted_password };

    passwords[*num_passwords] = new_password;
    (*num_passwords)++;
}

void print_passwords(struct Password *passwords, int num_passwords) {
    for (int i = 0; i < num_passwords; i++) {
        printf("Service: %s, Password: %s\n", passwords[i].service_name, decrypt(passwords[i].encrypted_password));
    }
}

int main() {
    struct Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    while (1) {
        printf("1. Create password\n2. Print passwords\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_password(passwords, &num_passwords);
                break;
            case 2:
                print_passwords(passwords, num_passwords);
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    return 0;
}