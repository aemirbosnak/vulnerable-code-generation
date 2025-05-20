//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define NAME_LENGTH 50

// Define the structure for a user
typedef struct User {
    int id;
    char name[NAME_LENGTH];
    int age;
} User;

// Define the structure for the index node
typedef struct IndexNode {
    int id;
    int userIndex;
    struct IndexNode *next;
} IndexNode;

// User database
User userDatabase[MAX_USERS];
int userCount = 0;

// Index linked list head
IndexNode *indexHead = NULL;

// Function to create a new index node
IndexNode* createIndexNode(int id, int userIndex) {
    IndexNode *newNode = (IndexNode *)malloc(sizeof(IndexNode));
    newNode->id = id;
    newNode->userIndex = userIndex;
    newNode->next = NULL;
    return newNode;
}

// Function to insert an index node into the linked list
void insertIndex(int id, int userIndex) {
    IndexNode *newNode = createIndexNode(id, userIndex);
    if (indexHead == NULL || indexHead->id > id) {
        newNode->next = indexHead;
        indexHead = newNode;
    } else {
        IndexNode *current = indexHead;
        while (current->next != NULL && current->next->id < id) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to search for a user by ID using the index
User* searchUserById(int id) {
    IndexNode *current = indexHead;
    while (current != NULL) {
        if (current->id == id) {
            return &userDatabase[current->userIndex];
        }
        current = current->next;
    }
    return NULL;
}

// Function to add a user to the database
void addUser(int id, const char *name, int age) {
    if (userCount >= MAX_USERS) return;
    User newUser = {id, "", age};
    strncpy(newUser.name, name, NAME_LENGTH);
    userDatabase[userCount++] = newUser;
    insertIndex(id, userCount - 1);
}

// Function to display all users
void displayUsers() {
    printf("User Database:\n");
    for (int i = 0; i < userCount; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", userDatabase[i].id, userDatabase[i].name, userDatabase[i].age);
    }
}

// Function to display a user by ID
void displayUserById(int id) {
    User *user = searchUserById(id);
    if (user) {
        printf("User found -> ID: %d, Name: %s, Age: %d\n", user->id, user->name, user->age);
    } else {
        printf("User with ID %d not found.\n", id);
    }
}

// Main function to run the database indexing system
int main() {
    // Adding users to the database
    addUser(1, "Alice", 30);
    addUser(2, "Bob", 25);
    addUser(3, "Charlie", 35);
    
    // Display all users
    displayUsers();

    // Search for a user by ID
    int searchId;
    printf("Enter user ID to search: ");
    scanf("%d", &searchId);
    displayUserById(searchId);

    // Clean up memory for the index
    IndexNode *current = indexHead;
    while (current != NULL) {
        IndexNode *next = current->next;
        free(current);
        current = next;
    }
    
    return 0;
}