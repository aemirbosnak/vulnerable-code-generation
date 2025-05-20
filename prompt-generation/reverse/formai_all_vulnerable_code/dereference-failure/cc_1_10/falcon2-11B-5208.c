//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Node definition
struct Node {
    char* email;
    struct Node* next;
};

// Mailing list definition
struct MailingList {
    struct Node* head;
};

// Add a subscriber to the mailing list
void addSubscriber(struct MailingList* list, char* email) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->email = email;
    newNode->next = list->head;

    list->head = newNode;
}

// Remove a subscriber from the mailing list
void removeSubscriber(struct MailingList* list, char* email) {
    struct Node* current = list->head;
    struct Node* previous = NULL;

    while (current!= NULL && strcmp(current->email, email)!= 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Subscriber not found in the mailing list.\n");
        return;
    }

    if (previous == NULL) {
        list->head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
}

// Display the mailing list
void displayList(struct MailingList* list) {
    struct Node* current = list->head;

    while (current!= NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

int main() {
    struct MailingList list;
    list.head = NULL;

    addSubscriber(&list, "subscriber1@example.com");
    addSubscriber(&list, "subscriber2@example.com");
    addSubscriber(&list, "subscriber3@example.com");

    printf("Mailing List:\n");
    displayList(&list);

    removeSubscriber(&list, "subscriber2@example.com");
    printf("Mailing List:\n");
    displayList(&list);

    return 0;
}