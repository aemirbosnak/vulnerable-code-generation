//Gemma-7B DATASET v1.0 Category: System administration ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct User {
    char name[MAX_NAME_LENGTH];
    int age;
    struct User* next;
} User;

User* createUser(char* name, int age) {
    User* newUser = malloc(sizeof(User));
    strcpy(newUser->name, name);
    newUser->age = age;
    newUser->next = NULL;
    return newUser;
}

void addUser(User* head, char* name, int age) {
    User* newUser = createUser(name, age);
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

void printUsers(User* head) {
    User* temp = head;
    while (temp) {
        printf("%s (age: %d)\n", temp->name, temp->age);
        temp = temp->next;
    }
}

int main() {
    User* head = NULL;

    addUser(head, "Romeo", 16);
    addUser(head, "Juliet", 15);
    addUser(head, "Benvolio", 17);
    addUser(head, " Mercutio", 18);
    addUser(head, "Tybalt", 19);

    printUsers(head);

    return 0;
}