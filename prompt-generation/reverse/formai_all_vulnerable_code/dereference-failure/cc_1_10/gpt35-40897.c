//FormAI DATASET v1.0 Category: Database simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold information about a user
typedef struct {
    int id;
    char name[50];
    char email[50];
    char phone[20];
} User;

// Function to create a new user
User* createUser(int id, char* name, char* email, char* phone) {
    User* user = (User*)malloc(sizeof(User));
    user->id = id;
    strcpy(user->name, name);
    strcpy(user->email, email);
    strcpy(user->phone, phone);
    return user;
}

// Array to hold all the users
User* users[50];

// Index of the next available slot in the array
int nextIndex = 0;

// Function to print all the users in the array
void printUsers() {
    printf("ID\tName\tEmail\t\tPhone\n");
    for(int i = 0; i < nextIndex; i++) {
        printf("%d\t%s\t%s\t%s\n", users[i]->id, users[i]->name, users[i]->email, users[i]->phone);
    }
}

// Function to search for a user by their ID
User* getUserById(int id) {
    for(int i = 0; i < nextIndex; i++) {
        if(users[i]->id == id) {
            return users[i];
        }
    }
    return NULL;
}

int main() {
    // Create some sample users
    User* user1 = createUser(1, "Alice", "alice@example.com", "555-1234");
    User* user2 = createUser(2, "Bob", "bob@example.com", "555-5678");
    User* user3 = createUser(3, "Charlie", "charlie@example.com", "555-9999");
    
    // Add the users to the array
    users[nextIndex++] = user1;
    users[nextIndex++] = user2;
    users[nextIndex++] = user3;
    
    // Print out all the users in the array
    printf("Initial Users:\n");
    printUsers();
    
    // Find a user by their ID
    printf("\nSearching for user with ID 2...\n");
    User* user = getUserById(2);
    if(user) {
        printf("Found user: %s\n", user->name);
    } else {
        printf("User not found.\n");
    }
    
    // Add a new user to the array
    printf("\nAdding new user...\n");
    User* newUser = createUser(4, "Dave", "dave@example.com", "555-4444");
    users[nextIndex++] = newUser;
    printf("New user added successfully.\n");
    
    // Print out all the users in the array again
    printf("\nAll Users:\n");
    printUsers();
    
    return 0;
}