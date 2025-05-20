//Gemma-7B DATASET v1.0 Category: System administration ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_USER_NAME_LENGTH 255

typedef struct UserInfo {
    char userName[MAX_USER_NAME_LENGTH];
    int userId;
    struct UserInfo* next;
} UserInfo;

typedef struct SystemAdmin {
    UserInfo* head;
    int numUsers;
    struct SystemAdmin* next;
} SystemAdmin;

SystemAdmin* createSystemAdmin() {
    SystemAdmin* sysAdmin = malloc(sizeof(SystemAdmin));
    sysAdmin->head = NULL;
    sysAdmin->numUsers = 0;
    sysAdmin->next = NULL;
    return sysAdmin;
}

void addUser(SystemAdmin* sysAdmin, char* userName, int userId) {
    UserInfo* newUser = malloc(sizeof(UserInfo));
    strcpy(newUser->userName, userName);
    newUser->userId = userId;
    newUser->next = NULL;

    if (sysAdmin->head == NULL) {
        sysAdmin->head = newUser;
    } else {
        sysAdmin->head->next = newUser;
    }
    sysAdmin->numUsers++;
}

void printUsers(SystemAdmin* sysAdmin) {
     UserInfo* currUser = sysAdmin->head;
    while (currUser) {
        printf("%s (%d)\n", currUser->userName, currUser->userId);
        currUser = currUser->next;
    }
}

int main() {
    SystemAdmin* sysAdmin = createSystemAdmin();
    addUser(sysAdmin, "John Doe", 1);
    addUser(sysAdmin, "Jane Doe", 2);
    addUser(sysAdmin, "Peter Pan", 3);

    printUsers(sysAdmin);

    return 0;
}