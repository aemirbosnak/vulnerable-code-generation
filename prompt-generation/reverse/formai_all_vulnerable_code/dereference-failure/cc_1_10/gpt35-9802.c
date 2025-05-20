//FormAI DATASET v1.0 Category: Mailing list manager ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Struct for storing email addresses and linked list pointers
struct emailNode {
    char email[50];
    struct emailNode* next;
};

//Function for adding an email to the mailing list
void addEmail(struct emailNode** head, char email[]) {
    //Create a new email node
    struct emailNode* newEmail = (struct emailNode*)malloc(sizeof(struct emailNode));
    strcpy(newEmail->email, email);
    newEmail->next = NULL;

    //Check if the mailing list is empty
    if (*head == NULL) {
        *head = newEmail;
        return;
    }

    //Find the last email in the list
    struct emailNode* lastEmail = *head;
    while (lastEmail->next != NULL)
        lastEmail = lastEmail->next;

    //Add the new email to the end of the list
    lastEmail->next = newEmail;
}

//Function for removing an email from the mailing list
void removeEmail(struct emailNode** head, char email[]) {
    //Check if the mailing list is empty
    if (*head == NULL)
        return;

    //Check if the first email is the one to remove
    if (strcmp((*head)->email, email) == 0) {
        struct emailNode* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    //Find the node before the email to remove
    struct emailNode* prevEmail = *head;
    while (prevEmail->next != NULL && strcmp(prevEmail->next->email, email) != 0)
        prevEmail = prevEmail->next;

    //Check if the email was found
    if (prevEmail->next != NULL) {
        struct emailNode* temp = prevEmail->next;
        prevEmail->next = temp->next;
        free(temp);
    }
}

//Function for printing all emails in the mailing list
void printList(struct emailNode* head) {
    //Check if the mailing list is empty
    if (head == NULL) {
        printf("The mailing list is empty.\n");
        return;
    }

    //Iterate through the mailing list and print each email
    struct emailNode* currentEmail = head;
    while (currentEmail != NULL) {
        printf("%s\n", currentEmail->email);
        currentEmail = currentEmail->next;
    }
}

int main() {
    struct emailNode* head = NULL;

    //Add some emails to the mailing list
    addEmail(&head, "example1@gmail.com");
    addEmail(&head, "example2@yahoo.com");
    addEmail(&head, "example3@hotmail.com");
    addEmail(&head, "example4@gmail.com");
    addEmail(&head, "example5@yahoo.com");

    //Print the current mailing list
    printf("Current mailing list:\n");
    printList(head);

    //Remove an email from the mailing list
    printf("Removing example3@hotmail.com from the mailing list...\n");
    removeEmail(&head, "example3@hotmail.com");

    //Print the updated mailing list
    printf("Updated mailing list:\n");
    printList(head);

    return 0;
}