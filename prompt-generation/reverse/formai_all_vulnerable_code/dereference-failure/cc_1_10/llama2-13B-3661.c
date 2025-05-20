//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100

// Structure to hold user information
typedef struct {
    char name[MAX_NAME_LEN];
    int age;
} user_info_t;

// Function to get user information
user_info_t get_user_info(void) {
    user_info_t user;

    // Check if the user's name is valid
    if (strlen(user.name) > MAX_NAME_LEN) {
        printf("Error: Name too long\n");
        return user;
    }

    // Check if the user's age is valid
    if (user.age < 0 || user.age > MAX_AGE) {
        printf("Error: Age must be positive and less than or equal to %d\n", MAX_AGE);
        return user;
    }

    // Get the user's name and age
    printf("Enter your name: ");
    fgets(user.name, MAX_NAME_LEN, stdin);
    user.age = atoi(stdin);

    return user;
}

int main(void) {
    user_info_t user;

    // Get the user's information
    user = get_user_info();

    // Print the user's information
    printf("Your name is: %s\n", user.name);
    printf("Your age is: %d\n", user.age);

    return 0;
}