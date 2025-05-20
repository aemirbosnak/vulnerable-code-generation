//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a struct to hold password information
struct password {
    char *username;
    char *password;
    int age;
};

// Define a function to generate a random password
void generate_password(struct password *pwd) {
    int i, j, len = 10;
    char pass[10];

    for (i = 0; i < len; i++) {
        pass[i] = 'a' + (rand() % 26);
    }

    pwd->password = pass;
    pwd->age = time(NULL);
}

// Define a function to check if a password is valid
int check_password(struct password *pwd, char *input) {
    int i, j, len = strlen(input);

    for (i = 0; i < len; i++) {
        if (pwd->password[i] != input[i]) {
            return 0;
        }
    }

    return 1;
}

// Define a function to display the password information
void display_password(struct password *pwd) {
    printf("Username: %s\n", pwd->username);
    printf("Password: %s\n", pwd->password);
    printf("Age: %d\n", pwd->age);
}

int main() {
    struct password pwd;

    // Initialize the password struct
    pwd.username = "admin";
    pwd.password = "123456";
    pwd.age = 0;

    // Generate a new password
    generate_password(&pwd);

    // Check if the new password is valid
    if (!check_password(&pwd, "123456")) {
        printf("Invalid password. Try again!\n");
        return 1;
    }

    // Display the password information
    display_password(&pwd);

    return 0;
}