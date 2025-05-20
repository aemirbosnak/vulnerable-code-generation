//FormAI DATASET v1.0 Category: Data structures visualization ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

//declaring the node structure
struct Node {
    int data;
    struct Node* next;
};

//function to push elements to the stack
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

//function to check if the stack is empty
int isEmpty(struct Node* head) {
    return !head;
}

//function to pop elements from the stack
int pop(struct Node** head_ref) {
    if (isEmpty(*head_ref))
        return -1;
    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

//function to display the stack
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//main function
int main() {
    struct Node* head = NULL;
    int option, num;
    do {
        printf("\n1. Push Element");
        printf("\n2. Pop Element");
        printf("\n3. Display Elements");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &option);
        switch (option) {
        case 1:
            printf("\nEnter the element to push: ");
            scanf("%d", &num);
            push(&head, num);
            printf("%d pushed to stack\n", num);
            break;
        case 2:
            num = pop(&head);
            if (num == -1)
                printf("\nStack is empty\n");
            else
                printf("%d popped from stack\n", num);
            break;
        case 3:
            display(head);
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid option\n");
        }
    } while (option != 4);
    return 0;
}