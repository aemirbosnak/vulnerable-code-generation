//FormAI DATASET v1.0 Category: Password management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function prototypes
void addPassword(char* service, char* password);
void getPassword(char* service);
void deletePassword(char* service);
int checkIfExists(char* service);

//Structure for password storage
struct node {
    char service[20];
    char password[20];
    struct node* next;
};

struct node* head = NULL;

int main() {
    int choice;
    char service[20];
    char password[20];

    //Menu
    printf("Password Manager\n");
    printf("1. Add new password\n");
    printf("2. Retrieve a password\n");
    printf("3. Delete a password\n");
    printf("4. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter service name: ");
                scanf("%s", service);
                printf("Enter password: ");
                scanf("%s", password);
                addPassword(service, password);
                break;
            case 2:
                printf("\nEnter service name: ");
                scanf("%s", service);
                getPassword(service);
                break;
            case 3:
                printf("\nEnter service name: ");
                scanf("%s", service);
                deletePassword(service);
                break;
            case 4:
                printf("\nExiting password manager...\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a valid choice.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void addPassword(char* service, char* password) {
    struct node* temp;

    if (checkIfExists(service)) {
        printf("\nPassword for this service already exists.\n");
        return;
    }

    //Create new node
    temp = (struct node*) malloc(sizeof(struct node));
    strcpy(temp->service, service);
    strcpy(temp->password, password);
    temp->next = NULL;

    //Insert node at the beginning of the list
    if (head == NULL) {
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }

    printf("\nPassword added successfully!\n");
}

void getPassword(char* service) {
    struct node* temp;

    //Search for the service in the list
    temp = head;
    while (temp != NULL) {
        if (strcmp(temp->service, service) == 0) {
            printf("\nService: %s\nPassword: %s\n", temp->service, temp->password);
            return;
        }
        temp = temp->next;
    }

    printf("\nPassword for this service does not exist.\n");
}

void deletePassword(char* service) {
    struct node* temp;
    struct node* prev;

    //Search for the service in the list
    temp = head;
    prev = NULL;
    while (temp != NULL) {
        if (strcmp(temp->service, service) == 0) {
            //Service found, delete the node
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("\nPassword for %s deleted successfully!\n", service);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("\nPassword for this service does not exist.\n");
}

int checkIfExists(char* service) {
    struct node* temp;

    //Search for the service in the list
    temp = head;
    while (temp != NULL) {
        if (strcmp(temp->service, service) == 0) {
            return 1;
        }
        temp = temp->next;
    }

    return 0;
}