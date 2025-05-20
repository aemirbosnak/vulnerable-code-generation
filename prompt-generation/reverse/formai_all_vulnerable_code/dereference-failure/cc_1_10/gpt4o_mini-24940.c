//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 5
#define MAX_NAME_LENGTH 50

typedef struct {
    char *name;
    int age;
} User;

void allocate_user(User *user, const char *name, int age) {
    user->name = (char *)malloc(strlen(name) + 1); // allocate memory for name
    if (user->name != NULL) {
        strcpy(user->name, name); // copy name into allocated memory
        user->age = age; // set age
    } else {
        fprintf(stderr, "Memory allocation failed for user name\n");
        exit(1);
    }
}

void free_user(User *user) {
    free(user->name); // free allocated name memory
    user->name = NULL; // set pointer to NULL to avoid dangling pointer
}

void print_user(const User *user) {
    if (user->name != NULL) {
        printf("Name: %s, Age: %d\n", user->name, user->age);
    } else {
        printf("User has no name.\n");
    }
}

int main() {
    User *users = (User *)malloc(MAX_USERS * sizeof(User)); // allocate array of users
    if (users == NULL) {
        fprintf(stderr, "Memory allocation failed for users\n");
        return 1;
    }

    // Populate user data
    allocate_user(&users[0], "Alice", 30);
    allocate_user(&users[1], "Bob", 25);
    allocate_user(&users[2], "Charlie", 28);
    allocate_user(&users[3], "Diana", 22);
    allocate_user(&users[4], "Ethan", 35);

    // Print user information
    printf("User Information:\n");
    for (int i = 0; i < MAX_USERS; i++) {
        print_user(&users[i]);
    }

    // Free users
    for (int i = 0; i < MAX_USERS; i++) {
        free_user(&users[i]);
    }

    free(users); // free the user array
    users = NULL; // set pointer to NULL to avoid dangling pointer

    return 0;
}