//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_WORKOUTS 50

// User structure
typedef struct {
    char name[50];
    int age;
    int weight;
    int height;
    int workouts[MAX_WORKOUTS];
} User;

// Function to create a new user
User* createUser(char* name, int age, int weight, int height) {
    User* user = (User*)malloc(sizeof(User));
    strcpy(user->name, name);
    user->age = age;
    user->weight = weight;
    user->height = height;
    for (int i = 0; i < MAX_WORKOUTS; i++) {
        user->workouts[i] = 0;
    }
    return user;
}

// Function to add a workout for a user
void addWorkout(User* user, int workout) {
    for (int i = 0; i < MAX_WORKOUTS; i++) {
        if (user->workouts[i] == 0) {
            user->workouts[i] = workout;
            return;
        }
    }
    printf("Error: No more workouts can be added for this user.\n");
}

// Function to display user information
void displayUser(User* user) {
    printf("Name: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Weight: %d\n", user->weight);
    printf("Height: %d\n", user->height);
    printf("Workouts:\n");
    for (int i = 0; i < MAX_WORKOUTS; i++) {
        if (user->workouts[i]!= 0) {
            printf("%d\n", user->workouts[i]);
        }
    }
}

// Function to display all user information
void displayUsers(User users[], int numUsers) {
    for (int i = 0; i < numUsers; i++) {
        displayUser(users + i);
        printf("\n");
    }
}

int main() {
    User users[MAX_USERS];
    int numUsers = 0;

    // Create new user
    User* newUser = createUser("John Doe", 30, 180, 80);
    numUsers++;

    // Add workouts for user
    addWorkout(newUser, 10);
    addWorkout(newUser, 20);

    // Display user information
    displayUser(newUser);

    // Create another new user
    User* anotherUser = createUser("Jane Doe", 25, 150, 70);
    numUsers++;

    // Add workouts for user
    addWorkout(anotherUser, 5);
    addWorkout(anotherUser, 15);

    // Display user information
    displayUser(anotherUser);

    // Display all user information
    displayUsers(users, numUsers);

    return 0;
}