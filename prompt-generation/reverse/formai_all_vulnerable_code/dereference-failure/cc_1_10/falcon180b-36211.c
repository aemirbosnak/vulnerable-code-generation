//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *data;
    struct node *next;
} node;

typedef struct {
    node *head;
    int count;
} list;

void init_list(list *lst) {
    lst->head = NULL;
    lst->count = 0;
}

void add_node(list *lst, char *data) {
    node *new_node = (node *)malloc(sizeof(node));
    if(new_node == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    if(lst->head == NULL) {
        lst->head = new_node;
    } else {
        node *temp = lst->head;
        while(temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    lst->count++;
}

void print_list(list *lst) {
    node *temp = lst->head;
    while(temp!= NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    list my_list;
    init_list(&my_list);
    add_node(&my_list, "apple");
    add_node(&my_list, "banana");
    add_node(&my_list, "cherry");
    print_list(&my_list);
    return 0;
}