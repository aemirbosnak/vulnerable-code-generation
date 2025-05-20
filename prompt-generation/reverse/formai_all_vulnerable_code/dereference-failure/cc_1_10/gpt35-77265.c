//FormAI DATASET v1.0 Category: Linked list operations ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* createNode(int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insertAtBeginning(Node** head_ref, int data){
    Node* temp = createNode(data);
    temp->next = (*head_ref);
    (*head_ref) = temp;
    printf("%d has been inserted at the beginning of the list\n", data);
}

void insertAtEnd(Node** head_ref, int data){
    Node* temp = createNode(data);
    Node* last = (*head_ref);
    if(*head_ref == NULL){
        *head_ref = temp;
        printf("%d has been inserted at the end of the list\n", data);
        return;
    }
    while(last->next != NULL)
        last = last->next;
    last->next = temp;
    printf("%d has been inserted at the end of the list\n", data);
}

void insertAtIndex(Node** head_ref, int data, int index){
    if(index < 0){
        printf("Invalid Index\n");
        return;
    }
    if(index == 0){
        insertAtBeginning(head_ref, data);
        return;
    }
    Node* temp = createNode(data);
    Node* prev = (*head_ref);
    for(int i = 0; i < index - 1; i++){
        if(prev == NULL){
            printf("Invalid Index\n");
            return;
        }
        prev = prev->next;
    }
    temp->next = prev->next;
    prev->next = temp;
    printf("%d has been inserted at index %d of the list\n", data, index);
}

void deleteAtBeginning(Node** head_ref){
    if(*head_ref == NULL){
        printf("List is already empty\n");
        return;
    }
    Node* temp = (*head_ref);
    (*head_ref) = (*head_ref)->next;
    free(temp);
    printf("First element of the list has been deleted\n");
}

void deleteAtEnd(Node** head_ref){
    if(*head_ref == NULL){
        printf("List is already empty\n");
        return;
    }
    if((*head_ref)->next == NULL){
        free(*head_ref);
        *head_ref = NULL;
        printf("Last element of the list has been deleted\n");
        return;
    }
    Node* last = (*head_ref);
    while(last->next->next != NULL)
        last = last->next;
    free(last->next);
    last->next = NULL;
    printf("Last element of the list has been deleted\n");
}

void deleteAtIndex(Node** head_ref, int index){
    if(*head_ref == NULL || index < 0){
        printf("Invalid Index\n");
        return;
    }
    if(index == 0){
        deleteAtBeginning(head_ref);
        return;
    }
    Node* prev = (*head_ref);
    for(int i = 0; i < index - 1; i++){
        if(prev == NULL || prev->next == NULL){
            printf("Invalid Index\n");
            return;
        }
        prev = prev->next;
    }
    Node* temp = prev->next->next;
    free(prev->next);
    prev->next = temp;
    printf("Element at index %d of the list has been deleted\n", index);
}

void display(Node* head){
     if(head == NULL){
        printf("List is empty\n");
        return;
    }
    printf("The list is: ");
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
    Node* head = NULL;
    int choice, data, index;
    while(1){
        printf("\n==============================\n");
        printf("Operations:\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Index\n4. Delete at Beginning\n5. Delete at End\n6. Delete at Index\n7. Display List\n8. Exit\n");
        printf("==============================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data to be inserted at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter the data to be inserted at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter the data and index for insertion: ");
                scanf("%d%d", &data, &index);
                insertAtIndex(&head, data, index);
                break;
            case 4:
                deleteAtBeginning(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                printf("Enter the index for deletion: ");
                scanf("%d", &index);
                deleteAtIndex(&head, index);
                break;
            case 7:
                display(head);
                break;
            case 8:
                printf("Exiting Program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}