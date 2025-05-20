//FormAI DATASET v1.0 Category: Email Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct email {
    char sender[50];
    char receiver[50];
    char subject[100];
    char body[1000];
};

typedef struct email Email;

void add_email(Email* ptr, char* s, char* r, char* sub, char* b) {
    strcpy(ptr->sender, s);
    strcpy(ptr->receiver, r);
    strcpy(ptr->subject, sub);
    strcpy(ptr->body, b);
}

void display_email(Email* ptr) {
    printf("Sender: %s\n", ptr->sender);
    printf("Receiver: %s\n", ptr->receiver);
    printf("Subject: %s\n", ptr->subject);
    printf("Body: %s\n", ptr->body);
}

char* get_subject(Email* ptr) {
    return ptr->subject;
}

// Linked List implementation to store emails
struct ListNode {
    Email data;
    struct ListNode* next;
};

typedef struct ListNode ListNode;

ListNode* insert_at_front(ListNode* head, Email* e) {
    ListNode* new_node = (ListNode*) malloc(sizeof(ListNode));
    new_node->data = *e;
    new_node->next = head;

    return new_node;
}

ListNode* delete_at_front(ListNode* head) {
    if (head == NULL)
        return NULL;

    ListNode* temp = head;
    head = head->next;
    free(temp);

    return head;
}

void display_list(ListNode* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List of emails:\n");
    while (head != NULL) {
        display_email(&head->data);
        head = head->next;
    }
}

void delete_list(ListNode* head) {
    ListNode* curr = head;
    while (curr != NULL) {
        ListNode* temp = curr;
        curr = curr->next;
        free(temp);
    }
}

int main() {
    ListNode* head = NULL;

    printf("Welcome to the C Email Client!\n\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Compose an email\n");
        printf("2. View inbox\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Email* e = (Email*) malloc(sizeof(Email));
                printf("\nEnter sender address:\n");
                scanf("%s", e->sender);
                printf("Enter receiver address:\n");
                scanf("%s", e->receiver);
                printf("Enter subject:\n");
                scanf(" %[^\n]s", e->subject);
                printf("Enter body:\n");
                scanf(" %[^\n]s", e->body);

                head = insert_at_front(head, e);
                printf("\nEmail composed and added to inbox!\n");
                break;
            }
            case 2: {
                display_list(head);
                break;
            }
            case 3: {
                delete_list(head);
                printf("\nGoodbye!\n");
                exit(0);
            }
            default: {
                printf("\nInvalid choice. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}