//Falcon-180B DATASET v1.0 Category: Password management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

typedef struct {
    char *username;
    char *password;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Too many passwords!\n");
        return;
    }
    num_passwords++;
    passwords[num_passwords - 1].username = strdup(username);
    passwords[num_passwords - 1].password = strdup(password);
}

Password* find_password(char *username) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return &passwords[i];
        }
    }
    return NULL;
}

int main() {
    char *filename = "passwords.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'!\n", filename);
        return 1;
    }
    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *username = strtok(line, ":");
        char *password = strtok(NULL, ":");
        add_password(username, password);
    }
    fclose(file);

    char *username;
    char *password;
    do {
        printf("Enter username: ");
        scanf("%s", username);
        Password *pw = find_password(username);
        if (pw == NULL) {
            printf("Password not found!\n");
            continue;
        }
        printf("Enter password: ");
        scanf("%s", password);
        if (strcmp(pw->password, password) == 0) {
            printf("Login successful!\n");
        } else {
            printf("Login failed!\n");
        }
    } while (1);

    return 0;
}