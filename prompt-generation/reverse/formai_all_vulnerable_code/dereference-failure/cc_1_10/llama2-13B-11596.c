//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100

// Structure to store user information
typedef struct {
    char name[MAX_NAME_LEN];
    int age;
} user_info_t;

// Function to print a happy message
void print_happy_message(void) {
    printf("Happiness is contagious! 😊\n");
}

// Function to create a new user
user_info_t create_user(char *name, int age) {
    user_info_t new_user;
    strcpy(new_user.name, name);
    new_user.age = age;
    return new_user;
}

// Function to print user information
void print_user_info(user_info_t user) {
    printf("Name: %s, Age: %d\n", user.name, user.age);
}

// Function to update user information
void update_user_info(user_info_t *user, char *new_name, int new_age) {
    strcpy(user->name, new_name);
    user->age = new_age;
    print_happy_message();
}

// Function to delete a user
void delete_user(user_info_t *user) {
    free(user);
    print_happy_message();
}

int main(void) {
    // Create a new user
    user_info_t user = create_user("Alice", 25);
    print_user_info(user);

    // Update the user's information
    update_user_info(&user, "Bob", 30);
    print_user_info(user);

    // Delete the user
    delete_user(&user);
    print_happy_message();

    return 0;
}