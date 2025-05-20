//FormAI DATASET v1.0 Category: Mailing list manager ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Email {
    char *to;
    char *subject;
    char *body;
};

struct Node {
    struct Email *email;
    struct Node *next;
};

struct List {
    struct Node *head;
    struct Node *tail;
};

void add_email(struct List *list, struct Email *email) {
    struct Node *node = malloc(sizeof(struct Node));
    node->email = email;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
    } else {
        list->tail->next = node;
    }

    list->tail = node;
}

void print_email(struct Email *email) {
    printf("To: %s\nSubject: %s\nBody: %s\n\n", email->to, email->subject, email->body);
}

void print_list(struct List *list) {
    struct Node *node = list->head;

    while (node != NULL) {
        print_email(node->email);
        node = node->next;
    }
}

void free_list(struct List *list) {
    struct Node *node = list->head;

    while (node != NULL) {
        free(node->email->to);
        free(node->email->subject);
        free(node->email->body);

        struct Node *temp = node;
        node = node->next;
        free(temp);
    }
}

int main() {
    struct List *list = malloc(sizeof(struct List));
    list->head = NULL;
    list->tail = NULL;

    while (1) {
        char *input = malloc(sizeof(char) * 1024);
        printf("Enter an email (or \"quit\" to exit):\n");
        fgets(input, 1024, stdin);

        if (strcmp(input, "quit\n") == 0) {
            free(input);
            break;
        }

        char *to = strtok(input, ",");
        char *subject = strtok(NULL, ",");
        char *body = strtok(NULL, "");

        struct Email *email = malloc(sizeof(struct Email));
        email->to = malloc(sizeof(char) * (strlen(to) + 1));
        email->subject = malloc(sizeof(char) * (strlen(subject) + 1));
        email->body = malloc(sizeof(char) * (strlen(body) + 1));

        strcpy(email->to, to);
        strcpy(email->subject, subject);
        strcpy(email->body, body);

        add_email(list, email);
        free(input);
    }

    printf("\nList of emails:\n");
    print_list(list);

    free_list(list);
    free(list);

    return 0;
}