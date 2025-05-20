//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONNECT 10

typedef struct User {
    char name[20];
    int heart_rate;
    int steps_taken;
    struct User* next;
} User;

User* head = NULL;

void insertUser(char* name, int heart_rate, int steps_taken) {
    User* newUser = (User*)malloc(sizeof(User));
    strcpy(newUser->name, name);
    newUser->heart_rate = heart_rate;
    newUser->steps_taken = steps_taken;
    newUser->next = NULL;

    if (head == NULL) {
        head = newUser;
    } else {
        User* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newUser;
    }
}

void updateUser(char* name, int heart_rate, int steps_taken) {
    User* temp = head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            temp->heart_rate = heart_rate;
            temp->steps_taken = steps_taken;
            return;
        }
        temp = temp->next;
    }
    printf("User not found.\n");
}

void showUsers() {
    User* temp = head;
    while (temp) {
        printf("Name: %s, Heart Rate: %d, Steps Taken: %d\n", temp->name, temp->heart_rate, temp->steps_taken);
        temp = temp->next;
    }
}

int main() {
    insertUser("John Doe", 70, 1000);
    insertUser("Jane Doe", 60, 1200);
    insertUser("Peter Pan", 80, 1400);

    updateUser("John Doe", 65, 1100);

    showUsers();

    return 0;
}