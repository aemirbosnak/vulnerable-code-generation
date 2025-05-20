//FormAI DATASET v1.0 Category: Email Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct message_s {
    int id;
    char from[50];
    char to[50];
    char subject[100];
    char content[500];
} message;
 
void print_logo() {
    printf("   ,;'';;,   \n");
    printf("  ; ;;'; ;;'  Email Client in the Middle Ages \n");
    printf(" ;; ;;; ;;;;  Version: 1.0 \n");
    printf("  ,;; ;;' ;;\n");
    printf("     ';;,;;' \n\n");
}
 
void send_message(message* msg) {
    // Code for sending a pigeon with a message attached
    printf("Your message to %s has been sent by pigeon carrier\n", msg->to);
}
 
void receive_message(message** inbox, int* num_messages) {
    // Code for receiving a pigeon with a message attached
    // and adding it to the inbox
    printf("A pigeon has arrived with a new message\n");
    (*num_messages)++;
    message* new_inbox = realloc(*inbox, (*num_messages) * sizeof(message));
    if (new_inbox != NULL) {
        *inbox = new_inbox;
        message* msg = &(*inbox)[*num_messages - 1];
        msg->id = *num_messages;
        strcpy(msg->from, "anonymous");
        printf("Please enter the recipient: ");
        scanf("%s", msg->to);
        printf("Please enter the subject: ");
        scanf("%s", msg->subject);
        printf("Please enter the message content: ");
        scanf("%s", msg->content);
    } else {
        printf("Could not allocate memory for message.");
    }
}
 
void view_inbox(message* inbox, int num_messages) {
    printf("Inbox contains %d messages:\n", num_messages);
    for (int i = 0; i < num_messages; i++) {
        printf("Message %d - From: %s, To: %s, Subject: %s\n", inbox[i].id, 
            inbox[i].from, inbox[i].to, inbox[i].subject);
    }
    printf("\n");
}
 
void delete_message(message** inbox, int* num_messages, int id) {
    // Code for releasing the pigeon back into the wild, with the message attached
    // and removing the message from the inbox
    int found = 0;
    for (int i = 0; i < *num_messages; i++) {
        if ((*inbox)[i].id == id) {
            found = 1;
            printf("Message %d - From: %s, To: %s, Subject: %s\n",
                (*inbox)[i].id, (*inbox)[i].from, (*inbox)[i].to, (*inbox)[i].subject);
            printf("Message has been deleted and the pigeon was released.\n");
            for (int j = i; j < *num_messages - 1; j++) {
                (*inbox)[j] = (*inbox)[j + 1];
                (*inbox)[j].id--;
            }
            (*num_messages)--;
            message* new_inbox = realloc(*inbox, (*num_messages) * sizeof(message));
            if (new_inbox != NULL) {
                *inbox = new_inbox;
            }
            break;
        }
    }
    if (!found) {
        printf("Message with id %d not found\n", id);
    }
}
 
int main() {
    message* inbox = NULL;
    int num_messages = 0;
    int choice = -1;
 
    print_logo();
 
    while (choice != 0) {
        printf("What would you like to do?\n");
        printf("1. Send a message\n");
        printf("2. Receive a message\n");
        printf("3. View Inbox\n");
        printf("4. Delete message\n");
        printf("0. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
        switch (choice) {
            case 1: {
                message msg;
                strcpy(msg.from, "anonymous");
                printf("Please enter the recipient: ");
                scanf("%s", msg.to);
                printf("Please enter the subject: ");
                scanf("%s", msg.subject);
                printf("Please enter the message content: ");
                scanf("%s", msg.content);
                send_message(&msg);
                break;
            }
            case 2:
                receive_message(&inbox, &num_messages);
                break;
            case 3:
                view_inbox(inbox, num_messages);
                break;
            case 4:
                printf("Please enter the id of the message you want to delete: ");
                int id;
                scanf("%d", &id);
                delete_message(&inbox, &num_messages, id);
                break;
            case 0:
                printf("Exiting Medieval Email Client. Thanks for using!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        printf("\n");
    }
 
    free(inbox);
 
    return 0;
}