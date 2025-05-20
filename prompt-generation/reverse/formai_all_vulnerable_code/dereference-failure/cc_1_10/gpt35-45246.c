//FormAI DATASET v1.0 Category: Mailing list manager ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char email[50];
    struct Node* next;
} Node;

Node* createNode(char* email) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->email, email);
    newNode->next = NULL;
    return newNode;
}

Node* addEmail(Node* head, char* email) {
    Node* newNode = createNode(email);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

Node* deleteEmail(Node* head, char* email) {
    if (head == NULL) {
        return NULL;
    }
    Node* temp = head;
    if (strcmp(temp->email, email) == 0) {
        head = head->next;
        free(temp);
    } else {
        while (temp->next != NULL) {
            if (strcmp(temp->next->email, email) == 0) {
                Node* toBeDeleted = temp->next;
                temp->next = toBeDeleted->next;
                free(toBeDeleted);
                break;
            }
            temp = temp->next;
        }
    }
    return head;
}

Node* searchEmail(Node* head, char* email) {
    Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->email, email) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void printList(Node* head) {
    if (head == NULL) {
        printf("The mailing list is empty.\n");
    } else {
        printf("Mailing list:\n");
        Node* temp = head;
        while (temp != NULL) {
            printf("- %s\n", temp->email);
            temp = temp->next;
        }
    }
}

int main() {
    Node* mailingList = NULL;
    char op, email[50];
    do {
        printf("\nMenu:\n");
        printf("1) Add email address\n");
        printf("2) Delete email address\n");
        printf("3) Search email address\n");
        printf("4) Print mailing list\n");
        printf("0) Exit\n");
        printf("Enter operation: ");
        scanf(" %c", &op);
        switch (op) {
            case '1':
                printf("Enter email address to add: ");
                scanf("%s", email);
                mailingList = addEmail(mailingList, email);
                printf("Email address added!\n");
                break;
            case '2':
                printf("Enter email address to delete: ");
                scanf("%s", email);
                mailingList = deleteEmail(mailingList, email);
                printf("Email address deleted!\n");
                break;
            case '3':
                printf("Enter email address to search: ");
                scanf("%s", email);
                Node* found = searchEmail(mailingList, email);
                if (found == NULL) {
                    printf("Email address not found.\n");
                } else {
                    printf("Email address found!\n");
                }
                break;
            case '4':
                printList(mailingList);
                break;
            case '0':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid operation.\n");
                break;
        }
    } while (op != '0');
    return 0;
}