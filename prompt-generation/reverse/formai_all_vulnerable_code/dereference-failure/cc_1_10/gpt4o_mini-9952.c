//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char email[NAME_LENGTH];
} User;

typedef struct {
    User *users[MAX_USERS];
    int userCount;
} UserDatabase;

UserDatabase db;

// Function to initialize the user database
void initDatabase() {
    db.userCount = 0;
}

// Function to create a new user
User *createUser(int id, const char *name, const char *email) {
    User *newUser = (User *)malloc(sizeof(User));
    newUser->id = id;
    strncpy(newUser->name, name, NAME_LENGTH);
    strncpy(newUser->email, email, NAME_LENGTH);
    return newUser;
}

// Function to add a user to the database
int addUser(int id, const char *name, const char *email) {
    if (db.userCount >= MAX_USERS) {
        printf("Database is full, cannot add more users.\n");
        return -1;
    }
    User *user = createUser(id, name, email);
    db.users[db.userCount++] = user;
    printf("User added: %d, %s, %s\n", id, name, email);
    return 0;
}

// Function to list all users
void listUsers() {
    printf("User List:\n");
    for (int i = 0; i < db.userCount; i++) {
        User *user = db.users[i];
        printf("ID: %d, Name: %s, Email: %s\n", user->id, user->name, user->email);
    }
}

// Function to find a user by ID
User *findUserById(int id) {
    for (int i = 0; i < db.userCount; i++) {
        if (db.users[i]->id == id) {
            return db.users[i];
        }
    }
    return NULL;
}

// Function to free allocated memory
void freeDatabase() {
    for (int i = 0; i < db.userCount; i++) {
        free(db.users[i]);
    }
    db.userCount = 0;
}

// Program entry point
int main() {
    initDatabase();

    // Adding some users
    addUser(1, "Alice Johnson", "alice@example.com");
    addUser(2, "Bob Smith", "bob@example.com");
    addUser(3, "Charlie Brown", "charlie@example.com");

    // Listing all users
    listUsers();

    // Searching for a user by ID
    int searchId = 2;
    User *foundUser = findUserById(searchId);
    if (foundUser) {
        printf("\nUser found: ID: %d, Name: %s, Email: %s\n", 
            foundUser->id, foundUser->name, foundUser->email);
    } else {
        printf("\nUser with ID %d not found.\n", searchId);
    }

    // Free memory before exiting
    freeDatabase();
    return 0;
}