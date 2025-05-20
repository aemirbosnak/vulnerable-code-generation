//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char* email;
    struct node* next;
} node;

node* head = NULL;

void add_user(char* email) {
    node* new_node = (node*)malloc(sizeof(node));
    strcpy(new_node->email, email);
    new_node->next = head;
    head = new_node;
}

void print_users() {
    node* current = head;
    while (current!= NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

void delete_user(char* email) {
    node* current = head;
    while (current!= NULL) {
        if (strcmp(current->email, email) == 0) {
            break;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("User not found.\n");
    } else {
        node* prev = current->next;
        free(current);
        head = prev;
    }
}

int main() {
    char email1[50];
    char email2[50];

    printf("Enter email address 1: ");
    scanf("%s", email1);
    add_user(email1);

    printf("Enter email address 2: ");
    scanf("%s", email2);
    add_user(email2);

    print_users();

    printf("Enter email address to delete: ");
    scanf("%s", email1);
    delete_user(email1);

    print_users();

    return 0;
}