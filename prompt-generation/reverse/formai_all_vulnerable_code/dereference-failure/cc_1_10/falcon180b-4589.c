//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: genious
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node* node){
    while(node!= NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int search(struct Node* head, int x){
    struct Node* current = head;
    while(current!= NULL){
        if(current->data == x)
            return 1;
        current = current->next;
    }
    return 0;
}

void deleteNode(struct Node **head_ref, int key){
    struct Node* temp = *head_ref;
    struct Node* prev;
    if(temp!= NULL && temp->data == key){
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while(temp!= NULL && temp->data!= key){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

int main(){
    struct Node* head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 50);
    printf("Created Linked List: ");
    printList(head);
    int pos = 3;
    int key = 30;
    int flag = search(head, key);
    if(flag == 1){
        printf("\nKey %d found at position %d\n", key, pos);
    }
    else{
        printf("\nKey %d not found in the Linked List\n", key);
    }
    deleteNode(&head, key);
    printf("Linked List after deleting %d: ", key);
    printList(head);
    return 0;
}