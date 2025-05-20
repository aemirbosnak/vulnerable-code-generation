//FormAI DATASET v1.0 Category: Data recovery tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} node_t;

typedef struct {
    node_t* head;
    int size;
} list_t;

void list_init(list_t* lst) {
    lst->head = NULL;
    lst->size = 0;
}

void list_append(list_t* lst, int data) {
    node_t* new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (lst->head == NULL) {
        lst->head = new_node;
    } else {
        node_t* cur_node = lst->head;
        while (cur_node->next != NULL) {
            cur_node = cur_node->next;
        }
        cur_node->next = new_node;
    }
    lst->size++;
}

void list_remove(list_t* lst, int data) {
    if (lst->head != NULL) {
        if (lst->head->data == data) {
            node_t* tmp = lst->head;
            lst->head = lst->head->next;
            free(tmp);
            lst->size--;
        } else {
            node_t* cur_node = lst->head;
            while (cur_node->next != NULL) {
                if (cur_node->next->data == data) {
                    node_t* tmp = cur_node->next;
                    cur_node->next = cur_node->next->next;
                    free(tmp);
                    lst->size--;
                    break;
                }
                cur_node = cur_node->next;
            }
        }
    }
}

bool list_contains(list_t* lst, int data) {
    if (lst->head != NULL) {
        node_t* cur_node = lst->head;
        while (cur_node != NULL) {
            if (cur_node->data == data) {
                return true;
            }
            cur_node = cur_node->next;
        }
    }
    return false;
}

void list_print(list_t* lst) {
    if (lst->head != NULL) {
        node_t* cur_node = lst->head;
        while (cur_node != NULL) {
            printf("%d", cur_node->data);
            cur_node = cur_node->next;
        }
    }
}

int main() {
    list_t lst;
    list_init(&lst);

    list_append(&lst, 1);
    list_append(&lst, 2);
    list_append(&lst, 3);

    printf("List contains 2: %s\n", list_contains(&lst, 2) ? "true" : "false");

    list_remove(&lst, 2);

    printf("List contains 2: %s\n", list_contains(&lst, 2) ? "true" : "false");

    list_print(&lst);

    return 0;
}