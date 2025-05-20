//Falcon-180B DATASET v1.0 Category: Password management ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 256

typedef struct {
    char* username;
    char* password;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char* username, char* password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: maximum number of passwords reached.\n");
        return;
    }
    passwords[num_passwords].username = strdup(username);
    passwords[num_passwords].password = strdup(password);
    num_passwords++;
}

void delete_password(int index) {
    if (index < 0 || index >= num_passwords) {
        printf("Error: invalid password index.\n");
        return;
    }
    free(passwords[index].username);
    free(passwords[index].password);
    for (int i = index; i < num_passwords - 1; i++) {
        passwords[i] = passwords[i + 1];
    }
    num_passwords--;
}

void change_password(int index, char* new_password) {
    if (index < 0 || index >= num_passwords) {
        printf("Error: invalid password index.\n");
        return;
    }
    free(passwords[index].password);
    passwords[index].password = strdup(new_password);
}

void list_passwords() {
    for (int i = 0; i < num_passwords; i++) {
        printf("%s - %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    add_password("example@gmail.com", "password123");
    add_password("example2@gmail.com", "password456");
    list_passwords();
    change_password(0, "new_password123");
    list_passwords();
    delete_password(1);
    list_passwords();
    return 0;
}