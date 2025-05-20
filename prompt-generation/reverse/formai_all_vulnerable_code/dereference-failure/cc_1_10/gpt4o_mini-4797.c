//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_USERS 100
#define NAME_LENGTH 50

typedef struct User {
    int id;
    char name[NAME_LENGTH];
} User;

User **users;  // Array of pointers to User 
int user_count = 0;

// Function to initialize the user management system
void init_users() {
    users = (User **)malloc(MAX_USERS * sizeof(User *));
    if (!users) {
        perror("Failed to allocate memory for users");
        exit(EXIT_FAILURE);
    }
}

// Function to create a new user
void create_user(const char *name) {
    if (user_count >= MAX_USERS) {
        printf("User limit reached. Cannot create more users.\n");
        return;
    }

    users[user_count] = (User *)malloc(sizeof(User));
    if (!users[user_count]) {
        perror("Failed to allocate memory for user");
        exit(EXIT_FAILURE);
    }

    users[user_count]->id = user_count + 1; // Assign an ID based on count
    strncpy(users[user_count]->name, name, NAME_LENGTH);
    users[user_count]->name[NAME_LENGTH - 1] = '\0'; // Ensure null termination
    user_count++;
    printf("User created: ID=%d, Name=%s\n", users[user_count - 1]->id, users[user_count - 1]->name);
}

// Function to delete a user based on ID
void delete_user(int id) {
    if (id < 1 || id > user_count) {
        printf("Invalid user ID: %d. Please enter a valid ID.\n", id);
        return;
    }

    free(users[id - 1]);  // Free the memory for the specified user
    for (int i = id - 1; i < user_count - 1; i++) {
        users[i] = users[i + 1];  // Shift users down
    }
    user_count--;
    users[user_count] = NULL;  // Nullify the last pointer
    printf("User with ID=%d has been deleted.\n", id);
}

// Function to list all users
void list_users() {
    if (user_count == 0) {
        printf("No users available.\n");
        return;
    }

    printf("List of Users:\n");
    for (int i = 0; i < user_count; i++) {
        printf("ID=%d, Name=%s\n", users[i]->id, users[i]->name);
    }
}

// Function to clean up and free all users
void cleanup_users() {
    for (int i = 0; i < user_count; i++) {
        free(users[i]);
    }
    free(users);
    printf("Cleaned up all users.\n");
}

int main() {
    init_users();

    create_user("Linus Torvalds");
    create_user("Richard Stallman");
    create_user("Brian Kernighan");
    create_user("Dennis Ritchie");

    list_users();

    int delete_id;
    printf("Enter ID of user to delete: ");
    scanf("%d", &delete_id);
    delete_user(delete_id);

    list_users();

    cleanup_users();
    return 0;
}