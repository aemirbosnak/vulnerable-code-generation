//FormAI DATASET v1.0 Category: Memory management ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

void createList(struct node* head, int n) {
    struct node* new_node, * curr_node;
    int i, num;
    
    for (i = 0; i < n;i++) {
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter data of node %d: ", i+1);
        scanf("%d", &num);
        new_node->data = num;
        
        if(i==0) {
            head->next = new_node;
            curr_node = new_node;
        }
        else {
            curr_node->next = new_node;
            curr_node = curr_node->next;
        }
    }
    curr_node->next = NULL;
}

void printList(struct node* head) {
    struct node* curr_node = head->next;
    
    if(curr_node == NULL) {
        printf("List is empty\n");
    }
    else {
        printf("List: ");
        while(curr_node != NULL) {
            printf("%d ", curr_node->data);
            curr_node = curr_node->next;
        }
        printf("\n");
    }
}

void deleteNode(struct node* head, int val) {
    if(head == NULL) {
        return;
    }
    struct node* curr_node = head->next;
    struct node* prev_node = head;
    
    while(curr_node != NULL) {
        if(curr_node->data == val) {
            prev_node->next = curr_node->next;
            free(curr_node);
            printf("%d deleted from the list\n", val);
            return;
        }
        else {
            prev_node = curr_node;
            curr_node = curr_node->next;
        }
    }
    
    printf("%d not found in the list\n", val);
}

void deleteList(struct node* head) {
    if(head == NULL) {
        return;
    }
    if(head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    deleteList(head->next);
    free(head);
}

int main() {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->next = NULL;
    
    int choice, val, n;
    do {
        printf("1. Create List\n2. Print List\n3. Delete Node\n4. Delete List\n5. Exit\nEnter Choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(head, n);
                break;
            case 2:
                printList(head);
                break;
            case 3:
                printf("Enter the value of node to be deleted: ");
                scanf("%d", &val);
                deleteNode(head, val);
                break;
            case 4:
                deleteList(head);
                printf("List Deleted\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while(1);
    
    return 0;
}