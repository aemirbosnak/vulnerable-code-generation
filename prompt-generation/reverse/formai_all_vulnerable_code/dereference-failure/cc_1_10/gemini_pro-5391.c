//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the user database
#define MAX_USERS 100

// Define the structure of a user
typedef struct {
    char username[20];
    char password[20];
    int age;
    int height;
    int weight;
    int steps;
    int calories;
    int distance;
} user;

// Define the structure of the fitness tracker database
typedef struct {
    user users[MAX_USERS];
    int num_users;
} fitness_tracker;

// Create a new fitness tracker database
fitness_tracker *create_fitness_tracker() {
    fitness_tracker *ft = malloc(sizeof(fitness_tracker));
    if (ft == NULL) {
        return NULL;
    }
    ft->num_users = 0;
    return ft;
}

// Add a new user to the fitness tracker database
int add_user(fitness_tracker *ft, user *u) {
    if (ft->num_users >= MAX_USERS) {
        return -1;
    }
    ft->users[ft->num_users] = *u;
    ft->num_users++;
    return 0;
}

// Find a user in the fitness tracker database
user *find_user(fitness_tracker *ft, char *username) {
    for (int i = 0; i < ft->num_users; i++) {
        if (strcmp(ft->users[i].username, username) == 0) {
            return &ft->users[i];
        }
    }
    return NULL;
}

// Update a user's information in the fitness tracker database
int update_user(fitness_tracker *ft, user *u) {
    user *found_user = find_user(ft, u->username);
    if (found_user == NULL) {
        return -1;
    }
    *found_user = *u;
    return 0;
}

// Delete a user from the fitness tracker database
int delete_user(fitness_tracker *ft, char *username) {
    int index = -1;
    for (int i = 0; i < ft->num_users; i++) {
        if (strcmp(ft->users[i].username, username) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        return -1;
    }
    for (int i = index + 1; i < ft->num_users; i++) {
        ft->users[i - 1] = ft->users[i];
    }
    ft->num_users--;
    return 0;
}

// Print the information of all users in the fitness tracker database
void print_users(fitness_tracker *ft) {
    for (int i = 0; i < ft->num_users; i++) {
        printf("Username: %s\n", ft->users[i].username);
        printf("Password: %s\n", ft->users[i].password);
        printf("Age: %d\n", ft->users[i].age);
        printf("Height: %d\n", ft->users[i].height);
        printf("Weight: %d\n", ft->users[i].weight);
        printf("Steps: %d\n", ft->users[i].steps);
        printf("Calories: %d\n", ft->users[i].calories);
        printf("Distance: %d\n\n", ft->users[i].distance);
    }
}

// Main function
int main() {
    // Create a new fitness tracker database
    fitness_tracker *ft = create_fitness_tracker();

    // Add some users to the database
    user u1 = {"user1", "password1", 20, 170, 70, 10000, 2000, 5};
    add_user(ft, &u1);
    user u2 = {"user2", "password2", 30, 180, 80, 15000, 2500, 6};
    add_user(ft, &u2);

    // Find a user in the database
    user *u = find_user(ft, "user1");
    if (u != NULL) {
        printf("Found user: %s\n", u->username);
    } else {
        printf("User not found\n");
    }

    // Update a user's information in the database
    u->steps = 12000;
    update_user(ft, u);

    // Delete a user from the database
    delete_user(ft, "user2");

    // Print the information of all users in the database
    print_users(ft);

    // Free the memory allocated for the fitness tracker database
    free(ft);

    return 0;
}