//Gemma-7B DATASET v1.0 Category: System administration ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ADMIN_NUM 10

typedef struct Admin {
    char name[20];
    int id;
    struct Admin* next;
} Admin;

Admin* head = NULL;

void addAdmin(char* name, int id) {
    Admin* newAdmin = (Admin*)malloc(sizeof(Admin));
    strcpy(newAdmin->name, name);
    newAdmin->id = id;
    newAdmin->next = NULL;

    if (head == NULL) {
        head = newAdmin;
    } else {
        Admin* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newAdmin;
    }
}

void deleteAdmin(int id) {
    Admin* temp = head;
    Admin* prev = NULL;

    while (temp && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (prev) {
        prev->next = temp->next;
        free(temp);
    } else {
        head = temp->next;
        free(temp);
    }
}

int main() {
    addAdmin("John Doe", 1);
    addAdmin("Jane Doe", 2);
    addAdmin("Peter Pan", 3);
    deleteAdmin(2);

    Admin* currentAdmin = head;
    while (currentAdmin) {
        printf("%s (ID: %d)\n", currentAdmin->name, currentAdmin->id);
        currentAdmin = currentAdmin->next;
    }

    return 0;
}