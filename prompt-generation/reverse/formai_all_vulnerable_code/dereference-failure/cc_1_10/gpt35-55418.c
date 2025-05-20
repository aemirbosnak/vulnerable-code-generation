//FormAI DATASET v1.0 Category: Mailing list manager ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 1024

struct MailingList {
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
    int age;
    struct MailingList *next;
};

void addSubscriber(struct MailingList** head, char name[], char email[], int age) {
    struct MailingList* newSubscriber = (struct MailingList*) malloc(sizeof(struct MailingList));
    strcpy(newSubscriber->name, name);
    strcpy(newSubscriber->email, email);
    newSubscriber->age = age;
    newSubscriber->next = (*head);
    (*head) = newSubscriber;
}

void printList(struct MailingList* node) {
    while (node != NULL) {
        printf("%s, %s, %d\n", node->name, node->email, node->age);
        node = node->next;
    }
}

int main() {
    struct MailingList* head = NULL;
    int option = -1;
    char name[MAX_LENGTH], email[MAX_LENGTH];
    int age;

    while (option != 0) {
        printf("Menu\n");
        printf("1. Add Subscriber\n");
        printf("2. Print List\n");
        printf("0. Exit\n");
        printf("Option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Email: ");
                scanf("%s", email);
                printf("Enter Age: ");
                scanf("%d", &age);
                addSubscriber(&head, name, email, age);
                break;
            case 2:
                printList(head);
                break;
            case 0:
                break;
            default:
                printf("Invalid Option\n");
                break;
        }
    }
    return 0;
}