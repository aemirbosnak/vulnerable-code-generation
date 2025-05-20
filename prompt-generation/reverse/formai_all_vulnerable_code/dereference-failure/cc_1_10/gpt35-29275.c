//FormAI DATASET v1.0 Category: Password management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Node struct for password linked list */
typedef struct password_node {
    char *username;
    char *password;
    struct password_node *next;
} PasswordNode;

/* Basic queue struct for async password manager */
typedef struct queue {
    bool locked;  // flag to track if queue is currently being accessed
    PasswordNode *head;
} Queue;

/* Queue initializer */
Queue *init_queue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->locked = false;
    queue->head = NULL;
    return queue;
}

/* Password node initializer */
PasswordNode *init_password_node(char *username, char *password) {
    PasswordNode *node = (PasswordNode *)malloc(sizeof(PasswordNode));
    node->username = (char *)malloc(sizeof(char) * (strlen(username) + 1));
    node->password = (char *)malloc(sizeof(char) * (strlen(password) + 1));
    strcpy(node->username, username);
    strcpy(node->password, password);
    node->next = NULL;
    return node;
}

/* Adding a password to the queue */
void add_password(Queue *queue, char *username, char *password) {
    while (queue->locked) {}  // wait until lock is released
    queue->locked = true;  // acquire queue lock
    PasswordNode *node = init_password_node(username, password);
    if (!queue->head) {
        queue->head = node;
    } else {
        PasswordNode *curr = queue->head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = node;
    }
    queue->locked = false;  // release queue lock
}

/* Retrieving a password by username */
void get_password(Queue *queue, char *username) {
    while (queue->locked) {}  // wait until lock is released
    queue->locked = true;  // acquire queue lock
    PasswordNode *curr = queue->head;
    while (curr) {
        if (strcmp(curr->username, username) == 0) {
            printf("Username: %s\nPassword: %s\n", curr->username, curr->password);
            queue->locked = false;  // release queue lock
            return;
        }
        curr = curr->next;
    }
    printf("Password not found for %s.\n", username);
    queue->locked = false;  // release queue lock
}

/* Main function for testing password manager */
int main(void) {
    Queue *queue = init_queue();
    add_password(queue, "user1", "password1");
    add_password(queue, "user2", "password2");
    add_password(queue, "user3", "password3");
    add_password(queue, "user4", "password4");

    get_password(queue, "user2");
    get_password(queue, "user4");
    get_password(queue, "user1");
    get_password(queue, "user5");

    return 0;
}