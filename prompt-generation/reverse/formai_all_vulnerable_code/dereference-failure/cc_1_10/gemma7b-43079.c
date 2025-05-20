//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of users
#define MAX_USER_NUM 10

// Define the user data structure
typedef struct User {
    char name[20];
    int id;
    struct User* next;
} User;

// Create a linked list of users
User* createUserList() {
    User* head = NULL;
    User* tail = NULL;

    // Allocate memory for the first user
    head = (User*)malloc(sizeof(User));
    tail = head;

    // Set the user's name and ID
    strcpy(head->name, "John Doe");
    head->id = 1;

    // Create the remaining users
    for (int i = 2; i <= MAX_USER_NUM; i++) {
        tail->next = (User*)malloc(sizeof(User));
        tail = tail->next;
        strcpy(tail->name, "User");
        tail->id = i;
    }

    return head;
}

// Function to detect intrusion
void detectIntrusion(User* userHead) {
    // Iterate over the user list
    User* current = userHead;
    while (current) {
        // Check if the user's name is "Admin"
        if (strcmp(current->name, "Admin") == 0) {
            // If the user's ID is not 1, the user is an intruder
            if (current->id != 1) {
                printf("Intrusion detected: User %s with ID %d is an intruder.\n", current->name, current->id);
            }
        }
        current = current->next;
    }
}

int main() {
    // Create a linked list of users
    User* userHead = createUserList();

    // Detect intrusion
    detectIntrusion(userHead);

    return 0;
}