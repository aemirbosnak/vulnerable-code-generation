//Falcon-180B DATASET v1.0 Category: Password management ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 64

typedef struct {
    char* username;
    char* password;
    bool is_valid;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void read_passwords() {
    FILE* file = fopen("passwords.txt", "r");
    if (file == NULL) {
        printf("Error opening passwords file.\n");
        exit(1);
    }

    char line[MAX_PASSWORD_LENGTH];
    while (fgets(line, MAX_PASSWORD_LENGTH, file)!= NULL) {
        char* username = strtok(line, ":");
        char* password = strtok(NULL, ":");

        if (num_passwords >= MAX_PASSWORDS) {
            printf("Maximum number of passwords reached.\n");
            break;
        }

        passwords[num_passwords].username = strdup(username);
        passwords[num_passwords].password = strdup(password);
        passwords[num_passwords].is_valid = true;

        num_passwords++;
    }

    fclose(file);
}

void write_passwords() {
    FILE* file = fopen("passwords.txt", "w");
    if (file == NULL) {
        printf("Error opening passwords file.\n");
        exit(1);
    }

    for (int i = 0; i < num_passwords; i++) {
        fprintf(file, "%s:%s\n", passwords[i].username, passwords[i].password);
    }

    fclose(file);
}

int main() {
    read_passwords();

    char* username;
    char* password;

    printf("Enter username: ");
    scanf("%s", username);

    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(username, passwords[i].username) == 0) {
            printf("Enter password for %s: ", username);
            scanf("%s", password);

            if (strcmp(password, passwords[i].password) == 0) {
                printf("Login successful.\n");
                return 0;
            } else {
                passwords[i].is_valid = false;
                write_passwords();
                printf("Incorrect password.\n");
                return 1;
            }
        }
    }

    printf("User not found.\n");
    return 1;
}