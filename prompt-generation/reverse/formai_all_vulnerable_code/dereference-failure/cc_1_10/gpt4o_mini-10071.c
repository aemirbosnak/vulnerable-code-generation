//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 5
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int age;
    char *email;
} User;

void allocateMemoryForUser(User *user) {
    user->email = (char *)malloc(100 * sizeof(char));
    if (user->email == NULL) {
        fprintf(stderr, "Memory allocation failed for email.\n");
        exit(EXIT_FAILURE);
    }
}

void deallocateMemoryForUser(User *user) {
    free(user->email);
    user->email = NULL; // Set pointer to NULL after freeing
}

void inputUserData(User *user) {
    printf("Enter name: ");
    fgets(user->name, NAME_LENGTH, stdin);
    user->name[strcspn(user->name, "\n")] = '\0'; // Remove newline

    printf("Enter age: ");
    scanf("%d", &user->age);
    getchar(); // Clear the newline left by scanf

    printf("Enter email: ");
    fgets(user->email, 100, stdin);
    user->email[strcspn(user->email, "\n")] = '\0'; // Remove newline
}

void printUserData(const User *user) {
    printf("User Information:\n");
    printf("Name: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Email: %s\n", user->email);
}

void cleanupUsers(User *users, int count) {
    for (int i = 0; i < count; i++) {
        deallocateMemoryForUser(&users[i]);
    }
}

int main() {
    User users[MAX_USERS];
    int userCount = 0;

    while (userCount < MAX_USERS) {
        printf("Adding user %d of %d\n", userCount + 1, MAX_USERS);
        allocateMemoryForUser(&users[userCount]);
        inputUserData(&users[userCount]);
        userCount++;
        printf("\n");
    }

    for (int i = 0; i < userCount; i++) {
        printUserData(&users[i]);
        printf("\n");
    }

    cleanupUsers(users, userCount);

    return 0;
}