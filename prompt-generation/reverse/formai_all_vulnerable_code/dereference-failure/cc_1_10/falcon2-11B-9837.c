//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

struct node {
    char name[MAX_STRING_LENGTH];
    struct node* next;
};

struct node* head = NULL;

void insert_node(struct node* new_node) {
    if (head == NULL) {
        head = new_node;
        return;
    }
    
    struct node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void print_list() {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%s\n", temp->name);
        temp = temp->next;
    }
}

int main() {
    struct node* new_node;
    char name[MAX_STRING_LENGTH];
    
    printf("Enter name: ");
    scanf("%s", name);
    
    new_node = (struct node*) malloc(sizeof(struct node));
    strcpy(new_node->name, name);
    
    insert_node(new_node);
    
    print_list();
    
    free(new_node);
    
    return 0;
}