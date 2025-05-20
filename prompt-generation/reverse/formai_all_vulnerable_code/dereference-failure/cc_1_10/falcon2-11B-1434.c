//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

typedef struct List {
    ListNode* head;
    ListNode* tail;
} List;

ListNode* create_node(int val) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

List* create_list() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void insert_node(List* list, int val) {
    ListNode* node = create_node(val);
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

void print_list(List* list) {
    ListNode* current = list->head;
    while (current!= NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

int main() {
    List* list = create_list();
    insert_node(list, 1);
    insert_node(list, 2);
    insert_node(list, 3);
    insert_node(list, 4);
    insert_node(list, 5);
    print_list(list);
    return 0;
}