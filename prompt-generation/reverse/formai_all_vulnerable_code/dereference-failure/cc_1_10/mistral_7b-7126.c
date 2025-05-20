//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LIST_SIZE 100

typedef struct Node {
    char email[50];
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;
int list_size = 0;

bool is_full() {
    return (list_size == MAX_LIST_SIZE);
}

void add_email(char *email) {
    if (is_full()) {
        printf("Mailing list is full.\n");
        return;
    }

    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->email, email);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }

    list_size++;
}

void remove_email(char *email) {
    Node *current = head;
    Node *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }

            free(current);
            list_size--;
            break;
        }

        previous = current;
        current = current->next;
    }
}

void display_list() {
    Node *current = head;

    printf("Mailing List:\n");
    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

int main() {
    add_email("user1@example.com");
    add_email("user2@example.com");
    add_email("user3@example.com");

    display_list();

    remove_email("user2@example.com");

    display_list();

    return 0;
}