//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: puzzling
#include <stdio.h>
#include <string.h>

struct User {
    char username[20];
    char password[20];
    int session_key;
};

void add_user(struct User* users, int num_users, char* username, char* password) {
    int i;
    for (i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Username already exists\n");
            return;
        }
    }
    strcpy(users[num_users].username, username);
    strcpy(users[num_users].password, password);
    users[num_users].session_key = 0;
    num_users++;
}

void authenticate(struct User* users, int num_users, char* username, char* password) {
    int i;
    for (i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            users[i].session_key = rand() % 1000;
            return;
        }
    }
    printf("Invalid username or password\n");
}

int vote(struct User* users, int num_users, char* candidate) {
    int i;
    for (i = 0; i < num_users; i++) {
        if (users[i].session_key == 0) {
            printf("Invalid session key\n");
            return -1;
        }
        if (strcmp(users[i].username, candidate) == 0) {
            users[i].session_key = 0;
            return 1;
        }
    }
    printf("Invalid username\n");
    return -1;
}

int count_votes(struct User* users, int num_users) {
    int i, total_votes = 0;
    char candidates[100];
    for (i = 0; i < num_users; i++) {
        if (users[i].session_key == 0) {
            total_votes++;
        } else {
            strcat(candidates, " ");
            strcat(candidates, users[i].username);
        }
    }
    printf("Votes for %s: %d\n", candidates, total_votes);
    return total_votes;
}

void error_handler(int error_code) {
    switch (error_code) {
        case -1:
            printf("Invalid username or password\n");
            break;
        case -2:
            printf("Invalid session key\n");
            break;
        case -3:
            printf("Invalid username\n");
            break;
    }
}

int main() {
    struct User users[100];
    int num_users = 0;
    char username[20], password[20], candidate[20];

    printf("What is the length of a registration program?\n");
    add_user(users, num_users, username, password);
    printf("What is the length of an authentication program?\n");
    authenticate(users, num_users, username, password);
    printf("What is the length of a voting program?\n");
    vote(users, num_users, candidate);
    printf("What is the length of a result counting program?\n");
    count_votes(users, num_users);

    return 0;
}