//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Subscriber {
    char name[50];
    char email[100];
} Subscriber;

typedef struct Node {
    Subscriber data;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
    int size;
} List;

List mailingList = {NULL, NULL, 0};

void addSubscriber(Subscriber subscriber) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = subscriber;
    newNode->next = NULL;

    if (mailingList.head == NULL) {
        mailingList.head = newNode;
        mailingList.tail = newNode;
    } else {
        mailingList.tail->next = newNode;
        mailingList.tail = newNode;
    }

    mailingList.size++;
}

void removeSubscriber(char* email) {
    Node* current = mailingList.head;
    Node* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->data.email, email) == 0) {
            if (previous == NULL) {
                mailingList.head = current->next;
            } else {
                previous->next = current->next;
            }

            if (current == mailingList.tail) {
                mailingList.tail = previous;
            }

            free(current);
            mailingList.size--;
            break;
        }
        previous = current;
        current = current->next;
    }
}

void printMailingList() {
    Node* current = mailingList.head;

    printf("Mailing List (\n");
    while (current != NULL) {
        printf("Name: %s, Email: %s\n", current->data.name, current->data.email);
        current = current->next;
    }
    printf(")\n");
}

int main() {
    Subscriber newSubscriber = {"John Doe", "johndoe@example.com"};

    addSubscriber(newSubscriber);

    Subscriber anotherSubscriber = {"Jane Doe", "janedoe@example.com"};
    addSubscriber(anotherSubscriber);

    printMailingList();

    removeSubscriber("johndoe@example.com");

    printMailingList();

    return 0;
}