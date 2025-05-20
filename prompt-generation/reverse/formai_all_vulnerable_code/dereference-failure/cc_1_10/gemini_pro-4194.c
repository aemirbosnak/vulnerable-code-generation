//GEMINI-pro DATASET v1.0 Category: Password management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Welcome Message
void welcome() {
    printf("\n\n");
    printf("============================================\n");
    printf("Welcome to 221B Baker Street, my dear Watson.\n");
    printf("I am consulting detective, Sherlock Holmes, and I am here to assist you with your password management.\n");
    printf("============================================\n\n");
}

// Get User Input
char *getInput(char *prompt) {
    char *input;
    size_t len;
    printf("%s", prompt);
    getline(&input, &len, stdin);
    input[strlen(input) - 1] = '\0';
    return input;
}

// Encrypt Password
char *encryptPassword(char *password) {
    int key = 3;
    int i;
    char *encrypted = malloc(strlen(password) + 1);
    for (i = 0; i < strlen(password); i++) {
        encrypted[i] = password[i] + key;
    }
    return encrypted;
}

// Decrypt Password
char *decryptPassword(char *encrypted) {
    int key = 3;
    int i;
    char *decrypted = malloc(strlen(encrypted) + 1);
    for (i = 0; i < strlen(encrypted); i++) {
        decrypted[i] = encrypted[i] - key;
    }
    return decrypted;
}

// Save Password
void savePassword(char *name, char *password) {
    char filename[100];
    sprintf(filename, "passwords/%s.txt", name);
    FILE *file = fopen(filename, "w");
    char *encrypted = encryptPassword(password);
    fprintf(file, "%s", encrypted);
    fclose(file);
    free(encrypted);
}

// Load Password
char *loadPassword(char *name) {
    char filename[100];
    sprintf(filename, "passwords/%s.txt", name);
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }
    char *encrypted = malloc(100);
    fgets(encrypted, 100, file);
    fclose(file);
    char *decrypted = decryptPassword(encrypted);
    free(encrypted);
    return decrypted;
}

// List Passwords
void listPasswords() {
    char command[100];
    sprintf(command, "ls passwords");
    system(command);
}

// Main Function
int main() {
    welcome();

    int choice;
    while (1) {
        printf("\n");
        printf("1. Add a Password\n");
        printf("2. Get a Password\n");
        printf("3. List Passwords\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
        {
            char *name = getInput("Enter the name of the password: ");
            char *password = getInput("Enter the password: ");
            savePassword(name, password);
            printf("Password saved successfully.\n");
            break;
        }
        case 2:
        {
            char *name = getInput("Enter the name of the password to retrieve: ");
            char *password = loadPassword(name);
            if (password == NULL) {
                printf("Password not found.\n");
            } else {
                printf("Password: %s\n", password);
                free(password);
            }
            break;
        }
        case 3:
        {
            listPasswords();
            break;
        }
        case 4:
        {
            printf("Thank you for using my services, my dear Watson. Until next time.\n");
            exit(0);
        }
        default:
        {
            printf("Invalid choice. Please try again.\n");
        }
        }
    }

    return 0;
}