//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
    char *name;
    char *email;
    struct node *next;
} node_t;

node_t *head = NULL;

void add_subscriber(char *name, char *email) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->name = strdup(name);
    new_node->email = strdup(email);
    new_node->next = head;
    head = new_node;
}

void remove_subscriber(char *name) {
    node_t *current = head;
    node_t *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }

            free(current->name);
            free(current->email);
            free(current);

            break;
        }

        prev = current;
        current = current->next;
    }
}

void send_email(char *subject, char *body) {
    node_t *current = head;

    while (current != NULL) {
        // Send the email to the current subscriber
        printf("Sending email to %s <%s>\n", current->name, current->email);
        printf("Subject: %s\n", subject);
        printf("Body: %s\n", body);

        current = current->next;
    }
}

int main() {
    add_subscriber("John Doe", "john.doe@example.com");
    add_subscriber("Jane Doe", "jane.doe@example.com");

    send_email("Hello", "This is a test email.");

    remove_subscriber("John Doe");

    send_email("Goodbye", "This is a goodbye email.");

    return 0;
}