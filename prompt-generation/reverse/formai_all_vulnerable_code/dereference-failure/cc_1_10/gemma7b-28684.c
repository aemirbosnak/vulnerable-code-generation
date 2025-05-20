//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 100

typedef struct Node {
    char name[20];
    struct Node* next;
} Node;

struct ListManager {
    Node* head;
    int size;
    char** mailList;
};

void insertNode(struct ListManager* listManager, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (listManager->head == NULL) {
        listManager->head = newNode;
    } else {
        Node* temp = listManager->head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    listManager->size++;
}

void printList(struct ListManager* listManager) {
    Node* temp = listManager->head;
    while (temp) {
        printf("%s ", temp->name);
        temp = temp->next;
    }
    printf("\n");
}

void manageMailList(struct ListManager* listManager) {
    printf("Enter the name of the recipient: ");
    char* name = malloc(20);
    scanf("%s", name);
    insertNode(listManager, name);

    printf("Enter the subject of the mail: ");
    char* subject = malloc(20);
    scanf("%s", subject);

    printf("Enter the message of the mail: ");
    char* message = malloc(200);
    scanf("%s", message);

    // Send the mail
    printf("Mail sent to %s with subject %s and message %s\n", name, subject, message);
}

int main() {
    struct ListManager* listManager = (struct ListManager*)malloc(sizeof(struct ListManager));
    listManager->head = NULL;
    listManager->size = 0;
    listManager->mailList = NULL;

    manageMailList(listManager);

    printList(listManager);

    return 0;
}