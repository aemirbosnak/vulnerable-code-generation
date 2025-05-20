//Gemma-7B DATASET v1.0 Category: Email Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_SIZE 1024

typedef struct Message
{
    char *subject;
    char *from;
    char *to;
    char *body;
    struct Message *next;
} Message;

Message *create_message(char *subject, char *from, char *to, char *body)
{
    Message *message = malloc(sizeof(Message));

    message->subject = strdup(subject);
    message->from = strdup(from);
    message->to = strdup(to);
    message->body = strdup(body);
    message->next = NULL;

    return message;
}

void print_message(Message *message)
{
    printf("Subject: %s\n", message->subject);
    printf("From: %s\n", message->from);
    printf("To: %s\n", message->to);
    printf("Body: %s\n", message->body);
    printf("\n");
}

int main()
{
    Message *inbox = NULL;
    Message *sent = NULL;

    // Create a few messages
    Message *message1 = create_message("Hey, you!", "john.doe@example.com", "alice.smith@example.com", "This is the first message.");
    Message *message2 = create_message("What's up?", "jane.doe@example.com", "alice.smith@example.com", "This is the second message.");
    Message *message3 = create_message("Have a nice day!", "bill.smith@example.com", "alice.smith@example.com", "This is the third message.");

    // Add messages to the inbox
    inbox = message1;
    inbox->next = message2;
    inbox->next->next = message3;

    // Print all messages in the inbox
    print_message(inbox);

    // Send a message
    message2 = create_message("Re: What's up?", "jane.doe@example.com", "alice.smith@example.com", "This is a reply to the second message.");

    // Add the message to the sent list
    sent = message2;

    // Print all messages in the sent list
    print_message(sent);

    return 0;
}