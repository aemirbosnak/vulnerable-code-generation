//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct node {
    char data[MAX_SIZE];
    struct node *next;
};

struct node *head = NULL;

void create_node(char *data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    strcpy(new_node->data, data);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void traverse_list() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct node *temp = head;
        while (temp!= NULL) {
            printf("%s ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    head = NULL;

    create_node("Hello world!");
    create_node("This is a test.");
    create_node("How are you doing today?");

    traverse_list();

    return 0;
}