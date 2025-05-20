//Gemma-7B DATASET v1.0 Category: Email Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MESSAGES 10

typedef struct Message {
    char sender[20];
    char recipient[20];
    char subject[20];
    char message[MAX_MESSAGES];
    struct Message* next;
} Message;

Message* createMessage(char* sender, char* recipient, char* subject, char* message) {
    Message* newMessage = (Message*)malloc(sizeof(Message));

    strcpy(newMessage->sender, sender);
    strcpy(newMessage->recipient, recipient);
    strcpy(newMessage->subject, subject);
    strcpy(newMessage->message, message);

    newMessage->next = NULL;

    return newMessage;
}

void sendMessage(Message* message) {
    printf("From: %s\n", message->sender);
    printf("To: %s\n", message->recipient);
    printf("Subject: %s\n", message->subject);
    printf("Message: %s\n", message->message);

    printf("\n");
}

int main() {
    Message* inbox = NULL;
    Message* outbox = NULL;

    // Create a few sample messages
    Message* message1 = createMessage("Romeo", "Juliet", "Secret Meeting", "Meet me at the rose garden at midnight.");
    Message* message2 = createMessage("Juliet", "Romeo", "Reunion", "I'm coming to the feast at Capulet's mansion.");
    Message* message3 = createMessage("Tybalt", "Benvolio", "Challenge", "Prepare for a duel, Montague and Capulet.");

    // Add the messages to the inbox and outbox
    inbox = message1;
    outbox = message2;

    // Send a message
    sendMessage(message3);

    // Print the inbox and outbox
    printf("Inbox:\n");
    while (inbox) {
        sendMessage(inbox);
        inbox = inbox->next;
    }

    printf("Outbox:\n");
    while (outbox) {
        sendMessage(outbox);
        outbox = outbox->next;
    }

    return 0;
}