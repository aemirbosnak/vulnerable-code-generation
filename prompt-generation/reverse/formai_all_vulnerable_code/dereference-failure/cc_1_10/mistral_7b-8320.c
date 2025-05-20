//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_end(Node** head, int data) {
    Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

float mean(Node* head) {
    Node* current = head;
    float sum = 0;
    int count = 0;
    while (current != NULL) {
        sum += current->data;
        count++;
        current = current->next;
    }
    return sum / count;
}

float median(Node* head) {
    Node* current = head;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    Node* middle = head;
    int middle_index = count / 2;
    int index = 0;
    while (middle != NULL && index < middle_index) {
        middle = middle->next;
        index++;
    }
    return middle->data;
}

float standard_deviation(Node* head) {
    Node* current = head;
    float sum = 0;
    int count = 0;
    while (current != NULL) {
        sum += current->data * current->data;
        count++;
        current = current->next;
    }
    float avg = mean(head);
    return sqrt(sum / count - pow(avg, 2));
}

int main() {
    Node* head = NULL;
    insert_at_end(&head, 5);
    insert_at_end(&head, 3);
    insert_at_end(&head, 8);
    insert_at_end(&head, 1);
    insert_at_end(&head, 6);

    printf("Mean: %.2f\n", mean(head));
    printf("Median: %.2f\n", median(head));
    printf("Standard Deviation: %.2f\n", standard_deviation(head));

    return 0;
}