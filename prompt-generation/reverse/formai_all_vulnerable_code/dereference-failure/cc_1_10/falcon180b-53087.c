//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 64
#define MAX_EMAIL_LEN 128
#define MAX_SUBJECTS 64
#define MAX_RECIPIENTS 64
#define MAX_MESSAGE_LEN 1024

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} recipient;

typedef struct {
    char subject[MAX_SUBJECTS];
    recipient *recipients;
    int num_recipients;
    char message[MAX_MESSAGE_LEN];
} message;

void init_message(message *msg) {
    msg->num_recipients = 0;
    msg->recipients = NULL;
}

int add_recipient(message *msg, char *name, char *email) {
    recipient *recipient = malloc(sizeof(recipient));
    strncpy(recipient->name, name, MAX_NAME_LEN - 1);
    strncpy(recipient->email, email, MAX_EMAIL_LEN - 1);
    recipient->email[MAX_EMAIL_LEN - 1] = '\0';
    msg->recipients = realloc(msg->recipients, sizeof(recipient) * (msg->num_recipients + 1));
    msg->recipients[msg->num_recipients++] = *recipient;
    return 0;
}

int send_message(message *msg) {
    printf("Sending message to %d recipients:\n", msg->num_recipients);
    for (int i = 0; i < msg->num_recipients; i++) {
        printf("  %s <%s>\n", msg->recipients[i].name, msg->recipients[i].email);
    }
    printf("Subject: %s\n", msg->subject);
    printf("Message:\n%s\n", msg->message);
    return 0;
}

int main() {
    message msg;
    init_message(&msg);
    char input[MAX_MESSAGE_LEN];
    while (fgets(input, MAX_MESSAGE_LEN, stdin)) {
        if (input[0] == 'T') {
            char *name = strtok(input, " ");
            char *email = strtok(NULL, " ");
            add_recipient(&msg, name, email);
        } else if (input[0] == 'S') {
            strcpy(msg.subject, input + 1);
        } else if (input[0] == 'M') {
            strcpy(msg.message, input + 1);
        }
    }
    send_message(&msg);
    return 0;
}