//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a Knight and their Messages
typedef struct Message {
    char content[256];
    struct Message *next;
} Message;

typedef struct Knight {
    char name[50];
    Message *inbox;
    struct Knight *next;
} Knight;

// Function Prototypes
void send_message(Knight *knights, const char *sender_name, const char *receiver_name, const char *content);
void receive_messages(Knight *knights, const char *knight_name);
Knight* find_knight(Knight *head, const char *name);
void add_knight(Knight **head, const char *name);
void free_knights(Knight *head);

int main() {
    // The Round Table of Knights
    Knight *knights = NULL;
    
    // Add some knights
    add_knight(&knights, "Sir Lancelot");
    add_knight(&knights, "Lady Guinevere");
    add_knight(&knights, "Sir Gawain");
    add_knight(&knights, "Wizard Merlin");

    // Sending messages between knights
    send_message(knights, "Sir Lancelot", "Lady Guinevere", "My heart rides upon the wings of your beauty!");
    send_message(knights, "Lady Guinevere", "Sir Lancelot", "Thou art a noble knight, and I shall forever cherish thy words.");
    send_message(knights, "Sir Gawain", "Sir Lancelot", "A challenge awaits thee at dawn, noble friend!");
    
    // Receiving messages
    printf("Mail for Sir Lancelot:\n");
    receive_messages(knights, "Sir Lancelot");
    
    printf("\nMail for Lady Guinevere:\n");
    receive_messages(knights, "Lady Guinevere");

    // Free the list of knights and their messages
    free_knights(knights);
    
    return 0;
}

// Function to add a knight to the table
void add_knight(Knight **head, const char *name) {
    Knight *new_knight = malloc(sizeof(Knight));
    strncpy(new_knight->name, name, 50);
    new_knight->inbox = NULL;
    new_knight->next = *head;
    *head = new_knight;
}

// Function to find a knight by name
Knight* find_knight(Knight *head, const char *name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to send a message from one knight to another
void send_message(Knight *knights, const char *sender_name, const char *receiver_name, const char *content) {
    Knight *receiver = find_knight(knights, receiver_name);
    if (receiver != NULL) {
        Message *new_message = malloc(sizeof(Message));
        strcpy(new_message->content, content);
        new_message->next = receiver->inbox;
        receiver->inbox = new_message;
        printf("%s hath sent a message to %s: '%s'\n", sender_name, receiver_name, content);
    } else {
        printf("Alas! The knight %s is not found in the realm.\n", receiver_name);
    }
}

// Function to receive messages for a knight
void receive_messages(Knight *knights, const char *knight_name) {
    Knight *knight = find_knight(knights, knight_name);
    if (knight) {
        Message *current = knight->inbox;
        while (current) {
            printf(" - %s\n", current->content);
            current = current->next;
        }
        if (!knight->inbox) {
            printf(" - No messages hath been received.\n");
        }
    } else {
        printf("The knight craves to read letters, however, he is not found.\n");
    }
}

// Function to free the memory for knights and messages
void free_knights(Knight *head) {
    while (head) {
        Knight *temp = head;
        Message *msg = head->inbox;

        while (msg) {
            Message *msg_temp = msg;
            msg = msg->next;
            free(msg_temp);
        }

        head = head->next;
        free(temp);
    }
}