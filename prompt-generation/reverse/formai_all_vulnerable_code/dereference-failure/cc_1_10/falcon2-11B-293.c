//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: unmistakable
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

typedef struct {
    Node* head;
} LinkedList;

void push(LinkedList* list, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
}

int pop(LinkedList* list) {
    if (list->head == NULL) {
        return -1;
    }
    int data = list->head->data;
    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
    return data;
}

void print(LinkedList* list) {
    Node* current = list->head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    push(list, 1);
    push(list, 2);
    push(list, 3);
    print(list); // Output: 1 2 3
    printf("\n");
    int popped_data = pop(list);
    printf("Popped data: %d\n", popped_data); // Output: 1
    printf("\n");
    print(list); // Output: 2 3
    printf("\n");
    return 0;
}