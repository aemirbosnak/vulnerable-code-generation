//Falcon2-11B DATASET v1.0 Category: Password management ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAMES 100

typedef struct {
    char username[MAX_USERNAMES];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password* passwords;
int num_passwords;

void add_password(char* username, char* password) {
    Password* p = &passwords[num_passwords];
    strcpy(p->username, username);
    strcpy(p->password, password);
    num_passwords++;
}

char* get_password(char* username) {
    Password* p = &passwords[0];
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(p->username, username) == 0) {
            return p->password;
        }
        p++;
    }
    return NULL;
}

void print_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        Password p = passwords[i];
        printf("Username: %s, Password: %s\n", p.username, p.password);
    }
}

int main() {
    passwords = (Password*) malloc(num_passwords * sizeof(Password));
    if (passwords == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    num_passwords = 0;

    char username[MAX_USERNAMES];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter a username and password, or type 'quit' to quit:\n");

    while (1) {
        scanf("%s", username);
        if (strcmp(username, "quit") == 0) {
            break;
        }
        scanf("%s", password);
        add_password(username, password);
        print_passwords();
    }

    return 0;
}