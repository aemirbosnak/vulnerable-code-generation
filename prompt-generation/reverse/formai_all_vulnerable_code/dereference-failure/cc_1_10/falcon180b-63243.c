//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 200
#define MAX_SUBJECT_LENGTH 200
#define MAX_BODY_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    time_t last_contacted;
    char *subject;
    char *body;
    struct node *next;
} Contact;

typedef struct node {
    Contact *data;
    struct node *next;
} Node;

Node *head = NULL;

void add_contact(char *name, char *email, char *subject, char *body) {
    Contact *contact = (Contact *) malloc(sizeof(Contact));
    strcpy(contact->name, name);
    strcpy(contact->email, email);
    strcpy(contact->subject, subject);
    strcpy(contact->body, body);
    contact->last_contacted = time(NULL);
    contact->next = NULL;

    if (head == NULL) {
        head = (Node *) malloc(sizeof(Node));
        head->data = contact;
        head->next = NULL;
    } else {
        Node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = (Node *) malloc(sizeof(Node));
        temp->next->data = contact;
        temp->next->next = NULL;
    }
}

void print_contacts() {
    Node *temp = head;
    while (temp!= NULL) {
        Contact *contact = temp->data;
        printf("Name: %s\nEmail: %s\nLast Contacted: %s", contact->name, contact->email, ctime(&contact->last_contacted));
        printf("Subject: %s\nBody:\n%s\n", contact->subject, contact->body);
        temp = temp->next;
    }
}

void send_email(char *name, char *email, char *subject, char *body) {
    printf("Sending email to %s with subject %s:\n%s\n", name, subject, body);
}

int main() {
    add_contact("John Doe", "john.doe@example.com", "Hello", "How are you?");
    add_contact("Jane Doe", "jane.doe@example.com", "Hi", "What's up?");

    print_contacts();

    send_email("John Doe", "john.doe@example.com", "Test", "This is a test email.");

    return 0;
}