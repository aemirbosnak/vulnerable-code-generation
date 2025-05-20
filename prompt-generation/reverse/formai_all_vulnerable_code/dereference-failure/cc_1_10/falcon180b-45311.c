//Falcon-180B DATASET v1.0 Category: Email Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *name;
    char *email;
    struct node *next;
} Node;

Node *head = NULL;

void add_node(Node *head, char *name, char *email) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->name = strdup(name);
    new_node->email = strdup(email);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node *curr_node = head;
        while (curr_node->next!= NULL) {
            curr_node = curr_node->next;
        }
        curr_node->next = new_node;
    }
}

void print_list(Node *head) {
    Node *curr_node = head;
    while (curr_node!= NULL) {
        printf("%s <%s>\n", curr_node->name, curr_node->email);
        curr_node = curr_node->next;
    }
}

int main() {
    char input[MAX_LINE_SIZE];
    char name[MAX_LINE_SIZE];
    char email[MAX_LINE_SIZE];

    printf("Enter your name: ");
    fgets(input, MAX_LINE_SIZE, stdin);
    strcpy(name, input);
    strtok(name, " ");

    printf("Enter your email: ");
    fgets(input, MAX_LINE_SIZE, stdin);
    strcpy(email, input);
    strtok(email, " ");

    add_node(head, name, email);

    printf("List of contacts:\n");
    print_list(head);

    return 0;
}