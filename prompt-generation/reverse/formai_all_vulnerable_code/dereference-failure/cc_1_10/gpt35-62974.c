//FormAI DATASET v1.0 Category: Password management ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 16
#define FILENAME "passwords.bin"

struct PasswordManager {
    char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];
    int numPasswords;
    char masterPassword[MAX_PASSWORD_LENGTH];
};

void printOptions() {
    printf("Choose an option:\n");
    printf("1. Create new password\n");
    printf("2. View password list\n");
    printf("3. Exit program\n");
}

void encryptPassword(char* password, char* key) {
    for (int i = 0; i < strlen(password); i++) {
        password[i] ^= key[i % strlen(key)];
    }
}

void decryptPassword(char* password, char* key) {
    for (int i = 0; i < strlen(password); i++) {
        password[i] ^= key[i % strlen(key)];
    }
}

void savePasswords(struct PasswordManager* pm) {
    FILE* file = fopen(FILENAME, "wb");
    fwrite(pm, sizeof(struct PasswordManager), 1, file);
    fclose(file);
}

void readPasswords(struct PasswordManager* pm) {
    FILE* file = fopen(FILENAME, "rb");
    if (file != NULL) {
        fread(pm, sizeof(struct PasswordManager), 1, file);
        fclose(file);
    }
}

void createNewPassword(struct PasswordManager* pm) {
    if (pm->numPasswords >= MAX_PASSWORDS) {
        printf("Too many passwords saved. Delete some passwords before adding new ones.\n");
        return;
    }

    printf("Enter new password: ");
    scanf("%s", pm->passwords[pm->numPasswords]);
    encryptPassword(pm->passwords[pm->numPasswords], pm->masterPassword);
    printf("Password added.\n");
    pm->numPasswords++;
    savePasswords(pm);
}

void viewPasswordList(struct PasswordManager* pm) {
    char masterPassword[MAX_PASSWORD_LENGTH];
    printf("Enter master password to view password list: ");
    scanf("%s", masterPassword);

    if (strcmp(masterPassword, pm->masterPassword) != 0) {
        printf("Incorrect master password.\n");
        return;
    }

    printf("Password list:\n");
    for (int i = 0; i < pm->numPasswords; i++) {
        decryptPassword(pm->passwords[i], pm->masterPassword);
        printf("%d. %s\n", i + 1, pm->passwords[i]);
        encryptPassword(pm->passwords[i], pm->masterPassword);
    }
}

int main() {
    struct PasswordManager pm;
    memset(&pm, 0, sizeof(pm));

    readPasswords(&pm);

    printf("Welcome to the Password Manager!\n");
    printf("Enter master password: ");
    scanf("%s", pm.masterPassword);

    bool exitProgram = false;
    while (!exitProgram) {
        printOptions();

        int choice = 0;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createNewPassword(&pm);
                break;
            case 2:
                viewPasswordList(&pm);
                break;
            case 3:
                exitProgram = true;
                break;
            default:
                printf("Invalid option.\n");
        }
    }

    savePasswords(&pm);

    return 0;
}