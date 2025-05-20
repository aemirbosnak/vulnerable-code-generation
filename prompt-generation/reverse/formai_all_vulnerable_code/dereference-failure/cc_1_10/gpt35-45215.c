//FormAI DATASET v1.0 Category: Mailing list manager ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char email[50];
    struct node *next;
} Node;

void append(Node **head_ref, char *new_email) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->email, new_email);
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    Node *last_node = *head_ref;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

void display(Node *node) {
    printf("Mailing List:\n");
    while (node != NULL) {
        printf("%s\n", node->email);
        node = node->next;
    }
}

int main() {
    Node *mailing_list = NULL;

    // Add some emails to mailing_list
    append(&mailing_list, "example1@gmail.com");
    append(&mailing_list, "example2@yahoo.com");
    append(&mailing_list, "example3@hotmail.com");

    // Display mailing_list
    display(mailing_list);

    // Add a new email to mailing_list
    printf("Enter a new email: ");
    char new_email[50];
    scanf("%s", new_email);
    append(&mailing_list, new_email);

    // Display mailing_list again
    display(mailing_list);

    return 0;
}