//Gemma-7B DATASET v1.0 Category: System administration ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct SystemAdmin {
    char username[MAX_BUFFER_SIZE];
    char password[MAX_BUFFER_SIZE];
    char email[MAX_BUFFER_SIZE];
    int id;
    struct SystemAdmin *next;
} SystemAdmin;

SystemAdmin *createSystemAdmin() {
    SystemAdmin *newAdmin = (SystemAdmin *)malloc(sizeof(SystemAdmin));
    newAdmin->username[0] = '\0';
    newAdmin->password[0] = '\0';
    newAdmin->email[0] = '\0';
    newAdmin->id = 0;
    newAdmin->next = NULL;
    return newAdmin;
}

void addSystemAdmin(SystemAdmin *head, SystemAdmin *newAdmin) {
    if (head == NULL) {
        head = newAdmin;
    } else {
        newAdmin->next = head;
        head = newAdmin;
    }
}

void listSystemAdmins(SystemAdmin *head) {
    SystemAdmin *currAdmin = head;
    while (currAdmin) {
        printf("Username: %s, Email: %s, ID: %d\n", currAdmin->username, currAdmin->email, currAdmin->id);
        currAdmin = currAdmin->next;
    }
}

int main() {
    SystemAdmin *head = NULL;
    SystemAdmin *newAdmin = createSystemAdmin();
    addSystemAdmin(head, newAdmin);

    newAdmin = createSystemAdmin();
    addSystemAdmin(head, newAdmin);

    listSystemAdmins(head);

    return 0;
}