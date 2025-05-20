//FormAI DATASET v1.0 Category: Data recovery tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node* next;
} Node;

Node* create_node(int val) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = NULL;
    return new_node;
}

void insert_at_end(Node** head, int val) {
    Node* new_node = create_node(val);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node* temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void display_list(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void recover_data(Node* head) {
    FILE* fp = fopen("recovered_data.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(0);
    }
    Node* temp = head;
    while (temp != NULL) {
        fprintf(fp, "%d\n", temp->data);
        temp = temp->next;
    }
    fclose(fp);
    printf("Data recovery successful!\n");
}

int main() {
    Node* head = NULL;
    insert_at_end(&head, 5);
    insert_at_end(&head, 10);
    insert_at_end(&head, 15);
    insert_at_end(&head, 20);
    insert_at_end(&head, 25);
    printf("Original Data:\n");
    display_list(head);
    recover_data(head);
    return 0;
}