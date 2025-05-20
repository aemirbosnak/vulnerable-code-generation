//Gemma-7B DATASET v1.0 Category: System administration ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_USER_NAME_LENGTH 256

typedef struct User {
    char name[MAX_USER_NAME_LENGTH];
    int uid;
    struct User* next;
} User;

User* createUser(char* name, int uid) {
    User* newUser = malloc(sizeof(User));
    strcpy(newUser->name, name);
    newUser->uid = uid;
    newUser->next = NULL;
    return newUser;
}

void updateUser(User* user, char* name, int uid) {
    strcpy(user->name, name);
    user->uid = uid;
}

void deleteUser(User* user) {
    free(user);
}

int main() {
    User* head = NULL;
    User* tail = NULL;

    // Create a new user
    User* newUser = createUser("Ken Thompson", 123);
    if (head == NULL) {
        head = newUser;
        tail = newUser;
    } else {
        tail->next = newUser;
        tail = newUser;
    }

    // Update the user's name and uid
    updateUser(newUser, "John Doe", 456);

    // Delete the user
    deleteUser(newUser);

    // Print the remaining users
    for (User* user = head; user != NULL; user = user->next) {
        printf("Name: %s, UID: %d\n", user->name, user->uid);
    }

    return 0;
}