//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
} User;

typedef struct {
    User *users[MAX_RECORDS];
    int count;
} Database;

// Function Prototypes
Database* createDatabase();
void addUser(Database *db, int id, const char *name, int age);
void displayUsers(Database *db);
User* findUserById(Database *db, int id);
void updateUser(Database *db, int id, const char *newName, int newAge);
void deleteUser(Database *db, int id);
void freeDatabase(Database *db);

int main() {
    Database *db = createDatabase();
    int choice, id, age;
    char name[NAME_LENGTH];

    while (1) {
        printf("\nDatabase Menu:\n");
        printf("1. Add User\n");
        printf("2. Display Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter User ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                addUser(db, id, name, age);
                break;
            case 2:
                displayUsers(db);
                break;
            case 3:
                printf("Enter User ID to Update: ");
                scanf("%d", &id);
                printf("Enter New Name: ");
                scanf("%s", name);
                printf("Enter New Age: ");
                scanf("%d", &age);
                updateUser(db, id, name, age);
                break;
            case 4:
                printf("Enter User ID to Delete: ");
                scanf("%d", &id);
                deleteUser(db, id);
                break;
            case 5:
                freeDatabase(db);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to create a new database
Database* createDatabase() {
    Database *db = (Database *)malloc(sizeof(Database));
    db->count = 0;
    return db;
}

// Function to add a new user to the database
void addUser(Database *db, int id, const char *name, int age) {
    if (db->count < MAX_RECORDS) {
        User *newUser = (User *)malloc(sizeof(User));
        newUser->id = id;
        strncpy(newUser->name, name, NAME_LENGTH);
        newUser->age = age;
        db->users[db->count++] = newUser;
        printf("User added successfully.\n");
    } else {
        printf("Database is full, cannot add more users.\n");
    }
}

// Function to display all users in the database
void displayUsers(Database *db) {
    if (db->count == 0) {
        printf("No users to display.\n");
        return;
    }
    printf("\nList of Users:\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", db->users[i]->id, db->users[i]->name, db->users[i]->age);
    }
}

// Function to find a user by ID
User* findUserById(Database *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->users[i]->id == id) {
            return db->users[i];
        }
    }
    return NULL;
}

// Function to update a user in the database
void updateUser(Database *db, int id, const char *newName, int newAge) {
    User *user = findUserById(db, id);
    if (user) {
        strncpy(user->name, newName, NAME_LENGTH);
        user->age = newAge;
        printf("User updated successfully.\n");
    } else {
        printf("User with ID %d not found.\n", id);
    }
}

// Function to delete a user from the database
void deleteUser(Database *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->users[i]->id == id) {
            free(db->users[i]);
            db->users[i] = db->users[--db->count]; // Replace with last user and reduce count
            printf("User deleted successfully.\n");
            return;
        }
    }
    printf("User with ID %d not found.\n", id);
}

// Function to free the database
void freeDatabase(Database *db) {
    for (int i = 0; i < db->count; i++) {
        free(db->users[i]);
    }
    free(db);
}