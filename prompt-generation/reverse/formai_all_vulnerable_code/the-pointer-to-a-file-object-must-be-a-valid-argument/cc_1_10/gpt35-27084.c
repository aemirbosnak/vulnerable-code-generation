//FormAI DATASET v1.0 Category: Password management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char website[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} PasswordEntry;

int main(void) {
    PasswordEntry passwordEntries[MAX_PASSWORDS];
    int numPasswords = 0;

    // Load existing passwords from file
    FILE* file = fopen("passwords.txt", "r");
    char line[MAX_PASSWORD_LENGTH * 3];
    while (fgets(line, sizeof(line), file)) {
        char* website = strtok(line, ",");
        char* username = strtok(NULL, ",");
        char* password = strtok(NULL, "\n");
        strcpy(passwordEntries[numPasswords].website, website);
        strcpy(passwordEntries[numPasswords].username, username);
        strcpy(passwordEntries[numPasswords].password, password);
        numPasswords++;
    }
    fclose(file);

    // Main loop
    while (1) {
        printf("Enter option:\n");
        printf("1. Add password\n");
        printf("2. List passwords\n");
        printf("3. Quit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                if (numPasswords == MAX_PASSWORDS) {
                    printf("ERROR: Maximum number of passwords reached!\n");
                    break;
                }
                printf("Enter website:\n");
                scanf("%s", passwordEntries[numPasswords].website);
                printf("Enter username:\n");
                scanf("%s", passwordEntries[numPasswords].username);
                printf("Enter password:\n");
                scanf("%s", passwordEntries[numPasswords].password);
                numPasswords++;

                // Save passwords to file
                file = fopen("passwords.txt", "w");
                for (int i = 0; i < numPasswords; i++) {
                    fprintf(file, "%s,%s,%s\n",
                            passwordEntries[i].website,
                            passwordEntries[i].username,
                            passwordEntries[i].password);
                }
                fclose(file);

                printf("Password added!\n");
                break;
            }
            case 2: {
                printf("Website\tUsername\tPassword\n");
                for (int i = 0; i < numPasswords; i++) {
                    printf("%s\t%s\t%s\n",
                            passwordEntries[i].website,
                            passwordEntries[i].username,
                            passwordEntries[i].password);
                }
                break;
            }
            case 3: {
                printf("Goodbye!\n");
                return 0;
            }
            default: {
                printf("Error: Invalid option!\n");
                break;
            }
        }
    }
}