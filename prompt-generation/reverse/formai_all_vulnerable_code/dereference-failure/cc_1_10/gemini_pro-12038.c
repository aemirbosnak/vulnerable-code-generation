//GEMINI-pro DATASET v1.0 Category: Password management ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_PW_LEN 100

typedef struct {
    char *username;
    char *password;
} credential;

credential *credentials;
int num_credentials = 0;

void add_credential(char *username, char *password) {
    credentials = realloc(credentials, (num_credentials + 1) * sizeof(credential));
    credentials[num_credentials].username = strdup(username);
    credentials[num_credentials].password = strdup(password);
    num_credentials++;
}

int find_credential(char *username) {
    for (int i = 0; i < num_credentials; i++) {
        if (strcmp(credentials[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

void delete_credential(char *username) {
    int index = find_credential(username);
    if (index >= 0) {
        free(credentials[index].username);
        free(credentials[index].password);
        for (int i = index + 1; i < num_credentials; i++) {
            credentials[i - 1] = credentials[i];
        }
        num_credentials--;
        credentials = realloc(credentials, num_credentials * sizeof(credential));
    }
}

int main() {
    char username[MAX_PW_LEN];
    char password[MAX_PW_LEN];
    char hashed_password[SHA256_DIGEST_LENGTH];
    int choice;

    while (1) {
        printf("\n1. Add a credential\n");
        printf("2. Find a credential\n");
        printf("3. Delete a credential\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);

                // Hash the password
                SHA256(password, strlen(password), hashed_password);

                add_credential(username, hashed_password);
                break;

            case 2:
                printf("Enter username: ");
                scanf("%s", username);

                int index = find_credential(username);
                if (index >= 0) {
                    printf("Password: %s\n", credentials[index].password);
                } else {
                    printf("Username not found.\n");
                }
                break;

            case 3:
                printf("Enter username: ");
                scanf("%s", username);

                delete_credential(username);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}