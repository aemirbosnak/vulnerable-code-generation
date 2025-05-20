//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *name;
    int age;
    double weight;
    double height;
    int steps;
    int calories;
    int distance;
} User;

// Create a new user
User *create_user(char *name, int age, double weight, double height) {
    User *user = malloc(sizeof(User));
    user->name = name;
    user->age = age;
    user->weight = weight;
    user->height = height;
    user->steps = 0;
    user->calories = 0;
    user->distance = 0;
    return user;
}

// Destroy a user
void destroy_user(User *user) {
    free(user->name);
    free(user);
}

// Get the user's name
char *get_user_name(User *user) {
    return user->name;
}

// Get the user's age
int get_user_age(User *user) {
    return user->age;
}

// Get the user's weight
double get_user_weight(User *user) {
    return user->weight;
}

// Get the user's height
double get_user_height(User *user) {
    return user->height;
}

// Get the user's steps
int get_user_steps(User *user) {
    return user->steps;
}

// Get the user's calories
int get_user_calories(User *user) {
    return user->calories;
}

// Get the user's distance
int get_user_distance(User *user) {
    return user->distance;
}

// Set the user's steps
void set_user_steps(User *user, int steps) {
    user->steps = steps;
}

// Set the user's calories
void set_user_calories(User *user, int calories) {
    user->calories = calories;
}

// Set the user's distance
void set_user_distance(User *user, int distance) {
    user->distance = distance;
}

// Update the user's steps, calories, and distance
void update_user(User *user, int steps, int calories, int distance) {
    set_user_steps(user, get_user_steps(user) + steps);
    set_user_calories(user, get_user_calories(user) + calories);
    set_user_distance(user, get_user_distance(user) + distance);
}

// Print the user's information
void print_user(User *user) {
    printf("Name: %s\n", get_user_name(user));
    printf("Age: %d\n", get_user_age(user));
    printf("Weight: %.2lf\n", get_user_weight(user));
    printf("Height: %.2lf\n", get_user_height(user));
    printf("Steps: %d\n", get_user_steps(user));
    printf("Calories: %d\n", get_user_calories(user));
    printf("Distance: %d\n", get_user_distance(user));
}

// Main function
int main() {
    // Create a new user
    User *user = create_user("John Doe", 30, 80.0, 1.80);

    // Update the user's steps, calories, and distance
    update_user(user, 10000, 500, 5);

    // Print the user's information
    print_user(user);

    // Destroy the user
    destroy_user(user);

    return 0;
}