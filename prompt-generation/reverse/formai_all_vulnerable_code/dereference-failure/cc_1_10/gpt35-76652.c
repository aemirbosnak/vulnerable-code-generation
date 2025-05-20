//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ATTACK_THRESHOLD 5 // number of invalid login attempts before triggering an alarm
#define USER_DATABASE_SIZE 10 // maximum number of users in the database

// structure representing each user in the database
struct user {
    char *username;
    char *password;
};

// function signatures
struct user *create_users();
void print_users(struct user *users);
int login(struct user *users, int num_users);
void trigger_alarm();

int main() {
    struct user *users = create_users();
    int num_users = USER_DATABASE_SIZE;
    int num_attempts = 0;
    
    // simulate login attempts
    for(int i = 0; i < 15; i++) {
        int result = login(users, num_users);
        if(result == 1) {
            printf("Login successful!\n");
            break;
        } else if(result == -1) {
            printf("Invalid login attempt.\n");
            num_attempts++;
        }
        if(num_attempts >= ATTACK_THRESHOLD) {
            trigger_alarm();
            break;
        }
        printf("------------------------------\n");
    }

    // deallocate memory
    for(int i = 0; i < num_users; i++) {
        free(users[i].username);
        free(users[i].password);
    }
    free(users);

    return 0;
}

// function to create a database of users
struct user *create_users() {
    struct user *users = malloc(sizeof(struct user) * USER_DATABASE_SIZE);
    for(int i = 0; i < USER_DATABASE_SIZE; i++) {
        users[i].username = malloc(sizeof(char) * 20);
        users[i].password = malloc(sizeof(char) * 20);
        sprintf(users[i].username, "user%d", i+1);
        sprintf(users[i].password, "password%d", i+1);
    }
    return users;
}

// function to print the users in the database
void print_users(struct user *users) {
    printf("Users in the database:\n");
    for(int i = 0; i < USER_DATABASE_SIZE; i++) {
        printf("Username: %s, Password: %s\n", users[i].username, users[i].password);
    }
}

// function to simulate a login attempt
int login(struct user *users, int num_users) {
    srand(time(NULL));
    int index = rand() % num_users;
    char username[20];
    char password[20];
    strcpy(username, users[index].username);
    printf("Attempting login with username: %s\n", username);
    printf("Enter password: ");
    scanf("%s", password);
    printf("\n");
    if(strcmp(password, users[index].password) == 0) {
        return 1; // login successful
    } else {
        return -1; // invalid password
    }
}

// function to trigger an alarm when an attack is detected
void trigger_alarm() {
    for(int i = 0; i < 10; i++) {
        printf("INTRUSION DETECTED!\a\n");
        printf("******************************\n");
    }
}