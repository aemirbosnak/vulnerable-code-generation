//Falcon2-11B DATASET v1.0 Category: Password management ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct User {
    char* username;
    char* password;
    int* next;
};

struct User* createUser(const char* username, const char* password) {
    struct User* newUser = malloc(sizeof(struct User));
    if (!newUser) {
        fprintf(stderr, "Failed to allocate memory for new user.\n");
        return NULL;
    }
    newUser->username = strdup(username);
    if (!newUser->username) {
        fprintf(stderr, "Failed to duplicate username.\n");
        free(newUser);
        return NULL;
    }
    newUser->password = strdup(password);
    if (!newUser->password) {
        fprintf(stderr, "Failed to duplicate password.\n");
        free(newUser->username);
        free(newUser);
        return NULL;
    }
    newUser->next = NULL;
    return newUser;
}

struct User* insertUser(struct User* users, struct User* newUser) {
    if (users == NULL) {
        users = newUser;
        return users;
    }
    struct User* current = users;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newUser;
    return users;
}

void printUsers(struct User* users) {
    struct User* current = users;
    while (current!= NULL) {
        printf("Username: %s\nPassword: %s\n", current->username, current->password);
        current = current->next;
    }
}

int main() {
    struct User* users = NULL;
    users = createUser("sherlock", "holmes");
    users = insertUser(users, createUser("watson", "watson"));
    printUsers(users);
    return 0;
}