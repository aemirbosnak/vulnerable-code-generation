//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: complex
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct MailList {
    char name[MAX_SIZE];
    char address[MAX_SIZE];
    char email[MAX_SIZE];
    struct MailList* next;
} MailList;

void addMail(MailList** head) {
    MailList* newNode = (MailList*)malloc(sizeof(MailList));
    printf("Enter name: ");
    scanf("%s", newNode->name);
    printf("Enter address: ");
    scanf("%s", newNode->address);
    printf("Enter email: ");
    scanf("%s", newNode->email);

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
    *head = newNode;
}

void displayMail(MailList* head) {
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Address: %s\n", head->address);
        printf("Email: %s\n", head->email);
        printf("\n");
        head = head->next;
    }
}

int main() {
    MailList* head = NULL;
    int choice;

    printf("Enter 1 to add a new mail, 2 to display all mail: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addMail(&head);
            break;
        case 2:
            displayMail(head);
            break;
        default:
            printf("Invalid input.\n");
    }

    return 0;
}