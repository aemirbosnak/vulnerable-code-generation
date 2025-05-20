//FormAI DATASET v1.0 Category: Password management ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct password {
    char service_name[50];
    char password[20];
    struct password *next;
};

struct password *head = NULL;
int pass_count = 0;

//Function to add password
void add_password() {
    struct password *new_password;
    new_password = (struct password *)malloc(sizeof(struct password));
    printf("Enter service name: ");
    scanf("%s", new_password->service_name);
    printf("Enter password: ");
    scanf("%s", new_password->password);
    new_password->next = head;
    head = new_password;
    pass_count++;
}

//Function to display all passwords
void display_all(struct password *node) {
    if(node == NULL) {
        return;
    }
    printf("Service Name: %s\n", node->service_name);
    printf("Password: %s\n", node->password);
    printf("====================\n");
    display_all(node->next);
}

//Function to search for a password
struct password *search_password(struct password *node, char *service) {
    if(node == NULL) {
        return NULL;
    }
    if(strcmp(node->service_name, service) == 0) {
        return node;
    }
    return search_password(node->next, service);
}

//Function to delete a password
void delete_password(struct password *node, char *service) {
    struct password *prev = NULL;
    if(node == NULL) {
        return;
    }
    if(strcmp(node->service_name, service) == 0) {
        head = node->next;
        free(node);
        pass_count--;
        return;
    }
    while(node != NULL && strcmp(node->service_name, service) != 0) {
        prev = node;
        node = node->next;
    }
    if(node == NULL) {
        printf("Password not found!\n");
        return;
    }
    prev->next = node->next;
    free(node);
    pass_count--;
}

int main() {
    int choice;
    char service[50];
    printf("Password Management System\n");
    printf("==========================\n");
    while(1) {
        printf("1. Add New Password\n");
        printf("2. Display All Passwords\n");
        printf("3. Search Password\n");
        printf("4. Delete Password\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: add_password();
                    break;
            case 2: if(head == NULL) {
                        printf("No passwords found!\n");
                    }
                    else {
                        printf("Total Passwords: %d\n", pass_count);
                        printf("====================\n");
                        display_all(head);
                    }
                    break;
            case 3: printf("Enter service name: ");
                    scanf("%s", service);
                    struct password* result = search_password(head, service);
                    if(result == NULL) {
                        printf("Password not found!\n");
                    }
                    else {
                        printf("Service Name: %s\n", result->service_name);
                        printf("Password: %s\n", result->password);
                        printf("====================\n");
                    }
                    break;
            case 4: printf("Enter service name: ");
                    scanf("%s", service);
                    delete_password(head, service);
                    break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}