//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create_list(int n) {
    struct Node* head = NULL;
    for (int i = 0; i < n; i++) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = i;
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
        } else {
            struct Node* last_node = head;
            while (last_node->next!= NULL) {
                last_node = last_node->next;
            }
            last_node->next = new_node;
        }
    }
    return head;
}

void print_list(struct Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* reverse_list(struct Node* head) {
    struct Node* prev_node = NULL;
    struct Node* curr_node = head;
    while (curr_node!= NULL) {
        struct Node* next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    return prev_node;
}

void delete_list(struct Node* head) {
    while (head!= NULL) {
        struct Node* temp_node = head;
        head = head->next;
        free(temp_node);
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    struct Node* head = create_list(n);
    print_list(head);

    head = reverse_list(head);
    printf("Reversed list: ");
    print_list(head);

    delete_list(head);

    return 0;
}