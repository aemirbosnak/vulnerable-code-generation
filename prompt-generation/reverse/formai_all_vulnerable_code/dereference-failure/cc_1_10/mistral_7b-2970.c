//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[50];
    char number[20];
    struct Node *next;
} Node;

Node *head = NULL;
Node *current = NULL;

void createNode(char name[], char number[]) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->number, number);
    newNode->next = NULL;
}

void addContact(char name[], char number[]) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    if (head == NULL) {
        head = newNode;
        current = newNode;
    } else {
        current->next = newNode;
        current = newNode;
    }

    createNode(name, number);
}

void displayMenu() {
    printf("\n**** WhizPhone ****\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Search Contact\n");
    printf("4. Delete Contact\n");
    printf("5. Exit\n");
}

void displayContacts() {
    Node *temp = head;

    printf("\nContacts:\n");

    while (temp != NULL) {
        printf("%s: %s\n", temp->name, temp->number);
        temp = temp->next;
    }
}

int main() {
    char name[50], number[20];
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Number: ");
                scanf("%s", number);
                addContact(name, number);
                break;

            case 2:
                displayContacts();
                break;

            case 3:
                printf("Enter Name to Search: ");
                scanf("%s", name);

                Node *search = head;

                while (search != NULL) {
                    if (strcmp(search->name, name) == 0) {
                        printf("\nContact Found!\n");
                        printf("Name: %s\n", search->name);
                        printf("Number: %s\n", search->number);
                        break;
                    }
                    search = search->next;
                }

                if (search == NULL)
                    printf("\nContact Not Found.\n");

                break;

            case 4:
                printf("Enter Name to Delete: ");
                scanf("%s", name);

                Node *prev = NULL;
                Node *temp = head;

                while (temp != NULL && strcmp(temp->name, name) != 0) {
                    prev = temp;
                    temp = temp->next;
                }

                if (temp == NULL)
                    printf("\nContact Not Found.\n");
                else {
                    if (prev == NULL)
                        head = temp->next;
                    else
                        prev->next = temp->next;

                    free(temp);
                    printf("\nContact Deleted.\n");
                }

                break;

            case 5:
                exit(0);

            default:
                printf("\nInvalid Choice. Please Try Again.\n");
        }
    }

    return 0;
}