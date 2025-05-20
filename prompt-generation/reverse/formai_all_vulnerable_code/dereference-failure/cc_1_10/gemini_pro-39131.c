//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int value;
    struct node *next;
} node;

node *create_list(int n) {
    node *head = NULL;
    node *prev = NULL;
    for (int i = 0; i < n; i++) {
        node *new_node = malloc(sizeof(node));
        new_node->value = rand() % 100;
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
        } else {
            prev->next = new_node;
        }
        prev = new_node;
    }
    return head;
}

void print_list(node *head) {
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

int search_list(node *head, int target) {
    int index = 0;
    while (head != NULL) {
        if (head->value == target) {
            return index;
        }
        index++;
        head = head->next;
    }
    return -1;
}

int main() {
    srand(time(NULL));
    int n = 10;
    node *head = create_list(n);
    print_list(head);
    int target = 50;
    int index = search_list(head, target);
    if (index == -1) {
        printf("%d not found in the list.\n", target);
    } else {
        printf("%d found at index %d.\n", target, index);
    }
    return 0;
}