//FormAI DATASET v1.0 Category: Linked list operations ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

//Node structure
struct Node{
    int data;
    struct Node *next;
};

//Initialize list
void initList(struct Node **head){
    *head = NULL;
}

//Add a new node to the list
void addNode(struct Node **head, int data){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = *head;
    *head = temp;
    printf("Node added to list successfully!\n");
}

//Print the list
void printList(struct Node *head){
    if(head == NULL){
        printf("List is empty!\n");
        return;
    }
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

//Delete a node from the list
void deleteNode(struct Node **head, int key){
    if(*head == NULL){
        printf("List is empty, Node cannot be deleted!\n");
        return;
    }
    struct Node *temp = *head, *prev = NULL;
    if(temp != NULL && temp->data == key){
        *head = temp->next;
        free(temp);
        printf("Node deleted successfully!\n");
        return;
    }
    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Node not found in the list!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node deleted successfully!\n");
}

//Find the length of the list
int lengthList(struct Node *head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head->next;
    }
    return count;
}

//Reverse the list
void reverseList(struct Node **head){
    struct Node *prev = NULL, *current = *head, *next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    printf("List reversed successfully!\n");
}

int main(){
    struct Node *head;
    int choice, data, key;
    initList(&head);
    do{
        printf("\n--Linked List Operations--\n");
        printf("1. Add Node\n");
        printf("2. Delete Node\n");
        printf("3. Print List\n");
        printf("4. Length of the List\n");
        printf("5. Reverse List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case 2:
                printf("Enter the key to be deleted: ");
                scanf("%d", &key);
                deleteNode(&head, key);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                printf("Length of the list is %d\n", lengthList(head));
                break;
            case 5:
                reverseList(&head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }while(choice != 6);
    return 0;
}