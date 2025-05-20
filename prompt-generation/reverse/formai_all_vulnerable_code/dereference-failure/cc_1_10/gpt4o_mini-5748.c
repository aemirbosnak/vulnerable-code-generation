//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct User {
    int id;
    char name[50];
    struct User *next;
} User;

User *head = NULL;

User* createUser(int id, const char *name) {
    User *newUser = (User *)malloc(sizeof(User));
    newUser->id = id;
    strncpy(newUser->name, name, sizeof(newUser->name));
    newUser->next = NULL;
    return newUser;
}

void insertUser(int id, const char *name) {
    User *newUser = createUser(id, name);
    newUser->next = head;
    head = newUser;
}

void displayUsers() {
    User *current = head;
    printf("User List:\n");
    while (current) {
        printf("ID: %d, Name: %s\n", current->id, current->name);
        current = current->next;
    }
}

User* findUser(int id, User *current) {
    if (current == NULL)
        return NULL;
    if (current->id == id)
        return current;
    return findUser(id, current->next);
}

void queryUser(int id) {
    User *result = findUser(id, head);
    if (result)
        printf("Found User: ID: %d, Name: %s\n", result->id, result->name);
    else
        printf("User with ID %d not found.\n", id);
}

void cleanup(User *current) {
    if (current == NULL)
        return;
    cleanup(current->next);
    free(current);
}

void freeUsers() {
    cleanup(head);
    head = NULL;
}

int main() {
    insertUser(1, "Alice");
    insertUser(2, "Bob");
    insertUser(3, "Charlie");
    insertUser(4, "Diana");
    
    displayUsers();
    
    int idToFind;
    printf("Enter user ID to search: ");
    scanf("%d", &idToFind);
    queryUser(idToFind);
    
    printf("Cleaning up the database...\n");
    freeUsers();
    
    return 0;
}