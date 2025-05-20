//FormAI DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void insert(int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Fie! A new data hath been added to thy linked list!\n");
}

void delete(int data) {
    if (head == NULL) {
        printf("Alack! Thy linked list is empty and there is nought to delete.\n");
    } else if (head->data == data) {
        Node *temp = head;
        head = head->next;
        free(temp);
        printf("Hark! The first element hath been deleted from thy linked list.\n");
    } else {
        Node *temp = head;
        while(temp->next != NULL && temp->next->data != data) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            printf("Alackaday! The data thou seeketh is not found in thy linked list.\n");
        } else {
            Node *temp2 = temp->next;
            temp->next = temp2->next;
            free(temp2);
            printf("Gramercy! The data thou seeketh hath been deleted from thy linked list.\n");
        }
    }
}

void display() {
    if (head == NULL) {
        printf("Verily! Thy linked list is empty.\n");
    } else {
        Node *temp = head;
        while(temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    printf("Welcome to thy medieval linketh list operation program!\n");
    while (true) {
        printf("Pray telleth thy command (1. insert, 2. delete, 3. display, 4. exit): ");
        int command, data;
        scanf("%d", &command);
        switch(command) {
            case 1:
                printf("What ho! Pray telleth, what data wouldst thou like to insert: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("Hark! Pray telleth, what data wouldst thou like to delete: ");
                scanf("%d", &data);
                delete(data);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Fare thee well!\n");
                exit(0);
            default:
                printf("Alas! Thou hast entered an invalid command. Pray telleth again!\n");
        }
    }
    return 0;
}