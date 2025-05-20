//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define node structure for our mailing list
typedef struct mail_node {
    char* email;
    struct mail_node* next;
} mail_node;

// Function to add nodes to the list in sorted order
void add_node(mail_node** head, char* email) {
    mail_node* new_node = (mail_node*) malloc(sizeof(mail_node));
    new_node->email = (char*) malloc(strlen(email)+1);
    strcpy(new_node->email, email);
    new_node->next = NULL;

    if (*head == NULL || strcmp((*head)->email, email) > 0) {
        new_node->next = *head;
        *head = new_node;
    } else {
        mail_node* current_node = *head;
        while (current_node->next != NULL && strcmp(current_node->next->email, email) < 0) {
            current_node = current_node->next;
        }
        new_node->next = current_node->next;
        current_node->next = new_node;
    }
}

// Function to print out all nodes in the list
void print_list(mail_node* head) {
    printf("Mailing List:\n");
    while (head != NULL) {
        printf("%s\n", head->email);
        head = head->next;
    }
}

int main() {
    mail_node* mailing_list = NULL;
    printf("Greetings, my dear friend! Please enter email addresses to add to your mailing list:\n");

    char email[256];
    while (1) {
        printf("Enter email address (or type 'done' to finish):\n");
        scanf("%s", email);
        if (strcmp(email, "done") == 0) {
            break;
        }
        add_node(&mailing_list, email);
    }

    printf("\nThank you my dear friend. Your Mailing List is now ready to use.\n\n");
    print_list(mailing_list);

    return 0;
}