//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_NAME_LENGTH 256
#define MAX_AGE 100

// Structure to hold user information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} user_info_t;

// Function to get user information
user_info_t get_user_info(void) {
    char name[MAX_NAME_LENGTH];
    int age;

    // Get the user's name
    printf("Enter your name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);

    // Convert the name to uppercase
    for (int i = 0; i < strlen(name); i++) {
        name[i] = toupper(name[i]);
    }

    // Get the user's age
    printf("Enter your age: ");
    scanf("%d", &age);

    // Check if the age is valid
    if (age < 0 || age > MAX_AGE) {
        errno = EINVAL; // Set error number
        return (user_info_t) { NULL, 0 }; // Return invalid user info
    }

    return (user_info_t) { name, age }; // Return valid user info
}

// Function to print the user information
void print_user_info(user_info_t user) {
    printf("Your name is: %s\n", user.name);
    printf("Your age is: %d\n", user.age);
}

int main(void) {
    user_info_t user = get_user_info();

    if (user.name == NULL) {
        printf("Error: Invalid name\n");
        return 1;
    }

    print_user_info(user);

    return 0;
}