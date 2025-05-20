//FormAI DATASET v1.0 Category: Mailing list manager ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    char email[100];
    struct Node* next;
};

struct List {
    struct Node* head;
    int size;
};

struct List* createList() {
    struct List* list = (struct List*) malloc(sizeof(struct List));
    list->head = NULL;
    list->size = 0;
    return list;
}

void insert(struct List* list, char* email) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    strcpy(newNode->email, email);
    newNode->next = NULL;
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Node* currNode = list->head;
        while (currNode->next != NULL) {
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }
    list->size++;
}

void removeEmail(struct List* list, char* email) {
    struct Node* currNode = list->head;
    struct Node* prevNode = NULL;
    while (currNode != NULL) {
        if (strcmp(currNode->email, email) == 0) {
            if (prevNode == NULL) {
                list->head = currNode->next;
            } else {
                prevNode->next = currNode->next;
            }
            free(currNode);
            list->size--;
            return;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}

void printList(struct List* list) {
    if (list->size == 0) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* currNode = list->head;
    while (currNode != NULL) {
        printf("%s\n", currNode->email);
        currNode = currNode->next;
    }
}

int main() {
    struct List* emailList = createList();

    printf("Welcome to the email list manager!\n");
    while (1) {
        printf("\n");
        printf("Enter a command (add, remove, print, exit): ");
        char command[10];
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            printf("Enter an email address: ");
            char email[100];
            scanf("%s", email);
            insert(emailList, email);
            printf("Email address added to the list.\n");
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter an email address to remove: ");
            char email[100];
            scanf("%s", email);
            removeEmail(emailList, email);
            printf("Email address removed from the list.\n");
        } else if (strcmp(command, "print") == 0) {
            printf("Printing email list:\n");
            printList(emailList);
        } else if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            return 0;
        } else {
            printf("Invalid command.\n");
        }
    }
}