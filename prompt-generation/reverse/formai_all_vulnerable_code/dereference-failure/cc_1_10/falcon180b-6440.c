//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_node(Node** head, int data) {
    Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node* last = *head;
    while (last->next!= NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void print_list(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void bucket_sort(Node* head, int num_buckets) {
    Node** buckets = (Node**) malloc(sizeof(Node*) * num_buckets);
    if (!buckets) {
        printf("Memory error\n");
        exit(1);
    }
    int bucket_size = 100000;
    for (int i = 0; i < num_buckets; i++) {
        buckets[i] = NULL;
    }
    Node* curr_node = head;
    while (curr_node!= NULL) {
        int bucket_index = curr_node->data / bucket_size;
        add_node(&buckets[bucket_index], curr_node->data);
        curr_node = curr_node->next;
    }
    curr_node = head;
    for (int i = 0; i < num_buckets; i++) {
        while (buckets[i]!= NULL) {
            curr_node = curr_node->next;
            buckets[i] = buckets[i]->next;
            if (curr_node == head) {
                curr_node = head;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int num_nodes = rand() % 10000 + 1;
    Node* head = NULL;
    for (int i = 0; i < num_nodes; i++) {
        int data = rand() % 10000;
        add_node(&head, data);
    }
    printf("Before sorting:\n");
    print_list(head);
    bucket_sort(head, 10);
    printf("After sorting:\n");
    print_list(head);
    return 0;
}