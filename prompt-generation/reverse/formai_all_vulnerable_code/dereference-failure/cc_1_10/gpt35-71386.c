//FormAI DATASET v1.0 Category: Linked list operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void print_list(struct Node* head) {
    printf("[ ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("]");
}

struct Node* reverse_list(struct Node* head) {
    struct Node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

int main() {

    struct Node* head = NULL;

    printf("Welcome to the linked list puzzle! \n\n");

    printf("Enter the number of elements you want to add to the list: ");
    int num_elements;
    scanf("%d", &num_elements);

    printf("Great! Now enter %d integer values: \n", num_elements);
    for (int i = 0; i < num_elements; i++) {
        int num;
        scanf("%d", &num);
        insert(&head, num);
    }

    printf("\nHere's the linked list you created: \n");
    print_list(head);

    printf("\n\nCan you guess what the reverse of this linked list looks like?");
    printf("\nType 'yes' to see the reverse list: ");

    char answer[4];
    scanf("%s", answer);

    if (strcmp(answer, "yes") == 0) {
        struct Node* reversed_head = reverse_list(head);
        printf("\nThe reverse of this linked list is: \n");
        print_list(reversed_head);
    } else {
        printf("\nYou don't want to see the reverse list? That's okay, the program is still complete!");
    }

    return 0;
}