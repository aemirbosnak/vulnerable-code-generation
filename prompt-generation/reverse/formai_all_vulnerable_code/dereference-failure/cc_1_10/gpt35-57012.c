//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_ATTEMPTS 10

struct User {
    char username[20];
    char password[20];
};

struct LoginAttempt {
    char username[20];
    char password[20];
    struct tm time;
};

struct User users[MAX_USERS];
struct LoginAttempt attempts[MAX_ATTEMPTS];
int numUsers = 0;
int numAttempts = 0;

void addUser(char* username, char* password) {
    if (numUsers < MAX_USERS) {
        strcpy(users[numUsers].username, username);
        strcpy(users[numUsers].password, password);
        numUsers++;
    }
}

void logAttempt(char* username, char* password) {
    if (numAttempts < MAX_ATTEMPTS) {
        strcpy(attempts[numAttempts].username, username);
        strcpy(attempts[numAttempts].password, password);
        time_t t = time(NULL);
        attempts[numAttempts].time = *localtime(&t);
        numAttempts++;
    }
}

void checkForIntrusion(char* username) {
    int numFailedAttempts = 0;
    for (int i = 0; i < numAttempts; i++) {
        if (strcmp(attempts[i].username, username) == 0) {
            if (strcmp(attempts[i].password, users[i].password) != 0) {
                numFailedAttempts++;
            }
        }
    }
    if (numFailedAttempts >= 5) {
        printf("INTRUSION DETECTED!\n");
    }
}

int main() {
    addUser("Alice", "pa55w0rd");
    addUser("Bob", "qwerty");
    addUser("Eve", "hunter2");

    logAttempt("Alice", "letmein");
    logAttempt("Bob", "password");
    logAttempt("Eve", "password");
    logAttempt("Alice", "password");
    logAttempt("Bob", "password");
    logAttempt("Eve", "password");
    logAttempt("Alice", "password");
    logAttempt("Bob", "password");
    logAttempt("Eve", "password");
    logAttempt("Alice", "password");

    checkForIntrusion("Alice");
    checkForIntrusion("Bob");
    checkForIntrusion("Eve");
    return 0;
}