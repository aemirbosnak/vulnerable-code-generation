//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char name[MAX_LINE_SIZE];
    char email[MAX_LINE_SIZE];
    int subscribed;
    struct node *next;
} node;

node *head = NULL;

void add_node(char *name, char *email) {
    node *temp = (node *) malloc(sizeof(node));
    strcpy(temp->name, name);
    strcpy(temp->email, email);
    temp->subscribed = 1;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    } else {
        node *curr = head;
        while (curr->next!= NULL) {
            curr = curr->next;
        }
        curr->next = temp;
    }
    printf("User %s added to mailing list\n", name);
}

void remove_node(char *email) {
    node *temp = head;
    node *prev = NULL;
    while (temp!= NULL) {
        if (strcmp(temp->email, email) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("User %s removed from mailing list\n", temp->name);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("User not found in mailing list\n");
}

void print_list() {
    node *temp = head;
    while (temp!= NULL) {
        printf("%s (%s)\n", temp->name, temp->email);
        temp = temp->next;
    }
}

void send_mail(char *email) {
    printf("Sending email to %s\n", email);
}

int main() {
    add_node("John Doe", "john.doe@example.com");
    add_node("Jane Smith", "jane.smith@example.com");
    add_node("Bob Johnson", "bob.johnson@example.com");
    print_list();
    remove_node("jane.smith@example.com");
    print_list();
    send_mail("john.doe@example.com");
    send_mail("bob.johnson@example.com");
    return 0;
}