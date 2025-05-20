//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_USERS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char email[MAX_NAME_LENGTH];
} User;

// Function prototypes
User* create_user(const char* name, int age, const char* email);
void delete_user(User* user);
void print_user(const User* user);
void print_all_users(User** users, int count);

int main() {
    // Hold user pointers dynamically
    User** userDatabase = (User**)malloc(MAX_USERS * sizeof(User*));
    if (userDatabase == NULL) {
        fprintf(stderr, "Memory allocation for user database failed.\n");
        return EXIT_FAILURE;
    }

    int userCount = 0;
    
    // Adding users to the database
    userDatabase[userCount++] = create_user("Alice", 28, "alice@example.com");
    userDatabase[userCount++] = create_user("Bob", 32, "bob@example.com");
    userDatabase[userCount++] = create_user("Charlie", 25, "charlie@example.com");

    // Print all users
    print_all_users(userDatabase, userCount);

    // Change Bob's email
    printf("\nUpdating Bob's email...\n");
    strcpy(userDatabase[1]->email, "bob_new@example.com");

    // Print all users again
    print_all_users(userDatabase, userCount);

    // Cleanup: Free allocated memory for users
    for (int i = 0; i < userCount; i++) {
        delete_user(userDatabase[i]);
    }

    // Free the user database
    free(userDatabase);

    return EXIT_SUCCESS;
}

// Function implementations
User* create_user(const char* name, int age, const char* email) {
    User* newUser = (User*)malloc(sizeof(User));
    if (newUser == NULL) {
        fprintf(stderr, "Memory allocation for user failed.\n");
        return NULL;
    }
    
    strncpy(newUser->name, name, MAX_NAME_LENGTH);
    newUser->age = age;
    strncpy(newUser->email, email, MAX_NAME_LENGTH);

    printf("User created: %s, Age: %d, Email: %s\n", newUser->name, newUser->age, newUser->email);
    return newUser;
}

void delete_user(User* user) {
    if (user != NULL) {
        free(user);
        printf("User deleted successfully.\n");
    } else {
        fprintf(stderr, "Attempted to delete a null user.\n");
    }
}

void print_user(const User* user) {
    if (user != NULL) {
        printf("Name: %s, Age: %d, Email: %s\n", user->name, user->age, user->email);
    } else {
        fprintf(stderr, "Cannot print a null user.\n");
    }
}

void print_all_users(User** users, int count) {
    printf("\nCurrent User Database:\n");
    for (int i = 0; i < count; i++) {
        print_user(users[i]);
    }
}