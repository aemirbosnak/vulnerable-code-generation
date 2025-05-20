//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Macro to ensure safety checks on inputs and outputs
#define CHECK_NULL(ptr) if ((ptr) == NULL) { \
                            fprintf(stderr, "Memory allocation failed at %s:%d\n", __FILE__, __LINE__); \
                            exit(EXIT_FAILURE); \
                        }
#ifdef DEBUG
#define LOG(msg) printf("DEBUG: %s:%d: %s\n", __FILE__, __LINE__, msg)
#else
#define LOG(msg)
#endif

// Structure to hold user data
typedef struct {
    char* username;
    char* password;
} UserData;

// Function declarations
UserData* create_user(const char* username, const char* password);
void delete_user(UserData* user);
void encrypt_password(char* password);
void paranoid_check(UserData* user);
void handle_memory_leak(UserData* user);

int main() {
    LOG("Program started");

    char username[50];
    char password[50];
    
    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);
    strtok(username, "\n"); // Remove newline character

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    strtok(password, "\n"); // Remove newline character

    LOG("User input received");

    UserData* user = create_user(username, password);
    paranoid_check(user);

    // Simulate an operation on user data
    encrypt_password(user->password);
    printf("Secure data has been processed...\n");

    handle_memory_leak(user);
    delete_user(user);
    return 0;
}

UserData* create_user(const char* username, const char* password) {
    LOG("Creating new user");
    
    UserData* user = (UserData*)malloc(sizeof(UserData));
    CHECK_NULL(user);

    user->username = (char*)malloc(strlen(username) + 1);
    CHECK_NULL(user->username);
    strcpy(user->username, username);

    user->password = (char*)malloc(strlen(password) + 1);
    CHECK_NULL(user->password);
    strcpy(user->password, password);

    return user;
}

void delete_user(UserData* user) {
    LOG("Deleting user data");

    if (user) {
        free(user->username);
        free(user->password);
        free(user);
    }
}

void encrypt_password(char* password) {
    LOG("Encrypting password");
    
    // A simple encryption by shifting characters
    for (int i = 0; password[i] != '\0'; ++i) {
        password[i] += 3; // Shift each character by 3
    }
    printf("Your encrypted password is: %s\n", password);
}

void paranoid_check(UserData* user) {
    LOG("Performing paranoid checks");

    if (!user->username || !user->password) {
        fprintf(stderr, "Security breach detected: User data is compromised.\n");
        exit(EXIT_FAILURE);
    }

    printf("User validation successful: %s\n", user->username);
}

void handle_memory_leak(UserData* user) {
    LOG("Checking for memory leaks");

    if (user != NULL) {
        printf("Warning: Memory leak detected, user structure is still present!\n");
    } else {
        printf("Clean: No memory leaks, user structure is freed.\n");
    }
}