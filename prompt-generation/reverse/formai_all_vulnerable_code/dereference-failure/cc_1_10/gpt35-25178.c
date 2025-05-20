//FormAI DATASET v1.0 Category: Email Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct Email {
    char sender[50];
    char recipient[50];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

typedef struct LinkedListNode {
    Email email;
    struct LinkedListNode* next;
} LinkedListNode;

typedef struct LinkedList {
    LinkedListNode* head;
    int size;
} LinkedList;

void addEmail(LinkedList* list, Email email) {
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    newNode->email = email;
    newNode->next = NULL;

    if(list->head == NULL) {
        list->head = newNode;
    } else {
        LinkedListNode* curr = list->head;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    list->size++;
}

void printEmail(Email email) {
    printf("Sender: %s\n", email.sender);
    printf("Recipient: %s\n", email.recipient);
    printf("Subject: %s\n", email.subject);
    printf("Body: %s\n", email.body);
}

void printAllEmails(LinkedList list) {
    printf("Number of Emails: %d\n", list.size);
    LinkedListNode* curr = list.head;
    while(curr != NULL) {
        printf("------------------------\n");
        printEmail(curr->email);
        printf("------------------------\n");
        curr = curr->next;
    }
}

int main() {
    LinkedList emails = {NULL, 0};

    Email email1 = {"me@gmail.com", "you@gmail.com", "Hello", "Hey, how are you doing?"};
    Email email2 = {"you@gmail.com", "me@gmail.com", "Re: Hello", "I'm doing well, thanks for asking."};
    Email email3 = {"us@gmail.com", "everyone@gmail.com", "Important Announcement", "Please read attached document."};

    addEmail(&emails, email1);
    addEmail(&emails, email2);
    addEmail(&emails, email3);

    printAllEmails(emails);

    return 0;
}