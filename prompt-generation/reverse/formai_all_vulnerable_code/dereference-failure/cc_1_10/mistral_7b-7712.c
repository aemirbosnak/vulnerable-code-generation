//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node {
    int data;
    char* name;
    struct Node* next;
} Node;

Node* create_node(int data, char* name) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error! (o_o)\n");
        return NULL;
    }
    new_node->data = data;
    new_node->name = strdup(name);
    new_node->next = NULL;
    return new_node;
}

void print_list(Node* head) {
    Node* current = head;
    printf("( ͡° ͜ʖ ͡°) List of Mysteries:\n");
    while (current != NULL) {
        printf("(%d) %s -> ", current->data, current->name);
        current = current->next;
    }
    printf("NULL\n");
}

void append_node(Node** head, int data, char* name) {
    Node* new_node = create_node(data, name);
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node* last = *head;
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

int main() {
    srand(time(NULL));
    Node* list_head = NULL;

    int num_elements = rand() % 10 + 1;
    printf("(≖‿≖) Creating %d elements...\n", num_elements);

    for (int i = 0; i < num_elements; i++) {
        int random_data = rand() % 50 + 1;
        char random_name[15];
        sprintf(random_name, "Mystery %d", i + 1);
        append_node(&list_head, random_data, random_name);
    }

    print_list(list_head);

    free(list_head);
    printf("(≖‿≖) List of Mysteries destroyed.\n");

    return 0;
}