//FormAI DATASET v1.0 Category: Data structures visualization ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struct for Nodes in the Linked List
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Struct for Visualization of Linked List
typedef struct ListVis {
    char* str;
    Node* head;
} ListVis;

// generates a random integer between 1 and 100
int randomInt() {
    return rand() % 100 + 1;
}

// creates and initializes a new node
Node* createNode(int data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// appends a new node to the linked list
Node* append(Node* head, int data) {
    if (head == NULL) {
        head = createNode(data);
        return head;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = createNode(data);
    return head;
}

// creates a new visualization of the linked list
ListVis* createVisualization(Node* head) {
    ListVis* listVis = malloc(sizeof(ListVis));
    listVis->str = malloc(sizeof(char) * 100);
    listVis->head = head;
    return listVis;
}

// visualizes the linked list and returns a string
char* printVisualization(ListVis* listVis) {
    char* str = listVis->str;
    Node* current = listVis->head;

    for (int i = 0; i < 10; i++) {
        if (current == NULL) {
            sprintf(str + strlen(str), "NULL ");
        } else {
            sprintf(str + strlen(str), "%d -> ", current->data);
            current = current->next;
        }
    }
    return str;
}

int main() {
    srand(time(NULL));

    Node* head = NULL;
    ListVis* listVis = createVisualization(head);

    // append random integers to the linked list
    for (int i = 0; i < 10; i++) {
        int num = randomInt();
        head = append(head, num);
        printf("Appended %d to the linked list\n", num);
        printf("%s\n", printVisualization(listVis));
    }
    
    free(listVis->str);
    free(listVis);
    return 0;
}