//FormAI DATASET v1.0 Category: Email Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct email {
    char *from;
    char *to;
    char *subject;
    char *message;
    struct email *next;
};

struct email *createEmail(char *from, char *to, char *subject, char *message) {
    struct email *newemail = malloc(sizeof(struct email));
    newemail->from = strdup(from);
    newemail->to = strdup(to);
    newemail->subject = strdup(subject);
    newemail->message = strdup(message);
    newemail->next = NULL;

    return newemail;
}

struct email *addEmail(struct email *head, char *from, char *to, char *subject, char *message) {
    if (head == NULL) {
        return createEmail(from, to, subject, message);
    }

    head->next = addEmail(head->next, from, to, subject, message);

    return head;
}

void printEmail(struct email *email) {
    printf("From: %s\nTo: %s\nSubject: %s\nMessage: %s\n", email->from, email->to, email->subject, email->message);
}

void printAllEmails(struct email *head) {
    if (head == NULL) {
        printf("No emails found.\n");
        return;
    }

    printEmail(head);
    printf("\n");

    printAllEmails(head->next);
}

void deleteEmail(struct email *head, char *search) {
    if (head == NULL) {
        printf("Email not found.\n");
        return;
    }

    if (strcmp(head->subject, search) == 0) {
        struct email *temp = head;
        head = head->next;
        free(temp);
        printf("Email deleted.\n");
        return;
    }

    deleteEmail(head->next, search);
}

int main() {
    struct email *head = NULL;

    head = addEmail(head, "user1@example.com", "user2@example.com", "Meeting Recap", "Hello, here is the summary of our meeting:\n- Discussed project timeline\n- Assigned tasks for next week\n\nBest,\nUser1");
    head = addEmail(head, "user2@example.com", "user1@example.com", "Project Update", "Hey User1,\nJust wanted to update you on the project status. We are making good progress and should have everything done on time.\n\nThanks,\nUser2");
    head = addEmail(head, "user3@example.com", "user1@example.com", "Question about project", "Hi User1,\nI had a question about the project. Are we planning on using the new API for this?\n\nThanks,\nUser3");

    printf("All Emails:\n");
    printAllEmails(head);

    deleteEmail(head, "Project Update");

    printf("\nUpdated Emails:\n");
    printAllEmails(head);

    return 0;
}