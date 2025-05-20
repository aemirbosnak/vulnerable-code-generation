//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct Intrusion {
    char username[MAX_USERNAME_LENGTH];
    char message[100];
};

struct IntrusionLog {
    struct Intrusion *intrusion;
    int count;
    int size;
};

void add_intrusion(struct IntrusionLog *log, char *username, char *message) {
    if (log->count == log->size) {
        log->size *= 2;
        log->intrusion = realloc(log->intrusion, log->size * sizeof(struct Intrusion));
    }
    strncpy(log->intrusion[log->count].username, username, MAX_USERNAME_LENGTH);
    strncpy(log->intrusion[log->count].message, message, 100);
    log->count++;
}

void check_intrusions(struct IntrusionLog *log) {
    for (int i = 0; i < log->count; i++) {
        printf("Intrusion detected for user %s: %s\n", log->intrusion[i].username, log->intrusion[i].message);
    }
}

int main() {
    struct User users[3];
    strcpy(users[0].username, "admin");
    strcpy(users[0].password, "admin123");
    strcpy(users[1].username, "user");
    strcpy(users[1].password, "password");
    strcpy(users[2].username, "test");
    strcpy(users[2].password, "test");

    struct IntrusionLog log;
    log.size = 10;
    log.intrusion = malloc(log.size * sizeof(struct Intrusion));
    log.count = 0;

    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username:\n");
    scanf("%s", username);

    int index = -1;
    for (int i = 0; i < 3; i++) {
        if (strcmp(users[i].username, username) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        add_intrusion(&log, username, "Invalid username entered");
        check_intrusions(&log);
        return 1;
    }

    printf("Enter password:\n");
    scanf("%s", password);

    if (strcmp(users[index].password, password) != 0) {
        add_intrusion(&log, username, "Invalid password entered");
        check_intrusions(&log);
        return 1;
    }

    printf("Welcome, %s!\n", username);

    return 0;
}