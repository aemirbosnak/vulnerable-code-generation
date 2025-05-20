//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOGIN_TRIES 3
#define MAX_USERNAME_LENGTH 30
#define MAX_PASSWORD_LENGTH 30
#define SECRET_PASSWORD "LetMeIn"

void displayWelcome();
void performLogin();
int validateCredentials(const char* inputUsername, const char* inputPassword);
void simulateParanoia();
void logAttempt(const char* username, int success);
void silentAlert();

int main() {
    displayWelcome();
    performLogin();
    return 0;
}

void displayWelcome() {
    printf("****************************************\n");
    printf("* Welcome to the Overly Paranoid System *\n");
    printf("****************************************\n");
    printf("* Warning: Your actions are being monitored. *\n");
    printf("****************************************\n");
}

void performLogin() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int tries = 0;
    int authenticated = 0;

    while (tries < MAX_LOGIN_TRIES && !authenticated) {
        printf("Enter your username: ");
        fgets(username, MAX_USERNAME_LENGTH, stdin);
        username[strcspn(username, "\n")] = 0;  // Remove trailing newline

        printf("Enter your password: ");
        fgets(password, MAX_PASSWORD_LENGTH, stdin);
        password[strcspn(password, "\n")] = 0;  // Remove trailing newline

        authenticated = validateCredentials(username, password);
        logAttempt(username, authenticated);
        
        if (!authenticated) {
            printf("Failed login attempt %d/%d. \n", ++tries, MAX_LOGIN_TRIES);
            silentAlert();  // Simulate alerting user about suspicious activity
            simulateParanoia();  // Function to add paranoia aspects
        }
    }

    if (authenticated) {
        printf("Login successful!\n");
    } else {
        printf("Too many failed attempts. Exiting...\n");
        exit(EXIT_FAILURE);
    }
}

int validateCredentials(const char* inputUsername, const char* inputPassword) {
    char safeUsername[MAX_USERNAME_LENGTH] = "user123";  // Pre-set username
    return (strcmp(inputUsername, safeUsername) == 0 && strcmp(inputPassword, SECRET_PASSWORD) == 0);
}

void simulateParanoia() {
    // Randomly print paranoia messages
    const char* paranoiaMessages[] = {
        "Did you hear that? Someone might be watching you!",
        "Are you sure your password is safe?",
        "Your connection could be compromised!",
        "Do you feel like someone is following you?",
        "Always change your passwords regularly!"
    };

    srand(time(NULL)); // Seed for randomness
    int messageIndex = rand() % (sizeof(paranoiaMessages) / sizeof(paranoiaMessages[0]));
    printf("<< Alert >>: %s\n", paranoiaMessages[messageIndex]);
}

void logAttempt(const char* username, int success) {
    FILE *logFile = fopen("login_attempts.log", "a");
    if (logFile != NULL) {
        time_t now = time(NULL);
        char* timeStr = ctime(&now);
        timeStr[strcspn(timeStr, "\n")] = 0; // Remove trailing newline
        fprintf(logFile, "Timestamp: %s, Username: %s, Success: %s\n", timeStr, username, success ? "Yes" : "No");
        fclose(logFile);
    } else {
        printf("Could not open log file for writing.\n");
    }
}

void silentAlert() {
    printf("<< Silent Alert >>: An unknown login attempt was detected!\n");
}