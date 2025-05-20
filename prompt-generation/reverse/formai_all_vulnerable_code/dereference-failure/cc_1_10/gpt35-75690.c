//FormAI DATASET v1.0 Category: Database querying ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_PASSWORD_LENGTH 20

struct User {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct UserDB {
    struct User* users;
    int size;
};

void print_user(const struct User* user) {
    printf("Name: %s\n", user->name);
    printf("Email: %s\n", user->email);
}

void print_users(const struct UserDB* userdb) {
    printf("Total users: %d\n", userdb->size);
    for (int i = 0; i < userdb->size; i++) {
        printf("User %d:\n", i);
        print_user(&userdb->users[i]);
    }
}

int main() {
    // Initialize database
    struct UserDB userdb;
    userdb.size = 0;
    userdb.users = NULL;

    // Add user
    struct User user1 = {"John Smith", "jsmith@gmail.com", "12345"};
    userdb.size++;
    userdb.users = (struct User*)realloc(userdb.users, userdb.size * sizeof(struct User));
    if (!userdb.users) {
        printf("Error: Out of memory!");
        return 1;
    }
    userdb.users[userdb.size - 1] = user1;

    // Add another user
    struct User user2 = {"Jane Doe", "jdoe@gmail.com", "54321"};
    userdb.size++;
    userdb.users = (struct User*)realloc(userdb.users, userdb.size * sizeof(struct User));
    if (!userdb.users) {
        printf("Error: Out of memory!");
        return 1;
    }
    userdb.users[userdb.size - 1] = user2;

    // Find user by email
    char search_email[MAX_EMAIL_LENGTH];
    printf("Enter a user email to search for: ");
    fgets(search_email, MAX_EMAIL_LENGTH, stdin);
    search_email[strcspn(search_email, "\n")] = 0;
    for (int i = 0; i < userdb.size; i++) {
        if (strcmp(userdb.users[i].email, search_email) == 0) {
            print_user(&userdb.users[i]);
            break;
        }
    }

    // Free memory
    free(userdb.users);

    return 0;
}