//FormAI DATASET v1.0 Category: Linked list operations ; Style: statistical
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void insertBegin(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insertEnd(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    while(last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

void deleteElement(struct Node **head_ref, int key){
    struct Node* temp = *head_ref, *prev;
    if(temp != NULL && temp->data == key){
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

void printList(struct Node *node){
    while(node != NULL){
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    int choice, data, pos;
    while(1){
        printf("1. Insert at Beginning\n2. Insert at End\n3. Delete Element\n4. Print List\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter data to be inserted: ");
                scanf("%d",&data);
                insertBegin(&head,data);
                break;
            case 2:
                printf("Enter data to be inserted: ");
                scanf("%d",&data);
                insertEnd(&head,data);
                break;
            case 3:
                printf("Enter data to be deleted: ");
                scanf("%d",&data);
                deleteElement(&head,data);
                break;
            case 4:
                printList(head);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}