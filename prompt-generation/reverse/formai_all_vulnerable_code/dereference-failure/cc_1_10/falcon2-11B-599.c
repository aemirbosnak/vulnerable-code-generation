//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: futuristic
// This program visualizes a futuristic data structure in C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

typedef struct node {
    int value;
    struct node* next;
} Node;

typedef struct {
    Node* head;
} List;

List* create_list() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    return list;
}

void append_to_list(List* list, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node* current = list->head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void display_list(List* list) {
    Node* current = list->head;
    while (current!= NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main() {
    List* list = create_list();
    
    for (int i = 0; i < 10; i++) {
        int value = rand() % 100;
        append_to_list(list, value);
    }
    
    display_list(list);
    
    return 0;
}