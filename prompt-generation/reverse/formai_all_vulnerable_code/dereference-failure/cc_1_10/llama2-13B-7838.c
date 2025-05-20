//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a struct to store password information
typedef struct {
    char *username;
    char *password;
    int age;
} user_info;

// Function to create a new user
user_info *create_user(char *name, char *pass) {
    user_info *new_user = (user_info *)malloc(sizeof(user_info));
    new_user->username = name;
    new_user->password = pass;
    new_user->age = 0;
    return new_user;
}

// Function to login to the system
int login(user_info *user) {
    // Generate a random password age
    user->age++;

    // Check if the password is still valid
    if (user->age % 2 == 0) {
        printf("Password expired! Please update your password now.\n");
        return 0;
    }

    // Password is still valid, return 1
    return 1;
}

// Function to update the password
void update_password(user_info *user, char *new_pass) {
    // Generate a new password age
    user->age++;

    // Update the password
    user->password = new_pass;
}

// Function to display the user information
void display_user(user_info *user) {
    printf("Welcome, %s!\n", user->username);
    printf("Your password is: %s\n", user->password);
    printf("Your age is: %d\n", user->age);
}

int main() {
    // Create a new user
    user_info *user = create_user("Happy", "Cat");

    // Login to the system
    if (login(user)) {
        printf("Logged in successfully! 😊\n");
    } else {
        printf("Password expired! Please update your password now.\n");
    }

    // Update the password
    update_password(user, "HappyKitty");

    // Display the user information
    display_user(user);

    return 0;
}